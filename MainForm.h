#pragma once
#include <string>
#include "Database.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include "Render.h"

namespace OpenCVTesseract {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;





	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ marketName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ReceiptNo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ totalPrice;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ kdv;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ products;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ date;






	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->marketName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ReceiptNo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->totalPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->kdv = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->products = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(742, 96);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(159, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox1_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::Gainsboro;
			this->textBox3->Location = System::Drawing::Point(321, 50);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox3->Size = System::Drawing::Size(305, 280);
			this->textBox3->TabIndex = 4;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox3_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label1->Location = System::Drawing::Point(653, 103);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Market name :";
			this->label1->Click += gcnew System::EventHandler(this, &MainForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label2->Location = System::Drawing::Point(726, 27);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 18);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Search";
			this->label2->Click += gcnew System::EventHandler(this, &MainForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label3->Location = System::Drawing::Point(655, 127);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(86, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Date            :";
			this->label3->Click += gcnew System::EventHandler(this, &MainForm::label3_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->marketName,
					this->ReceiptNo, this->totalPrice, this->kdv, this->products, this->date
			});
			this->dataGridView1->Location = System::Drawing::Point(9, 340);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(895, 110);
			this->dataGridView1->TabIndex = 8;
			// 
			// marketName
			// 
			this->marketName->FillWeight = 250;
			this->marketName->HeaderText = L"Market Name";
			this->marketName->MinimumWidth = 6;
			this->marketName->Name = L"marketName";
			this->marketName->ReadOnly = true;
			this->marketName->Width = 250;
			// 
			// ReceiptNo
			// 
			this->ReceiptNo->HeaderText = L"Receipt No";
			this->ReceiptNo->Name = L"ReceiptNo";
			// 
			// totalPrice
			// 
			this->totalPrice->HeaderText = L"Total Price";
			this->totalPrice->MinimumWidth = 6;
			this->totalPrice->Name = L"totalPrice";
			this->totalPrice->ReadOnly = true;
			this->totalPrice->Width = 125;
			// 
			// kdv
			// 
			this->kdv->HeaderText = L"KDV";
			this->kdv->MinimumWidth = 6;
			this->kdv->Name = L"kdv";
			this->kdv->ReadOnly = true;
			this->kdv->Width = 125;
			// 
			// products
			// 
			this->products->FillWeight = 250;
			this->products->HeaderText = L"Products";
			this->products->MinimumWidth = 6;
			this->products->Name = L"products";
			this->products->ReadOnly = true;
			this->products->Width = 250;
			// 
			// date
			// 
			this->date->FillWeight = 150;
			this->date->HeaderText = L"Date";
			this->date->MinimumWidth = 6;
			this->date->Name = L"date";
			this->date->ReadOnly = true;
			this->date->Width = 150;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->button1->Location = System::Drawing::Point(9, 17);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(617, 29);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Select image";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(9, 50);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(293, 280);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 10;
			this->pictureBox1->TabStop = false;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(744, 121);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(159, 20);
			this->dateTimePicker1->TabIndex = 11;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &MainForm::dateTimePicker1_ValueChanged);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->ClientSize = System::Drawing::Size(913, 461);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	private:
		System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {

		}
		System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			for each (DataGridViewRow^ row in dataGridView1->Rows)
			{
				if (row->Cells["marketName"]->Value != nullptr) {
					if(row->Cells["marketName"]->Value->ToString()->Contains(textBox1->Text->ToUpper())) row->Visible = true;
					else row->Visible = false;
				}
			}
		}
		System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		}
		System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

			openFileDialog1->InitialDirectory = "c:\\";
			openFileDialog1->Filter = "Image Files (*.jpg,*.png,*.jpeg)|*.jpg;*.png;*.jpeg;*.tiff|All files (*.*)|*.*";
			openFileDialog1->FilterIndex = 1;
			openFileDialog1->RestoreDirectory = true;

			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				const char* FileName = (const char*)(Runtime::InteropServices::Marshal::StringToHGlobalAnsi(openFileDialog1->FileName)).ToPointer();
				pictureBox1->Image = Image::FromFile(openFileDialog1->FileName);
				std::string ImageName = FileName;
				cv::Mat image = cv::imread(ImageName);
				cv::Mat CopyImage = image;
				cv::Mat gray, Copygray;
				cv::resize(CopyImage, CopyImage, cv::Size(360, 480));

				cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
				cv::cvtColor(CopyImage, Copygray, cv::COLOR_BGR2GRAY);

				cv::threshold(gray, gray, 100, 255, cv::THRESH_BINARY);
				cv::threshold(Copygray, Copygray, 100, 255, cv::THRESH_BINARY);

				cv::adaptiveThreshold(gray, gray, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 31, 2);
				cv::adaptiveThreshold(Copygray, Copygray, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 31, 2);

				cv::imshow("image", CopyImage);
				cv::imshow("gray", Copygray);

				// Pass it to Tesseract API
				tesseract::TessBaseAPI* api = new tesseract::TessBaseAPI();
				api->Init("./tessdata", "turfast", tesseract::OEM_DEFAULT);
				api->SetPageSegMode(tesseract::PSM_SINGLE_BLOCK);
				api->SetImage((uchar*)gray.data, gray.cols, gray.rows, 1, gray.cols);

				// Get the text
				char* out = api->GetUTF8Text();
				System::String^ clistr = gcnew System::String(out, 0, 999, System::Text::Encoding::UTF8);
				System::String^ textBoxString = (System::String^)clistr->Clone();
				textBoxString = textBoxString->Replace("\n", Environment::NewLine);
				textBox3->Text = textBoxString;
				AddReceipt(Render::FindName(clistr)->ToUpper(), Render::FindReceiptNo(clistr), Render::FindPrice(clistr), Render::FindKDV(clistr), 
					Render::FindProducts(clistr), Render::FindDate(clistr));
				/*MessageBox::Show(Render::FindReceiptNo(clistr).ToString());
				MessageBox::Show(Render::FindKDV(clistr).ToString());
				MessageBox::Show(Render::FindPrice(clistr).ToString());
				MessageBox::Show(Render::FindDate(clistr));
				MessageBox::Show(Render::FindName(clistr));*/
			}
		}
		System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
			Database^ db = gcnew Database();
			auto Receipts = db->getAllReceipts();
			for each (auto Receipt in Receipts)
			{
				dataGridView1->Rows->Add(Receipt->MarketName, Receipt->ReceiptNO, Receipt->TotalPrice, Receipt->KDV, Receipt->Products, Receipt->Date);
			}
		}
		System::Void dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
			for each (DataGridViewRow ^ row in dataGridView1->Rows)
			{
				if (row->Cells["date"]->Value != nullptr) {
					if (row->Cells["date"]->Value->ToString() == dateTimePicker1->Value.ToString("yyyy-MM-dd")) row->Visible = true;
					else row->Visible = false;
				}
			}
		}
		System::Void AddReceipt(String^ marketName, int receiptNo, double total, double kdv, String^ productions, String^ date) {
			DateTime^ dt = gcnew DateTime();
			auto dates = date->Split('-');
			MessageBox::Show(date);
			int year, month, day;
			try {
				Int32::TryParse(dates[2], year);
				Int32::TryParse(dates[1], month);
				Int32::TryParse(dates[0], day);
				date = "" + year + "-" + month + "-" + day;
			}
			catch(Exception^ Ex) {

			}
			Database^ db = gcnew Database();
			db->addMarket(marketName);
			int marketID = db->GetMarketID(marketName);
			db->AddReceipt(marketID, receiptNo, total, kdv, productions, date);
			dataGridView1->Rows->Insert(0, marketName, receiptNo, total, kdv, productions, date);
		}
	};
};