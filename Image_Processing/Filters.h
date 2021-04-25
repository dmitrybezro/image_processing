#pragma once

#include <vector>
#include <string>
#include <cmath>
#include<algorithm>

namespace Filters_BPP {

#define MAX(a, b) a>=b ? a : b
#define MIN(a, b) a>=b ? b : a
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//  Базовый класс фильтра
	class Filters {

	protected:
		virtual Color calculateNewPixelColor(Bitmap^ sourceImage, int x, int y) = 0;

	public:
		Bitmap^ processImage( Bitmap^ sourceImage, ProgressBar^ progress) {
			Bitmap^ resultImage = gcnew Bitmap  (sourceImage->Width, sourceImage->Height);
			for (int i = 0; i < sourceImage->Width; i++) {
				for (int j = 0; j <sourceImage->Height; j++) {
					resultImage->SetPixel(i, j, calculateNewPixelColor(sourceImage, i, j));
					progress->PerformStep();
				}
			}

			return resultImage;
		}
		
		int Clamp(int value, int min, int max) {
			if (value < min)
				return min;
			if (value > max)
				return max;
			return value;
		}
	};

	//  Инверсия
	class InvertFilter : public Filters {
	public:
		Color calculateNewPixelColor(Bitmap^ sourceImage, int x, int y) {
			Color sourceColor = sourceImage->GetPixel(x, y);
			Color resultColor = Color::FromArgb(255 - sourceColor.R,
												255 - sourceColor.G,
												255 - sourceColor.B);
			return resultColor;
		}
	};

	//  Шкала серого
	class GrayScaleFilter : public Filters {
	public:
		Color calculateNewPixelColor(Bitmap^ sourceImage, int x, int y) {
			Color sourceColor = sourceImage->GetPixel(x, y);
			float intensity = 0.299 * sourceColor.R + 0.587 * sourceColor.G + 0.114 * sourceColor.B;
			Color resultColor = Color::FromArgb(intensity, intensity, intensity);
			return resultColor;
		}
	};

	//  Сепия
	class SepiaFilter : public Filters {
	public:
		Color calculateNewPixelColor(Bitmap^ sourceImage, int x, int y) {
			Color sourceColor = sourceImage->GetPixel(x, y);
			float intensity = 0.299 * sourceColor.R + 0.587 * sourceColor.G + 0.114 * sourceColor.B;
			float K = 64;
			Color resultColor = Color::FromArgb(Clamp(intensity + 2 * K, 0, 255), 
												Clamp(intensity + 0.5 * K, 0, 255),
												Clamp(intensity - K, 0 , 255));
			return resultColor;
		}
	};

	//  Яркость
	class BrightnessFilter : public Filters {
	public:
		Color calculateNewPixelColor(Bitmap^ sourceImage, int x, int y) {
			Color sourceColor = sourceImage->GetPixel(x, y);
			float Br = 45;
			Color resultColor = Color::FromArgb(Clamp(sourceColor.R + Br, 0, 255),
				Clamp(sourceColor.G + Br, 0, 255),
				Clamp(sourceColor.B + Br, 0, 255));
			return resultColor;
		}
	};

	//  Базовый класс матричных фильтров
	class MatrixFilter : public Filters {
	protected:
		std::vector<std::vector<float>> kernel;
		MatrixFilter() {}

	public:
		MatrixFilter(std::vector<std::vector<float>> _kernel) {
			this->kernel = _kernel;
		}

	protected:
		Color calculateNewPixelColor(Bitmap^ sourceImage, int x, int y) {

			int radiusX = kernel.size()/2;
			int radiusY = kernel[0].size()/2;

			float resultR = 0;
			float resultG = 0;
			float resultB = 0;
			for (int l = -radiusY; l <= radiusY; l++) {
				for (int k = -radiusX; k <= radiusX; k++) {
					int idX = Clamp(x + k, 0, sourceImage->Width - 1);
					int idY = Clamp(y + k, 0, sourceImage->Height - 1);

					Color neighColor = sourceImage->GetPixel(idX, idY);
					resultR += neighColor.R * kernel[k + radiusX][l + radiusY];
					resultG += neighColor.G * kernel[k + radiusX][l + radiusY];
					resultB += neighColor.B * kernel[k + radiusX][l + radiusY];
				}
			}
			return Color::FromArgb(Clamp((int)resultR, 0, 255), Clamp((int)resultG, 0, 255), Clamp((int)resultB, 0, 255));
		}
	};

