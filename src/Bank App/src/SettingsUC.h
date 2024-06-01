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
	/// Summary for SettingsUC
	/// </summary>
	public ref class SettingsUC : public System::Windows::Forms::UserControl
	{
	public:
		int loggedUserID;
		SettingsUC(int id)
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
		~SettingsUC()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ settingsErrorLb;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ deleteAccountBtn;
	private: System::Windows::Forms::Button^ changePasswordBtn;
	private: System::Windows::Forms::Label^ helpPersonalLb;
	private: System::Windows::Forms::Button^ nextBtn;
	private: System::Windows::Forms::TableLayoutPanel^ personalTableLayoutPanel;
	private: System::Windows::Forms::TextBox^ surnameInput;
	private: System::Windows::Forms::TextBox^ forenameInput;
	private: System::Windows::Forms::TextBox^ emailInput;
	private: System::Windows::Forms::Label^ surnameLb;
	private: System::Windows::Forms::Label^ emailLb;
	private: System::Windows::Forms::Label^ birthDateLb;
	private: System::Windows::Forms::DateTimePicker^ birthDatePicker;
	private: System::Windows::Forms::Label^ phoneLb;
	private: System::Windows::Forms::TextBox^ phoneInput;
	private: System::Windows::Forms::Label^ forenameLb;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ headerLb;
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
			this->settingsErrorLb = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->deleteAccountBtn = (gcnew System::Windows::Forms::Button());
			this->changePasswordBtn = (gcnew System::Windows::Forms::Button());
			this->helpPersonalLb = (gcnew System::Windows::Forms::Label());
			this->nextBtn = (gcnew System::Windows::Forms::Button());
			this->personalTableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->surnameInput = (gcnew System::Windows::Forms::TextBox());
			this->forenameInput = (gcnew System::Windows::Forms::TextBox());
			this->emailInput = (gcnew System::Windows::Forms::TextBox());
			this->surnameLb = (gcnew System::Windows::Forms::Label());
			this->emailLb = (gcnew System::Windows::Forms::Label());
			this->birthDateLb = (gcnew System::Windows::Forms::Label());
			this->birthDatePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->phoneLb = (gcnew System::Windows::Forms::Label());
			this->phoneInput = (gcnew System::Windows::Forms::TextBox());
			this->forenameLb = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->headerLb = (gcnew System::Windows::Forms::Label());
			this->panel2->SuspendLayout();
			this->personalTableLayoutPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// settingsErrorLb
			// 
			this->settingsErrorLb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->settingsErrorLb->Font = (gcnew System::Drawing::Font(L"Impact", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->settingsErrorLb->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(193)), static_cast<System::Int32>(static_cast<System::Byte>(13)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->settingsErrorLb->Location = System::Drawing::Point(0, 532);
			this->settingsErrorLb->Name = L"settingsErrorLb";
			this->settingsErrorLb->Size = System::Drawing::Size(1538, 134);
			this->settingsErrorLb->TabIndex = 14;
			this->settingsErrorLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->Controls->Add(this->settingsErrorLb);
			this->panel2->Controls->Add(this->deleteAccountBtn);
			this->panel2->Controls->Add(this->changePasswordBtn);
			this->panel2->Controls->Add(this->helpPersonalLb);
			this->panel2->Controls->Add(this->nextBtn);
			this->panel2->Controls->Add(this->personalTableLayoutPanel);
			this->panel2->Controls->Add(this->label13);
			this->panel2->Controls->Add(this->headerLb);
			this->panel2->Location = System::Drawing::Point(20, 20);
			this->panel2->Name = L"panel2";
			this->panel2->Padding = System::Windows::Forms::Padding(10);
			this->panel2->Size = System::Drawing::Size(1538, 666);
			this->panel2->TabIndex = 13;
			// 
			// deleteAccountBtn
			// 
			this->deleteAccountBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(193)),
				static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->deleteAccountBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->deleteAccountBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
			this->deleteAccountBtn->ForeColor = System::Drawing::Color::White;
			this->deleteAccountBtn->Location = System::Drawing::Point(821, 303);
			this->deleteAccountBtn->Name = L"deleteAccountBtn";
			this->deleteAccountBtn->Size = System::Drawing::Size(690, 86);
			this->deleteAccountBtn->TabIndex = 7;
			this->deleteAccountBtn->Text = L"Usun konto";
			this->deleteAccountBtn->UseVisualStyleBackColor = false;
			this->deleteAccountBtn->Click += gcnew System::EventHandler(this, &SettingsUC::deleteAccountBtn_Click);
			// 
			// changePasswordBtn
			// 
			this->changePasswordBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->changePasswordBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
			this->changePasswordBtn->Location = System::Drawing::Point(821, 182);
			this->changePasswordBtn->Name = L"changePasswordBtn";
			this->changePasswordBtn->Size = System::Drawing::Size(690, 86);
			this->changePasswordBtn->TabIndex = 6;
			this->changePasswordBtn->Text = L"Zmien haslo";
			this->changePasswordBtn->UseVisualStyleBackColor = true;
			this->changePasswordBtn->Click += gcnew System::EventHandler(this, &SettingsUC::changePasswordBtn_Click);
			// 
			// helpPersonalLb
			// 
			this->helpPersonalLb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->helpPersonalLb->Location = System::Drawing::Point(0, 121);
			this->helpPersonalLb->Name = L"helpPersonalLb";
			this->helpPersonalLb->Size = System::Drawing::Size(787, 58);
			this->helpPersonalLb->TabIndex = 11;
			this->helpPersonalLb->Text = L"Dane osobowe:";
			this->helpPersonalLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// nextBtn
			// 
			this->nextBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->nextBtn->BackColor = System::Drawing::Color::White;
			this->nextBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->nextBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->nextBtn->ForeColor = System::Drawing::SystemColors::ControlText;
			this->nextBtn->Location = System::Drawing::Point(821, 419);
			this->nextBtn->Name = L"nextBtn";
			this->nextBtn->Size = System::Drawing::Size(690, 86);
			this->nextBtn->TabIndex = 8;
			this->nextBtn->Text = L"Zaktualizuj dane osobowe";
			this->nextBtn->UseVisualStyleBackColor = false;
			this->nextBtn->Click += gcnew System::EventHandler(this, &SettingsUC::nextBtn_Click);
			// 
			// personalTableLayoutPanel
			// 
			this->personalTableLayoutPanel->ColumnCount = 2;
			this->personalTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				45)));
			this->personalTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				55)));
			this->personalTableLayoutPanel->Controls->Add(this->surnameInput, 1, 1);
			this->personalTableLayoutPanel->Controls->Add(this->forenameInput, 1, 0);
			this->personalTableLayoutPanel->Controls->Add(this->emailInput, 1, 4);
			this->personalTableLayoutPanel->Controls->Add(this->surnameLb, 0, 1);
			this->personalTableLayoutPanel->Controls->Add(this->emailLb, 0, 4);
			this->personalTableLayoutPanel->Controls->Add(this->birthDateLb, 0, 3);
			this->personalTableLayoutPanel->Controls->Add(this->birthDatePicker, 1, 3);
			this->personalTableLayoutPanel->Controls->Add(this->phoneLb, 0, 2);
			this->personalTableLayoutPanel->Controls->Add(this->phoneInput, 1, 2);
			this->personalTableLayoutPanel->Controls->Add(this->forenameLb, 0, 0);
			this->personalTableLayoutPanel->Location = System::Drawing::Point(0, 182);
			this->personalTableLayoutPanel->Name = L"personalTableLayoutPanel";
			this->personalTableLayoutPanel->RowCount = 5;
			this->personalTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				65)));
			this->personalTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				65)));
			this->personalTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				65)));
			this->personalTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				65)));
			this->personalTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->personalTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->personalTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->personalTableLayoutPanel->Size = System::Drawing::Size(787, 323);
			this->personalTableLayoutPanel->TabIndex = 0;
			// 
			// surnameInput
			// 
			this->surnameInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->surnameInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->surnameInput->Location = System::Drawing::Point(364, 75);
			this->surnameInput->Margin = System::Windows::Forms::Padding(10);
			this->surnameInput->MaxLength = 32;
			this->surnameInput->MinimumSize = System::Drawing::Size(4, 35);
			this->surnameInput->Name = L"surnameInput";
			this->surnameInput->Size = System::Drawing::Size(413, 39);
			this->surnameInput->TabIndex = 2;
			// 
			// forenameInput
			// 
			this->forenameInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->forenameInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->forenameInput->Location = System::Drawing::Point(364, 10);
			this->forenameInput->Margin = System::Windows::Forms::Padding(10);
			this->forenameInput->MaxLength = 32;
			this->forenameInput->MinimumSize = System::Drawing::Size(4, 35);
			this->forenameInput->Name = L"forenameInput";
			this->forenameInput->Size = System::Drawing::Size(413, 39);
			this->forenameInput->TabIndex = 1;
			// 
			// emailInput
			// 
			this->emailInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->emailInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->emailInput->Location = System::Drawing::Point(364, 270);
			this->emailInput->Margin = System::Windows::Forms::Padding(10);
			this->emailInput->MinimumSize = System::Drawing::Size(4, 35);
			this->emailInput->Name = L"emailInput";
			this->emailInput->Size = System::Drawing::Size(413, 39);
			this->emailInput->TabIndex = 5;
			// 
			// surnameLb
			// 
			this->surnameLb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->surnameLb->AutoSize = true;
			this->surnameLb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->surnameLb->Location = System::Drawing::Point(3, 65);
			this->surnameLb->Name = L"surnameLb";
			this->surnameLb->Size = System::Drawing::Size(348, 65);
			this->surnameLb->TabIndex = 12;
			this->surnameLb->Text = L"Nazwisko:";
			this->surnameLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// emailLb
			// 
			this->emailLb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->emailLb->AutoSize = true;
			this->emailLb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->emailLb->Location = System::Drawing::Point(3, 260);
			this->emailLb->Name = L"emailLb";
			this->emailLb->Size = System::Drawing::Size(348, 63);
			this->emailLb->TabIndex = 1;
			this->emailLb->Text = L"E-Mail:";
			this->emailLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// birthDateLb
			// 
			this->birthDateLb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->birthDateLb->AutoSize = true;
			this->birthDateLb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->birthDateLb->Location = System::Drawing::Point(3, 195);
			this->birthDateLb->Name = L"birthDateLb";
			this->birthDateLb->Size = System::Drawing::Size(348, 65);
			this->birthDateLb->TabIndex = 3;
			this->birthDateLb->Text = L"Data urodzenia:";
			this->birthDateLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// birthDatePicker
			// 
			this->birthDatePicker->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->birthDatePicker->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->birthDatePicker->Location = System::Drawing::Point(364, 205);
			this->birthDatePicker->Margin = System::Windows::Forms::Padding(10);
			this->birthDatePicker->MaxDate = System::DateTime(2022, 12, 1, 0, 0, 0, 0);
			this->birthDatePicker->MinimumSize = System::Drawing::Size(4, 35);
			this->birthDatePicker->Name = L"birthDatePicker";
			this->birthDatePicker->Size = System::Drawing::Size(413, 35);
			this->birthDatePicker->TabIndex = 4;
			this->birthDatePicker->Value = System::DateTime(2022, 12, 1, 0, 0, 0, 0);
			// 
			// phoneLb
			// 
			this->phoneLb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->phoneLb->AutoSize = true;
			this->phoneLb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->phoneLb->Location = System::Drawing::Point(3, 130);
			this->phoneLb->Name = L"phoneLb";
			this->phoneLb->Size = System::Drawing::Size(348, 65);
			this->phoneLb->TabIndex = 2;
			this->phoneLb->Text = L"Nr telefonu:";
			this->phoneLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// phoneInput
			// 
			this->phoneInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->phoneInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->phoneInput->Location = System::Drawing::Point(364, 140);
			this->phoneInput->Margin = System::Windows::Forms::Padding(10);
			this->phoneInput->MaxLength = 9;
			this->phoneInput->MinimumSize = System::Drawing::Size(4, 35);
			this->phoneInput->Name = L"phoneInput";
			this->phoneInput->Size = System::Drawing::Size(413, 39);
			this->phoneInput->TabIndex = 3;
			// 
			// forenameLb
			// 
			this->forenameLb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->forenameLb->AutoSize = true;
			this->forenameLb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->forenameLb->Location = System::Drawing::Point(3, 0);
			this->forenameLb->Name = L"forenameLb";
			this->forenameLb->Size = System::Drawing::Size(348, 65);
			this->forenameLb->TabIndex = 12;
			this->forenameLb->Text = L"Imie:";
			this->forenameLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label13
			// 
			this->label13->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label13->Location = System::Drawing::Point(19, 124);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(744, 67);
			this->label13->TabIndex = 4;
			this->label13->Text = L"Dane konta:";
			this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// headerLb
			// 
			this->headerLb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->headerLb->Location = System::Drawing::Point(26, 3);
			this->headerLb->Name = L"headerLb";
			this->headerLb->Size = System::Drawing::Size(740, 98);
			this->headerLb->TabIndex = 0;
			this->headerLb->Text = L"Edytuj dane";
			this->headerLb->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// SettingsUC
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->panel2);
			this->Name = L"SettingsUC";
			this->Padding = System::Windows::Forms::Padding(20);
			this->Size = System::Drawing::Size(1578, 709);
			this->Load += gcnew System::EventHandler(this, &SettingsUC::SettingsUC_Load);
			this->panel2->ResumeLayout(false);
			this->personalTableLayoutPanel->ResumeLayout(false);
			this->personalTableLayoutPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void SettingsUC_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void changePasswordBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void deleteAccountBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nextBtn_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
