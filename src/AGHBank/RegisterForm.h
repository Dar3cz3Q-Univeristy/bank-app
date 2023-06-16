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
	/// Summary for RegisterForm
	/// </summary>
	public ref class RegisterForm : public System::Windows::Forms::Form
	{
	public:
		RegisterForm(void)
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
		~RegisterForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::LinkLabel^ haveAccountLink;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ logoLb;
	private: System::Windows::Forms::PictureBox^ logoBox;
	private: System::Windows::Forms::Label^ headerLb;
	private: System::Windows::Forms::Label^ registerErrorLb;
    private: System::Windows::Forms::TableLayoutPanel^ accountTableLayoutPanel;
	private: System::Windows::Forms::Label^ usernameLb;
	private: System::Windows::Forms::Label^ emailLb;
	private: System::Windows::Forms::Label^ passwordLb;
	private: System::Windows::Forms::Label^ retypedPasswordLb;
	private: System::Windows::Forms::TextBox^ usernameInput;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label13;
    private: System::Windows::Forms::TableLayoutPanel^ personalTableLayoutPanel;
	private: System::Windows::Forms::Label^ peselLb;
	private: System::Windows::Forms::Label^ cardIDLb;
	private: System::Windows::Forms::Label^ phoneLb;
	private: System::Windows::Forms::Label^ birthDateLb;
	private: System::Windows::Forms::DateTimePicker^ birthDatePicker;
	private: System::Windows::Forms::Button^ nextBtn;
	private: System::Windows::Forms::TextBox^ phoneInput;
	private: System::Windows::Forms::TextBox^ cardIDInput;
	private: System::Windows::Forms::TextBox^ peselInput;
	private: System::Windows::Forms::TextBox^ retypedPasswordInput;
	private: System::Windows::Forms::TextBox^ passwordInput;
	private: System::Windows::Forms::TextBox^ emailInput;
	private: System::Windows::Forms::Label^ helpPersonalLb;
	private: System::Windows::Forms::Label^ helpAccountLb;
	private: System::Windows::Forms::TextBox^ surnameInput;
	private: System::Windows::Forms::TextBox^ forenameInput;
	private: System::Windows::Forms::Label^ surnameLb;
	private: System::Windows::Forms::Label^ forenameLb;
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
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RegisterForm::typeid));
            this->haveAccountLink = (gcnew System::Windows::Forms::LinkLabel());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->helpPersonalLb = (gcnew System::Windows::Forms::Label());
            this->helpAccountLb = (gcnew System::Windows::Forms::Label());
            this->nextBtn = (gcnew System::Windows::Forms::Button());
            this->personalTableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->surnameInput = (gcnew System::Windows::Forms::TextBox());
            this->forenameInput = (gcnew System::Windows::Forms::TextBox());
            this->surnameLb = (gcnew System::Windows::Forms::Label());
            this->birthDateLb = (gcnew System::Windows::Forms::Label());
            this->birthDatePicker = (gcnew System::Windows::Forms::DateTimePicker());
            this->phoneLb = (gcnew System::Windows::Forms::Label());
            this->cardIDLb = (gcnew System::Windows::Forms::Label());
            this->peselLb = (gcnew System::Windows::Forms::Label());
            this->phoneInput = (gcnew System::Windows::Forms::TextBox());
            this->cardIDInput = (gcnew System::Windows::Forms::TextBox());
            this->peselInput = (gcnew System::Windows::Forms::TextBox());
            this->forenameLb = (gcnew System::Windows::Forms::Label());
            this->label14 = (gcnew System::Windows::Forms::Label());
            this->label13 = (gcnew System::Windows::Forms::Label());
            this->accountTableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->retypedPasswordInput = (gcnew System::Windows::Forms::TextBox());
            this->passwordInput = (gcnew System::Windows::Forms::TextBox());
            this->emailInput = (gcnew System::Windows::Forms::TextBox());
            this->usernameLb = (gcnew System::Windows::Forms::Label());
            this->emailLb = (gcnew System::Windows::Forms::Label());
            this->passwordLb = (gcnew System::Windows::Forms::Label());
            this->retypedPasswordLb = (gcnew System::Windows::Forms::Label());
            this->usernameInput = (gcnew System::Windows::Forms::TextBox());
            this->headerLb = (gcnew System::Windows::Forms::Label());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->logoLb = (gcnew System::Windows::Forms::Label());
            this->logoBox = (gcnew System::Windows::Forms::PictureBox());
            this->registerErrorLb = (gcnew System::Windows::Forms::Label());
            this->panel2->SuspendLayout();
            this->personalTableLayoutPanel->SuspendLayout();
            this->accountTableLayoutPanel->SuspendLayout();
            this->panel1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logoBox))->BeginInit();
            this->SuspendLayout();
            // 
            // haveAccountLink
            // 
            this->haveAccountLink->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
            this->haveAccountLink->AutoSize = true;
            this->haveAccountLink->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->haveAccountLink->Location = System::Drawing::Point(1399, 856);
            this->haveAccountLink->Name = L"haveAccountLink";
            this->haveAccountLink->Size = System::Drawing::Size(167, 29);
            this->haveAccountLink->TabIndex = 12;
            this->haveAccountLink->TabStop = true;
            this->haveAccountLink->Text = L"Mam ju¿ konto";
            this->haveAccountLink->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &RegisterForm::noAccountLink_LinkClicked);
            // 
            // panel2
            // 
            this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->panel2->Controls->Add(this->helpPersonalLb);
            this->panel2->Controls->Add(this->helpAccountLb);
            this->panel2->Controls->Add(this->nextBtn);
            this->panel2->Controls->Add(this->personalTableLayoutPanel);
            this->panel2->Controls->Add(this->label14);
            this->panel2->Controls->Add(this->label13);
            this->panel2->Controls->Add(this->accountTableLayoutPanel);
            this->panel2->Controls->Add(this->headerLb);
            this->panel2->Location = System::Drawing::Point(0, 120);
            this->panel2->Name = L"panel2";
            this->panel2->Padding = System::Windows::Forms::Padding(10);
            this->panel2->Size = System::Drawing::Size(1578, 599);
            this->panel2->TabIndex = 6;
            this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &RegisterForm::panel2_Paint);
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
            // helpAccountLb
            // 
            this->helpAccountLb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->helpAccountLb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->helpAccountLb->Location = System::Drawing::Point(793, 121);
            this->helpAccountLb->Name = L"helpAccountLb";
            this->helpAccountLb->Size = System::Drawing::Size(785, 58);
            this->helpAccountLb->TabIndex = 10;
            this->helpAccountLb->Text = L"Dane konta:";
            this->helpAccountLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
            this->nextBtn->Location = System::Drawing::Point(1404, 492);
            this->nextBtn->Name = L"nextBtn";
            this->nextBtn->Size = System::Drawing::Size(147, 60);
            this->nextBtn->TabIndex = 11;
            this->nextBtn->Text = L"Dalej";
            this->nextBtn->UseVisualStyleBackColor = false;
            this->nextBtn->Click += gcnew System::EventHandler(this, &RegisterForm::nextBtn_Click);
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
            this->personalTableLayoutPanel->Controls->Add(this->surnameLb, 0, 1);
            this->personalTableLayoutPanel->Controls->Add(this->birthDateLb, 0, 5);
            this->personalTableLayoutPanel->Controls->Add(this->birthDatePicker, 1, 5);
            this->personalTableLayoutPanel->Controls->Add(this->phoneLb, 0, 4);
            this->personalTableLayoutPanel->Controls->Add(this->cardIDLb, 0, 3);
            this->personalTableLayoutPanel->Controls->Add(this->peselLb, 0, 2);
            this->personalTableLayoutPanel->Controls->Add(this->phoneInput, 1, 4);
            this->personalTableLayoutPanel->Controls->Add(this->cardIDInput, 1, 3);
            this->personalTableLayoutPanel->Controls->Add(this->peselInput, 1, 2);
            this->personalTableLayoutPanel->Controls->Add(this->forenameLb, 0, 0);
            this->personalTableLayoutPanel->Location = System::Drawing::Point(0, 182);
            this->personalTableLayoutPanel->Name = L"personalTableLayoutPanel";
            this->personalTableLayoutPanel->RowCount = 6;
            this->personalTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                65)));
            this->personalTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                65)));
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
            this->personalTableLayoutPanel->Size = System::Drawing::Size(787, 387);
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
            // birthDateLb
            // 
            this->birthDateLb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->birthDateLb->AutoSize = true;
            this->birthDateLb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->birthDateLb->Location = System::Drawing::Point(3, 325);
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
            this->birthDatePicker->Location = System::Drawing::Point(364, 335);
            this->birthDatePicker->Margin = System::Windows::Forms::Padding(10);
            this->birthDatePicker->MaxDate = System::DateTime(2022, 12, 1, 0, 0, 0, 0);
            this->birthDatePicker->MinimumSize = System::Drawing::Size(4, 35);
            this->birthDatePicker->Name = L"birthDatePicker";
            this->birthDatePicker->Size = System::Drawing::Size(413, 35);
            this->birthDatePicker->TabIndex = 6;
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
            this->phoneLb->Location = System::Drawing::Point(3, 260);
            this->phoneLb->Name = L"phoneLb";
            this->phoneLb->Size = System::Drawing::Size(348, 65);
            this->phoneLb->TabIndex = 2;
            this->phoneLb->Text = L"Nr telefonu:";
            this->phoneLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // cardIDLb
            // 
            this->cardIDLb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->cardIDLb->AutoSize = true;
            this->cardIDLb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->cardIDLb->Location = System::Drawing::Point(3, 195);
            this->cardIDLb->Name = L"cardIDLb";
            this->cardIDLb->Size = System::Drawing::Size(348, 65);
            this->cardIDLb->TabIndex = 1;
            this->cardIDLb->Text = L"Numer dowodu os.:";
            this->cardIDLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // peselLb
            // 
            this->peselLb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->peselLb->AutoSize = true;
            this->peselLb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->peselLb->Location = System::Drawing::Point(3, 130);
            this->peselLb->Name = L"peselLb";
            this->peselLb->Size = System::Drawing::Size(348, 65);
            this->peselLb->TabIndex = 0;
            this->peselLb->Text = L"Pesel:";
            this->peselLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // phoneInput
            // 
            this->phoneInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->phoneInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->phoneInput->Location = System::Drawing::Point(364, 270);
            this->phoneInput->Margin = System::Windows::Forms::Padding(10);
            this->phoneInput->MaxLength = 9;
            this->phoneInput->MinimumSize = System::Drawing::Size(4, 35);
            this->phoneInput->Name = L"phoneInput";
            this->phoneInput->Size = System::Drawing::Size(413, 39);
            this->phoneInput->TabIndex = 5;
            // 
            // cardIDInput
            // 
            this->cardIDInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->cardIDInput->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
            this->cardIDInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->cardIDInput->Location = System::Drawing::Point(364, 205);
            this->cardIDInput->Margin = System::Windows::Forms::Padding(10);
            this->cardIDInput->MaxLength = 9;
            this->cardIDInput->MinimumSize = System::Drawing::Size(4, 35);
            this->cardIDInput->Name = L"cardIDInput";
            this->cardIDInput->Size = System::Drawing::Size(413, 39);
            this->cardIDInput->TabIndex = 4;
            // 
            // peselInput
            // 
            this->peselInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->peselInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->peselInput->Location = System::Drawing::Point(364, 140);
            this->peselInput->Margin = System::Windows::Forms::Padding(10);
            this->peselInput->MaxLength = 11;
            this->peselInput->MinimumSize = System::Drawing::Size(4, 35);
            this->peselInput->Name = L"peselInput";
            this->peselInput->Size = System::Drawing::Size(413, 39);
            this->peselInput->TabIndex = 3;
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
            this->forenameLb->Text = L"Imiê:";
            this->forenameLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // label14
            // 
            this->label14->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->label14->Location = System::Drawing::Point(764, 124);
            this->label14->Name = L"label14";
            this->label14->Size = System::Drawing::Size(744, 0);
            this->label14->TabIndex = 5;
            this->label14->Text = L"Dane osobowe:";
            this->label14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // label13
            // 
            this->label13->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left));
            this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->label13->Location = System::Drawing::Point(19, 124);
            this->label13->Name = L"label13";
            this->label13->Size = System::Drawing::Size(744, 0);
            this->label13->TabIndex = 4;
            this->label13->Text = L"Dane konta:";
            this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // accountTableLayoutPanel
            // 
            this->accountTableLayoutPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->accountTableLayoutPanel->ColumnCount = 2;
            this->accountTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                45)));
            this->accountTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                55)));
            this->accountTableLayoutPanel->Controls->Add(this->retypedPasswordInput, 1, 3);
            this->accountTableLayoutPanel->Controls->Add(this->passwordInput, 1, 2);
            this->accountTableLayoutPanel->Controls->Add(this->emailInput, 1, 1);
            this->accountTableLayoutPanel->Controls->Add(this->usernameLb, 0, 0);
            this->accountTableLayoutPanel->Controls->Add(this->emailLb, 0, 1);
            this->accountTableLayoutPanel->Controls->Add(this->passwordLb, 0, 2);
            this->accountTableLayoutPanel->Controls->Add(this->retypedPasswordLb, 0, 3);
            this->accountTableLayoutPanel->Controls->Add(this->usernameInput, 1, 0);
            this->accountTableLayoutPanel->Location = System::Drawing::Point(793, 182);
            this->accountTableLayoutPanel->Margin = System::Windows::Forms::Padding(3, 3, 10, 3);
            this->accountTableLayoutPanel->Name = L"accountTableLayoutPanel";
            this->accountTableLayoutPanel->RowCount = 4;
            this->accountTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                65)));
            this->accountTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                65)));
            this->accountTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                65)));
            this->accountTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                65)));
            this->accountTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
                20)));
            this->accountTableLayoutPanel->Size = System::Drawing::Size(787, 260);
            this->accountTableLayoutPanel->TabIndex = 0;
            // 
            // retypedPasswordInput
            // 
            this->retypedPasswordInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->retypedPasswordInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
            this->retypedPasswordInput->Location = System::Drawing::Point(364, 205);
            this->retypedPasswordInput->Margin = System::Windows::Forms::Padding(10);
            this->retypedPasswordInput->MaxLength = 16;
            this->retypedPasswordInput->MinimumSize = System::Drawing::Size(4, 35);
            this->retypedPasswordInput->Name = L"retypedPasswordInput";
            this->retypedPasswordInput->Size = System::Drawing::Size(413, 39);
            this->retypedPasswordInput->TabIndex = 10;
            this->retypedPasswordInput->UseSystemPasswordChar = true;
            // 
            // passwordInput
            // 
            this->passwordInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->passwordInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->passwordInput->Location = System::Drawing::Point(364, 140);
            this->passwordInput->Margin = System::Windows::Forms::Padding(10);
            this->passwordInput->MaxLength = 16;
            this->passwordInput->MinimumSize = System::Drawing::Size(4, 35);
            this->passwordInput->Name = L"passwordInput";
            this->passwordInput->Size = System::Drawing::Size(413, 39);
            this->passwordInput->TabIndex = 9;
            this->passwordInput->UseSystemPasswordChar = true;
            // 
            // emailInput
            // 
            this->emailInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->emailInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->emailInput->Location = System::Drawing::Point(364, 75);
            this->emailInput->Margin = System::Windows::Forms::Padding(10);
            this->emailInput->MinimumSize = System::Drawing::Size(4, 35);
            this->emailInput->Name = L"emailInput";
            this->emailInput->Size = System::Drawing::Size(413, 39);
            this->emailInput->TabIndex = 8;
            // 
            // usernameLb
            // 
            this->usernameLb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->usernameLb->AutoSize = true;
            this->usernameLb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->usernameLb->Location = System::Drawing::Point(3, 0);
            this->usernameLb->Name = L"usernameLb";
            this->usernameLb->Size = System::Drawing::Size(348, 65);
            this->usernameLb->TabIndex = 0;
            this->usernameLb->Text = L"Nazwa u¿ytkownika:";
            this->usernameLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // emailLb
            // 
            this->emailLb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->emailLb->AutoSize = true;
            this->emailLb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->emailLb->Location = System::Drawing::Point(3, 65);
            this->emailLb->Name = L"emailLb";
            this->emailLb->Size = System::Drawing::Size(348, 65);
            this->emailLb->TabIndex = 1;
            this->emailLb->Text = L"E-Mail:";
            this->emailLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // passwordLb
            // 
            this->passwordLb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->passwordLb->AutoSize = true;
            this->passwordLb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->passwordLb->Location = System::Drawing::Point(3, 130);
            this->passwordLb->Name = L"passwordLb";
            this->passwordLb->Size = System::Drawing::Size(348, 65);
            this->passwordLb->TabIndex = 3;
            this->passwordLb->Text = L"Has³o:";
            this->passwordLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // retypedPasswordLb
            // 
            this->retypedPasswordLb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->retypedPasswordLb->AutoSize = true;
            this->retypedPasswordLb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->retypedPasswordLb->Location = System::Drawing::Point(3, 195);
            this->retypedPasswordLb->Name = L"retypedPasswordLb";
            this->retypedPasswordLb->Size = System::Drawing::Size(348, 65);
            this->retypedPasswordLb->TabIndex = 4;
            this->retypedPasswordLb->Text = L"Powtórz has³o:";
            this->retypedPasswordLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // usernameInput
            // 
            this->usernameInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->usernameInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->usernameInput->Location = System::Drawing::Point(364, 10);
            this->usernameInput->Margin = System::Windows::Forms::Padding(10);
            this->usernameInput->MaxLength = 32;
            this->usernameInput->MinimumSize = System::Drawing::Size(4, 35);
            this->usernameInput->Name = L"usernameInput";
            this->usernameInput->Size = System::Drawing::Size(413, 39);
            this->usernameInput->TabIndex = 7;
            // 
            // headerLb
            // 
            this->headerLb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->headerLb->Location = System::Drawing::Point(12, 3);
            this->headerLb->Name = L"headerLb";
            this->headerLb->Size = System::Drawing::Size(754, 98);
            this->headerLb->TabIndex = 0;
            this->headerLb->Text = L"Utwórz nowe konto";
            this->headerLb->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // panel1
            // 
            this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(221)));
            this->panel1->Controls->Add(this->logoLb);
            this->panel1->Controls->Add(this->logoBox);
            this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
            this->panel1->Location = System::Drawing::Point(0, 0);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(1578, 120);
            this->panel1->TabIndex = 5;
            this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &RegisterForm::panel1_Paint);
            // 
            // logoLb
            // 
            this->logoLb->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 26, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->logoLb->Location = System::Drawing::Point(154, 9);
            this->logoLb->Name = L"logoLb";
            this->logoLb->Size = System::Drawing::Size(468, 102);
            this->logoLb->TabIndex = 2;
            this->logoLb->Text = L"AGH Bank";
            this->logoLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // logoBox
            // 
            this->logoBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logoBox.Image")));
            this->logoBox->Location = System::Drawing::Point(0, 0);
            this->logoBox->Name = L"logoBox";
            this->logoBox->Size = System::Drawing::Size(148, 120);
            this->logoBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->logoBox->TabIndex = 0;
            this->logoBox->TabStop = false;
            // 
            // registerErrorLb
            // 
            this->registerErrorLb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->registerErrorLb->Font = (gcnew System::Drawing::Font(L"Impact", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->registerErrorLb->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(193)), static_cast<System::Int32>(static_cast<System::Byte>(13)),
                static_cast<System::Int32>(static_cast<System::Byte>(20)));
            this->registerErrorLb->Location = System::Drawing::Point(0, 722);
            this->registerErrorLb->Name = L"registerErrorLb";
            this->registerErrorLb->Size = System::Drawing::Size(1578, 134);
            this->registerErrorLb->TabIndex = 8;
            this->registerErrorLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // RegisterForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1578, 894);
            this->Controls->Add(this->registerErrorLb);
            this->Controls->Add(this->haveAccountLink);
            this->Controls->Add(this->panel2);
            this->Controls->Add(this->panel1);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->MinimumSize = System::Drawing::Size(1600, 950);
            this->Name = L"RegisterForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"AGH Bank - Rejestracja";
            this->Load += gcnew System::EventHandler(this, &RegisterForm::RegisterForm_Load);
            this->panel2->ResumeLayout(false);
            this->personalTableLayoutPanel->ResumeLayout(false);
            this->personalTableLayoutPanel->PerformLayout();
            this->accountTableLayoutPanel->ResumeLayout(false);
            this->accountTableLayoutPanel->PerformLayout();
            this->panel1->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logoBox))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
	public:
		bool switchToLogin = false;
	private: System::Void RegisterForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void noAccountLink_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
	private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {};
	private: System::Void nextBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {};
	private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {};
	};
}