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
	/// Summary for ChangePassword
	/// </summary>
	public ref class ChangePassword : public System::Windows::Forms::Form
	{
	public:
		int loggedUserID;
		ChangePassword(int id)
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
		~ChangePassword()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ errorLb;
	private: System::Windows::Forms::Button^ createBillBtn;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ accountTypeLb;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ oldPasswordInput;
	private: System::Windows::Forms::TextBox^ retypedNewPasswordInput;
	private: System::Windows::Forms::TextBox^ newPasswordInput;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->errorLb = (gcnew System::Windows::Forms::Label());
			this->createBillBtn = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->retypedNewPasswordInput = (gcnew System::Windows::Forms::TextBox());
			this->newPasswordInput = (gcnew System::Windows::Forms::TextBox());
			this->oldPasswordInput = (gcnew System::Windows::Forms::TextBox());
			this->accountTypeLb = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// errorLb
			// 
			this->errorLb->Font = (gcnew System::Drawing::Font(L"Impact", 16));
			this->errorLb->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(193)), static_cast<System::Int32>(static_cast<System::Byte>(13)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->errorLb->Location = System::Drawing::Point(15, 404);
			this->errorLb->Name = L"errorLb";
			this->errorLb->Size = System::Drawing::Size(851, 94);
			this->errorLb->TabIndex = 9;
			this->errorLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
			this->createBillBtn->Location = System::Drawing::Point(596, 517);
			this->createBillBtn->Name = L"createBillBtn";
			this->createBillBtn->Size = System::Drawing::Size(267, 60);
			this->createBillBtn->TabIndex = 8;
			this->createBillBtn->Text = L"Zmieñ has³o";
			this->createBillBtn->UseVisualStyleBackColor = false;
			this->createBillBtn->Click += gcnew System::EventHandler(this, &ChangePassword::createBillBtn_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				39.13044F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				60.86956F)));
			this->tableLayoutPanel1->Controls->Add(this->retypedNewPasswordInput, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->newPasswordInput, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->oldPasswordInput, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->accountTypeLb, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->label2, 0, 2);
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 12);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(851, 389);
			this->tableLayoutPanel1->TabIndex = 10;
			// 
			// retypedNewPasswordInput
			// 
			this->retypedNewPasswordInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->retypedNewPasswordInput->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->retypedNewPasswordInput->Location = System::Drawing::Point(336, 301);
			this->retypedNewPasswordInput->MaxLength = 16;
			this->retypedNewPasswordInput->Name = L"retypedNewPasswordInput";
			this->retypedNewPasswordInput->Size = System::Drawing::Size(512, 44);
			this->retypedNewPasswordInput->TabIndex = 6;
			this->retypedNewPasswordInput->UseSystemPasswordChar = true;
			// 
			// newPasswordInput
			// 
			this->newPasswordInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->newPasswordInput->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->newPasswordInput->Location = System::Drawing::Point(336, 171);
			this->newPasswordInput->MaxLength = 16;
			this->newPasswordInput->Name = L"newPasswordInput";
			this->newPasswordInput->Size = System::Drawing::Size(512, 44);
			this->newPasswordInput->TabIndex = 5;
			this->newPasswordInput->UseSystemPasswordChar = true;
			// 
			// oldPasswordInput
			// 
			this->oldPasswordInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->oldPasswordInput->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->oldPasswordInput->Location = System::Drawing::Point(336, 42);
			this->oldPasswordInput->MaxLength = 16;
			this->oldPasswordInput->Name = L"oldPasswordInput";
			this->oldPasswordInput->Size = System::Drawing::Size(512, 44);
			this->oldPasswordInput->TabIndex = 4;
			this->oldPasswordInput->UseSystemPasswordChar = true;
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
			this->accountTypeLb->Size = System::Drawing::Size(327, 129);
			this->accountTypeLb->TabIndex = 1;
			this->accountTypeLb->Text = L"Aktualne has³o:";
			this->accountTypeLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(3, 129);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(327, 129);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Nowe has³o:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->label2->Location = System::Drawing::Point(3, 258);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(327, 131);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Powtórz nowe has³o:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ChangePassword
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(878, 594);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->errorLb);
			this->Controls->Add(this->createBillBtn);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"ChangePassword";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Zmieñ has³o";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void createBillBtn_Click(System::Object^ sender, System::EventArgs^ e);
};
}
