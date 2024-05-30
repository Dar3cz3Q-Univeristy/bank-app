#pragma once

namespace AGHBank {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for CreateContractor
	/// </summary>
	public ref class CreateContractor : public System::Windows::Forms::Form
	{
	public:
		int loggedUserID;
		CreateContractor(int id)
		{
			loggedUserID = id;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CreateContractor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ customNameLb;
	private: System::Windows::Forms::TextBox^ customNameInput;
	private: System::Windows::Forms::Label^ accountNumberLb;
	private: System::Windows::Forms::TextBox^ accountNumberInput;
	private: System::Windows::Forms::Button^ addContractorBtn;
	private: System::Windows::Forms::Label^ errorLb;




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
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->accountNumberLb = (gcnew System::Windows::Forms::Label());
			this->customNameLb = (gcnew System::Windows::Forms::Label());
			this->customNameInput = (gcnew System::Windows::Forms::TextBox());
			this->accountNumberInput = (gcnew System::Windows::Forms::TextBox());
			this->addContractorBtn = (gcnew System::Windows::Forms::Button());
			this->errorLb = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				28.81549F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				71.18451F)));
			this->tableLayoutPanel1->Controls->Add(this->accountNumberLb, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->customNameLb, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->customNameInput, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->accountNumberInput, 1, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->Padding = System::Windows::Forms::Padding(20, 0, 20, 0);
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(878, 450);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// accountNumberLb
			// 
			this->accountNumberLb->AutoSize = true;
			this->accountNumberLb->Dock = System::Windows::Forms::DockStyle::Fill;
			this->accountNumberLb->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->accountNumberLb->Location = System::Drawing::Point(23, 225);
			this->accountNumberLb->Name = L"accountNumberLb";
			this->accountNumberLb->Size = System::Drawing::Size(235, 225);
			this->accountNumberLb->TabIndex = 3;
			this->accountNumberLb->Text = L"Numer konta:";
			this->accountNumberLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// customNameLb
			// 
			this->customNameLb->AutoSize = true;
			this->customNameLb->Dock = System::Windows::Forms::DockStyle::Fill;
			this->customNameLb->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->customNameLb->Location = System::Drawing::Point(23, 0);
			this->customNameLb->Name = L"customNameLb";
			this->customNameLb->Size = System::Drawing::Size(235, 225);
			this->customNameLb->TabIndex = 0;
			this->customNameLb->Text = L"Nazwa wlasna:";
			this->customNameLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// customNameInput
			// 
			this->customNameInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->customNameInput->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->customNameInput->Location = System::Drawing::Point(264, 90);
			this->customNameInput->MaxLength = 50;
			this->customNameInput->Name = L"customNameInput";
			this->customNameInput->Size = System::Drawing::Size(591, 44);
			this->customNameInput->TabIndex = 1;
			// 
			// accountNumberInput
			// 
			this->accountNumberInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->accountNumberInput->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->accountNumberInput->Location = System::Drawing::Point(264, 315);
			this->accountNumberInput->MaxLength = 35;
			this->accountNumberInput->Name = L"accountNumberInput";
			this->accountNumberInput->Size = System::Drawing::Size(591, 44);
			this->accountNumberInput->TabIndex = 2;
			this->accountNumberInput->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &CreateContractor::accountNumberInput_KeyPress);
			this->accountNumberInput->Leave += gcnew System::EventHandler(this, &CreateContractor::accountNumberInput_Leave);
			// 
			// addContractorBtn
			// 
			this->addContractorBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->addContractorBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(193)),
				static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->addContractorBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->addContractorBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->addContractorBtn->ForeColor = System::Drawing::Color::White;
			this->addContractorBtn->Location = System::Drawing::Point(576, 522);
			this->addContractorBtn->Name = L"addContractorBtn";
			this->addContractorBtn->Size = System::Drawing::Size(290, 60);
			this->addContractorBtn->TabIndex = 4;
			this->addContractorBtn->Text = L"Dodaj kontrahenta";
			this->addContractorBtn->UseVisualStyleBackColor = false;
			this->addContractorBtn->Click += gcnew System::EventHandler(this, &CreateContractor::addContractorBtn_Click);
			// 
			// errorLb
			// 
			this->errorLb->Font = (gcnew System::Drawing::Font(L"Impact", 16));
			this->errorLb->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(193)), static_cast<System::Int32>(static_cast<System::Byte>(13)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->errorLb->Location = System::Drawing::Point(12, 486);
			this->errorLb->Name = L"errorLb";
			this->errorLb->Size = System::Drawing::Size(558, 96);
			this->errorLb->TabIndex = 8;
			this->errorLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// CreateContractor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(878, 594);
			this->Controls->Add(this->errorLb);
			this->Controls->Add(this->addContractorBtn);
			this->Controls->Add(this->tableLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"CreateContractor";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Dodaj kontrahenta";
			this->Load += gcnew System::EventHandler(this, &CreateContractor::CreateContractor_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void CreateContractor_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void accountNumberInput_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
	private: System::Void accountNumberInput_Leave(System::Object^ sender, System::EventArgs^ e);
	private: System::Void addContractorBtn_Click(System::Object^ sender, System::EventArgs^ e);
};
}