	//  Размытие
	class BlurFilter : public MatrixFilter {
	public:
		BlurFilter() {
			int sizeX = 3;
			int sizeY = 3;
			float mean = 1.0f / (static_cast<float>(sizeX * sizeY));

			std::vector<std::vector<float>> tmp(sizeX);
			for (int i = 0; i < tmp.size(); i++)
				tmp[i].resize(sizeX);
			kernel = tmp;

			for (int i = 0; i < kernel.size(); i++) {
				for (int j = 0; j < kernel[i].size(); j++) {
					kernel[i][j] = mean;
				}
			}

		}
	};

	//  Фильтр Гаусса
	class GaussianFilter : public MatrixFilter {
	public:
		void createGaussianKernel(int radius, float sigma) {
			int size = 2 * radius + 1;

			std::vector<std::vector<float>> tmp(size);
			for (int i = 0; i < size; i++)
				tmp[i].resize(size);
			kernel = tmp;

			//  Коэф нормировки ядра
			float norm = 0;

			//  Рассчитать ядро
			for (int i = -radius; i <= radius; i++) {
				for (int j = -radius; j <= radius; j++) {
					kernel[i + radius][j + radius] = static_cast<float>(exp(-(i * i + j * j) / (2 * pow(sigma, 2))));
					norm += kernel[i + radius][j + radius];
				}
			}

			//  Нормируем ядро
			for (int i = 0; i < size; i++)
				for (int j = 0; j < size; j++)
					kernel[i][j] /= norm;
		}

		GaussianFilter() {
			createGaussianKernel(3, 2);
		}
	};

	//  Фильтр Собеля
	class SobelFilter : public MatrixFilter {
	public:
		SobelFilter() {
			std::vector<std::vector<float>> tmp(3);
			for (int i = 0; i < tmp.size(); i++)
				tmp[i].resize(3);
			kernel = tmp;

			kernel[0][0] = -1;
			kernel[0][1] = -2;
			kernel[0][2] = -1;
			kernel[1][0] = 0;
			kernel[1][1] = 0;
			kernel[1][2] = 0;
			kernel[2][0] = 1;
			kernel[2][1] = 2;
			kernel[2][2] = 1;
		}
	};

	//  Резкость
	class SharpnessFilter : public MatrixFilter {
	public: 
		SharpnessFilter() {
			std::vector<std::vector<float>> tmp(3);
			for (int i = 0; i < tmp.size(); i++)
				tmp[i].resize(3);
			kernel = tmp;

			kernel[0][0] = 0;
			kernel[0][1] = -1;
			kernel[0][2] = 0;
			kernel[1][0] = -1;
			kernel[1][1] = 5;
			kernel[1][2] = -1;
			kernel[2][0] = 0;
			kernel[2][1] = -1;
			kernel[2][2] = 0;
				
	}
	};

	//  Идеальный отражатель
	class PergectReflectorFilter : public Filters {
	private:
		unsigned int maxR = 0;
		unsigned int maxG = 0;
		unsigned int maxB = 0;
	public:
		Color calculateNewPixelColor(Bitmap^ sourceImage, int x, int y) {
			Color sourceColor = sourceImage->GetPixel(x, y);
			Color resultColor = Color::FromArgb(sourceColor.R * (255 / maxR),
												sourceColor.G * (255 / maxG),
												sourceColor.B * (255 / maxB));
			return resultColor;
		}
		void MaxColor( Bitmap^ sourceImage) {
			for (int i = 0; i < sourceImage->Width; i++)
				for (int j = 0; j < sourceImage->Height; j++) {
					Color sourceColor = sourceImage->GetPixel(i, j);
					maxR = MAX(maxR, sourceColor.R);
					maxG = MAX(maxG, sourceColor.G);
					maxB = MAX(maxB, sourceColor.B);
				}
		}
		Bitmap^ processImage(Bitmap^ sourceImage, ProgressBar^ progress) {
			Bitmap^ resultImage = gcnew Bitmap(sourceImage->Width, sourceImage->Height);

			//  Ищем максмимум цвета
					MaxColor(sourceImage);
			
			for (int i = 0; i < sourceImage->Width; i++) {
				for (int j = 0; j < sourceImage->Height; j++) {
					resultImage->SetPixel(i, j, calculateNewPixelColor(sourceImage, i, j));
					progress->PerformStep();
				}
			}

			return resultImage;
		}
	};

