#include "HistoryForm.h"
#include "Database.h"
#include "StringConversion.h"

using namespace AGHBank;

System::Void HistoryForm::HistoryForm_Load(System::Object^ sender, System::EventArgs^ e) {
	try {
		SqlConnection sqlConn(ConvertString::toSystemString(DatabaseConfig::sqlConnectionString));
		sqlConn.Open();

		String^ sqlQuery = "SELECT CONCAT(Pd.Forename, ' ', Pd.Surname), Tr.Title, TrT.Name, Tr.Amount, Tr.AmountInAccountMainCurrency, FORMAT(Tr.TransferDate,'dd.MM.yyyy'), Cu.Shortcut, Tr.StartingAccountID, Tr.DestinationAccountID, Tr.TypeID, RIGHT(Acc.Number, 4) as 'Last digits' FROM Transactions as Tr JOIN BankAccounts as Acc ON Tr.DestinationAccountID = Acc.AccountID JOIN PersonDetails as Pd ON Acc.PersonID = Pd.PersonID JOIN TransactionTypes as TrT ON Tr.TypeID = TrT.TypeID JOIN Currencies as Cu ON Tr.CurrencyID = Cu.CurrencyID WHERE Tr.StartingAccountID = @billID ORDER BY Tr.TransferDate DESC";

		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@billID", choosedBillID);

		SqlDataReader^ reader = command.ExecuteReader();

		int i = 1, initialHeight = 50;

		SqlTypes::SqlMoney incomeSum = 0, expenseSum = 0;

		while (reader->Read()) {
			String^ contractorName = reader->GetString(0);
			String^ title = reader->GetString(1);
			String^ type = reader->GetString(2);
			SqlTypes::SqlMoney amount = reader->GetSqlMoney(3);
			SqlTypes::SqlMoney amountInAccCurrency = reader->GetSqlMoney(4);
			String^ transferDate = reader->GetString(5);
			String^ currencyShortcut = reader->GetString(6);
			int startingAccountID = reader->GetInt32(7);
			int destinationAccountID = reader->GetInt32(8);
			int typeID = reader->GetInt32(9);
			String^ accountLastDigits = reader->GetString(10);

			Label^ contractorLabel = gcnew Label();
			contractorLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			contractorLabel->Dock = DockStyle::Fill;
			contractorLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			contractorLabel->Text = contractorName + " - **** " + accountLastDigits;

			Label^ titleLabel = gcnew Label();
			titleLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans MT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			titleLabel->Dock = DockStyle::Fill;
			titleLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			titleLabel->Text = title;

			Label^ typeLabel = gcnew Label();
			typeLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans MT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			typeLabel->Dock = DockStyle::Fill;
			typeLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			typeLabel->Text = type;

			Label^ amountLabel = gcnew Label();
			amountLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			amountLabel->Dock = DockStyle::Fill;
			amountLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			amountLabel->Text = amount + " " + currencyShortcut;

			//Do przeróbki
			if (typeID % 2 == 0) {
				amountLabel->Text = "-" + amountLabel->Text;
				amountLabel->ForeColor = Color::FromArgb(1, 193, 13, 20);
				expenseSum += amountInAccCurrency;
			}
			else {
				incomeSum += amountInAccCurrency;
			}
			//Do przeróbki

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

		sqlQuery = "SELECT Cu.Shortcut FROM BankAccounts as Acc JOIN Currencies as Cu ON Acc.Currency = Cu.CurrencyID WHERE Acc.AccountID = @billID";

		SqlCommand secondCommand(sqlQuery, % sqlConn);
		secondCommand.Parameters->AddWithValue("@billID", choosedBillID);

		reader = secondCommand.ExecuteReader();

		String^ mainAccountCurrencyShortcut = "";

		if (reader->Read()) {
			mainAccountCurrencyShortcut = " " + reader->GetString(0);
		}

		reader->Close();
		sqlConn.Close();

		this->incomeLb->Text = "Przychody: " + incomeSum + mainAccountCurrencyShortcut;
		this->expensesLb->Text = "Wydatki: " + expenseSum + mainAccountCurrencyShortcut;
		this->historyListTableLayoutPanel->AutoScroll = true;
	}
	catch (SqlException^ e) {
		MessageBox::Show(e->Message, "Blad polaczenia", MessageBoxButtons::OK);
	}
}

