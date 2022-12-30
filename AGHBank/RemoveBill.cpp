#include "RemoveBill.h"
#include "Database.h"
#include "StringConversion.h"
#include "ComboItem.h"

using namespace AGHBank;

System::Void RemoveBill::RemoveBill_Load(System::Object^ sender, System::EventArgs^ e) {
	try {
		SqlConnection sqlConn(ConvertString::toSystemString(DatabaseConfig::sqlConnectionString));
		sqlConn.Open();

		String^ sqlQuery = "SELECT AccType.Name, Acc.AccountID, RIGHT(Acc.Number, 4) as 'Last digits' FROM BankAccounts as Acc JOIN BankAccountTypes as AccType ON Acc.TypeID = AccType.TypeID WHERE Acc.PersonID = @personID AND Acc.Active = 1";

		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@personID", loggedUserID);

		SqlDataReader^ reader = command.ExecuteReader();

		while (reader->Read()) {
			String^ accountName = reader->GetString(0);
			int accountID = reader->GetInt32(1);
			String^ lastDigits = reader->GetString(2);
			this->accountListCombo->Items->Add(gcnew ComboItem(accountName + " - **** " + lastDigits, accountID, 0));
		}
	}
	catch (SqlException^ e) {
		MessageBox::Show(e->Message, "B³¹d po³¹czenia", MessageBoxButtons::OK);
	}
}

System::Void RemoveBill::removeBillBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	this->errorLb->Text = "";
	int selectedItemID = this->accountListCombo->SelectedIndex;
	if (selectedItemID < 0) {
		this->errorLb->Text = "Nie wybrano rachunku!";
		return;
	}
	ComboItem^ item = safe_cast<ComboItem^>(this->accountListCombo->Items[selectedItemID]);
	int selectedComboID = item->GetTagValue();
	try {
		SqlConnection sqlConn(ConvertString::toSystemString(DatabaseConfig::sqlConnectionString));
		sqlConn.Open();

		String^ sqlQuery = "UPDATE BankAccounts SET Active = 0 WHERE AccountID = @AccountID";

		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@AccountID", selectedComboID);

		command.ExecuteNonQuery();
		sqlConn.Close();

		MessageBox::Show("Rachunek zosta³ zamkniêty", "Informacja", MessageBoxButtons::OK);
		this->Close();
	}
	catch (SqlException^ e) {
		MessageBox::Show(e->Message, "B³¹d po³¹czenia", MessageBoxButtons::OK);
	}
}
