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
	/// Summary for RemoveBill
	/// </summary>
	public ref class RemoveBill : public System::Windows::Forms::Form
	{
	public:
		int loggedUserID;
		RemoveBill(int id)
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
		~RemoveBill()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ closeBillLb;
	private: System::Windows::Forms::Button^ removeBillBtn;
	private: System::Windows::Forms::ComboBox^ accountListCombo;
	private: System::Windows::Forms::Label^ errorLb;
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
			this->closeBillLb = (gcnew System::Windows::Forms::Label());
			this->removeBillBtn = (gcnew System::Windows::Forms::Button());
			this->accountListCombo = (gcnew System::Windows::Forms::ComboBox());
			this->errorLb = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// closeBillLb
			// 
			this->closeBillLb->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->closeBillLb->Location = System::Drawing::Point(43, 55);
			this->closeBillLb->Name = L"closeBillLb";
			this->closeBillLb->Size = System::Drawing::Size(643, 65);
			this->closeBillLb->TabIndex = 0;
			this->closeBillLb->Text = L"Wybierz rachunek do zamkniecia:";
			this->closeBillLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// removeBillBtn
			// 
			this->removeBillBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->removeBillBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(193)), static_cast<System::Int32>(static_cast<System::Byte>(13)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->removeBillBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->removeBillBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->removeBillBtn->ForeColor = System::Drawing::Color::White;
			this->removeBillBtn->Location = System::Drawing::Point(449, 372);
			this->removeBillBtn->Name = L"removeBillBtn";
			this->removeBillBtn->Size = System::Drawing::Size(267, 60);
			this->removeBillBtn->TabIndex = 4;
			this->removeBillBtn->Text = L"Zamknij rachunek";
			this->removeBillBtn->UseVisualStyleBackColor = false;
			this->removeBillBtn->Click += gcnew System::EventHandler(this, &RemoveBill::removeBillBtn_Click);
			// 
			// accountListCombo
			// 
			this->accountListCombo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->accountListCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->accountListCombo->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->accountListCombo->FormattingEnabled = true;
			this->accountListCombo->Location = System::Drawing::Point(43, 200);
			this->accountListCombo->Name = L"accountListCombo";
			this->accountListCombo->Size = System::Drawing::Size(643, 45);
			this->accountListCombo->TabIndex = 5;
			// 
			// errorLb
			// 
			this->errorLb->Font = (gcnew System::Drawing::Font(L"Impact", 16));
			this->errorLb->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(193)), static_cast<System::Int32>(static_cast<System::Byte>(13)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->errorLb->Location = System::Drawing::Point(12, 271);
			this->errorLb->Name = L"errorLb";
			this->errorLb->Size = System::Drawing::Size(704, 87);
			this->errorLb->TabIndex = 6;
			this->errorLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// RemoveBill
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(728, 444);
			this->Controls->Add(this->errorLb);
			this->Controls->Add(this->accountListCombo);
			this->Controls->Add(this->removeBillBtn);
			this->Controls->Add(this->closeBillLb);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"RemoveBill";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Zamknij istniejacy rachunek";
			this->Load += gcnew System::EventHandler(this, &RemoveBill::RemoveBill_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void RemoveBill_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void removeBillBtn_Click(System::Object^ sender, System::EventArgs^ e);
	};
}