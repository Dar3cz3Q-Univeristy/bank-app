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
	/// Summary for AccountUC
	/// </summary>
	public ref class AccountUC : public System::Windows::Forms::UserControl
	{
	public:
		int loggedUserID;
		AccountUC(int id)
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
		~AccountUC()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ fullNameLb;
	private: System::Windows::Forms::PictureBox^ personPictureBox;
	private: System::Windows::Forms::Label^ ageLb;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ accountNameLb;
	private: System::Windows::Forms::Label^ balanceLb;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ createdDateLb;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::Label^ allOperationLb;
	private: System::Windows::Forms::Label^ allIntrestLb;
	private: System::Windows::Forms::Label^ allIncomeLb;
	private: System::Windows::Forms::Label^ allExpenseLb;
	private: System::Windows::Forms::Label^ allOperationValLb;
	private: System::Windows::Forms::Label^ allIncomeValLb;
	private: System::Windows::Forms::Label^ allExpenseValLb;
	private: System::Windows::Forms::Label^ allIntrestValLb;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AccountUC::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->ageLb = (gcnew System::Windows::Forms::Label());
			this->fullNameLb = (gcnew System::Windows::Forms::Label());
			this->personPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->balanceLb = (gcnew System::Windows::Forms::Label());
			this->accountNameLb = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->createdDateLb = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->allIntrestLb = (gcnew System::Windows::Forms::Label());
			this->allOperationLb = (gcnew System::Windows::Forms::Label());
			this->allIncomeLb = (gcnew System::Windows::Forms::Label());
			this->allExpenseLb = (gcnew System::Windows::Forms::Label());
			this->allOperationValLb = (gcnew System::Windows::Forms::Label());
			this->allIncomeValLb = (gcnew System::Windows::Forms::Label());
			this->allExpenseValLb = (gcnew System::Windows::Forms::Label());
			this->allIntrestValLb = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->personPictureBox))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->ageLb);
			this->panel1->Controls->Add(this->fullNameLb);
			this->panel1->Controls->Add(this->personPictureBox);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(20, 20);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1538, 100);
			this->panel1->TabIndex = 0;
			// 
			// ageLb
			// 
			this->ageLb->Font = (gcnew System::Drawing::Font(L"Calibri", 20));
			this->ageLb->Location = System::Drawing::Point(1212, 26);
			this->ageLb->Name = L"ageLb";
			this->ageLb->Size = System::Drawing::Size(300, 49);
			this->ageLb->TabIndex = 2;
			this->ageLb->Text = L"$age$";
			this->ageLb->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// fullNameLb
			// 
			this->fullNameLb->AutoSize = true;
			this->fullNameLb->Font = (gcnew System::Drawing::Font(L"Calibri", 20));
			this->fullNameLb->Location = System::Drawing::Point(130, 26);
			this->fullNameLb->Name = L"fullNameLb";
			this->fullNameLb->Size = System::Drawing::Size(205, 49);
			this->fullNameLb->TabIndex = 1;
			this->fullNameLb->Text = L"$fullname$";
			// 
			// personPictureBox
			// 
			this->personPictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"personPictureBox.Image")));
			this->personPictureBox->Location = System::Drawing::Point(0, 0);
			this->personPictureBox->Name = L"personPictureBox";
			this->personPictureBox->Size = System::Drawing::Size(100, 100);
			this->personPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->personPictureBox->TabIndex = 0;
			this->personPictureBox->TabStop = false;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->panel4);
			this->panel2->Controls->Add(this->balanceLb);
			this->panel2->Controls->Add(this->accountNameLb);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel2->Location = System::Drawing::Point(20, 120);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(726, 563);
			this->panel2->TabIndex = 1;
			// 
			// panel4
			// 
			this->panel4->Location = System::Drawing::Point(757, 3);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(778, 451);
			this->panel4->TabIndex = 5;
			// 
			// balanceLb
			// 
			this->balanceLb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->balanceLb->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->balanceLb->Location = System::Drawing::Point(3, 93);
			this->balanceLb->Name = L"balanceLb";
			this->balanceLb->Size = System::Drawing::Size(720, 40);
			this->balanceLb->TabIndex = 3;
			this->balanceLb->Text = L"$balance$";
			this->balanceLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// accountNameLb
			// 
			this->accountNameLb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->accountNameLb->Font = (gcnew System::Drawing::Font(L"Calibri", 16, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->accountNameLb->Location = System::Drawing::Point(3, 3);
			this->accountNameLb->Name = L"accountNameLb";
			this->accountNameLb->Size = System::Drawing::Size(720, 90);
			this->accountNameLb->TabIndex = 2;
			this->accountNameLb->Text = L"$account name$";
			this->accountNameLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				61.66328F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				38.33672F)));
			this->tableLayoutPanel1->Location = System::Drawing::Point(20, 256);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 5;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(723, 424);
			this->tableLayoutPanel1->TabIndex = 3;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->createdDateLb);
			this->panel3->Location = System::Drawing::Point(777, 580);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(778, 100);
			this->panel3->TabIndex = 4;
			// 
			// createdDateLb
			// 
			this->createdDateLb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->createdDateLb->Font = (gcnew System::Drawing::Font(L"Calibri", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->createdDateLb->Location = System::Drawing::Point(8, 31);
			this->createdDateLb->Name = L"createdDateLb";
			this->createdDateLb->Size = System::Drawing::Size(764, 39);
			this->createdDateLb->TabIndex = 2;
			this->createdDateLb->Text = L"$created date$";
			this->createdDateLb->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 16, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(777, 123);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(778, 67);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Statystyki rachunku:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				61.66328F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				38.33672F)));
			this->tableLayoutPanel2->Controls->Add(this->allIntrestLb, 0, 3);
			this->tableLayoutPanel2->Controls->Add(this->allOperationLb, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->allIncomeLb, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->allExpenseLb, 0, 2);
			this->tableLayoutPanel2->Controls->Add(this->allOperationValLb, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->allIncomeValLb, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->allExpenseValLb, 1, 2);
			this->tableLayoutPanel2->Controls->Add(this->allIntrestValLb, 1, 3);
			this->tableLayoutPanel2->Location = System::Drawing::Point(777, 193);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 4;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(775, 381);
			this->tableLayoutPanel2->TabIndex = 6;
			// 
			// allIntrestLb
			// 
			this->allIntrestLb->AutoSize = true;
			this->allIntrestLb->Dock = System::Windows::Forms::DockStyle::Fill;
			this->allIntrestLb->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11, System::Drawing::FontStyle::Underline));
			this->allIntrestLb->Location = System::Drawing::Point(3, 285);
			this->allIntrestLb->Name = L"allIntrestLb";
			this->allIntrestLb->Size = System::Drawing::Size(471, 96);
			this->allIntrestLb->TabIndex = 4;
			this->allIntrestLb->Text = L"Calkowita kwota odsetek:";
			this->allIntrestLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// allOperationLb
			// 
			this->allOperationLb->AutoSize = true;
			this->allOperationLb->Dock = System::Windows::Forms::DockStyle::Fill;
			this->allOperationLb->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->allOperationLb->Location = System::Drawing::Point(3, 0);
			this->allOperationLb->Name = L"allOperationLb";
			this->allOperationLb->Size = System::Drawing::Size(471, 95);
			this->allOperationLb->TabIndex = 1;
			this->allOperationLb->Text = L"Calkowita ilosc operacji:";
			this->allOperationLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// allIncomeLb
			// 
			this->allIncomeLb->AutoSize = true;
			this->allIncomeLb->Dock = System::Windows::Forms::DockStyle::Fill;
			this->allIncomeLb->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11, System::Drawing::FontStyle::Underline));
			this->allIncomeLb->Location = System::Drawing::Point(3, 95);
			this->allIncomeLb->Name = L"allIncomeLb";
			this->allIncomeLb->Size = System::Drawing::Size(471, 95);
			this->allIncomeLb->TabIndex = 2;
			this->allIncomeLb->Text = L"Calkowite przychody:";
			this->allIncomeLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// allExpenseLb
			// 
			this->allExpenseLb->AutoSize = true;
			this->allExpenseLb->Dock = System::Windows::Forms::DockStyle::Fill;
			this->allExpenseLb->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11, System::Drawing::FontStyle::Underline));
			this->allExpenseLb->Location = System::Drawing::Point(3, 190);
			this->allExpenseLb->Name = L"allExpenseLb";
			this->allExpenseLb->Size = System::Drawing::Size(471, 95);
			this->allExpenseLb->TabIndex = 3;
			this->allExpenseLb->Text = L"Calkowite wydatki:";
			this->allExpenseLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// allOperationValLb
			// 
			this->allOperationValLb->AutoSize = true;
			this->allOperationValLb->Dock = System::Windows::Forms::DockStyle::Fill;
			this->allOperationValLb->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->allOperationValLb->Location = System::Drawing::Point(480, 0);
			this->allOperationValLb->Name = L"allOperationValLb";
			this->allOperationValLb->Size = System::Drawing::Size(292, 95);
			this->allOperationValLb->TabIndex = 5;
			this->allOperationValLb->Text = L"0";
			this->allOperationValLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// allIncomeValLb
			// 
			this->allIncomeValLb->AutoSize = true;
			this->allIncomeValLb->Dock = System::Windows::Forms::DockStyle::Fill;
			this->allIncomeValLb->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->allIncomeValLb->Location = System::Drawing::Point(480, 95);
			this->allIncomeValLb->Name = L"allIncomeValLb";
			this->allIncomeValLb->Size = System::Drawing::Size(292, 95);
			this->allIncomeValLb->TabIndex = 6;
			this->allIncomeValLb->Text = L"0";
			this->allIncomeValLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// allExpenseValLb
			// 
			this->allExpenseValLb->AutoSize = true;
			this->allExpenseValLb->Dock = System::Windows::Forms::DockStyle::Fill;
			this->allExpenseValLb->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->allExpenseValLb->Location = System::Drawing::Point(480, 190);
			this->allExpenseValLb->Name = L"allExpenseValLb";
			this->allExpenseValLb->Size = System::Drawing::Size(292, 95);
			this->allExpenseValLb->TabIndex = 8;
			this->allExpenseValLb->Text = L"0";
			this->allExpenseValLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// allIntrestValLb
			// 
			this->allIntrestValLb->AutoSize = true;
			this->allIntrestValLb->Dock = System::Windows::Forms::DockStyle::Fill;
			this->allIntrestValLb->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->allIntrestValLb->Location = System::Drawing::Point(480, 285);
			this->allIntrestValLb->Name = L"allIntrestValLb";
			this->allIntrestValLb->Size = System::Drawing::Size(292, 96);
			this->allIntrestValLb->TabIndex = 7;
			this->allIntrestValLb->Text = L"0";
			this->allIntrestValLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// AccountUC
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"AccountUC";
			this->Padding = System::Windows::Forms::Padding(20);
			this->Size = System::Drawing::Size(1578, 703);
			this->Load += gcnew System::EventHandler(this, &AccountUC::AccountUC_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->personPictureBox))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	public:
		int randomAccountID;
		String^ currencyShortcut;
	private: System::Void AccountUC_Load(System::Object^ sender, System::EventArgs^ e);
	};
}
