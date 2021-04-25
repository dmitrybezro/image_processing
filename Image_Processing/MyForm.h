#pragma once
#include "Filters.h"
#include<Windows.h>
#include"MyForm1.h"

namespace ImageProcessing {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Filters_BPP;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	
	public ref class MyForm : public System::Windows::Forms::Form
	{

	public:
		int size_mask;
		float** mask_update;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::Label^ label1;
	public:


		   Bitmap^ image;
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::TabControl^ tabControl1;

	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ grayScaleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����������������ToolStripMenuItem;
	private: System::Windows::Forms::MenuStrip^ menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������ToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::ToolStripMenuItem^ dilationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ erosionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ closingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ topHatToolStripMenuItem;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->grayScaleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dilationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->erosionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->topHatToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->menuStrip2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->SuspendLayout();
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(12, 648);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(885, 23);
			this->progressBar1->TabIndex = 2;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(889, 630);
			this->tabControl1->TabIndex = 3;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->pictureBox1);
			this->tabPage1->Controls->Add(this->menuStrip1);
			this->tabPage1->Location = System::Drawing::Point(4, 29);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(881, 597);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"�������";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(6, 39);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(869, 552);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->����ToolStripMenuItem,
					this->������������ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(3, 3);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(875, 33);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->�������ToolStripMenuItem });
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(69, 29);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(184, 34);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�������ToolStripMenuItem_Click_1);
			// 
			// ������������ToolStripMenuItem
			// 
			this->������������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->��������ToolStripMenuItem,
					this->���������ToolStripMenuItem
			});
			this->������������ToolStripMenuItem->Name = L"������������ToolStripMenuItem";
			this->������������ToolStripMenuItem->Size = System::Drawing::Size(155, 29);
			this->������������ToolStripMenuItem->Text = L"���� ��������";
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {
				this->��������ToolStripMenuItem,
					this->grayScaleToolStripMenuItem, this->�����ToolStripMenuItem, this->�������ToolStripMenuItem, this->�������������������ToolStripMenuItem,
					this->��������ToolStripMenuItem, this->������������ToolStripMenuItem, this->�������ToolStripMenuItem, this->�����������������ToolStripMenuItem,
					this->���������������ToolStripMenuItem
			});
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(209, 34);
			this->��������ToolStripMenuItem->Text = L"��������";
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(305, 34);
			this->��������ToolStripMenuItem->Text = L"��������";
			this->��������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::��������ToolStripMenuItem_Click_1);
			// 
			// grayScaleToolStripMenuItem
			// 
			this->grayScaleToolStripMenuItem->Name = L"grayScaleToolStripMenuItem";
			this->grayScaleToolStripMenuItem->Size = System::Drawing::Size(305, 34);
			this->grayScaleToolStripMenuItem->Text = L"Gray Scale";
			this->grayScaleToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::grayScaleToolStripMenuItem_Click_1);
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(305, 34);
			this->�����ToolStripMenuItem->Text = L"�����";
			this->�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�����ToolStripMenuItem_Click_1);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(305, 34);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�������ToolStripMenuItem_Click_1);
			// 
			// �������������������ToolStripMenuItem
			// 
			this->�������������������ToolStripMenuItem->Name = L"�������������������ToolStripMenuItem";
			this->�������������������ToolStripMenuItem->Size = System::Drawing::Size(305, 34);
			this->�������������������ToolStripMenuItem->Text = L"��������� ����������";
			this->�������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�������������������ToolStripMenuItem_Click_1);
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(305, 34);
			this->��������ToolStripMenuItem->Text = L"����� ���";
			this->��������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::��������ToolStripMenuItem_Click_1);
			// 
			// ������������ToolStripMenuItem
			// 
			this->������������ToolStripMenuItem->Name = L"������������ToolStripMenuItem";
			this->������������ToolStripMenuItem->Size = System::Drawing::Size(305, 34);
			this->������������ToolStripMenuItem->Text = L"������ ������";
			this->������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::������������ToolStripMenuItem_Click_1);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(305, 34);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�������ToolStripMenuItem_Click_1);
			// 
			// �����������������ToolStripMenuItem
			// 
			this->�����������������ToolStripMenuItem->Name = L"�����������������ToolStripMenuItem";
			this->�����������������ToolStripMenuItem->Size = System::Drawing::Size(305, 34);
			this->�����������������ToolStripMenuItem->Text = L"�������� ���������";
			this->�����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�����������������ToolStripMenuItem_Click_1);
			// 
			// ���������������ToolStripMenuItem
			// 
			this->���������������ToolStripMenuItem->Name = L"���������������ToolStripMenuItem";
			this->���������������ToolStripMenuItem->Size = System::Drawing::Size(305, 34);
			this->���������������ToolStripMenuItem->Text = L"��������� ������";
			this->���������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::���������������ToolStripMenuItem_Click_1);
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->��������ToolStripMenuItem,
					this->������������ToolStripMenuItem, this->������������ToolStripMenuItem, this->��������ToolStripMenuItem, this->���������������ToolStripMenuItem,
					this->�����������������ToolStripMenuItem
			});
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(209, 34);
			this->���������ToolStripMenuItem->Text = L"���������";
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(287, 34);
			this->��������ToolStripMenuItem->Text = L"��������";
			this->��������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::��������ToolStripMenuItem_Click_1);
			// 
			// ������������ToolStripMenuItem
			// 
			this->������������ToolStripMenuItem->Name = L"������������ToolStripMenuItem";
			this->������������ToolStripMenuItem->Size = System::Drawing::Size(287, 34);
			this->������������ToolStripMenuItem->Text = L"������ ������";
			this->������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::������������ToolStripMenuItem_Click_1);
			// 
			// ������������ToolStripMenuItem
			// 
			this->������������ToolStripMenuItem->Name = L"������������ToolStripMenuItem";
			this->������������ToolStripMenuItem->Size = System::Drawing::Size(287, 34);
			this->������������ToolStripMenuItem->Text = L"������ ������";
			this->������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::������������ToolStripMenuItem_Click_1);
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(287, 34);
			this->��������ToolStripMenuItem->Text = L"��������";
			this->��������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::��������ToolStripMenuItem_Click_1);
			// 
			// ���������������ToolStripMenuItem
			// 
			this->���������������ToolStripMenuItem->Name = L"���������������ToolStripMenuItem";
			this->���������������ToolStripMenuItem->Size = System::Drawing::Size(287, 34);
			this->���������������ToolStripMenuItem->Text = L"��������� ������";
			this->���������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::���������������ToolStripMenuItem_Click_1);
			// 
			// �����������������ToolStripMenuItem
			// 
			this->�����������������ToolStripMenuItem->Name = L"�����������������ToolStripMenuItem";
			this->�����������������ToolStripMenuItem->Size = System::Drawing::Size(287, 34);
			this->�����������������ToolStripMenuItem->Text = L"���������� �������";
			this->�����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�����������������ToolStripMenuItem_Click_1);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->pictureBox2);
			this->tabPage2->Controls->Add(this->menuStrip2);
			this->tabPage2->Location = System::Drawing::Point(4, 29);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(881, 597);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"����������";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(0, 48);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(875, 543);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// menuStrip2
			// 
			this->menuStrip2->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip2->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->����ToolStripMenuItem1,
					this->��������ToolStripMenuItem
			});
			this->menuStrip2->Location = System::Drawing::Point(3, 3);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Size = System::Drawing::Size(875, 33);
			this->menuStrip2->TabIndex = 0;
			this->menuStrip2->Text = L"menuStrip2";
			// 
			// ����ToolStripMenuItem1
			// 
			this->����ToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->�������ToolStripMenuItem1 });
			this->����ToolStripMenuItem1->Name = L"����ToolStripMenuItem1";
			this->����ToolStripMenuItem1->Size = System::Drawing::Size(69, 29);
			this->����ToolStripMenuItem1->Text = L"����";
			// 
			// �������ToolStripMenuItem1
			// 
			this->�������ToolStripMenuItem1->Name = L"�������ToolStripMenuItem1";
			this->�������ToolStripMenuItem1->Size = System::Drawing::Size(184, 34);
			this->�������ToolStripMenuItem1->Text = L"�������";
			this->�������ToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::�������ToolStripMenuItem1_Click);
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->dilationToolStripMenuItem,
					this->erosionToolStripMenuItem, this->openingToolStripMenuItem, this->closingToolStripMenuItem, this->topHatToolStripMenuItem
			});
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(112, 29);
			this->��������ToolStripMenuItem->Text = L"��������";
			// 
			// dilationToolStripMenuItem
			// 
			this->dilationToolStripMenuItem->Name = L"dilationToolStripMenuItem";
			this->dilationToolStripMenuItem->Size = System::Drawing::Size(183, 34);
			this->dilationToolStripMenuItem->Text = L"Dilation";
			this->dilationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::dilationToolStripMenuItem_Click);
			// 
			// erosionToolStripMenuItem
			// 
			this->erosionToolStripMenuItem->Name = L"erosionToolStripMenuItem";
			this->erosionToolStripMenuItem->Size = System::Drawing::Size(183, 34);
			this->erosionToolStripMenuItem->Text = L"Erosion";
			this->erosionToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::erosionToolStripMenuItem_Click);
			// 
			// openingToolStripMenuItem
			// 
			this->openingToolStripMenuItem->Name = L"openingToolStripMenuItem";
			this->openingToolStripMenuItem->Size = System::Drawing::Size(183, 34);
			this->openingToolStripMenuItem->Text = L"Opening";
			this->openingToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openingToolStripMenuItem_Click);
			// 
			// closingToolStripMenuItem
			// 
			this->closingToolStripMenuItem->Name = L"closingToolStripMenuItem";
			this->closingToolStripMenuItem->Size = System::Drawing::Size(183, 34);
			this->closingToolStripMenuItem->Text = L"Closing";
			this->closingToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::closingToolStripMenuItem_Click);
			// 
			// topHatToolStripMenuItem
			// 
			this->topHatToolStripMenuItem->Name = L"topHatToolStripMenuItem";
			this->topHatToolStripMenuItem->Size = System::Drawing::Size(183, 34);
			this->topHatToolStripMenuItem->Text = L"Top Hat";
			this->topHatToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::topHatToolStripMenuItem_Click);
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->label1);
			this->tabPage3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tabPage3->Location = System::Drawing::Point(4, 29);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(881, 597);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"����������";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(39, 82);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(727, 198);
			this->label1->TabIndex = 0;
			this->label1->Text = resources->GetString(L"label1.Text");
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(909, 687);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->progressBar1);
			this->MainMenuStrip = this->menuStrip2;
			this->Name = L"MyForm";
			this->Text = L"��������� �����������";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
