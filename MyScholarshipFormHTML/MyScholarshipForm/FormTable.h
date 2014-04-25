#pragma once

namespace MyScholarshipForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormTable
	/// </summary>
	public ref class FormTable : public System::Windows::Forms::Form
	{
	public:
		FormTable(void)
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
		~FormTable()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::WebBrowser^  webBrowserTable;
	protected: 

	protected: 

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
			this->webBrowserTable = (gcnew System::Windows::Forms::WebBrowser());
			this->SuspendLayout();
			// 
			// webBrowserTable
			// 
			this->webBrowserTable->Dock = System::Windows::Forms::DockStyle::Fill;
			this->webBrowserTable->Location = System::Drawing::Point(0, 0);
			this->webBrowserTable->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowserTable->Name = L"webBrowserTable";
			this->webBrowserTable->Size = System::Drawing::Size(605, 578);
			this->webBrowserTable->TabIndex = 0;
			// 
			// FormTable
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(605, 578);
			this->Controls->Add(this->webBrowserTable);
			this->Name = L"FormTable";
			this->Text = L"Scholarships Report";
			this->ResumeLayout(false);

			this->webBrowserTable->Navigate("file://C:/temp/ScholarshipsTable.html");

		}
#pragma endregion
	};
}