	//  Серый мир
	class GrayWorldFilter : public Filters {
	private:
		float averageR = 0;
		float averageG = 0;
		float averageB = 0;
	public:
		Color AverageBrightness(Bitmap^ sourceImage) {
			for (int i = 0; i < sourceImage->Width; i++)
				for (int j = 0; j < sourceImage->Height; j++) {
					Color sourceColor = sourceImage->GetPixel(i, j);
					averageR += sourceColor.R;
					averageG += sourceColor.G;
					averageB += sourceColor.B;
				}
			averageR /= (sourceImage->Width * sourceImage->Height);
			averageG /= (sourceImage->Width * sourceImage->Height);
			averageB /= (sourceImage->Width * sourceImage->Height);
			Color resultColor = Color::FromArgb(averageR,
												averageG,
												averageB);
			return resultColor;
		}
		Color calculateNewPixelColor(Bitmap^ sourceImage, int x, int y) {
			float Avg = (averageR + averageG + averageB) / 3;
			Color sourceColor = sourceImage->GetPixel(x, y);
			Color resultColor = Color::FromArgb(Clamp(sourceColor.R * (Avg / averageR),0,255),
				Clamp(sourceColor.G * (Avg / averageG),0,255),
				Clamp(sourceColor.B * (Avg / averageB),0,255));
			return resultColor;
		}
		Bitmap^ processImage(Bitmap^ sourceImage, ProgressBar^ progress) {
			Bitmap^ resultImage = gcnew Bitmap(sourceImage->Width, sourceImage->Height);

			//  Ищем среднюю яркость
			AverageBrightness(sourceImage);

			for (int i = 0; i < sourceImage->Width; i++) {
				for (int j = 0; j < sourceImage->Height; j++) {
					resultImage->SetPixel(i, j, calculateNewPixelColor(sourceImage, i, j));
					progress->PerformStep();
				}
			}

			return resultImage;
		}
	};

	//  Перенос
	class TransferFilter : public Filters {
	public:
		Color calculateNewPixelColor(Bitmap^ sourceImage, int x, int y) {
			Color sourceColor = sourceImage->GetPixel(x, y);
			Color resultColor = Color::FromArgb(sourceColor.R,
				sourceColor.G,
				sourceColor.B);
			return resultColor;
		}
		Bitmap^ processImage(Bitmap^ sourceImage, ProgressBar^ progress) {
			int number_bit = (sourceImage->Width) / 5;
			Bitmap^ resultImage = gcnew Bitmap(sourceImage->Width, sourceImage->Height);
			for (int i = number_bit; i < sourceImage->Width; i++) {
				for (int j = 0; j < sourceImage->Height; j++) {
					resultImage->SetPixel(i - number_bit, j, calculateNewPixelColor(sourceImage, i, j));
					progress->PerformStep();
				}
			}
			for (int i = sourceImage->Width - number_bit; i < sourceImage->Width; i++) {
				for (int j = 0; j < sourceImage->Height; j++) {
					resultImage->SetPixel(i, j, Color::FromArgb(0, 0, 0));
				}
			}

			return resultImage;
		}

	};