//  ������� �������
	private: System::Void �������ToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ dialog = (gcnew OpenFileDialog());
		dialog->Filter = "Image files|*.png;*.jpg;*.bpm|All files(*.*)|*.*";
		if (dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			image = gcnew Bitmap(dialog->FileName);
			pictureBox1->Image = image;
			pictureBox1->Refresh();
		}
	}

//  ��������
	private: System::Void ��������ToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
		progressBar1->Step = 1;
		progressBar1->Maximum = (image->Width * image->Height);
		InvertFilter filter = InvertFilter();
		Bitmap^ resultImage = filter.processImage(image, progressBar1);
		pictureBox1->Image = resultImage;
		pictureBox1->Refresh();
		progressBar1->Value = 0;
	}

//  ����� ������
	private: System::Void grayScaleToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
		progressBar1->Step = 1;
		progressBar1->Maximum = (image->Width * image->Height);
		GrayScaleFilter filter = GrayScaleFilter();
		Bitmap^ resultImage = filter.processImage(image, progressBar1);
		pictureBox1->Image = resultImage;
		pictureBox1->Refresh();
		progressBar1->Value = 0;


	}

//  �����
	private: System::Void �����ToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
		progressBar1->Step = 1;
		progressBar1->Maximum = (image->Width * image->Height);
		SepiaFilter filter = SepiaFilter();
		Bitmap^ resultImage = filter.processImage(image, progressBar1);
		pictureBox1->Image = resultImage;
		pictureBox1->Refresh();
		progressBar1->Value = 0;
	}

