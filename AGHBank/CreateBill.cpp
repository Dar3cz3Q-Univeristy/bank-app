#include "CreateBill.h"
#include "Database.h"
#include "StringConversion.h"

using namespace AGHBank;

System::Void CreateBill::CreateBill_Load(System::Object^ sender, System::EventArgs^ e) {
	try {
		SqlConnection sqlConn(ConvertString::toSystemString(DatabaseConfig::sqlConnectionString));
		sqlConn.Open();

		String^ sqlQuery = "SELECT Name FROM BankAccountTypes";

		SqlCommand command(sqlQuery, % sqlConn);

		SqlDataReader^ reader = command.ExecuteReader();

		while (reader->Read()) {
			String^ accountTypeName = reader->GetString(0);
			this->accountTypeCombo->Items->Add(accountTypeName);
		}

		reader->Close();
		sqlConn.Close();
	}
	catch (SqlException^ e) {
		MessageBox::Show(e->Message, "B��d po��czenia", MessageBoxButtons::OK);
	}
}

System::Void CreateBill::AccountTypeCombo_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	this->currencyCombo->Items->Clear();
	this->currencyCombo->SelectionLength = 0;
	int selectedType = this->accountTypeCombo->SelectedIndex;
	if (selectedType == 2) {
		this->currencyCombo->Enabled = true;
		try {
			SqlConnection sqlConn(ConvertString::toSystemString(DatabaseConfig::sqlConnectionString));
			sqlConn.Open();

			String^ sqlQuery = "SELECT Name, Shortcut FROM Currencies";

			SqlCommand command(sqlQuery, % sqlConn);

			SqlDataReader^ reader = command.ExecuteReader();

			while (reader->Read()) {
				String^ currencyName = reader->GetString(0);
				String^ currencyShortcut = reader->GetString(1);
				this->currencyCombo->Items->Add(currencyShortcut + " - " + currencyName);
			}

			reader->Close();
			sqlConn.Close();
		}
		catch (SqlException^ e) {
			MessageBox::Show(e->Message, "B��d po��czenia", MessageBoxButtons::OK);
		}
	}
	else {
		this->currencyCombo->Enabled = false;
		this->currencyCombo->Items->Add("PLN");
		this->currencyCombo->SelectedIndex = 0;
	}
}

System::Void CreateBill::createBillBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	int accountType = this->accountTypeCombo->SelectedIndex;
	int currencyType = this->currencyCombo->SelectedIndex;
	if (accountType < 0 || currencyType < 0) {
		MessageBox::Show("Nie wybrano typu konta lub waluty", "Informacja", MessageBoxButtons::OK);
		return;
	}
	accountType++;
	currencyType++;
	try {
		SqlConnection sqlConn(ConvertString::toSystemString(DatabaseConfig::sqlConnectionString));
		sqlConn.Open();

		String^ sqlQuery = "exec CreateBill @personID, @typeID, @currencyID";

		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@personID", loggedUserID);
		command.Parameters->AddWithValue("@typeID", accountType);
		command.Parameters->AddWithValue("@currencyID", currencyType);

		command.ExecuteNonQuery();
		sqlConn.Close();

		MessageBox::Show("Rachunek zosta� utworzony pomy�lnie", "Informacja", MessageBoxButtons::OK);

		sqlConn.Close();
	}
	catch (SqlException^ e) {
		MessageBox::Show(e->Message, "B��d po��czenia", MessageBoxButtons::OK);
	}
	this->Close();
}