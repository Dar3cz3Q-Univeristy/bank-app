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
	/// Summary for PasswordForm
	/// </summary>
	public ref class PasswordForm : public System::Windows::Forms::Form
	{
	public:
		String^ loggingUsername;
		PasswordForm(String^ name)
		{
			InitializeComponent();
			loggingUsername = name;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PasswordForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ passwordErrorLb;
	private: System::Windows::Forms::LinkLabel^ restorePasswordLink;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ helpLb;
	private: System::Windows::Forms::Button^ nextBtn;
	private: System::Windows::Forms::TextBox^ passwordInput;
	private: System::Windows::Forms::Label^ greetingLb;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ logoLb;
	private: System::Windows::Forms::PictureBox^ logoBox;
	private: System::Windows::Forms::LinkLabel^ backLink;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PasswordForm::typeid));
			this->passwordErrorLb = (gcnew System::Windows::Forms::Label());
			this->restorePasswordLink = (gcnew System::Windows::Forms::LinkLabel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->helpLb = (gcnew System::Windows::Forms::Label());
			this->nextBtn = (gcnew System::Windows::Forms::Button());
			this->passwordInput = (gcnew System::Windows::Forms::TextBox());
			this->greetingLb = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->logoLb = (gcnew System::Windows::Forms::Label());
			this->logoBox = (gcnew System::Windows::Forms::PictureBox());
			this->backLink = (gcnew System::Windows::Forms::LinkLabel());
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logoBox))->BeginInit();
			this->SuspendLayout();
			// 
			// passwordErrorLb
			// 
			this->passwordErrorLb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->passwordErrorLb->Font = (gcnew System::Drawing::Font(L"Impact", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->passwordErrorLb->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(193)), static_cast<System::Int32>(static_cast<System::Byte>(13)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->passwordErrorLb->Location = System::Drawing::Point(0, 476);
			this->passwordErrorLb->Name = L"passwordErrorLb";
			this->passwordErrorLb->Size = System::Drawing::Size(778, 158);
			this->passwordErrorLb->TabIndex = 0;
			this->passwordErrorLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// restorePasswordLink
			// 
			this->restorePasswordLink->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->restorePasswordLink->AutoSize = true;
			this->restorePasswordLink->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->restorePasswordLink->Location = System::Drawing::Point(577, 650);
			this->restorePasswordLink->Name = L"restorePasswordLink";
			this->restorePasswordLink->Size = System::Drawing::Size(0, 29);
			this->restorePasswordLink->TabIndex = 4;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->helpLb);
			this->panel2->Controls->Add(this->nextBtn);
			this->panel2->Controls->Add(this->passwordInput);
			this->panel2->Controls->Add(this->greetingLb);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 120);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(778, 353);
			this->panel2->TabIndex = 6;
			// 
			// helpLb
			// 
			this->helpLb->AutoSize = true;
			this->helpLb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->helpLb->Location = System::Drawing::Point(12, 181);
			this->helpLb->Name = L"helpLb";
			this->helpLb->Size = System::Drawing::Size(206, 37);
			this->helpLb->TabIndex = 0;
			this->helpLb->Text = L"Wpisz has³o:";
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
			this->nextBtn->Location = System::Drawing::Point(619, 286);
			this->nextBtn->Name = L"nextBtn";
			this->nextBtn->Size = System::Drawing::Size(147, 60);
			this->nextBtn->TabIndex = 2;
			this->nextBtn->Text = L"Dalej";
			this->nextBtn->UseVisualStyleBackColor = false;
			this->nextBtn->Click += gcnew System::EventHandler(this, &PasswordForm::nextBtn_Click);
			// 
			// passwordInput
			// 
			this->passwordInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->passwordInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->passwordInput->Location = System::Drawing::Point(19, 221);
			this->passwordInput->Name = L"passwordInput";
			this->passwordInput->Size = System::Drawing::Size(747, 44);
			this->passwordInput->TabIndex = 1;
			this->passwordInput->Text = L"zaq1@WSX";
			this->passwordInput->UseSystemPasswordChar = true;
			// 
			// greetingLb
			// 
			this->greetingLb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->greetingLb->Location = System::Drawing::Point(12, 3);
			this->greetingLb->Name = L"greetingLb";
			this->greetingLb->Size = System::Drawing::Size(754, 98);
			this->greetingLb->TabIndex = 0;
			this->greetingLb->Text = L"Zaloguj siê";
			this->greetingLb->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
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
			this->panel1->Size = System::Drawing::Size(778, 120);
			this->panel1->TabIndex = 5;
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
			// backLink
			// 
			this->backLink->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->backLink->AutoSize = true;
			this->backLink->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->backLink->Location = System::Drawing::Point(14, 650);
			this->backLink->Name = L"backLink";
			this->backLink->Size = System::Drawing::Size(89, 29);
			this->backLink->TabIndex = 3;
			this->backLink->TabStop = true;
			this->backLink->Text = L"Powrót";
			this->backLink->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &PasswordForm::backLink_LinkClicked);
			// 
			// PasswordForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(778, 694);
			this->Controls->Add(this->backLink);
			this->Controls->Add(this->passwordErrorLb);
			this->Controls->Add(this->restorePasswordLink);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(800, 750);
			this->Name = L"PasswordForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AGH Bank - Logowanie";
			this->Load += gcnew System::EventHandler(this, &PasswordForm::PasswordForm_Load);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logoBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		bool auth = false;
		bool switchToLogin = false;
	private: System::Void PasswordForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nextBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void backLink_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
	};
}