//  �������
	private: System::Void �������ToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
		progressBar1->Step = 1;
		progressBar1->Maximum = (image->Width * image->Height);
		BrightnessFilter filter = BrightnessFilter();
		Bitmap^ resultImage = filter.processImage(image, progressBar1);
		pictureBox1->Image = resultImage;
		pictureBox1->Refresh();
		progressBar1->Value = 0;

	}

//  ��������� ����������
	private: System::Void �������������������ToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
		progressBar1->Step = 1;
		progressBar1->Maximum = (image->Width * image->Height);
		PergectReflectorFilter filter = PergectReflectorFilter();
		Bitmap^ resultImage = filter.processImage(image, progressBar1);
		pictureBox1->Image = resultImage;
		pictureBox1->Refresh();
		progressBar1->Value = 0;

	}

//  ����� ���
	private: System::Void ��������ToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
		progressBar1->Step = 1;
		progressBar1->Maximum = (image->Width * image->Height);
		GrayWorldFilter filter = GrayWorldFilter();
		Bitmap^ resultImage = filter.processImage(image, progressBar1);
		pictureBox1->Image = resultImage;
		pictureBox1->Refresh();
		progressBar1->Value = 0;
	}

//  �������
	private: System::Void �������ToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
		progressBar1->Step = 1;
		progressBar1->Maximum = (image->Width * image->Height + 200);
		TransferFilter filter = TransferFilter();
		Bitmap^ resultImage = filter.processImage(image, progressBar1);
		pictureBox1->Image = resultImage;
		pictureBox1->Refresh();
		progressBar1->Value = 0;

	}

