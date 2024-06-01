#include "PaymentUC.h"
#include "Database.h"
#include "StringConversion.h"
#include "ComboItem.h"

using namespace AGHBank;

System::Void PaymentUC::PaymentUC_Load(System::Object^ sender, System::EventArgs^ e) {
	try {
		SqlConnection sqlConn(ConvertString::toSystemString(DatabaseConfig::sqlConnectionString));
		sqlConn.Open();

		String^ sqlQuery = "SELECT AccType.Name, Acc.AccountID, RIGHT(Acc.Number, 4) as 'Last digits', Acc.Currency FROM BankAccounts as Acc JOIN BankAccountTypes as AccType ON Acc.TypeID = AccType.TypeID WHERE Acc.PersonID = @personID AND Acc.Active = 1";

		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@personID", loggedUserID);

		SqlDataReader^ reader = command.ExecuteReader();

		while (reader->Read()) {
			String^ accountName = reader->GetString(0);
			int accountID = reader->GetInt32(1);
			String^ lastDigits = reader->GetString(2);
			int accountCurrencyID = reader->GetInt32(3);
			this->billsComboBox->Items->Add(gcnew ComboItem(accountName + " - **** " + lastDigits, accountID, accountCurrencyID, ""));
		}

		reader->Close();
		sqlConn.Close();
	}
	catch (SqlException^ e) {
		MessageBox::Show(e->Message, "Blad polaczenia", MessageBoxButtons::OK);
	}
}

System::Void PaymentUC::billsComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	this->amountInput->Enabled = true;
	this->currencyComboBox->Enabled = true;
	selectedComboID = this->billsComboBox->SelectedIndex;
	ComboItem^ item = safe_cast<ComboItem^>(this->billsComboBox->Items[selectedComboID]);
	selectedAccountID = item->GetTagValue();
	int accountCurrencyID = item->GetAdditionalValue();
	try {
		SqlConnection sqlConn(ConvertString::toSystemString(DatabaseConfig::sqlConnectionString));
		sqlConn.Open();

		String^ sqlQuery = "SELECT Shortcut FROM Currencies";

		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@personID", loggedUserID);

		SqlDataReader^ reader = command.ExecuteReader();

		while (reader->Read()) {
			String^ currencyShortcut = reader->GetString(0);
			this->currencyComboBox->Items->Add(currencyShortcut);
		}

		reader->Close();
		sqlConn.Close();

		this->currencyComboBox->SelectedIndex = accountCurrencyID - 1;
	}
	catch (SqlException^ e) {
		MessageBox::Show(e->Message, "Blad polaczenia", MessageBoxButtons::OK);
	}
}

System::Void PaymentUC::nextBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	this->nextBtn->Enabled = false;
	this->errorLb->Text = "";
	int selectedCurrencyID = this->currencyComboBox->SelectedIndex;
	String^ amount = this->amountInput->Text;
	if (selectedComboID < 0 || selectedCurrencyID < 0 || amount->Length == 0) {
		this->errorLb->Text = "Proszê uzupelnic puste pola!";
		this->nextBtn->Enabled = true;
		return;
	}
	int transactionType = this->paymentRadioBtn->Checked ? 1 : 2;
	selectedCurrencyID++;
	try {
		SqlConnection sqlConn(ConvertString::toSystemString(DatabaseConfig::sqlConnectionString));
		sqlConn.Open();

		String^ sqlQuery = "exec AddPaymentPaycheck @accountID, @currencyID, @amount, @typeID";

		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@accountID", selectedAccountID);
		command.Parameters->AddWithValue("@currencyID", selectedCurrencyID);
		command.Parameters->AddWithValue("@amount", amount);
		command.Parameters->AddWithValue("@typeID", transactionType);

		command.ExecuteNonQuery();
		sqlConn.Close();

		String^ infoType = transactionType == 1 ? "wp³acone" : "wyp³acone";

		MessageBox::Show("Pieniadze zostaly " + infoType + " pomyslnie", "Informacja", MessageBoxButtons::OK);
	}
	catch (SqlException^ e) {
		this->nextBtn->Enabled = true;
		if (e->Number == 547) {
			this->errorLb->Text = "Niewystarczajaca ilosc srodków!";
			return;
		}
		MessageBox::Show(e->Message, "Blad polaczenia", MessageBoxButtons::OK);
	}
}

System::Void PaymentUC::amountInput_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar == '.') {
		if (this->amountInput->Text->Contains(".") && !this->amountInput->SelectedText->Contains(".")) {
			e->Handled = true;
		}
	}
	else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}
}