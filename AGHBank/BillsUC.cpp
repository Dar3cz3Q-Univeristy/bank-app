#include "BillsUC.h"
#include "Database.h"
#include "StringConversion.h"
#include "CreateBill.h"
#include <string>
#include "HistoryForm.h"
#include "RemoveBill.h"

using namespace AGHBank;

System::Void BillsUC::BillsUC_Load(System::Object^ sender, System::EventArgs^ e) {
	try {
		SqlConnection sqlConn(ConvertString::toSystemString(DatabaseConfig::sqlConnectionString));
		sqlConn.Open();

		String^ sqlQuery = "SELECT Acc.AccountID, AccType.Name, Acc.Number, Acc.Balance, Acc.Active, Curr.Shortcut FROM BankAccounts as Acc JOIN BankAccountTypes as AccType ON Acc.TypeID = AccType.TypeID JOIN Currencies as Curr ON Acc.Currency = Curr.CurrencyID WHERE Acc.PersonID = @personID";

		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@personID", loggedUserID);

		SqlDataReader^ reader = command.ExecuteReader();

		int i = 0, initialHeight = 50;

		while (reader->Read()) {
			int ID = reader->GetInt32(0);
			String^ name = reader->GetString(1);
			String^ number = reader->GetString(2);
			SqlTypes::SqlMoney balance = reader->GetSqlMoney(3);
			SqlTypes::SqlBoolean active = reader->GetBoolean(4);
			String^ currency = reader->GetString(5);

			if (!active) {
				continue;
			}

			Label^ nameLabel = gcnew Label();
			nameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			nameLabel->Dock = DockStyle::Fill;
			nameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			nameLabel->Text = name;

			Label^ numberLabel = gcnew Label();
			numberLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans MT", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			numberLabel->Dock = DockStyle::Fill;
			numberLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			numberLabel->Cursor = System::Windows::Forms::Cursors::Hand;
			numberLabel->Text = number;

			ToolTip^ numberLabelToolTip = gcnew ToolTip();
			numberLabelToolTip->SetToolTip(numberLabel, "Naciœnij dwukrotnie aby skopiowaæ");

			Label^ ballanceLabel = gcnew Label();
			ballanceLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			ballanceLabel->Dock = DockStyle::Fill;
			ballanceLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			ballanceLabel->Text = "Saldo: " + balance + " " + currency;

			Button^ historyBtn = gcnew Button();
			historyBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			historyBtn->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 12, System::Drawing::FontStyle::Underline,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			historyBtn->Dock = DockStyle::Fill;
			historyBtn->TabIndex = i;
			historyBtn->Tag = L"" + ID;
			historyBtn->Text = L"Historia";
			historyBtn->UseVisualStyleBackColor = true;
			historyBtn->Click += gcnew System::EventHandler(this, &BillsUC::historyBtn_Click);

			this->billsTable->RowCount++;
			this->billsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, (float)initialHeight)));
			this->billsTable->Size = System::Drawing::Size(1572, initialHeight * this->billsTable->RowCount);

			this->billsTable->Controls->Add(nameLabel, 0, i);
			this->billsTable->Controls->Add(numberLabel, 1, i);
			this->billsTable->Controls->Add(ballanceLabel, 2, i);
			this->billsTable->Controls->Add(historyBtn, 3, i);
			i++;
		}

		reader->Close();
		sqlConn.Close();

		Button^ createBillBtn = gcnew Button();
		createBillBtn->Cursor = System::Windows::Forms::Cursors::Hand;
		createBillBtn->Dock = System::Windows::Forms::DockStyle::Fill;
		createBillBtn->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 12, System::Drawing::FontStyle::Underline));
		createBillBtn->Dock = DockStyle::Fill;
		createBillBtn->TabIndex = i;
		createBillBtn->Text = L"Otwórz nowy rachunek";
		createBillBtn->UseVisualStyleBackColor = true;
		createBillBtn->Click += gcnew System::EventHandler(this, &BillsUC::createBillBtn_Click);

		Button^ removeBillBtn = gcnew Button();
		removeBillBtn->Cursor = System::Windows::Forms::Cursors::Hand;
		removeBillBtn->Dock = System::Windows::Forms::DockStyle::Fill;
		removeBillBtn->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 12, System::Drawing::FontStyle::Underline));
		removeBillBtn->Dock = DockStyle::Fill;
		removeBillBtn->TabIndex = i;
		removeBillBtn->Text = L"Zamknij istniej¹cy rachunek";
		removeBillBtn->UseVisualStyleBackColor = true;
		removeBillBtn->Click += gcnew System::EventHandler(this, &BillsUC::removeBillBtn_Click);

		if (i > 1) {
			this->billsTable->Controls->Add(removeBillBtn, 0, i);
		}

		this->billsTable->Controls->Add(createBillBtn, 1, i);
	}
	catch (SqlException^ e) {
		MessageBox::Show(e->Message, "B³¹d po³¹czenia", MessageBoxButtons::OK);
	}
	this->billsTable->AutoScroll = true;
}

System::Void BillsUC::createBillBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	AGHBank::CreateBill CreateBill(loggedUserID);
	CreateBill.ShowDialog();
}

System::Void BillsUC::removeBillBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	AGHBank::RemoveBill RemoveBill(loggedUserID);
	RemoveBill.ShowDialog();
}

System::Void BillsUC::historyBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	Button^ button = safe_cast<Button^>(sender);
	int billId = stoi(ConvertString::toStandardString(button->Tag->ToString()));
	AGHBank::HistoryForm HistoryForm(billId);
	HistoryForm.ShowDialog();
}