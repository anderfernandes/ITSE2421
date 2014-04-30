#pragma once

#include "SimpleEncryption.h"

namespace VirtualEncryption {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace Runtime::InteropServices;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBoxInFile;
	protected: 
	private: System::Windows::Forms::TextBox^  textBoxOutFile;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  buttonEncrypt;
	private: System::Windows::Forms::TextBox^  textBoxKey;

	private: System::Windows::Forms::Label^  label3;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBoxInFile = (gcnew System::Windows::Forms::TextBox());
			this->textBoxOutFile = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buttonEncrypt = (gcnew System::Windows::Forms::Button());
			this->textBoxKey = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBoxInFile
			// 
			this->textBoxInFile->Location = System::Drawing::Point(98, 14);
			this->textBoxInFile->Name = L"textBoxInFile";
			this->textBoxInFile->Size = System::Drawing::Size(188, 20);
			this->textBoxInFile->TabIndex = 0;
			// 
			// textBoxOutFile
			// 
			this->textBoxOutFile->Location = System::Drawing::Point(98, 52);
			this->textBoxOutFile->Name = L"textBoxOutFile";
			this->textBoxOutFile->Size = System::Drawing::Size(188, 20);
			this->textBoxOutFile->TabIndex = 1;
			this->textBoxOutFile->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxOutFile_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Input File:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Output File:";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// buttonEncrypt
			// 
			this->buttonEncrypt->Location = System::Drawing::Point(123, 140);
			this->buttonEncrypt->Name = L"buttonEncrypt";
			this->buttonEncrypt->Size = System::Drawing::Size(75, 23);
			this->buttonEncrypt->TabIndex = 4;
			this->buttonEncrypt->Text = L"Encrypt";
			this->buttonEncrypt->UseVisualStyleBackColor = true;
			this->buttonEncrypt->Click += gcnew System::EventHandler(this, &Form1::buttonEncrypt_Click);
			// 
			// textBoxKey
			// 
			this->textBoxKey->Location = System::Drawing::Point(98, 92);
			this->textBoxKey->Name = L"textBoxKey";
			this->textBoxKey->Size = System::Drawing::Size(188, 20);
			this->textBoxKey->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 99);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(28, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Key:";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(323, 216);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBoxKey);
			this->Controls->Add(this->buttonEncrypt);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxOutFile);
			this->Controls->Add(this->textBoxInFile);
			this->Name = L"Form1";
			this->Text = L"Virtual Encryption";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void textBoxOutFile_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }


private: System::Void buttonEncrypt_Click(System::Object^  sender, System::EventArgs^  e) {

			 string strInFileName = static_cast<char*>(Marshal::StringToHGlobalAnsi(textBoxInFile->Text).ToPointer());
			 string strOutFileName = static_cast<char*>(Marshal::StringToHGlobalAnsi(textBoxOutFile->Text).ToPointer());
			 char *key = static_cast<char*>(Marshal::StringToHGlobalAnsi(textBoxKey->Text).ToPointer());

			 if (strInFileName.empty())
			 {
				 MessageBox::Show("Must provide an Input File Name. ", 
					 "Notification", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
				 return;
			 }
			 if (strOutFileName.empty())
			 {
				 MessageBox::Show("Must provide an Output File Name. ",
					 "Notification", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
				 return;
			 }

			 SimpleEncryption obfuscate(strInFileName, strOutFileName);
			 obfuscate.setKey(key[0]);
			 obfuscate.encrypt();
			 MessageBox::Show("Encryption Complete. ",
				 "Notification", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

			 
		 }
		  
};
}

