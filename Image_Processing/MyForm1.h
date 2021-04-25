#pragma once
#include "Filters.h"
namespace ImageProcessing {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Сводка для MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	private: 		

	public:
		float** m;
		int size;
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;




	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::TextBox^ textBox10;


	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::TextBox^ textBox14;
	private: System::Windows::Forms::TextBox^ textBox15;







	private: System::Windows::Forms::Button^ button2;





	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(257, 108);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(245, 20);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Введите структурный элемент";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(241, 177);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(74, 26);
			this->textBox1->TabIndex = 8;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(341, 177);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(74, 26);
			this->textBox2->TabIndex = 9;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(441, 177);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(74, 26);
			this->textBox3->TabIndex = 10;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(441, 242);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(74, 26);
			this->textBox8->TabIndex = 15;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(341, 242);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(74, 26);
			this->textBox9->TabIndex = 14;
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(241, 242);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(74, 26);
			this->textBox10->TabIndex = 13;
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(441, 307);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(74, 26);
			this->textBox13->TabIndex = 20;
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(341, 307);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(74, 26);
			this->textBox14->TabIndex = 19;
			// 
			// textBox15
			// 
			this->textBox15->Location = System::Drawing::Point(241, 307);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(74, 26);
			this->textBox15->TabIndex = 18;
			// 
			// button2
			// 
			this->button2->DialogResult = System::Windows::Forms::DialogResult::Yes;
			this->button2->Location = System::Drawing::Point(316, 400);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(112, 39);
			this->button2->TabIndex = 29;
			this->button2->Text = L"Установить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm1::button2_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(775, 523);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox13);
			this->Controls->Add(this->textBox14);
			this->Controls->Add(this->textBox15);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm1";
			this->Text = L"Структурный элемент";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: 


//  Установить
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	size = 3;
	m = new float* [size];
	for (int i = 0; i < size; i++)
		m[i] = new float[size];

		m[0][0] = (int(Convert::ToInt32(textBox1->Text)));
		m[0][1] = (int(Convert::ToInt32(textBox2->Text)));
		m[0][2] = (int(Convert::ToInt32(textBox3->Text)));
		m[1][0] = (int(Convert::ToInt32(textBox10->Text)));
		m[1][1] = (int(Convert::ToInt32(textBox9->Text)));
		m[1][2] = (int(Convert::ToInt32(textBox8->Text)));
		m[2][0] = (int(Convert::ToInt32(textBox15->Text)));
		m[2][1] = (int(Convert::ToInt32(textBox14->Text)));
		m[2][2] = (int(Convert::ToInt32(textBox13->Text)));
	
	Close();
}
};
}
