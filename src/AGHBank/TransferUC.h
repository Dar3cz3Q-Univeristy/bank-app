#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Data::SqlClient;

namespace AGHBank {

	/// <summary>
	/// Summary for TransferUC
	/// </summary>
	public ref class TransferUC : public System::Windows::Forms::UserControl
	{
	public:
		int loggedUserID;
		TransferUC(int id)
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
		~TransferUC()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ typePanel;
	private: System::Windows::Forms::RadioButton^ ownTransferRadioBtn;
	private: System::Windows::Forms::RadioButton^ countryTransferRadioBtn;
	private: System::Windows::Forms::Panel^ ownTransferPanel;
	private: System::Windows::Forms::Label^ billLb;
	private: System::Windows::Forms::ComboBox^ ownBillsComboBox;
	private: System::Windows::Forms::Panel^ amountPanel;
	private: System::Windows::Forms::TextBox^ amountInput;
	private: System::Windows::Forms::Label^ amountLb;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ errorLb;
	private: System::Windows::Forms::Button^ nextBtn;
	private: System::Windows::Forms::Panel^ countryTransferPanel;
	private: System::Windows::Forms::TextBox^ accountNumberInput;
	private: System::Windows::Forms::Button^ savedContractorsBtn;
	private: System::Windows::Forms::Label^ accountNumberLb;
	private: System::Windows::Forms::Panel^ startingAccountPanel;
	private: System::Windows::Forms::ComboBox^ startingAccountComboBox;
	private: System::Windows::Forms::Label^ startingAccountLb;
	private: System::Windows::Forms::Panel^ titlePanel;
	private: System::Windows::Forms::TextBox^ titleInput;
	private: System::Windows::Forms::Label^ titleLb;
	private: System::Windows::Forms::ComboBox^ currencyComboBox;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(TransferUC::typeid));
			this->typePanel = (gcnew System::Windows::Forms::Panel());
			this->ownTransferRadioBtn = (gcnew System::Windows::Forms::RadioButton());
			this->countryTransferRadioBtn = (gcnew System::Windows::Forms::RadioButton());
			this->ownTransferPanel = (gcnew System::Windows::Forms::Panel());
			this->billLb = (gcnew System::Windows::Forms::Label());
			this->ownBillsComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->countryTransferPanel = (gcnew System::Windows::Forms::Panel());
			this->accountNumberInput = (gcnew System::Windows::Forms::TextBox());
			this->savedContractorsBtn = (gcnew System::Windows::Forms::Button());
			this->accountNumberLb = (gcnew System::Windows::Forms::Label());
			this->amountPanel = (gcnew System::Windows::Forms::Panel());
			this->currencyComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->amountInput = (gcnew System::Windows::Forms::TextBox());
			this->amountLb = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->errorLb = (gcnew System::Windows::Forms::Label());
			this->nextBtn = (gcnew System::Windows::Forms::Button());
			this->startingAccountPanel = (gcnew System::Windows::Forms::Panel());
			this->startingAccountComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->startingAccountLb = (gcnew System::Windows::Forms::Label());
			this->titlePanel = (gcnew System::Windows::Forms::Panel());
			this->titleInput = (gcnew System::Windows::Forms::TextBox());
			this->titleLb = (gcnew System::Windows::Forms::Label());
			this->typePanel->SuspendLayout();
			this->ownTransferPanel->SuspendLayout();
			this->countryTransferPanel->SuspendLayout();
			this->amountPanel->SuspendLayout();
			this->panel3->SuspendLayout();
			this->startingAccountPanel->SuspendLayout();
			this->titlePanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// typePanel
			// 
			this->typePanel->Controls->Add(this->ownTransferRadioBtn);
			this->typePanel->Controls->Add(this->countryTransferRadioBtn);
			this->typePanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->typePanel->Location = System::Drawing::Point(0, 120);
			this->typePanel->Name = L"typePanel";
			this->typePanel->Padding = System::Windows::Forms::Padding(20, 5, 20, 5);
			this->typePanel->Size = System::Drawing::Size(1578, 100);
			this->typePanel->TabIndex = 0;
			// 
			// ownTransferRadioBtn
			// 
			this->ownTransferRadioBtn->Appearance = System::Windows::Forms::Appearance::Button;
			this->ownTransferRadioBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ownTransferRadioBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 18, System::Drawing::FontStyle::Bold));
			this->ownTransferRadioBtn->Location = System::Drawing::Point(820, 20);
			this->ownTransferRadioBtn->Name = L"ownTransferRadioBtn";
			this->ownTransferRadioBtn->Size = System::Drawing::Size(735, 60);
			this->ownTransferRadioBtn->TabIndex = 3;
			this->ownTransferRadioBtn->Text = L"Przelew wlasny";
			this->ownTransferRadioBtn->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->ownTransferRadioBtn->UseVisualStyleBackColor = true;
			// 
			// countryTransferRadioBtn
			// 
			this->countryTransferRadioBtn->Appearance = System::Windows::Forms::Appearance::Button;
			this->countryTransferRadioBtn->Checked = true;
			this->countryTransferRadioBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->countryTransferRadioBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->countryTransferRadioBtn->Location = System::Drawing::Point(23, 20);
			this->countryTransferRadioBtn->Name = L"countryTransferRadioBtn";
			this->countryTransferRadioBtn->Size = System::Drawing::Size(735, 60);
			this->countryTransferRadioBtn->TabIndex = 2;
			this->countryTransferRadioBtn->TabStop = true;
			this->countryTransferRadioBtn->Text = L"Przelew krajowy";
			this->countryTransferRadioBtn->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->countryTransferRadioBtn->UseVisualStyleBackColor = true;
			this->countryTransferRadioBtn->CheckedChanged += gcnew System::EventHandler(this, &TransferUC::countryTransferRadioBtn_CheckedChanged);
			// 
			// ownTransferPanel
			// 
			this->ownTransferPanel->Controls->Add(this->billLb);
			this->ownTransferPanel->Controls->Add(this->ownBillsComboBox);
			this->ownTransferPanel->Location = System::Drawing::Point(0, 220);
			this->ownTransferPanel->Name = L"ownTransferPanel";
			this->ownTransferPanel->Size = System::Drawing::Size(1578, 120);
			this->ownTransferPanel->TabIndex = 7;
			// 
			// billLb
			// 
			this->billLb->AutoSize = true;
			this->billLb->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->billLb->Location = System::Drawing::Point(238, 41);
			this->billLb->Name = L"billLb";
			this->billLb->Size = System::Drawing::Size(277, 37);
			this->billLb->TabIndex = 0;
			this->billLb->Text = L"Wybierz rachunek:";
			// 
			// ownBillsComboBox
			// 
			this->ownBillsComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ownBillsComboBox->Enabled = false;
			this->ownBillsComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->ownBillsComboBox->FormattingEnabled = true;
			this->ownBillsComboBox->Location = System::Drawing::Point(557, 38);
			this->ownBillsComboBox->Name = L"ownBillsComboBox";
			this->ownBillsComboBox->Size = System::Drawing::Size(713, 45);
			this->ownBillsComboBox->TabIndex = 4;
			this->ownBillsComboBox->TabStop = false;
			// 
			// countryTransferPanel
			// 
			this->countryTransferPanel->Controls->Add(this->accountNumberInput);
			this->countryTransferPanel->Controls->Add(this->savedContractorsBtn);
			this->countryTransferPanel->Controls->Add(this->accountNumberLb);
			this->countryTransferPanel->Location = System::Drawing::Point(0, 220);
			this->countryTransferPanel->Name = L"countryTransferPanel";
			this->countryTransferPanel->Size = System::Drawing::Size(1578, 120);
			this->countryTransferPanel->TabIndex = 0;
			// 
			// accountNumberInput
			// 
			this->accountNumberInput->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->accountNumberInput->Location = System::Drawing::Point(557, 38);
			this->accountNumberInput->MaxLength = 35;
			this->accountNumberInput->Name = L"accountNumberInput";
			this->accountNumberInput->Size = System::Drawing::Size(662, 44);
			this->accountNumberInput->TabIndex = 4;
			this->accountNumberInput->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &TransferUC::accountNumberInput_KeyPress);
			this->accountNumberInput->Leave += gcnew System::EventHandler(this, &TransferUC::accountNumberInput_Leave);
			// 
			// savedContractorsBtn
			// 
			this->savedContractorsBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->savedContractorsBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"savedContractorsBtn.Image")));
			this->savedContractorsBtn->Location = System::Drawing::Point(1225, 35);
			this->savedContractorsBtn->Name = L"savedContractorsBtn";
			this->savedContractorsBtn->Size = System::Drawing::Size(50, 50);
			this->savedContractorsBtn->TabIndex = 5;
			this->savedContractorsBtn->UseVisualStyleBackColor = true;
			this->savedContractorsBtn->Click += gcnew System::EventHandler(this, &TransferUC::savedContractorsBtn_Click);
			// 
			// accountNumberLb
			// 
			this->accountNumberLb->AutoSize = true;
			this->accountNumberLb->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->accountNumberLb->Location = System::Drawing::Point(303, 41);
			this->accountNumberLb->Name = L"accountNumberLb";
			this->accountNumberLb->Size = System::Drawing::Size(212, 37);
			this->accountNumberLb->TabIndex = 7;
			this->accountNumberLb->Text = L"Numer konta:";
			// 
			// amountPanel
			// 
			this->amountPanel->Controls->Add(this->currencyComboBox);
			this->amountPanel->Controls->Add(this->amountInput);
			this->amountPanel->Controls->Add(this->amountLb);
			this->amountPanel->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->amountPanel->Location = System::Drawing::Point(0, 459);
			this->amountPanel->Name = L"amountPanel";
			this->amountPanel->Size = System::Drawing::Size(1578, 120);
			this->amountPanel->TabIndex = 0;
			// 
			// currencyComboBox
			// 
			this->currencyComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->currencyComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->currencyComboBox->FormattingEnabled = true;
			this->currencyComboBox->Location = System::Drawing::Point(1155, 38);
			this->currencyComboBox->Name = L"currencyComboBox";
			this->currencyComboBox->Size = System::Drawing::Size(115, 45);
			this->currencyComboBox->TabIndex = 8;
			// 
			// amountInput
			// 
			this->amountInput->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->amountInput->Location = System::Drawing::Point(557, 38);
			this->amountInput->Name = L"amountInput";
			this->amountInput->Size = System::Drawing::Size(592, 44);
			this->amountInput->TabIndex = 7;
			this->amountInput->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &TransferUC::amountInput_KeyPress);
			// 
			// amountLb
			// 
			this->amountLb->AutoSize = true;
			this->amountLb->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->amountLb->Location = System::Drawing::Point(401, 41);
			this->amountLb->Name = L"amountLb";
			this->amountLb->Size = System::Drawing::Size(114, 37);
			this->amountLb->TabIndex = 6;
			this->amountLb->Text = L"Kwota:";
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->errorLb);
			this->panel3->Controls->Add(this->nextBtn);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel3->Location = System::Drawing::Point(0, 579);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1578, 130);
			this->panel3->TabIndex = 0;
			// 
			// errorLb
			// 
			this->errorLb->Font = (gcnew System::Drawing::Font(L"Impact", 16));
			this->errorLb->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(193)), static_cast<System::Int32>(static_cast<System::Byte>(13)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->errorLb->Location = System::Drawing::Point(138, 17);
			this->errorLb->Name = L"errorLb";
			this->errorLb->Size = System::Drawing::Size(851, 96);
			this->errorLb->TabIndex = 8;
			this->errorLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// nextBtn
			// 
			this->nextBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->nextBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(193)), static_cast<System::Int32>(static_cast<System::Byte>(13)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->nextBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->nextBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->nextBtn->ForeColor = System::Drawing::Color::White;
			this->nextBtn->Location = System::Drawing::Point(1221, 25);
			this->nextBtn->Name = L"nextBtn";
			this->nextBtn->Size = System::Drawing::Size(227, 81);
			this->nextBtn->TabIndex = 9;
			this->nextBtn->Text = L"Wykonaj";
			this->nextBtn->UseVisualStyleBackColor = false;
			this->nextBtn->Click += gcnew System::EventHandler(this, &TransferUC::nextBtn_Click);
			// 
			// startingAccountPanel
			// 
			this->startingAccountPanel->Controls->Add(this->startingAccountComboBox);
			this->startingAccountPanel->Controls->Add(this->startingAccountLb);
			this->startingAccountPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->startingAccountPanel->Location = System::Drawing::Point(0, 0);
			this->startingAccountPanel->Name = L"startingAccountPanel";
			this->startingAccountPanel->Size = System::Drawing::Size(1578, 120);
			this->startingAccountPanel->TabIndex = 0;
			// 
			// startingAccountComboBox
			// 
			this->startingAccountComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->startingAccountComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->startingAccountComboBox->FormattingEnabled = true;
			this->startingAccountComboBox->Location = System::Drawing::Point(557, 38);
			this->startingAccountComboBox->Name = L"startingAccountComboBox";
			this->startingAccountComboBox->Size = System::Drawing::Size(718, 45);
			this->startingAccountComboBox->TabIndex = 1;
			this->startingAccountComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &TransferUC::startingAccountComboBox_SelectedIndexChanged);
			// 
			// startingAccountLb
			// 
			this->startingAccountLb->AutoSize = true;
			this->startingAccountLb->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->startingAccountLb->Location = System::Drawing::Point(333, 41);
			this->startingAccountLb->Name = L"startingAccountLb";
			this->startingAccountLb->Size = System::Drawing::Size(182, 37);
			this->startingAccountLb->TabIndex = 8;
			this->startingAccountLb->Text = L"Z rachunku:";
			// 
			// titlePanel
			// 
			this->titlePanel->Controls->Add(this->titleInput);
			this->titlePanel->Controls->Add(this->titleLb);
			this->titlePanel->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->titlePanel->Location = System::Drawing::Point(0, 339);
			this->titlePanel->Name = L"titlePanel";
			this->titlePanel->Size = System::Drawing::Size(1578, 120);
			this->titlePanel->TabIndex = 0;
			// 
			// titleInput
			// 
			this->titleInput->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->titleInput->Location = System::Drawing::Point(557, 38);
			this->titleInput->MaxLength = 100;
			this->titleInput->Name = L"titleInput";
			this->titleInput->Size = System::Drawing::Size(713, 44);
			this->titleInput->TabIndex = 6;
			// 
			// titleLb
			// 
			this->titleLb->AutoSize = true;
			this->titleLb->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->titleLb->Location = System::Drawing::Point(417, 42);
			this->titleLb->Name = L"titleLb";
			this->titleLb->Size = System::Drawing::Size(97, 37);
			this->titleLb->TabIndex = 7;
			this->titleLb->Text = L"Tytul:";
			// 
			// TransferUC
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->titlePanel);
			this->Controls->Add(this->amountPanel);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->typePanel);
			this->Controls->Add(this->countryTransferPanel);
			this->Controls->Add(this->startingAccountPanel);
			this->Controls->Add(this->ownTransferPanel);
			this->Name = L"TransferUC";
			this->Size = System::Drawing::Size(1578, 709);
			this->Load += gcnew System::EventHandler(this, &TransferUC::TransferUC_Load);
			this->typePanel->ResumeLayout(false);
			this->ownTransferPanel->ResumeLayout(false);
			this->ownTransferPanel->PerformLayout();
			this->countryTransferPanel->ResumeLayout(false);
			this->countryTransferPanel->PerformLayout();
			this->amountPanel->ResumeLayout(false);
			this->amountPanel->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->startingAccountPanel->ResumeLayout(false);
			this->startingAccountPanel->PerformLayout();
			this->titlePanel->ResumeLayout(false);
			this->titlePanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	public:
		int selectedType = 1,
			startingAccountID;
	private: System::Void countryTransferRadioBtn_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void TransferUC_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void startingAccountComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void accountNumberInput_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
	private: System::Void accountNumberInput_Leave(System::Object^ sender, System::EventArgs^ e);
	private: System::Void amountInput_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
	private: System::Void nextBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void savedContractorsBtn_Click(System::Object^ sender, System::EventArgs^ e);
};
}