//  ������ ������
	private: System::Void ������������ToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
		progressBar1->Step = 1;
		progressBar1->Maximum = (image->Width * image->Height);
		GlassFilter filter = GlassFilter();
		Bitmap^ resultImage = filter.processImage(image, progressBar1);
		pictureBox1->Image = resultImage;
		pictureBox1->Refresh();
		progressBar1->Value = 0;
	}

//  �������� ���������� �����������
	private: System::Void �����������������ToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
		progressBar1->Step = 1;
		progressBar1->Maximum = (image->Width * image->Height);
		LinearCorrectionFilter filter = LinearCorrectionFilter();
		Bitmap^ resultImage = filter.processImage(image, progressBar1);
		pictureBox1->Image = resultImage;
		pictureBox1->Refresh();
		progressBar1->Value = 0;
	}

//  ��������� ������
	private: System::Void ���������������ToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
		progressBar1->Step = 1;
		progressBar1->Maximum = image->Width * image->Height;
		MedianFilter filter = MedianFilter();
		Bitmap^ resultImage = filter.processImage(image, progressBar1);
		pictureBox1->Image = resultImage;
		pictureBox1->Refresh();
		progressBar1->Value = 0;
	}

//  ��������
	private: System::Void ��������ToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
		progressBar1->Step = 1;
		progressBar1->Maximum = image->Width * image->Height;
		BlurFilter filter = BlurFilter();
		Bitmap^ resultImage = filter.processImage(image, progressBar1);
		pictureBox1->Image = resultImage;
		pictureBox1->Refresh();
		progressBar1->Value = 0;
	}

//  ������ ������
	private: System::Void ������������ToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
		progressBar1->Step = 1;
		progressBar1->Maximum = image->Width * image->Height;
		GaussianFilter filter = GaussianFilter();
		Bitmap^ resultImage = filter.processImage(image, progressBar1);
		pictureBox1->Image = resultImage;
		pictureBox1->Refresh();
		progressBar1->Value = 0;
	}

//  ������ ������
	private: System::Void ������������ToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
		progressBar1->Step = 1;
		progressBar1->Maximum = image->Width * image->Height;
		SobelFilter filter = SobelFilter();
		Bitmap^ resultImage = filter.processImage(image, progressBar1);
		pictureBox1->Image = resultImage;
		pictureBox1->Refresh();
		progressBar1->Value = 0;
	}

