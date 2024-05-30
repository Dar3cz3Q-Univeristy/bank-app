#include "AccountUC.h"
#include "Database.h"
#include "StringConversion.h"
#include <string>

using namespace AGHBank;

System::Void AccountUC::AccountUC_Load(System::Object^ sender, System::EventArgs^ e) {
	try {
		SqlConnection sqlConn(ConvertString::toSystemString(DatabaseConfig::sqlConnectionString));
		sqlConn.Open();

		String^ sqlQuery = "SELECT TOP 1 CONCAT(pd.Forename, ' ', pd.Surname), FORMAT(pl.CreatedTime, 'dd.MM.yyyy HH:mm'), FLOOR(DATEDIFF(day, pd.BirthDate, GETDATE()) / 365.2425), ba.AccountID, SUBSTRING(pd.Pesel, 10, 1) FROM PersonDetails as pd JOIN PersonLogins as pl ON pd.PersonID = pl.PersonID JOIN BankAccounts as ba ON pd.PersonID = ba.PersonID WHERE pl.PersonID = @personID AND ba.Active = 1 ORDER BY NEWID(); ";

		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@personID", loggedUserID);

		SqlDataReader^ reader = command.ExecuteReader();

		if (reader->Read()) {
			this->fullNameLb->Text = reader->GetString(0);
			this->createdDateLb->Text = "Konto utworzono: " + reader->GetString(1);
			this->ageLb->Text = reader->GetDecimal(2) + " lat";
			randomAccountID = reader->GetInt32(3);
			int genderCheck = stoi(ConvertString::toStandardString(reader->GetString(4)));
			if (genderCheck % 2 == 0) {
				personPictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(gcnew Bitmap("img\\women.png")));
			}
		}

		reader->Close();

		sqlQuery = "SELECT bt.Name, b.Balance, c.Shortcut FROM BankAccounts as b JOIN Currencies as c ON b.Currency = c.CurrencyID JOIN BankAccountTypes as bt ON b.TypeID = bt.TypeID WHERE AccountID = @billID;";

		SqlCommand secondCommand(sqlQuery, % sqlConn);
		secondCommand.Parameters->AddWithValue("@billID", randomAccountID);

		reader = secondCommand.ExecuteReader();

		if (reader->Read()) {
			currencyShortcut = reader->GetString(2);
			this->accountNameLb->Text = reader->GetString(0);
			this->balanceLb->Text = "Saldo: " + reader->GetSqlMoney(1) + " " + currencyShortcut;
		}

		reader->Close();

		sqlQuery = "SELECT TOP 5 t.Title, t.Amount, c.Shortcut, t.TypeID FROM Transactions as t JOIN Currencies as c ON t.CurrencyID = c.CurrencyID WHERE t.StartingAccountID = @billID ORDER BY t.TransferDate DESC;";

		SqlCommand thirdCommand(sqlQuery, % sqlConn);
		thirdCommand.Parameters->AddWithValue("@billID", randomAccountID);

		reader = thirdCommand.ExecuteReader();

		int i = 0;

		while (reader->Read()) {
			String^ title = reader->GetString(0);
			SqlTypes::SqlMoney money = reader->GetSqlMoney(1);
			String^ shortcut = reader->GetString(2);
			int typeID = reader->GetInt32(3);
			String^ amount;

			if (typeID % 2 == 0) {
				amount = "-" + money + " " + shortcut;
			}
			else {
				amount = money + " " + shortcut;
			}

			Label^ titleLabel = gcnew Label();
			titleLabel->AutoSize = true;
			titleLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			titleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			titleLabel->Location = System::Drawing::Point(3, 0);
			titleLabel->Size = System::Drawing::Size(439, 84);
			titleLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			titleLabel->Text = title;

			Label^ amountLabel = gcnew Label();
			amountLabel->AutoSize = true;
			amountLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			amountLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			amountLabel->Location = System::Drawing::Point(3, 0);
			amountLabel->Size = System::Drawing::Size(439, 84);
			amountLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			amountLabel->Text = amount;

			this->tableLayoutPanel1->Controls->Add(titleLabel, 0, i);
			this->tableLayoutPanel1->Controls->Add(amountLabel, 1, i);
			i++;
		}

		reader->Close();

		sqlQuery = "SELECT COUNT(*) FROM Transactions WHERE StartingAccountID = @billID;";

		SqlCommand fourthCommand(sqlQuery, % sqlConn);
		fourthCommand.Parameters->AddWithValue("@billID", randomAccountID);

		reader = fourthCommand.ExecuteReader();

		if (reader->Read()) {
			this->allOperationValLb->Text = ConvertString::toSystemString(std::to_string(reader->GetInt32(0)));
		}

		reader->Close();

		sqlQuery = "SELECT ISNULL(SUM(AmountInAccountMainCurrency), 0) FROM Transactions WHERE StartingAccountID = @billID AND TypeID % 2 = 0;";

		SqlCommand fifthCommand(sqlQuery, % sqlConn);
		fifthCommand.Parameters->AddWithValue("@billID", randomAccountID);

		reader = fifthCommand.ExecuteReader();

		if (reader->Read()) {
			this->allExpenseValLb->Text = reader->GetSqlMoney(0) + " " + currencyShortcut;
		}

		reader->Close();

		sqlQuery = "SELECT ISNULL(SUM(AmountInAccountMainCurrency), 0) FROM Transactions WHERE StartingAccountID = @billID AND TypeID % 2 <> 0;";

		SqlCommand sixthCommand(sqlQuery, % sqlConn);
		sixthCommand.Parameters->AddWithValue("@billID", randomAccountID);

		reader = sixthCommand.ExecuteReader();

		if (reader->Read()) {
			this->allIncomeValLb->Text = reader->GetSqlMoney(0) + " " + currencyShortcut;
		}

		reader->Close();

		sqlQuery = "SELECT ISNULL(SUM(AmountInAccountMainCurrency), 0) FROM Transactions WHERE StartingAccountID = @billID AND TypeID = 5;";

		SqlCommand seventhCommand(sqlQuery, % sqlConn);
		seventhCommand.Parameters->AddWithValue("@billID", randomAccountID);

		reader = seventhCommand.ExecuteReader();

		if (reader->Read()) {
			this->allIntrestValLb->Text = reader->GetSqlMoney(0) + " " + currencyShortcut;
		}

		reader->Close();
		sqlConn.Close();
	}
	catch (SqlException^ e) {
		MessageBox::Show(e->Message, "B³¹d po³¹czenia", MessageBoxButtons::OK);
	}
}
