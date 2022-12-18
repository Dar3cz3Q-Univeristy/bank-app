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
		String^ LoggingUsername;
		PasswordForm(String^ name)
		{
			InitializeComponent();
			LoggingUsername = name;
			GreetingLb->Text = "Witaj " + LoggingUsername + "!";
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
	private: System::Windows::Forms::Label^ PasswordErrorLb;
	protected:

	protected:
	private: System::Windows::Forms::LinkLabel^ RestorePasswordLink;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ NextBtn;
	private: System::Windows::Forms::TextBox^ PasswordInput;
	private: System::Windows::Forms::Label^ GreetingLb;


	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::LinkLabel^ BackLink;

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
			this->PasswordErrorLb = (gcnew System::Windows::Forms::Label());
			this->RestorePasswordLink = (gcnew System::Windows::Forms::LinkLabel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->NextBtn = (gcnew System::Windows::Forms::Button());
			this->PasswordInput = (gcnew System::Windows::Forms::TextBox());
			this->GreetingLb = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->BackLink = (gcnew System::Windows::Forms::LinkLabel());
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// PasswordErrorLb
			// 
			this->PasswordErrorLb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->PasswordErrorLb->Font = (gcnew System::Drawing::Font(L"Impact", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->PasswordErrorLb->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(193)), static_cast<System::Int32>(static_cast<System::Byte>(13)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->PasswordErrorLb->Location = System::Drawing::Point(0, 476);
			this->PasswordErrorLb->Name = L"PasswordErrorLb";
			this->PasswordErrorLb->Size = System::Drawing::Size(778, 158);
			this->PasswordErrorLb->TabIndex = 0;
			this->PasswordErrorLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// RestorePasswordLink
			// 
			this->RestorePasswordLink->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->RestorePasswordLink->AutoSize = true;
			this->RestorePasswordLink->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->RestorePasswordLink->Location = System::Drawing::Point(577, 650);
			this->RestorePasswordLink->Name = L"RestorePasswordLink";
			this->RestorePasswordLink->Size = System::Drawing::Size(178, 29);
			this->RestorePasswordLink->TabIndex = 4;
			this->RestorePasswordLink->TabStop = true;
			this->RestorePasswordLink->Text = L"Odzyskaj has³o";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->NextBtn);
			this->panel2->Controls->Add(this->PasswordInput);
			this->panel2->Controls->Add(this->GreetingLb);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 120);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(778, 353);
			this->panel2->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(12, 181);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(206, 37);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Wpisz has³o:";
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
			this->NextBtn->Click += gcnew System::EventHandler(this, &PasswordForm::NextBtn_Click);
			// 
			// PasswordInput
			// 
			this->PasswordInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->PasswordInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->PasswordInput->Location = System::Drawing::Point(19, 221);
			this->PasswordInput->Name = L"PasswordInput";
			this->PasswordInput->PasswordChar = '*';
			this->PasswordInput->Size = System::Drawing::Size(747, 44);
			this->PasswordInput->TabIndex = 1;
			// 
			// GreetingLb
			// 
			this->GreetingLb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->GreetingLb->Location = System::Drawing::Point(12, 3);
			this->GreetingLb->Name = L"GreetingLb";
			this->GreetingLb->Size = System::Drawing::Size(754, 98);
			this->GreetingLb->TabIndex = 0;
			this->GreetingLb->Text = L"Zaloguj siê";
			this->GreetingLb->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
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
			this->panel1->TabIndex = 5;
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
			// BackLink
			// 
			this->BackLink->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->BackLink->AutoSize = true;
			this->BackLink->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->BackLink->Location = System::Drawing::Point(14, 650);
			this->BackLink->Name = L"BackLink";
			this->BackLink->Size = System::Drawing::Size(89, 29);
			this->BackLink->TabIndex = 3;
			this->BackLink->TabStop = true;
			this->BackLink->Text = L"Powrót";
			// 
			// PasswordForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(778, 694);
			this->Controls->Add(this->BackLink);
			this->Controls->Add(this->PasswordErrorLb);
			this->Controls->Add(this->RestorePasswordLink);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->MinimumSize = System::Drawing::Size(800, 750);
			this->Name = L"PasswordForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AGH Bank - Logowanie";
			this->Load += gcnew System::EventHandler(this, &PasswordForm::PasswordForm_Load);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void PasswordForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	public:
		bool auth = false;
	private: System::Void NextBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ Password = this->PasswordInput->Text;
		if (Password->Length == 0) {
			this->PasswordErrorLb->Text = "Nie wpisano has³a!";
			return;
		}
		try {
			String^ connString = "Data Source=Dar3cz3Q-SQL;Initial Catalog=AGHBank;User ID=sa;Password=zaq1@WSX";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			String^ sqlQuery = "SELECT Username FROM PersonLogins WHERE Username = @Username AND Password = @Password;";

			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@Username", LoggingUsername);
			command.Parameters->AddWithValue("@Password", Password);

			SqlDataReader^ reader = command.ExecuteReader();

			if (reader->Read()) {
				auth = true;
				this->Close();
			}
			else {
				//user = nullptr;
				this->PasswordErrorLb->Text = "B³êdne has³o!";
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
