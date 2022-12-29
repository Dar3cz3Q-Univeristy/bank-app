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
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::Label^ UserNameLb;
	private: System::Windows::Forms::Panel^ PanelContainer;
	private: System::Windows::Forms::Button^ PaymentBtn;
	public:

	public:
		int loggedUserID;
		MainForm(int id)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ AccountBtn;
	private: System::Windows::Forms::Button^ BillBtn;
	private: System::Windows::Forms::Button^ ContractorsBtn;
	private: System::Windows::Forms::Button^ CardsBtn;
	private: System::Windows::Forms::Button^ TransferBtn;
	private: System::Windows::Forms::Label^ BankLogoLb;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->UserNameLb = (gcnew System::Windows::Forms::Label());
			this->BankLogoLb = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->PaymentBtn = (gcnew System::Windows::Forms::Button());
			this->TransferBtn = (gcnew System::Windows::Forms::Button());
			this->ContractorsBtn = (gcnew System::Windows::Forms::Button());
			this->CardsBtn = (gcnew System::Windows::Forms::Button());
			this->BillBtn = (gcnew System::Windows::Forms::Button());
			this->AccountBtn = (gcnew System::Windows::Forms::Button());
			this->PanelContainer = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(221)));
			this->panel1->Controls->Add(this->UserNameLb);
			this->panel1->Controls->Add(this->BankLogoLb);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Padding = System::Windows::Forms::Padding(50, 20, 50, 20);
			this->panel1->Size = System::Drawing::Size(1578, 120);
			this->panel1->TabIndex = 0;
			// 
			// UserNameLb
			// 
			this->UserNameLb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->UserNameLb->Font = (gcnew System::Drawing::Font(L"Calibri", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UserNameLb->Location = System::Drawing::Point(1061, 40);
			this->UserNameLb->Name = L"UserNameLb";
			this->UserNameLb->Size = System::Drawing::Size(464, 49);
			this->UserNameLb->TabIndex = 0;
			this->UserNameLb->Text = L"$user$";
			this->UserNameLb->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// BankLogoLb
			// 
			this->BankLogoLb->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 26, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BankLogoLb->Location = System::Drawing::Point(137, 9);
			this->BankLogoLb->Name = L"BankLogoLb";
			this->BankLogoLb->Size = System::Drawing::Size(468, 102);
			this->BankLogoLb->TabIndex = 1;
			this->BankLogoLb->Text = L"AGH Bank";
			this->BankLogoLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(131, 120);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(221)));
			this->panel2->Controls->Add(this->PaymentBtn);
			this->panel2->Controls->Add(this->TransferBtn);
			this->panel2->Controls->Add(this->ContractorsBtn);
			this->panel2->Controls->Add(this->CardsBtn);
			this->panel2->Controls->Add(this->BillBtn);
			this->panel2->Controls->Add(this->AccountBtn);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 120);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1578, 71);
			this->panel2->TabIndex = 1;
			// 
			// PaymentBtn
			// 
			this->PaymentBtn->BackColor = System::Drawing::Color::Transparent;
			this->PaymentBtn->Dock = System::Windows::Forms::DockStyle::Left;
			this->PaymentBtn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->PaymentBtn->FlatAppearance->BorderSize = 0;
			this->PaymentBtn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->PaymentBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->PaymentBtn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->PaymentBtn->Location = System::Drawing::Point(1315, 0);
			this->PaymentBtn->Name = L"PaymentBtn";
			this->PaymentBtn->Size = System::Drawing::Size(263, 71);
			this->PaymentBtn->TabIndex = 6;
			this->PaymentBtn->Text = L"Wp³ata/Wyp³ata";
			this->PaymentBtn->UseVisualStyleBackColor = false;
			this->PaymentBtn->Click += gcnew System::EventHandler(this, &MainForm::PaymentBtn_Click);
			// 
			// TransferBtn
			// 
			this->TransferBtn->BackColor = System::Drawing::Color::Transparent;
			this->TransferBtn->Dock = System::Windows::Forms::DockStyle::Left;
			this->TransferBtn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->TransferBtn->FlatAppearance->BorderSize = 0;
			this->TransferBtn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->TransferBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->TransferBtn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->TransferBtn->Location = System::Drawing::Point(1052, 0);
			this->TransferBtn->Name = L"TransferBtn";
			this->TransferBtn->Size = System::Drawing::Size(263, 71);
			this->TransferBtn->TabIndex = 5;
			this->TransferBtn->Text = L"Wykonaj przelew";
			this->TransferBtn->UseVisualStyleBackColor = false;
			// 
			// ContractorsBtn
			// 
			this->ContractorsBtn->BackColor = System::Drawing::Color::Transparent;
			this->ContractorsBtn->Dock = System::Windows::Forms::DockStyle::Left;
			this->ContractorsBtn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ContractorsBtn->FlatAppearance->BorderSize = 0;
			this->ContractorsBtn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->ContractorsBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ContractorsBtn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->ContractorsBtn->Location = System::Drawing::Point(789, 0);
			this->ContractorsBtn->Name = L"ContractorsBtn";
			this->ContractorsBtn->Size = System::Drawing::Size(263, 71);
			this->ContractorsBtn->TabIndex = 4;
			this->ContractorsBtn->Text = L"Kontrahenci";
			this->ContractorsBtn->UseVisualStyleBackColor = false;
			this->ContractorsBtn->Click += gcnew System::EventHandler(this, &MainForm::ContractorsBtn_Click);
			// 
			// CardsBtn
			// 
			this->CardsBtn->BackColor = System::Drawing::Color::Transparent;
			this->CardsBtn->Dock = System::Windows::Forms::DockStyle::Left;
			this->CardsBtn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->CardsBtn->FlatAppearance->BorderSize = 0;
			this->CardsBtn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->CardsBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CardsBtn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->CardsBtn->Location = System::Drawing::Point(526, 0);
			this->CardsBtn->Name = L"CardsBtn";
			this->CardsBtn->Size = System::Drawing::Size(263, 71);
			this->CardsBtn->TabIndex = 3;
			this->CardsBtn->Text = L"Karty";
			this->CardsBtn->UseVisualStyleBackColor = false;
			// 
			// BillBtn
			// 
			this->BillBtn->BackColor = System::Drawing::Color::Transparent;
			this->BillBtn->Dock = System::Windows::Forms::DockStyle::Left;
			this->BillBtn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->BillBtn->FlatAppearance->BorderSize = 0;
			this->BillBtn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->BillBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BillBtn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->BillBtn->Location = System::Drawing::Point(263, 0);
			this->BillBtn->Name = L"BillBtn";
			this->BillBtn->Size = System::Drawing::Size(263, 71);
			this->BillBtn->TabIndex = 2;
			this->BillBtn->Text = L"Rachunki";
			this->BillBtn->UseVisualStyleBackColor = false;
			this->BillBtn->Click += gcnew System::EventHandler(this, &MainForm::BillBtn_Click);
			// 
			// AccountBtn
			// 
			this->AccountBtn->BackColor = System::Drawing::Color::Transparent;
			this->AccountBtn->Dock = System::Windows::Forms::DockStyle::Left;
			this->AccountBtn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->AccountBtn->FlatAppearance->BorderSize = 0;
			this->AccountBtn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->AccountBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->AccountBtn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->AccountBtn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(193)), static_cast<System::Int32>(static_cast<System::Byte>(13)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->AccountBtn->Location = System::Drawing::Point(0, 0);
			this->AccountBtn->Name = L"AccountBtn";
			this->AccountBtn->Size = System::Drawing::Size(263, 71);
			this->AccountBtn->TabIndex = 1;
			this->AccountBtn->Text = L"Konto";
			this->AccountBtn->UseVisualStyleBackColor = false;
			this->AccountBtn->Click += gcnew System::EventHandler(this, &MainForm::AccountBtn_Click);
			// 
			// PanelContainer
			// 
			this->PanelContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PanelContainer->Location = System::Drawing::Point(0, 191);
			this->PanelContainer->Name = L"PanelContainer";
			this->PanelContainer->Size = System::Drawing::Size(1578, 703);
			this->PanelContainer->TabIndex = 2;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(1578, 894);
			this->Controls->Add(this->PanelContainer);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AGH Bank";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	public:
		void resetColorsBtns(void);
	private:
		void addUserControl(UserControl^ userControl);
		void downloadBasicData(void);
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AccountBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ContractorsBtn_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void BillBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void PaymentBtn_Click(System::Object^ sender, System::EventArgs^ e);
};
}
