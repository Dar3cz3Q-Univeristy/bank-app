#include "HistoryForm.h"
#include "Database.h"
#include "StringConversion.h"

using namespace AGHBank;

System::Void HistoryForm::HistoryForm_Load(System::Object^ sender, System::EventArgs^ e) {
	try {
		SqlConnection sqlConn(ConvertString::toSystemString(DatabaseConfig::sqlConnectionString));
		sqlConn.Open();

		String^ sqlQuery = "SELECT TOP 10 CONCAT(Pd.Forename, ' ', Pd.Surname), Tr.Title, TrT.Name, Tr.Amount, FORMAT(Tr.TransferDate,'dd.MM.yyyy'), Cu.Shortcut, Tr.StartingAccountID, Tr.DestinationAccountID, Tr.TypeID FROM Transactions as Tr JOIN BankAccounts as Acc ON Tr.StartingAccountID = Acc.AccountID JOIN PersonDetails as Pd ON Acc.PersonID = Pd.PersonID JOIN TransactionTypes as TrT ON Tr.TypeID = TrT.TypeID JOIN Currencies as Cu ON Tr.CurrencyID = Cu.CurrencyID WHERE Tr.StartingAccountID = @billID OR Tr.DestinationAccountID = @billID ORDER BY Tr.TransferDate DESC";

		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@billID", choosedBillID);

		SqlDataReader^ reader = command.ExecuteReader();

		int i = 1, initialHeight = 50;

		while (reader->Read()) {
			String^ contractorName = reader->GetString(0);
			String^ title = reader->GetString(1);
			String^ type = reader->GetString(2);
			SqlTypes::SqlMoney amount = reader->GetSqlMoney(3);
			String^ transferDate = reader->GetString(4);
			String^ currencyShortcut = reader->GetString(5);
			int startingAccountID = reader->GetInt32(6);
			int destinationAccountID = reader->GetInt32(7);
			int typeID = reader->GetInt32(8);

			Label^ contractorLabel = gcnew Label();
			contractorLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			contractorLabel->Dock = DockStyle::Fill;
			contractorLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			contractorLabel->Text = contractorName;

			Label^ titleLabel = gcnew Label();
			titleLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans MT", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			titleLabel->Dock = DockStyle::Fill;
			titleLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			titleLabel->Text = title;

			Label^ typeLabel = gcnew Label();
			typeLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans MT", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			typeLabel->Dock = DockStyle::Fill;
			typeLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			typeLabel->Text = type;

			Label^ amountLabel = gcnew Label();
			amountLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			amountLabel->Dock = DockStyle::Fill;
			amountLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			if (typeID <= 2) {
				if (typeID % 2 == 0) {
					amountLabel->Text = "-" + amount + " " + currencyShortcut;
					amountLabel->ForeColor = Color::FromArgb(1, 193, 13, 20);
				}
				else {
					amountLabel->Text = amount + " " + currencyShortcut;
					amountLabel->ForeColor = Color::FromArgb(1, 24, 201, 71);
				}
			}
			else {
				if (startingAccountID == choosedBillID) {
					amountLabel->Text = "-" + amount + " " + currencyShortcut;
					amountLabel->ForeColor = Color::FromArgb(1, 193, 13, 20);
				}
				else if (destinationAccountID == choosedBillID) {
					amountLabel->Text = amount + " " + currencyShortcut;
					amountLabel->ForeColor = Color::FromArgb(1, 24, 201, 71);
				}
			}

			Label^ transferDateLabel = gcnew Label();
			transferDateLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			transferDateLabel->Dock = DockStyle::Fill;
			transferDateLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			transferDateLabel->Text = transferDate;

			this->historyListTableLayoutPanel->RowCount++;
			this->historyListTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, (float)initialHeight)));
			this->historyListTableLayoutPanel->Size = System::Drawing::Size(1572, initialHeight * this->historyListTableLayoutPanel->RowCount);

			this->historyListTableLayoutPanel->Controls->Add(contractorLabel, 0, i);
			this->historyListTableLayoutPanel->Controls->Add(titleLabel, 1, i);
			this->historyListTableLayoutPanel->Controls->Add(typeLabel, 2, i);
			this->historyListTableLayoutPanel->Controls->Add(amountLabel, 3, i);
			this->historyListTableLayoutPanel->Controls->Add(transferDateLabel, 4, i);
			i++;
		}

		reader->Close();
		sqlConn.Close();
	}
	catch (SqlException^ e) {
		MessageBox::Show(e->Message, "B³¹d po³¹czenia", MessageBoxButtons::OK);
	}
}

