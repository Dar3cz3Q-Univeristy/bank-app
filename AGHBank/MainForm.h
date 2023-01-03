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
	private: System::Windows::Forms::Label^ userNameLb;
	private: System::Windows::Forms::Panel^ PanelContainer;
	private: System::Windows::Forms::Button^ paymentBtn;
	public:
		int loggedUserID;
		String^ loggedUserName;
		MainForm(int id, String^ name)
		{
			InitializeComponent();
			loggedUserName = name;
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
	private: System::Windows::Forms::Button^ accountBtn;
	private: System::Windows::Forms::Button^ billBtn;
	private: System::Windows::Forms::Button^ contractorsBtn;
	private: System::Windows::Forms::Button^ settingsBtn;
	private: System::Windows::Forms::Button^ transferBtn;
	private: System::Windows::Forms::Label^ bankLogoLb;
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
			this->userNameLb = (gcnew System::Windows::Forms::Label());
			this->bankLogoLb = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->settingsBtn = (gcnew System::Windows::Forms::Button());
			this->paymentBtn = (gcnew System::Windows::Forms::Button());
			this->transferBtn = (gcnew System::Windows::Forms::Button());
			this->contractorsBtn = (gcnew System::Windows::Forms::Button());
			this->billBtn = (gcnew System::Windows::Forms::Button());
			this->accountBtn = (gcnew System::Windows::Forms::Button());
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
			this->panel1->Controls->Add(this->userNameLb);
			this->panel1->Controls->Add(this->bankLogoLb);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Padding = System::Windows::Forms::Padding(50, 20, 50, 20);
			this->panel1->Size = System::Drawing::Size(1578, 120);
			this->panel1->TabIndex = 0;
			// 
			// userNameLb
			// 
			this->userNameLb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->userNameLb->Font = (gcnew System::Drawing::Font(L"Calibri", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->userNameLb->Location = System::Drawing::Point(1061, 40);
			this->userNameLb->Name = L"userNameLb";
			this->userNameLb->Size = System::Drawing::Size(464, 49);
			this->userNameLb->TabIndex = 0;
			this->userNameLb->Text = L"$user$";
			this->userNameLb->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// bankLogoLb
			// 
			this->bankLogoLb->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 26, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bankLogoLb->Location = System::Drawing::Point(137, 9);
			this->bankLogoLb->Name = L"bankLogoLb";
			this->bankLogoLb->Size = System::Drawing::Size(468, 102);
			this->bankLogoLb->TabIndex = 1;
			this->bankLogoLb->Text = L"AGH Bank";
			this->bankLogoLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
			this->panel2->Controls->Add(this->settingsBtn);
			this->panel2->Controls->Add(this->paymentBtn);
			this->panel2->Controls->Add(this->transferBtn);
			this->panel2->Controls->Add(this->contractorsBtn);
			this->panel2->Controls->Add(this->billBtn);
			this->panel2->Controls->Add(this->accountBtn);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 120);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1578, 71);
			this->panel2->TabIndex = 1;
			// 
			// settingsBtn
			// 
			this->settingsBtn->BackColor = System::Drawing::Color::Transparent;
			this->settingsBtn->Dock = System::Windows::Forms::DockStyle::Left;
			this->settingsBtn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->settingsBtn->FlatAppearance->BorderSize = 0;
			this->settingsBtn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->settingsBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->settingsBtn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->settingsBtn->Location = System::Drawing::Point(1315, 0);
			this->settingsBtn->Name = L"settingsBtn";
			this->settingsBtn->Size = System::Drawing::Size(263, 71);
			this->settingsBtn->TabIndex = 3;
			this->settingsBtn->TabStop = false;
			this->settingsBtn->Text = L"Ustawienia";
			this->settingsBtn->UseVisualStyleBackColor = false;
			this->settingsBtn->Click += gcnew System::EventHandler(this, &MainForm::settingsBtn_Click);
			// 
			// paymentBtn
			// 
			this->paymentBtn->BackColor = System::Drawing::Color::Transparent;
			this->paymentBtn->Dock = System::Windows::Forms::DockStyle::Left;
			this->paymentBtn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->paymentBtn->FlatAppearance->BorderSize = 0;
			this->paymentBtn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->paymentBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->paymentBtn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->paymentBtn->Location = System::Drawing::Point(1052, 0);
			this->paymentBtn->Name = L"paymentBtn";
			this->paymentBtn->Size = System::Drawing::Size(263, 71);
			this->paymentBtn->TabIndex = 6;
			this->paymentBtn->TabStop = false;
			this->paymentBtn->Text = L"Bankomat";
			this->paymentBtn->UseVisualStyleBackColor = false;
			this->paymentBtn->Click += gcnew System::EventHandler(this, &MainForm::paymentBtn_Click);
			// 
			// transferBtn
			// 
			this->transferBtn->BackColor = System::Drawing::Color::Transparent;
			this->transferBtn->Dock = System::Windows::Forms::DockStyle::Left;
			this->transferBtn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->transferBtn->FlatAppearance->BorderSize = 0;
			this->transferBtn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->transferBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->transferBtn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->transferBtn->Location = System::Drawing::Point(789, 0);
			this->transferBtn->Name = L"transferBtn";
			this->transferBtn->Size = System::Drawing::Size(263, 71);
			this->transferBtn->TabIndex = 5;
			this->transferBtn->TabStop = false;
			this->transferBtn->Text = L"Wykonaj przelew";
			this->transferBtn->UseVisualStyleBackColor = false;
			this->transferBtn->Click += gcnew System::EventHandler(this, &MainForm::transferBtn_Click);
			// 
			// contractorsBtn
			// 
			this->contractorsBtn->BackColor = System::Drawing::Color::Transparent;
			this->contractorsBtn->Dock = System::Windows::Forms::DockStyle::Left;
			this->contractorsBtn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->contractorsBtn->FlatAppearance->BorderSize = 0;
			this->contractorsBtn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->contractorsBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->contractorsBtn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->contractorsBtn->Location = System::Drawing::Point(526, 0);
			this->contractorsBtn->Name = L"contractorsBtn";
			this->contractorsBtn->Size = System::Drawing::Size(263, 71);
			this->contractorsBtn->TabIndex = 4;
			this->contractorsBtn->TabStop = false;
			this->contractorsBtn->Text = L"Kontrahenci";
			this->contractorsBtn->UseVisualStyleBackColor = false;
			this->contractorsBtn->Click += gcnew System::EventHandler(this, &MainForm::contractorsBtn_Click);
			// 
			// billBtn
			// 
			this->billBtn->BackColor = System::Drawing::Color::Transparent;
			this->billBtn->Dock = System::Windows::Forms::DockStyle::Left;
			this->billBtn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->billBtn->FlatAppearance->BorderSize = 0;
			this->billBtn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->billBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->billBtn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->billBtn->Location = System::Drawing::Point(263, 0);
			this->billBtn->Name = L"billBtn";
			this->billBtn->Size = System::Drawing::Size(263, 71);
			this->billBtn->TabIndex = 2;
			this->billBtn->TabStop = false;
			this->billBtn->Text = L"Rachunki";
			this->billBtn->UseVisualStyleBackColor = false;
			this->billBtn->Click += gcnew System::EventHandler(this, &MainForm::billBtn_Click);
			// 
			// accountBtn
			// 
			this->accountBtn->BackColor = System::Drawing::Color::Transparent;
			this->accountBtn->Dock = System::Windows::Forms::DockStyle::Left;
			this->accountBtn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->accountBtn->FlatAppearance->BorderSize = 0;
			this->accountBtn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->accountBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->accountBtn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->accountBtn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(193)), static_cast<System::Int32>(static_cast<System::Byte>(13)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->accountBtn->Location = System::Drawing::Point(0, 0);
			this->accountBtn->Name = L"accountBtn";
			this->accountBtn->Size = System::Drawing::Size(263, 71);
			this->accountBtn->TabIndex = 1;
			this->accountBtn->TabStop = false;
			this->accountBtn->Text = L"Konto";
			this->accountBtn->UseVisualStyleBackColor = false;
			this->accountBtn->Click += gcnew System::EventHandler(this, &MainForm::accountBtn_Click);
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
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void accountBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void contractorsBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void billBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void paymentBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void transferBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void settingsBtn_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
