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
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ NextBtn;
	private: System::Windows::Forms::TextBox^ LoginInput;
	private: System::Windows::Forms::LinkLabel^ NoAccountLink;



	private: System::Windows::Forms::Label^ LoginErrorLb;

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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->NextBtn = (gcnew System::Windows::Forms::Button());
			this->LoginInput = (gcnew System::Windows::Forms::TextBox());
			this->NoAccountLink = (gcnew System::Windows::Forms::LinkLabel());
			this->LoginErrorLb = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(221)));
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(778, 120);
			this->panel1->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 26, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(154, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(468, 102);
			this->label2->TabIndex = 2;
			this->label2->Text = L"AGH Bank";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(148, 120);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(12, 3);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(754, 98);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Zaloguj siê";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->NextBtn);
			this->panel2->Controls->Add(this->LoginInput);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 120);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(778, 353);
			this->panel2->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(12, 181);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(444, 37);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Wpisz numer klienta lub login:";
			// 
			// NextBtn
			// 
			this->NextBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->NextBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(193)), static_cast<System::Int32>(static_cast<System::Byte>(13)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->NextBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->NextBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->NextBtn->ForeColor = System::Drawing::Color::White;
			this->NextBtn->Location = System::Drawing::Point(619, 286);
			this->NextBtn->Name = L"NextBtn";
			this->NextBtn->Size = System::Drawing::Size(147, 60);
			this->NextBtn->TabIndex = 2;
			this->NextBtn->Text = L"Dalej";
			this->NextBtn->UseVisualStyleBackColor = false;
			this->NextBtn->Click += gcnew System::EventHandler(this, &LoginForm::button1_Click);
			// 
			// LoginInput
			// 
			this->LoginInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->LoginInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->LoginInput->Location = System::Drawing::Point(19, 221);
			this->LoginInput->Name = L"LoginInput";
			this->LoginInput->Size = System::Drawing::Size(747, 44);
			this->LoginInput->TabIndex = 1;
			// 
			// NoAccountLink
			// 
			this->NoAccountLink->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->NoAccountLink->AutoSize = true;
			this->NoAccountLink->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->NoAccountLink->Location = System::Drawing::Point(577, 634);
			this->NoAccountLink->Name = L"NoAccountLink";
			this->NoAccountLink->Size = System::Drawing::Size(189, 29);
			this->NoAccountLink->TabIndex = 3;
			this->NoAccountLink->TabStop = true;
			this->NoAccountLink->Text = L"Nie masz konta\?";
			// 
			// LoginErrorLb
			// 
			this->LoginErrorLb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->LoginErrorLb->Font = (gcnew System::Drawing::Font(L"Impact", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->LoginErrorLb->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(193)), static_cast<System::Int32>(static_cast<System::Byte>(13)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->LoginErrorLb->Location = System::Drawing::Point(0, 476);
			this->LoginErrorLb->Name = L"LoginErrorLb";
			this->LoginErrorLb->Size = System::Drawing::Size(778, 158);
			this->LoginErrorLb->TabIndex = 0;
			this->LoginErrorLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(778, 694);
			this->Controls->Add(this->LoginErrorLb);
			this->Controls->Add(this->NoAccountLink);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->MinimumSize = System::Drawing::Size(800, 750);
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AGH Bank - Logowanie";
			this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	public:
		User^ user = nullptr;
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ Username = this->LoginInput->Text;
		this->LoginErrorLb->Text = "";
		if (Username->Length == 0) {
			this->LoginErrorLb->Text = "Nie wpisano loginu!";
			return;
		}
		try {
			String^ connString = "Data Source=Dar3cz3Q-SQL;Initial Catalog=AGHBank;User ID=sa;Password=zaq1@WSX";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			String^ sqlQuery = "SELECT Username FROM PersonLogins WHERE Login = @Username OR Username = @Username;";

			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@Username", Username);

			SqlDataReader^ reader = command.ExecuteReader();

			if (reader->Read()) {
				user = gcnew User;
				user->name = reader->GetString(0);
				this->Close();
			}
			else {
				user = nullptr;
				this->LoginErrorLb->Text = "Nie istnieje taki u¿ytkownik!";
			}
			reader->Close();
			sqlConn.Close();
		}
		catch (Exception^ e) {
			MessageBox::Show("Nie uda³o siê po³¹czyæ z baz¹ danych", "B³¹d po³¹czenia", MessageBoxButtons::OK);
		}
	}
	};
}