//  ��������
	private: System::Void ��������ToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
		progressBar1->Step = 1;
		progressBar1->Maximum = image->Width * image->Height;
		SharpnessFilter filter = SharpnessFilter();
		Bitmap^ resultImage = filter.processImage(image, progressBar1);
		pictureBox1->Image = resultImage;
		pictureBox1->Refresh();
		progressBar1->Value = 0;
	}

//  ��������� ������
	private: System::Void ���������������ToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
		progressBar1->Step = 1;
		progressBar1->Maximum = 2 * (image->Width * image->Height);
		BorderSelectionFilter filter = BorderSelectionFilter();
		Bitmap^ resultImage = filter.processImage(image, progressBar1);
		pictureBox1->Image = resultImage;
		pictureBox1->Refresh();
		progressBar1->Value = 0;
	}

//  ���������� �������
	private: System::Void �����������������ToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
		progressBar1->Step = 1;
		progressBar1->Maximum = 4 * (image->Width * image->Height);

		MedianFilter filter1 = MedianFilter();
		Bitmap^ Image1 = filter1.processImage(image, progressBar1);


		BorderSelectionFilter filter2 = BorderSelectionFilter();
		Bitmap^ Image2 = filter2.processImage(Image1, progressBar1);

		MaximumFilter filter3 = MaximumFilter();
		Bitmap^ resultImage = filter3.processImage(Image2, progressBar1);

		pictureBox1->Image = resultImage;
		pictureBox1->Refresh();
		progressBar1->Value = 0;
	}

//  ������� ����������
	private: System::Void �������ToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ dialog = (gcnew OpenFileDialog());
		dialog->Filter = "Image files|*.png;*.jpg;*.bpm|All files(*.*)|*.*";
		if (dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			image = gcnew Bitmap(dialog->FileName);
			pictureBox2->Image = image;
			pictureBox2->Refresh();
		}
	}

//  ���������� - Dilation
	private: Bitmap^ dilation(Bitmap^ sourceImage, std::vector<std::vector<float>> mask) {
		Bitmap^ resultImage = gcnew Bitmap(sourceImage->Width, sourceImage->Height);
		
		int MW = mask.size();
		int MH = mask[0].size();
		int H = sourceImage->Height;
		int W = sourceImage->Width;
		
		for (int y = MH / 2; y < H - MH / 2; y++)
			for (int x = MW / 2; x < W - MW / 2; x++) {
				int max = 0;
				for (int j = -MH / 2; j <= MH / 2; j++)
					for (int i = -MW / 2; i <= MW / 2; i++) {
						if ((mask[i + MW / 2][j + MH / 2] == 1) && (((sourceImage->GetPixel(x + i, y + j)).R > max)))
							max = sourceImage->GetPixel(x + i, y + j).R;
						progressBar1->PerformStep();
					}
				resultImage->SetPixel(x, y, Color::FromArgb(255, max, max, max));
			}
		return resultImage;
	}
	private: System::Void dilationToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		progressBar1->Step = 1;
		progressBar1->Maximum =9 *( image->Width * image->Height);
		

		std::vector<std::vector<float>> mask;
		MyForm1^ f1 = gcnew MyForm1();

		if (f1->ShowDialog(this) == System::Windows::Forms::DialogResult::Yes) {
			mask_update = f1->m;
			size_mask = f1->size;

			mask.resize(size_mask);
			for (int i = 0; i < mask.size(); i++)
				mask[i].resize(size_mask);
			for (int i = 0; i < size_mask; i++) {
				for (int j = 0; j < size_mask; j++) {
					mask[i][j] = mask_update[i][j];
				}
			}
		}
		else {
			mask.resize(3);
			for (int i = 0; i < mask.size(); i++)
				mask[i].resize(3);
			mask[0][0] = 0; mask[0][1] = 1; mask[0][2] = 0;
			mask[1][0] = 1; mask[1][1] = 1; mask[1][2] = 1;
			mask[2][0] = 0; mask[2][1] = 1; mask[2][2] = 0;
		}




		Bitmap^ resultImage = dilation(image, mask);

		pictureBox2->Image = resultImage;
		pictureBox2->Refresh();
		progressBar1->Value = 0;
	
	}

