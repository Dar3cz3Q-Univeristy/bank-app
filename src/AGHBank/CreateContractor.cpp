#include "CreateContractor.h"
#include "Database.h"
#include "StringConversion.h"
#include "ArrayCheck.h"

using namespace AGHBank;

System::Void CreateContractor::CreateContractor_Load(System::Object^ sender, System::EventArgs^ e) {}

System::Void CreateContractor::accountNumberInput_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
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

System::Void CreateContractor::accountNumberInput_Leave(System::Object^ sender, System::EventArgs^ e) {
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

System::Void CreateContractor::addContractorBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	this->addContractorBtn->Enabled = false;
	this->errorLb->Text = "";
	String^ customName = this->customNameInput->Text;
	String^ accountNumber = this->accountNumberInput->Text;

	if (customName->Length == 0) {
		this->errorLb->Text = "Prosze uzupelnic puste pola!";
		this->addContractorBtn->Enabled = true;
		return;
	}

	if (accountNumber->Length != 35) {
		this->errorLb->Text = "Prosze uzupelnic/poprawic numer konta!";
		this->addContractorBtn->Enabled = true;
		return;
	}

	try {
		SqlConnection sqlConn(ConvertString::toSystemString(DatabaseConfig::sqlConnectionString));
		sqlConn.Open();

		String^ sqlQuery = "INSERT INTO Contractors(PersonID, CustomName, Number) VALUES(@personID, @customName, @number)";

		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@personID", loggedUserID);
		command.Parameters->AddWithValue("@customName", customName);
		command.Parameters->AddWithValue("@number", accountNumber);

		command.ExecuteNonQuery();
		sqlConn.Close();

		MessageBox::Show("Kontrahent zostal utworzony pomyslnie", "Informacja", MessageBoxButtons::OK);

		sqlConn.Close();
	}
	catch (SqlException^ e) {
		this->addContractorBtn->Enabled = true;
		MessageBox::Show(e->Message, "Blad polaczenia", MessageBoxButtons::OK);
	}
	this->Close();
}