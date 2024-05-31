#include "TransferUC.h"
#include "Database.h"
#include "StringConversion.h"
#include "ComboItem.h"
#include "SelectContractor.h"
#include "ArrayCheck.h"

using namespace AGHBank;

System::Void TransferUC::countryTransferRadioBtn_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	selectedType = this->countryTransferRadioBtn->Checked;
	if (selectedType) {
		this->countryTransferPanel->BringToFront();
		this->accountNumberInput->TabStop = true;
		this->savedContractorsBtn->TabStop = true;
		this->ownBillsComboBox->TabStop = false;
	}
	else {
		this->countryTransferPanel->SendToBack();
		this->accountNumberInput->TabStop = false;
		this->savedContractorsBtn->TabStop = false;
		this->ownBillsComboBox->TabStop = true;
	}
}

System::Void TransferUC::TransferUC_Load(System::Object^ sender, System::EventArgs^ e) {
	try {
		SqlConnection sqlConn(ConvertString::toSystemString(DatabaseConfig::sqlConnectionString));
		sqlConn.Open();

		String^ sqlQuery = "SELECT AccType.Name, Acc.AccountID, RIGHT(Acc.Number, 4) as 'Last digits', Acc.Currency, Acc.Number FROM BankAccounts as Acc JOIN BankAccountTypes as AccType ON Acc.TypeID = AccType.TypeID WHERE Acc.PersonID = @personID AND Acc.Active = 1";

		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@personID", loggedUserID);

		SqlDataReader^ reader = command.ExecuteReader();

		while (reader->Read()) {
			String^ accountName = reader->GetString(0);
			int accountID = reader->GetInt32(1);
			String^ lastDigits = reader->GetString(2);
			int accountCurrencyID = reader->GetInt32(3);
			String^ accountNumber = reader->GetString(4);
			this->startingAccountComboBox->Items->Add(gcnew ComboItem(accountName + " - **** " + lastDigits, accountID, accountCurrencyID, accountNumber));
		}

		reader->Close();

		sqlQuery = "SELECT Shortcut FROM Currencies";

		SqlCommand secondCommand(sqlQuery, % sqlConn);

		reader = secondCommand.ExecuteReader();

		while (reader->Read()) {
			String^ currencyShortcut = reader->GetString(0);
			this->currencyComboBox->Items->Add(currencyShortcut);
		}

		this->currencyComboBox->SelectedIndex = 0;

		reader->Close();
		sqlConn.Close();
	}
	catch (SqlException^ e) {
		MessageBox::Show(e->Message, "Blad polaczenia", MessageBoxButtons::OK);
	}
}

System::Void TransferUC::startingAccountComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	int startingAccountSelectedIndex = this->startingAccountComboBox->SelectedIndex;

	this->ownBillsComboBox->Items->Clear();

	ComboItem^ item = safe_cast<ComboItem^>(this->startingAccountComboBox->Items[startingAccountSelectedIndex]);
	startingAccountID = item->GetTagValue();

	try {
		SqlConnection sqlConn(ConvertString::toSystemString(DatabaseConfig::sqlConnectionString));
		sqlConn.Open();

		String^ sqlQuery = "SELECT AccType.Name, Acc.AccountID, RIGHT(Acc.Number, 4) as 'Last digits', Acc.Currency, Acc.Number FROM BankAccounts as Acc JOIN BankAccountTypes as AccType ON Acc.TypeID = AccType.TypeID WHERE Acc.PersonID = @personID AND Acc.Active = 1 AND Acc.AccountID != @startAccID";

		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@personID", loggedUserID);
		command.Parameters->AddWithValue("@startAccID", startingAccountID);

		SqlDataReader^ reader = command.ExecuteReader();

		while (reader->Read()) {
			String^ accountName = reader->GetString(0);
			int accountID = reader->GetInt32(1);
			String^ lastDigits = reader->GetString(2);
			int accountCurrencyID = reader->GetInt32(3);
			String^ accountNumber = reader->GetString(4);
			this->ownBillsComboBox->Items->Add(gcnew ComboItem(accountName + " - **** " + lastDigits, accountID, accountCurrencyID, accountNumber));
		}

		reader->Close();
		sqlConn.Close();

		this->ownBillsComboBox->Enabled = true;
	}
	catch (SqlException^ e) {
		MessageBox::Show(e->Message, "Blad polaczenia", MessageBoxButtons::OK);
	}
}