//  ������� - Erosion
	private: Bitmap^ erosion(Bitmap^ sourceImage, std::vector<std::vector<float>> mask) {
		Bitmap^ resultImage = gcnew Bitmap(sourceImage->Width, sourceImage->Height);

		int MW = mask.size();
		int MH = mask[1].size();

		int H = sourceImage->Height;
		int W = sourceImage->Width;

		for (int y = MH / 2; y < H - MH / 2 ; y++) {
			for (int x = MW / 2; x < W - MW / 2 ; x++) {
				int min = 255;
				for (int j = -MH / 2; j <= MH / 2; j++) {
					for (int i = -MW / 2; i <= MW / 2; i++) {
						if ((mask[i + MW / 2][j + MH / 2] == 1) && (((sourceImage->GetPixel(x + i, y + j)).R < min)))
							min = sourceImage->GetPixel(x + i, y + j).R;
						progressBar1->PerformStep();
					}
				}
				resultImage->SetPixel(x, y, Color::FromArgb(255, min, min, min));
			}
		}
		return resultImage;
	}
	private: System::Void erosionToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		progressBar1->Step = 1;
		progressBar1->Maximum = 9 * (image->Width * image->Height);
		Bitmap^ resultImage = gcnew Bitmap(image->Width, image->Height);

		std::vector<std::vector<float>> mask;
		MyForm1^ f1 = gcnew MyForm1();

		if (f1->ShowDialog(this) == System::Windows::Forms::DialogResult::Yes) {
			mask_update = f1->m;
			size_mask = f1->size;

			mask.resize(size_mask);
			for (int i = 0; i < mask.size(); i++)
				mask[i].resize(size_mask);
			for (int i = 0; i < size_mask; i++) {
				for (int j = 0; j < size_mask; j++) {
					mask[i][j] = mask_update[i][j];
				}
			}
		}
		else {
			mask.resize(3);
			for (int i = 0; i < mask.size(); i++)
				mask[i].resize(3);
			mask[0][0] = 1; mask[0][1] = 1; mask[0][2] = 1;
			mask[1][0] = 1; mask[1][1] = 1; mask[1][2] = 1;
			mask[2][0] = 1; mask[2][1] = 1; mask[2][2] = 1;
		}

		resultImage = erosion(image, mask);

		pictureBox2->Image = resultImage;
		pictureBox2->Refresh();
		progressBar1->Value = 0;
	}	

//  �������� - Opining
	private: Bitmap^ opening(Bitmap^ sourceImage, const std::vector<std::vector<float>>& mask) {
		Bitmap^ InterimImage = gcnew Bitmap(sourceImage->Width, sourceImage->Height);
		//  �������
		InterimImage = erosion(sourceImage, mask);

		//  ���������� � ����������
		Bitmap^ resultImage = gcnew Bitmap(InterimImage->Width, InterimImage->Height);
		resultImage = dilation(InterimImage, mask);
		return resultImage;

	}
	private: System::Void openingToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		progressBar1->Step = 1;
		progressBar1->Maximum = 18 * (image->Width * image->Height);


		std::vector<std::vector<float>> mask;
		MyForm1^ f1 = gcnew MyForm1();

		if (f1->ShowDialog(this) == System::Windows::Forms::DialogResult::Yes) {
			mask_update = f1->m;
			size_mask = f1->size;

			mask.resize(size_mask);
			for (int i = 0; i < mask.size(); i++)
				mask[i].resize(size_mask);
			for (int i = 0; i < size_mask; i++) {
				for (int j = 0; j < size_mask; j++) {
					mask[i][j] = mask_update[i][j];
				}
			}
		}
		else {
			mask.resize(3);
			for (int i = 0; i < mask.size(); i++)
				mask[i].resize(3);
			mask[0][0] = 1; mask[0][1] = 1; mask[0][2] = 1;
			mask[1][0] = 1; mask[1][1] = 1; mask[1][2] = 1;
			mask[2][0] = 1; mask[2][1] = 1; mask[2][2] = 1;
		}


		Bitmap^ resultImage = opening(image, mask);


		//  �������� ���������
		pictureBox2->Image = resultImage;
		pictureBox2->Refresh();
		progressBar1->Value = 0;
	}

