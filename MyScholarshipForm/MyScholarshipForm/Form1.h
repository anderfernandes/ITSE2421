#pragma once
#include "scholarshipClassDeclared.h"
#include "scholarships.h"


namespace MyScholarshipForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			s = new vector<Scholarship>; // since we used a pointer,
									     // must be initialized in form constructor
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
			delete s;
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  textBoxID;
	private: System::Windows::Forms::TextBox^  textBoxAmount;
	private: System::Windows::Forms::TextBox^  textBoxType;
	private: System::Windows::Forms::TextBox^  textBoxLength;
	private: System::Windows::Forms::TextBox^  textBoxStarts;
	private: System::Windows::Forms::TextBox^  textBoxFirstName;

	private: System::Windows::Forms::TextBox^  textBoxLastName;
	private: System::Windows::Forms::Button^  buttonPrevious;
	private: System::Windows::Forms::Button^  buttonNext;








	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Button^  buttonFirstRecord;
	private: System::Windows::Forms::Button^  buttonLastRecord;
			 vector<Scholarship> *s;    // This array of objects is initialized using 

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBoxID = (gcnew System::Windows::Forms::TextBox());
			this->textBoxAmount = (gcnew System::Windows::Forms::TextBox());
			this->textBoxType = (gcnew System::Windows::Forms::TextBox());
			this->textBoxLength = (gcnew System::Windows::Forms::TextBox());
			this->textBoxStarts = (gcnew System::Windows::Forms::TextBox());
			this->textBoxFirstName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxLastName = (gcnew System::Windows::Forms::TextBox());
			this->buttonPrevious = (gcnew System::Windows::Forms::Button());
			this->buttonNext = (gcnew System::Windows::Forms::Button());
			this->buttonFirstRecord = (gcnew System::Windows::Forms::Button());
			this->buttonLastRecord = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(17, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(401, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Cow Town College Scholarship Records";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(18, 94);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(26, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"ID";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(18, 138);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 20);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Amount";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(18, 182);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 20);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Type";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(18, 226);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(59, 20);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Length";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(18, 270);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(52, 20);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Starts";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(18, 314);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(86, 20);
			this->label7->TabIndex = 6;
			this->label7->Text = L"First Name";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(18, 358);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(86, 20);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Last Name";
			// 
			// textBoxID
			// 
			this->textBoxID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBoxID->Location = System::Drawing::Point(117, 94);
			this->textBoxID->Name = L"textBoxID";
			this->textBoxID->Size = System::Drawing::Size(309, 26);
			this->textBoxID->TabIndex = 8;
			// 
			// textBoxAmount
			// 
			this->textBoxAmount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBoxAmount->Location = System::Drawing::Point(117, 137);
			this->textBoxAmount->Name = L"textBoxAmount";
			this->textBoxAmount->Size = System::Drawing::Size(309, 26);
			this->textBoxAmount->TabIndex = 9;
			// 
			// textBoxType
			// 
			this->textBoxType->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBoxType->Location = System::Drawing::Point(117, 180);
			this->textBoxType->Name = L"textBoxType";
			this->textBoxType->Size = System::Drawing::Size(309, 26);
			this->textBoxType->TabIndex = 10;
			// 
			// textBoxLength
			// 
			this->textBoxLength->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBoxLength->Location = System::Drawing::Point(117, 223);
			this->textBoxLength->Name = L"textBoxLength";
			this->textBoxLength->Size = System::Drawing::Size(309, 26);
			this->textBoxLength->TabIndex = 11;
			// 
			// textBoxStarts
			// 
			this->textBoxStarts->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBoxStarts->Location = System::Drawing::Point(117, 266);
			this->textBoxStarts->Name = L"textBoxStarts";
			this->textBoxStarts->Size = System::Drawing::Size(309, 26);
			this->textBoxStarts->TabIndex = 12;
			// 
			// textBoxFirstName
			// 
			this->textBoxFirstName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBoxFirstName->Location = System::Drawing::Point(117, 309);
			this->textBoxFirstName->Name = L"textBoxFirstName";
			this->textBoxFirstName->Size = System::Drawing::Size(309, 26);
			this->textBoxFirstName->TabIndex = 13;
			// 
			// textBoxLastName
			// 
			this->textBoxLastName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBoxLastName->Location = System::Drawing::Point(117, 352);
			this->textBoxLastName->Name = L"textBoxLastName";
			this->textBoxLastName->Size = System::Drawing::Size(309, 26);
			this->textBoxLastName->TabIndex = 14;
			// 
			// buttonPrevious
			// 
			this->buttonPrevious->Location = System::Drawing::Point(143, 418);
			this->buttonPrevious->Name = L"buttonPrevious";
			this->buttonPrevious->Size = System::Drawing::Size(75, 23);
			this->buttonPrevious->TabIndex = 15;
			this->buttonPrevious->Text = L"< Previous";
			this->buttonPrevious->UseVisualStyleBackColor = true;
			this->buttonPrevious->Click += gcnew System::EventHandler(this, &Form1::buttonPrevious_Click);
			// 
			// buttonNext
			// 
			this->buttonNext->Location = System::Drawing::Point(235, 418);
			this->buttonNext->Name = L"buttonNext";
			this->buttonNext->Size = System::Drawing::Size(75, 23);
			this->buttonNext->TabIndex = 16;
			this->buttonNext->Text = L"Next >";
			this->buttonNext->UseVisualStyleBackColor = true;
			this->buttonNext->Click += gcnew System::EventHandler(this, &Form1::buttonNext_Click);
			// 
			// buttonFirstRecord
			// 
			this->buttonFirstRecord->Location = System::Drawing::Point(23, 418);
			this->buttonFirstRecord->Name = L"buttonFirstRecord";
			this->buttonFirstRecord->Size = System::Drawing::Size(108, 23);
			this->buttonFirstRecord->TabIndex = 17;
			this->buttonFirstRecord->Text = L"Go To 1st Record";
			this->buttonFirstRecord->UseVisualStyleBackColor = true;
			this->buttonFirstRecord->Click += gcnew System::EventHandler(this, &Form1::buttonFirstRecord_Click);
			// 
			// buttonLastRecord
			// 
			this->buttonLastRecord->Location = System::Drawing::Point(326, 417);
			this->buttonLastRecord->Name = L"buttonLastRecord";
			this->buttonLastRecord->Size = System::Drawing::Size(109, 23);
			this->buttonLastRecord->TabIndex = 18;
			this->buttonLastRecord->Text = L"Go To Last Record";
			this->buttonLastRecord->UseVisualStyleBackColor = true;
			this->buttonLastRecord->Click += gcnew System::EventHandler(this, &Form1::buttonLastRecord_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(465, 471);
			this->Controls->Add(this->buttonLastRecord);
			this->Controls->Add(this->buttonFirstRecord);
			this->Controls->Add(this->buttonNext);
			this->Controls->Add(this->buttonPrevious);
			this->Controls->Add(this->textBoxLastName);
			this->Controls->Add(this->textBoxFirstName);
			this->Controls->Add(this->textBoxStarts);
			this->Controls->Add(this->textBoxLength);
			this->Controls->Add(this->textBoxType);
			this->Controls->Add(this->textBoxAmount);
			this->Controls->Add(this->textBoxID);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"Scholarships";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

			string sFileLine;				 // a string to read in each line of the file
			vector<string> sParsedLine;      // array to hold the parsed line from file
			
			
			// Open input and output files and test to make sure they openned correctly
			ifstream fin;
			ofstream fout;
			OpenFiles(fin, fout);

			while(!fin.eof())
				// Read a line from the file and push onto end ofscholars object array
				(*s).push_back(readFile(sFileLine, sParsedLine, fin));

			fillFormFields(0);
		}

		void fillFormFields(int p)
		{
			static int i = 0;  // Keeps track of which record we are on
			i += p;		       // changes the current record
			

			if(i < 0) // Is the index within bounds
			{
				i = 0; // reset to beginning of array
				MessageBox::Show("Cannot go past beginning of array. Showing first record ",
					"Notification", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			}
			if(i > int((*s).size()-1)) // Is the index within bounds
			{
				i = int((*s).size()-1); // reset to end of array
				MessageBox::Show("Cannot go past end of array. Showing last record ",
					"Notification", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			}
			
			textBoxAmount->Text = gcnew String((*s)[i].getAmount().ToString());
			textBoxID->Text = gcnew String((*s)[i].getID().c_str());
			textBoxType->Text = gcnew String((*s)[i].getType().c_str());
			textBoxLength->Text = gcnew String((*s)[i].getLength().c_str());
			textBoxStarts->Text = gcnew String((*s)[i].getDate().c_str());
			textBoxLastName->Text = gcnew String((*s)[i].getLname().c_str());
			textBoxFirstName->Text = gcnew String((*s)[i].getFname().c_str());
		}

private: System::Void buttonPrevious_Click(System::Object^  sender, System::EventArgs^  e) {

			fillFormFields(-1);

		 }


		 
private: System::Void buttonNext_Click(System::Object^  sender, System::EventArgs^  e) {

			 fillFormFields(1);

		 }
private: System::Void buttonLastRecord_Click(System::Object^  sender, System::EventArgs^  e) {
		 
			 fillFormFields((*s).size());
		 }
private: System::Void buttonFirstRecord_Click(System::Object^  sender, System::EventArgs^  e) {
		 
			fillFormFields(-(*s).size());
		 }
};
}

