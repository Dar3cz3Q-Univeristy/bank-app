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
	/// Summary for CreateBill
	/// </summary>
	public ref class CreateBill : public System::Windows::Forms::Form
	{
	public:
		int loggedUserID;
		CreateBill(int id)
		{
			InitializeComponent();
			loggedUserID = id;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CreateBill()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ newBillSettingsTableLayoutPanel;
	private: System::Windows::Forms::Label^ accountTypeLb;
	private: System::Windows::Forms::Label^ currencyLb;
	private: System::Windows::Forms::ComboBox^ accountTypeCombo;
	private: System::Windows::Forms::ComboBox^ currencyCombo;
	private: System::Windows::Forms::Button^ createBillBtn;
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
			this->newBillSettingsTableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->currencyCombo = (gcnew System::Windows::Forms::ComboBox());
			this->accountTypeLb = (gcnew System::Windows::Forms::Label());
			this->currencyLb = (gcnew System::Windows::Forms::Label());
			this->accountTypeCombo = (gcnew System::Windows::Forms::ComboBox());
			this->createBillBtn = (gcnew System::Windows::Forms::Button());
			this->newBillSettingsTableLayoutPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// newBillSettingsTableLayoutPanel
			// 
			this->newBillSettingsTableLayoutPanel->ColumnCount = 2;
			this->newBillSettingsTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				30)));
			this->newBillSettingsTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				70)));
			this->newBillSettingsTableLayoutPanel->Controls->Add(this->currencyCombo, 1, 1);
			this->newBillSettingsTableLayoutPanel->Controls->Add(this->accountTypeLb, 0, 0);
			this->newBillSettingsTableLayoutPanel->Controls->Add(this->currencyLb, 0, 1);
			this->newBillSettingsTableLayoutPanel->Controls->Add(this->accountTypeCombo, 1, 0);
			this->newBillSettingsTableLayoutPanel->Location = System::Drawing::Point(12, 12);
			this->newBillSettingsTableLayoutPanel->Name = L"newBillSettingsTableLayoutPanel";
			this->newBillSettingsTableLayoutPanel->RowCount = 2;
			this->newBillSettingsTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->newBillSettingsTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->newBillSettingsTableLayoutPanel->Size = System::Drawing::Size(854, 416);
			this->newBillSettingsTableLayoutPanel->TabIndex = 0;
			// 
			// currencyCombo
			// 
			this->currencyCombo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->currencyCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->currencyCombo->Enabled = false;
			this->currencyCombo->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->currencyCombo->FormattingEnabled = true;
			this->currencyCombo->Location = System::Drawing::Point(259, 289);
			this->currencyCombo->Name = L"currencyCombo";
			this->currencyCombo->Size = System::Drawing::Size(592, 45);
			this->currencyCombo->TabIndex = 3;
			// 
			// accountTypeLb
			// 
			this->accountTypeLb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->accountTypeLb->AutoSize = true;
			this->accountTypeLb->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->accountTypeLb->Location = System::Drawing::Point(3, 0);
			this->accountTypeLb->Name = L"accountTypeLb";
			this->accountTypeLb->Size = System::Drawing::Size(250, 208);
			this->accountTypeLb->TabIndex = 0;
			this->accountTypeLb->Text = L"Typ konta:";
			this->accountTypeLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// currencyLb
			// 
			this->currencyLb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->currencyLb->AutoSize = true;
			this->currencyLb->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->currencyLb->Location = System::Drawing::Point(3, 208);
			this->currencyLb->Name = L"currencyLb";
			this->currencyLb->Size = System::Drawing::Size(250, 208);
			this->currencyLb->TabIndex = 1;
			this->currencyLb->Text = L"Waluta:";
			this->currencyLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// accountTypeCombo
			// 
			this->accountTypeCombo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->accountTypeCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->accountTypeCombo->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->accountTypeCombo->FormattingEnabled = true;
			this->accountTypeCombo->Location = System::Drawing::Point(259, 81);
			this->accountTypeCombo->Name = L"accountTypeCombo";
			this->accountTypeCombo->Size = System::Drawing::Size(592, 45);
			this->accountTypeCombo->TabIndex = 2;
			this->accountTypeCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &CreateBill::AccountTypeCombo_SelectedIndexChanged);
			// 
			// createBillBtn
			// 
			this->createBillBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->createBillBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(193)), static_cast<System::Int32>(static_cast<System::Byte>(13)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->createBillBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->createBillBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->createBillBtn->ForeColor = System::Drawing::Color::White;
			this->createBillBtn->Location = System::Drawing::Point(596, 512);
			this->createBillBtn->Name = L"createBillBtn";
			this->createBillBtn->Size = System::Drawing::Size(267, 60);
			this->createBillBtn->TabIndex = 3;
			this->createBillBtn->Text = L"Otwórz rachunek";
			this->createBillBtn->UseVisualStyleBackColor = false;
			this->createBillBtn->Click += gcnew System::EventHandler(this, &CreateBill::createBillBtn_Click);
			// 
			// CreateBill
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(878, 594);
			this->Controls->Add(this->createBillBtn);
			this->Controls->Add(this->newBillSettingsTableLayoutPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximumSize = System::Drawing::Size(900, 650);
			this->MinimumSize = System::Drawing::Size(900, 650);
			this->Name = L"CreateBill";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Otwórz nowy rachunek";
			this->Load += gcnew System::EventHandler(this, &CreateBill::CreateBill_Load);
			this->newBillSettingsTableLayoutPanel->ResumeLayout(false);
			this->newBillSettingsTableLayoutPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void CreateBill_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AccountTypeCombo_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void createBillBtn_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
