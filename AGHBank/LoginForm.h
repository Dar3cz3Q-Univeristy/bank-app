#pragma once

#include "User.h"

namespace AGHBank {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
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
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::PictureBox^ logoBox;
	private: System::Windows::Forms::Label^ logoLb;
	private: System::Windows::Forms::Label^ headerLb;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ helpLb;
	private: System::Windows::Forms::Button^ nextBtn;
	private: System::Windows::Forms::TextBox^ loginInput;
	private: System::Windows::Forms::LinkLabel^ noAccountLink;
	private: System::Windows::Forms::Label^ loginErrorLb;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->logoLb = (gcnew System::Windows::Forms::Label());
			this->logoBox = (gcnew System::Windows::Forms::PictureBox());
			this->headerLb = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->helpLb = (gcnew System::Windows::Forms::Label());
			this->nextBtn = (gcnew System::Windows::Forms::Button());
			this->loginInput = (gcnew System::Windows::Forms::TextBox());
			this->noAccountLink = (gcnew System::Windows::Forms::LinkLabel());
			this->loginErrorLb = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logoBox))->BeginInit();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
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
			this->panel1->TabIndex = 0;
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
			// headerLb
			// 
			this->headerLb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->headerLb->Location = System::Drawing::Point(12, 3);
			this->headerLb->Name = L"headerLb";
			this->headerLb->Size = System::Drawing::Size(754, 98);
			this->headerLb->TabIndex = 0;
			this->headerLb->Text = L"Zaloguj siê";
			this->headerLb->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->helpLb);
			this->panel2->Controls->Add(this->nextBtn);
			this->panel2->Controls->Add(this->loginInput);
			this->panel2->Controls->Add(this->headerLb);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 120);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(778, 353);
			this->panel2->TabIndex = 2;
			// 
			// helpLb
			// 
			this->helpLb->AutoSize = true;
			this->helpLb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->helpLb->Location = System::Drawing::Point(12, 181);
			this->helpLb->Name = L"helpLb";
			this->helpLb->Size = System::Drawing::Size(398, 37);
			this->helpLb->TabIndex = 0;
			this->helpLb->Text = L"Wpisz nazwê u¿ytkownika:";
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
			this->nextBtn->Click += gcnew System::EventHandler(this, &LoginForm::nextBtn_Click);
			// 
			// loginInput
			// 
			this->loginInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->loginInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->loginInput->Location = System::Drawing::Point(19, 221);
			this->loginInput->Name = L"loginInput";
			this->loginInput->Size = System::Drawing::Size(747, 44);
			this->loginInput->TabIndex = 1;
			this->loginInput->Text = L"Dar3cz3Q";
			// 
			// noAccountLink
			// 
			this->noAccountLink->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->noAccountLink->AutoSize = true;
			this->noAccountLink->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->noAccountLink->Location = System::Drawing::Point(577, 656);
			this->noAccountLink->Name = L"noAccountLink";
			this->noAccountLink->Size = System::Drawing::Size(189, 29);
			this->noAccountLink->TabIndex = 3;
			this->noAccountLink->TabStop = true;
			this->noAccountLink->Text = L"Nie masz konta\?";
			this->noAccountLink->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &LoginForm::noAccountLink_LinkClicked);
			// 
			// loginErrorLb
			// 
			this->loginErrorLb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->loginErrorLb->Font = (gcnew System::Drawing::Font(L"Impact", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->loginErrorLb->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(193)), static_cast<System::Int32>(static_cast<System::Byte>(13)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->loginErrorLb->Location = System::Drawing::Point(0, 476);
			this->loginErrorLb->Name = L"loginErrorLb";
			this->loginErrorLb->Size = System::Drawing::Size(778, 158);
			this->loginErrorLb->TabIndex = 0;
			this->loginErrorLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(778, 694);
			this->Controls->Add(this->loginErrorLb);
			this->Controls->Add(this->noAccountLink);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(800, 750);
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AGH Bank - Logowanie";
			this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logoBox))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	public:
		User^ person = nullptr;
		bool switchToRegister = false;
	private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {};
	private: System::Void nextBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void noAccountLink_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
	};
}