System::Void TransferUC::accountNumberInput_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	int currentStringLength = this->accountNumberInput->Text->Length + 1;

	if (Char::IsControl(e->KeyChar)) {
		e->Handled = false;
	}
	else if (ArrayCheck::contains(currentStringLength)) {
		if (int(e->KeyChar) == 32 || e->KeyChar == 0x08) {
			e->Handled = false;
		}
		else {
			e->Handled = true;
			this->accountNumberInput->AppendText(" " + e->KeyChar);
		}
	}
	else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}
}

System::Void TransferUC::accountNumberInput_Leave(System::Object^ sender, System::EventArgs^ e) {
	String^ accountNumber = this->accountNumberInput->Text;
	String^ resultNumber = "";
	for (int i = 0; i < accountNumber->Length; i++) {
		if (ArrayCheck::contains(resultNumber->Length + 1)) {
			if (!Char::IsDigit(accountNumber[i])) {
				resultNumber += accountNumber[i];
			}
			else {
				resultNumber += " " + accountNumber[i];
			}
		}
		else {
			if (Char::IsDigit(accountNumber[i])) {
				resultNumber += accountNumber[i];
			}
		}
		if (resultNumber->Length == 35) {
			break;
		}
	}
	this->accountNumberInput->Text = resultNumber;
}

System::Void TransferUC::amountInput_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar == '.') {
		if (this->amountInput->Text->Contains(".") && !this->amountInput->SelectedText->Contains(".")) {
			e->Handled = true;
		}
	}
	else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}
}

System::Void TransferUC::nextBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	this->nextBtn->Enabled = false;
	this->errorLb->Text = "";
	String^ accountNumber;
	String^ title = this->titleInput->Text;
	String^ amount = this->amountInput->Text;
	int currencyID = this->currencyComboBox->SelectedIndex + 1;

	if (selectedType == 1) {
		accountNumber = this->accountNumberInput->Text;
		if (accountNumber->Length != 35) {
			this->errorLb->Text = "Prosze uzupelnic/poprawic numer konta!";
			this->nextBtn->Enabled = true;
			return;
		}
	}
	else {
		int ownBillSelectedIndex = this->ownBillsComboBox->SelectedIndex;
		if (ownBillSelectedIndex < 0) {
			this->errorLb->Text = "Prosze wybrac rachunek!";
			this->nextBtn->Enabled = true;
			return;
		}
		ComboItem^ item = safe_cast<ComboItem^>(this->ownBillsComboBox->Items[ownBillSelectedIndex]);
		accountNumber = item->GetAccountNumber();
	}

	if (amount->Length == 0) {
		this->errorLb->Text = "Prosze uzupelnic puste pola!";
		this->nextBtn->Enabled = true;
		return;
	}

	try {
		SqlConnection sqlConn(ConvertString::toSystemString(DatabaseConfig::sqlConnectionString));
		sqlConn.Open();

		String^ sqlQuery = "exec AddTransfer @startingAccountID, @destinationAccountNumber, @title, @amount, @currencyID";

		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@startingAccountID", startingAccountID);
		command.Parameters->AddWithValue("@destinationAccountNumber", accountNumber);
		command.Parameters->AddWithValue("@title", title);
		command.Parameters->AddWithValue("@amount", amount);
		command.Parameters->AddWithValue("@currencyID", currencyID);

		command.ExecuteNonQuery();
		sqlConn.Close();

		MessageBox::Show("Pieniadze zostaly przelane pomyslnie", "Informacja", MessageBoxButtons::OK);
	}
	catch (SqlException^ e) {
		this->nextBtn->Enabled = true;
		if (e->Number == 50005) {
			this->errorLb->Text = e->Message;
			return;
		}
		if (e->Number == 547) {
			this->errorLb->Text = "Niewystarczajaca ilosc srodków!";
			return;
		}
		MessageBox::Show(e->Message, "Blad polaczenia", MessageBoxButtons::OK);
	}
}

System::Void TransferUC::savedContractorsBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	AGHBank::SelectContractor SelectContractor(loggedUserID);
	SelectContractor.ShowDialog();
	this->accountNumberInput->Text = SelectContractor.selectedContractorNumber;
}
