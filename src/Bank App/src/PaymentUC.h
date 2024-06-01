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
	/// Summary for PaymentUC
	/// </summary>
	public ref class PaymentUC : public System::Windows::Forms::UserControl
	{
	public:
		int loggedUserID;
		PaymentUC(int id)
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
		~PaymentUC()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RadioButton^ paymentRadioBtn;
	private: System::Windows::Forms::Panel^ typePanel;
	private: System::Windows::Forms::RadioButton^ paycheckRadioBtn;
	private: System::Windows::Forms::Label^ billLb;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::ComboBox^ billsComboBox;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ amountInput;
	private: System::Windows::Forms::Label^ amountLb;
	private: System::Windows::Forms::ComboBox^ currencyComboBox;
	private: System::Windows::Forms::Button^ nextBtn;
	private: System::Windows::Forms::Panel^ panel3;
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
			this->paymentRadioBtn = (gcnew System::Windows::Forms::RadioButton());
			this->typePanel = (gcnew System::Windows::Forms::Panel());
			this->paycheckRadioBtn = (gcnew System::Windows::Forms::RadioButton());
			this->billLb = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->billsComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->currencyComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->amountInput = (gcnew System::Windows::Forms::TextBox());
			this->amountLb = (gcnew System::Windows::Forms::Label());
			this->nextBtn = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->errorLb = (gcnew System::Windows::Forms::Label());
			this->typePanel->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// paymentRadioBtn
			// 
			this->paymentRadioBtn->Appearance = System::Windows::Forms::Appearance::Button;
			this->paymentRadioBtn->Checked = true;
			this->paymentRadioBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->paymentRadioBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->paymentRadioBtn->Location = System::Drawing::Point(23, 25);
			this->paymentRadioBtn->Name = L"paymentRadioBtn";
			this->paymentRadioBtn->Size = System::Drawing::Size(735, 60);
			this->paymentRadioBtn->TabIndex = 1;
			this->paymentRadioBtn->TabStop = true;
			this->paymentRadioBtn->Text = L"Wplata gotówki";
			this->paymentRadioBtn->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->paymentRadioBtn->UseVisualStyleBackColor = true;
			// 
			// typePanel
			// 
			this->typePanel->Controls->Add(this->paycheckRadioBtn);
			this->typePanel->Controls->Add(this->paymentRadioBtn);
			this->typePanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->typePanel->Location = System::Drawing::Point(0, 0);
			this->typePanel->Name = L"typePanel";
			this->typePanel->Padding = System::Windows::Forms::Padding(20, 5, 20, 5);
			this->typePanel->Size = System::Drawing::Size(1578, 85);
			this->typePanel->TabIndex = 4;
			// 
			// paycheckRadioBtn
			// 
			this->paycheckRadioBtn->Appearance = System::Windows::Forms::Appearance::Button;
			this->paycheckRadioBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->paycheckRadioBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 18, System::Drawing::FontStyle::Bold));
			this->paycheckRadioBtn->Location = System::Drawing::Point(820, 25);
			this->paycheckRadioBtn->Name = L"paycheckRadioBtn";
			this->paycheckRadioBtn->Size = System::Drawing::Size(735, 60);
			this->paycheckRadioBtn->TabIndex = 2;
			this->paycheckRadioBtn->Text = L"Wyplata gotówki";
			this->paycheckRadioBtn->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->paycheckRadioBtn->UseVisualStyleBackColor = true;
			// 
			// billLb
			// 
			this->billLb->AutoSize = true;
			this->billLb->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->billLb->Location = System::Drawing::Point(309, 121);
			this->billLb->Name = L"billLb";
			this->billLb->Size = System::Drawing::Size(277, 37);
			this->billLb->TabIndex = 5;
			this->billLb->Text = L"Wybierz rachunek:";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->billLb);
			this->panel1->Controls->Add(this->billsComboBox);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 85);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1578, 200);
			this->panel1->TabIndex = 6;
			// 
			// billsComboBox
			// 
			this->billsComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->billsComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->billsComboBox->FormattingEnabled = true;
			this->billsComboBox->Location = System::Drawing::Point(666, 118);
			this->billsComboBox->Name = L"billsComboBox";
			this->billsComboBox->Size = System::Drawing::Size(604, 45);
			this->billsComboBox->TabIndex = 3;
			this->billsComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &PaymentUC::billsComboBox_SelectedIndexChanged);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->currencyComboBox);
			this->panel2->Controls->Add(this->amountInput);
			this->panel2->Controls->Add(this->amountLb);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 285);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1578, 194);
			this->panel2->TabIndex = 7;
			// 
			// currencyComboBox
			// 
			this->currencyComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->currencyComboBox->Enabled = false;
			this->currencyComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->currencyComboBox->FormattingEnabled = true;
			this->currencyComboBox->Location = System::Drawing::Point(1155, 78);
			this->currencyComboBox->Name = L"currencyComboBox";
			this->currencyComboBox->Size = System::Drawing::Size(115, 45);
			this->currencyComboBox->TabIndex = 5;
			// 
			// amountInput
			// 
			this->amountInput->Enabled = false;
			this->amountInput->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->amountInput->Location = System::Drawing::Point(666, 78);
			this->amountInput->Name = L"amountInput";
			this->amountInput->Size = System::Drawing::Size(483, 44);
			this->amountInput->TabIndex = 4;
			this->amountInput->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &PaymentUC::amountInput_KeyPress);
			// 
			// amountLb
			// 
			this->amountLb->AutoSize = true;
			this->amountLb->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold));
			this->amountLb->Location = System::Drawing::Point(472, 82);
			this->amountLb->Name = L"amountLb";
			this->amountLb->Size = System::Drawing::Size(114, 37);
			this->amountLb->TabIndex = 6;
			this->amountLb->Text = L"Kwota:";
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
			this->nextBtn->Location = System::Drawing::Point(1221, 79);
			this->nextBtn->Name = L"nextBtn";
			this->nextBtn->Size = System::Drawing::Size(227, 81);
			this->nextBtn->TabIndex = 6;
			this->nextBtn->Text = L"Wykonaj";
			this->nextBtn->UseVisualStyleBackColor = false;
			this->nextBtn->Click += gcnew System::EventHandler(this, &PaymentUC::nextBtn_Click);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->errorLb);
			this->panel3->Controls->Add(this->nextBtn);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel3->Location = System::Drawing::Point(0, 479);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1578, 239);
			this->panel3->TabIndex = 8;
			// 
			// errorLb
			// 
			this->errorLb->Font = (gcnew System::Drawing::Font(L"Impact", 16));
			this->errorLb->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(193)), static_cast<System::Int32>(static_cast<System::Byte>(13)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->errorLb->Location = System::Drawing::Point(131, 71);
			this->errorLb->Name = L"errorLb";
			this->errorLb->Size = System::Drawing::Size(851, 96);
			this->errorLb->TabIndex = 8;
			this->errorLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// PaymentUC
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->typePanel);
			this->Name = L"PaymentUC";
			this->Size = System::Drawing::Size(1578, 709);
			this->Load += gcnew System::EventHandler(this, &PaymentUC::PaymentUC_Load);
			this->typePanel->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	public:
		int selectedComboID = -1,
			selectedAccountID;
	private: System::Void PaymentUC_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void billsComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nextBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void amountInput_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
	};
}