//  �������� - Closing
	private: Bitmap^ closing(Bitmap^ sourceImage, const std::vector<std::vector<float>>& mask) {
		Bitmap^ InterimImage = gcnew Bitmap(sourceImage->Width, sourceImage->Height);

		//  ����������
		InterimImage = dilation(sourceImage, mask);

		//  ������� � ����������
		Bitmap^ resultImage = gcnew Bitmap(InterimImage->Width, InterimImage->Height);
		resultImage = erosion(InterimImage, mask);

		return resultImage;

	}
	private: System::Void closingToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		//  ��� ���������� �������� �����������, ����� ����� ��������;
		progressBar1->Step = 1;
		progressBar1->Maximum = 18 * (image->Width * image->Height);
		Bitmap^ InterimImage = gcnew Bitmap(image->Width, image->Height);

		std::vector<std::vector<float>> mask;
		MyForm1^ f1 = gcnew MyForm1();

		if (f1->ShowDialog(this) == System::Windows::Forms::DialogResult::Yes) {
			mask_update = f1->m;
			size_mask = f1->size;

			mask.resize(size_mask);
			for (int i = 0; i < mask.size(); i++)
				mask[i].resize(size_mask);
			for (int i = 0; i < size_mask; i++) {
				for (int j = 0; j < size_mask; j++) {
					mask[i][j] = mask_update[i][j];
				}
			}
		}
		else {
			mask.resize(3);
			for (int i = 0; i < mask.size(); i++)
				mask[i].resize(3);
			mask[0][0] = 0; mask[0][1] = 1; mask[0][2] = 0;
			mask[1][0] = 1; mask[1][1] = 1; mask[1][2] = 1;
			mask[2][0] = 0; mask[2][1] = 1; mask[2][2] = 0;
		}

		Bitmap^ resultImage = closing(image, mask);


		//  �������� ���������
		pictureBox2->Image = resultImage;
		pictureBox2->Refresh();
		progressBar1->Value = 0;
	}

//  Top Hat
	private: Bitmap^ TopHat(Bitmap^ sourceImage, const std::vector<std::vector<float>>& mask) {
		Bitmap^ InterimImage = closing(sourceImage, mask);

		std::vector<std::vector<float>> image_in_vector(sourceImage->Width);
		for (int i = 0; i < image_in_vector.size(); i++)
			image_in_vector[i].resize(sourceImage->Height);

		for (int i = 0; i < image_in_vector.size(); i++)
			for (int j = 0; j < image_in_vector[i].size(); j++) {
				Color col = InterimImage->GetPixel(i, j);
				if (col.R  == 0)
					image_in_vector[i][j] = 0;
				else
					image_in_vector[i][j] = 1;
			}
		Bitmap^ resultImage = erosion(sourceImage, image_in_vector);
		return resultImage;
	}
	private: System::Void topHatToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
		progressBar1->Step = 1;
		progressBar1->Maximum = 29 * (image->Width * image->Height);

		Bitmap^ resultImage = gcnew Bitmap(image->Width, image->Height);

		std::vector<std::vector<float>> mask;
		MyForm1^ f1 = gcnew MyForm1();

		if (f1->ShowDialog(this) == System::Windows::Forms::DialogResult::Yes) {
			mask_update = f1->m;
			size_mask = f1->size;

			mask.resize(size_mask);
			for (int i = 0; i < mask.size(); i++)
				mask[i].resize(size_mask);
			for (int i = 0; i < size_mask; i++) {
				for (int j = 0; j < size_mask; j++) {
					mask[i][j] = mask_update[i][j];
				}
			}
		}
		else {
			mask.resize(3);
			for (int i = 0; i < mask.size(); i++)
				mask[i].resize(3);
			mask[0][0] = 0; mask[0][1] = 1; mask[0][2] = 0;
			mask[1][0] = 1; mask[1][1] = 1; mask[1][2] = 1;
			mask[2][0] = 0; mask[2][1] = 1; mask[2][2] = 0;
		}

		resultImage = TopHat(image, mask);

		pictureBox2->Image = resultImage;
		pictureBox2->Refresh();
		progressBar1->Value = 0;
	}
};
}
	