	//  Эффект стекла
	class GlassFilter : public Filters {
	public:
		Color calculateNewPixelColor(Bitmap^ sourceImage, int x, int y) {
			Color sourceColor = sourceImage->GetPixel(x, y);
			Color resultColor = Color::FromArgb(sourceColor.R,
				sourceColor.G,
				sourceColor.B);
			return resultColor;
		}
		Bitmap^ processImage(Bitmap^ sourceImage, ProgressBar^ progress) {
			Bitmap^ resultImage = gcnew Bitmap(sourceImage->Width, sourceImage->Height);
			for (int i = 0; i < sourceImage->Width; i++) {
				for (int j = 0; j < sourceImage->Height; j++) {
					progress->PerformStep();
					int k = Clamp(static_cast<int>(i + (rand() % 2 - 0.5) * 10), 0, sourceImage->Width-1);
					int l = Clamp(static_cast<int>(j + (rand() % 2 - 0.5) * 10), 0, sourceImage->Height-1);
					resultImage->SetPixel(i ,j, calculateNewPixelColor(sourceImage, k, l));
				}
			}


			return resultImage;
		}
	};

	//  Линейное растяжение гистограммы
	class LinearCorrectionFilter : public Filters {
	private:
		unsigned int maxR = 0, minR = 255;
		unsigned int maxG = 0, minG = 255;
		unsigned int maxB = 0, minB = 255;
	public:
		void MaxColor(Bitmap^ sourceImage) {
			for (int i = 0; i < sourceImage->Width; i++)
				for (int j = 0; j < sourceImage->Height; j++) {
					Color sourceColor = sourceImage->GetPixel(i, j);
					maxR = MAX(maxR, sourceColor.R);
					maxG = MAX(maxG, sourceColor.G);
					maxB = MAX(maxB, sourceColor.B);
				}
		}
		void MinColor(Bitmap^ sourceImage) {
			for (int i = 0; i < sourceImage->Width; i++)
				for (int j = 0; j < sourceImage->Height; j++) {
					Color sourceColor = sourceImage->GetPixel(i, j);
					minR = MIN(minR, sourceColor.R);
					minG = MIN(minG, sourceColor.G);
					minB = MIN(minB, sourceColor.B);
				}
		}
		Color calculateNewPixelColor(Bitmap^ sourceImage, int x, int y) {
			Color sourceColor = sourceImage->GetPixel(x, y);
			Color resultColor = Color::FromArgb((sourceColor.R - minR) * 255 / (maxR -minR),
												(sourceColor.G - minG) * 255 / (maxG - minG),
												(sourceColor.B - minB) * 255 / (maxB - minB));
			return resultColor;
		}
		Bitmap^ processImage(Bitmap^ sourceImage, ProgressBar^ progress) {
			Bitmap^ resultImage = gcnew Bitmap(sourceImage->Width, sourceImage->Height);

			//  Ищем максмимум цвета
			MaxColor(sourceImage);

			// Ищем минимуму цвета
			MinColor(sourceImage);

			for (int i = 0; i < sourceImage->Width; i++) {
				for (int j = 0; j < sourceImage->Height; j++) {
					progress->PerformStep();
					resultImage->SetPixel(i, j, calculateNewPixelColor(sourceImage, i, j));
				}
			}

			return resultImage;
		}

	};

	//  Медианный фильтр
	class MedianFilter : public Filters {
	private:
		int radius = 2;
	public:
		Color calculateNewPixelColor(Bitmap^ sourceImage, int x, int y) {
			int n = (2 * radius + 1) * (2 * radius + 1);
			std::vector<int> cR(n + 1, 0);
			std::vector<int> cG(n + 1, 0);
			std::vector<int> cB(n + 1, 0);

			int k = 1;
			for (int i = x - radius; i < x + radius + 1; i++)
			{
				for (int j = y - radius; j < y + radius + 1; j++)
				{
					System::Drawing::Color c = sourceImage->GetPixel(i, j);
					cR[k] = c.R;
					cG[k] = c.G;
					cB[k] = c.B;
					k++;
					
				}
			}
			std::sort(begin(cR), end(cR) - 1);
			std::sort(begin(cG), end(cG) - 1);
			std::sort(begin(cB), end(cB) - 1);

			int n_ = static_cast<int>(n / 2) + 1;


			return Color::FromArgb(cR[n_], cG[n_], cB[n_]);
		}
		Bitmap^ processImage(Bitmap^ sourceImage, ProgressBar^ progressBar1) {
			Bitmap^ resultImage = gcnew Bitmap(sourceImage->Width, sourceImage->Height);
			for (int i = radius + 1; i < sourceImage->Width - radius; i++) {
				//worker->ReportProgress((int)((float)i / resultImage->Width * 100));
				for (int j = radius + 1; j < sourceImage->Height - radius; j++) {
					resultImage->SetPixel(i, j, calculateNewPixelColor(sourceImage, i, j));
					progressBar1->PerformStep();
				}
			}

			return resultImage;
		}
	};

	//  Выделение границ
	class BorderSelectionFilter : public MatrixFilter {
	public:
		void ScharrOperator(void) {
			std::vector<std::vector<float>> tmp(3);
			for (int i = 0; i < tmp.size(); i++)
				tmp[i].resize(3);
			kernel = tmp;

			kernel[0][0] = 3;
			kernel[0][1] = 10;
			kernel[0][2] = 3;
			kernel[1][0] = 0;
			kernel[1][1] = 0;
			kernel[1][2] = 0;
			kernel[2][0] = -3;
			kernel[2][1] = -10;
			kernel[2][2] = -3;
		}
		void PruittOperator(void) {

			std::vector<std::vector<float>> tmp(3);
			for (int i = 0; i < tmp.size(); i++)
				tmp[i].resize(3);
			kernel = tmp;

			kernel[0][0] = -1;
			kernel[0][1] = -1;
			kernel[0][2] = -1;
			kernel[1][0] = 0;
			kernel[1][1] = 0;
			kernel[1][2] = 0;
			kernel[2][0] = 1;
			kernel[2][1] = 1;
			kernel[2][2] = 1;
		}
		Bitmap^ processImage(Bitmap^ sourceImage, ProgressBar^ progressBar1) {
			
			Bitmap^ InterimImage = gcnew Bitmap(sourceImage->Width, sourceImage->Height);
			ScharrOperator();
			for (int i = 0; i < sourceImage->Width; i++) {
				for (int j = 0; j < sourceImage->Height; j++) {
					InterimImage->SetPixel(i, j, calculateNewPixelColor(sourceImage, i, j));
					progressBar1->PerformStep();
				}
			}

			PruittOperator();
			Bitmap^ resultImage = gcnew Bitmap(InterimImage->Width, InterimImage->Height);
			for (int i = 0; i < InterimImage->Width; i++) {
				for (int j = 0; j < InterimImage->Height; j++) {
					resultImage->SetPixel(i, j, calculateNewPixelColor(InterimImage, i, j));
					progressBar1->PerformStep();
				}
			}

			return resultImage;
		}

	};

	//  Максимум
	class MaximumFilter : public Filters {
	private:
		int radius = 2;
	public:
		Color calculateNewPixelColor(Bitmap^ sourceImage, int x, int y) {
			int n = (2 * radius + 1) * (2 * radius + 1);
			std::vector<int> cR(n + 1, 0);
			std::vector<int> cG(n + 1, 0);
			std::vector<int> cB(n + 1, 0);

			int k = 1;
			for (int i = x - radius; i < x + radius + 1; i++)
			{
				for (int j = y - radius; j < y + radius + 1; j++)
				{
					System::Drawing::Color c = sourceImage->GetPixel(i, j);
					cR[k] = c.R;
					cG[k] = c.G;
					cB[k] = c.B;
					k++;

				}
			}
			std::sort(begin(cR), end(cR) - 1);
			std::sort(begin(cG), end(cG) - 1);
			std::sort(begin(cB), end(cB) - 1);

			int n_ = cR.size() - 1;


			return Color::FromArgb(cR[n_], cG[n_], cB[n_]);
		}

		Bitmap^ processImage(Bitmap^ sourceImage, ProgressBar^ progressBar1) {
			Bitmap^ resultImage = gcnew Bitmap(sourceImage->Width, sourceImage->Height);
			for (int i = radius + 1; i < sourceImage->Width - radius; i++) {
				for (int j = radius + 1; j < sourceImage->Height - radius; j++) {
					resultImage->SetPixel(i, j, calculateNewPixelColor(sourceImage, i, j));
					progressBar1->PerformStep();
				}
			}

			return resultImage;
		}
	};

}
