#include "SettingsUC.h"
#include "Database.h"
#include "StringConversion.h"
#include "ChangePassword.h"
#include "PersonDetailsConstraints.h"
#include <ctime>
#include <string>
#include <regex>

using namespace AGHBank;

System::Void SettingsUC::SettingsUC_Load(System::Object^ sender, System::EventArgs^ e) {
	try {
		SqlConnection sqlConn(ConvertString::toSystemString(DatabaseConfig::sqlConnectionString));
		sqlConn.Open();

		String^ sqlQuery = "SELECT Forename, Surname, PhoneNumber, BirthDate, EMail FROM PersonDetails WHERE PersonID = @personID;";

		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@personID", loggedUserID);

		SqlDataReader^ reader = command.ExecuteReader();

		if (reader->Read()) {
			this->forenameInput->Text = reader->GetString(0);
			this->surnameInput->Text = reader->GetString(1);
			this->phoneInput->Text = reader->GetString(2);
			this->birthDatePicker->Value = reader->GetDateTime(3);
			this->emailInput->Text = reader->GetString(4);

			std::time_t now = std::time(0);
			std::tm* today = std::localtime(&now);
			this->birthDatePicker->MaxDate = System::DateTime(today->tm_year + 1900, today->tm_mon + 1, today->tm_mday, 0, 0, 0, 0);

		}

		reader->Close();
		sqlConn.Close();
	}
	catch (SqlException^ e) {
		MessageBox::Show(e->Message, "Blad polaczenia", MessageBoxButtons::OK);
	}
}

System::Void SettingsUC::changePasswordBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	AGHBank::ChangePassword ChangePassword(loggedUserID);
	ChangePassword.ShowDialog();
}

System::Void SettingsUC::deleteAccountBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("Czy na pewno chcesz usunac konto?", "Usuwanie konta", MessageBoxButtons::YesNo) != ::DialogResult::Yes) {
		return;
	}
	try {
		SqlConnection sqlConn(ConvertString::toSystemString(DatabaseConfig::sqlConnectionString));
		sqlConn.Open();

		String^ sqlQuery = "UPDATE PersonLogins SET Active = 0, Username = @removedName WHERE PersonID = @personID;";

		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@personID", loggedUserID);
		command.Parameters->AddWithValue("@removedName", "DeletedUser" + loggedUserID);

		command.ExecuteNonQuery();

		sqlConn.Close();
	}
	catch (SqlException^ e) {
		MessageBox::Show(e->Message, "Blad polaczenia", MessageBoxButtons::OK);
	}
	Application::Exit();
}

System::Void SettingsUC::nextBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	this->settingsErrorLb->Text = "";
	this->nextBtn->Enabled = false;

	String^ forename = this->forenameInput->Text;
	String^ surname = this->surnameInput->Text;
	String^ phoneNumber = this->phoneInput->Text;
	DateTime birthDate = this->birthDatePicker->Value;
	String^ email = this->emailInput->Text;

	bool emptyFields = false;

	if (forename->Length == 0) {
		emptyFields = true;
	}
	if (surname->Length == 0) {
		emptyFields = true;
	}
	if (phoneNumber->Length == 0) {
		emptyFields = true;
	}
	if (email->Length == 0) {
		emptyFields = true;
	}

	if (emptyFields) {
		this->settingsErrorLb->Text = "Uzupelnij puste pola!";
		this->nextBtn->Enabled = true;
		return;
	}

	if (phoneNumber->Length != 9) {
		this->settingsErrorLb->Text = "Numer telefonu jest niepoprawny!";
		this->nextBtn->Enabled = true;
		return;
	}

	if (!PersonDetailsCheck::isAdult(birthDate)) {
		this->settingsErrorLb->Text = "Osoba musi byc pelnoletnia!";
		this->nextBtn->Enabled = true;
		return;
	}

	const std::string EMAIL_REGEX{ "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+" };

	std::regex regexEmailRule(EMAIL_REGEX);
	std::string emailString = ConvertString::toStandardString(email);
	bool isEmailValid = regex_match(emailString, regexEmailRule);

	if (!isEmailValid) {
		this->settingsErrorLb->Text = "E-Mail jest niepoprawny!";
		this->nextBtn->Enabled = true;
		return;
	}

	try {
		SqlConnection sqlConn(ConvertString::toSystemString(DatabaseConfig::sqlConnectionString));
		sqlConn.Open();

		String^ sqlQuery = "UPDATE PersonDetails SET Forename = @Forename, Surname = @Surname, EMail = @EMail, PhoneNumber = @Phone, BirthDate = @Birthdate WHERE PersonID = @personID;";

		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@personID", loggedUserID);
		command.Parameters->AddWithValue("@Forename", forename);
		command.Parameters->AddWithValue("@Surname", surname);
		command.Parameters->AddWithValue("@EMail", email);
		command.Parameters->AddWithValue("@Phone", phoneNumber);
		command.Parameters->AddWithValue("@Birthdate", birthDate);

		command.ExecuteNonQuery();
		sqlConn.Close();

		MessageBox::Show("Dane zostaly zmienione pomyslnie", "Informacja", MessageBoxButtons::OK);
	}
	catch (SqlException^ e) {
		this->nextBtn->Enabled = true;
		if (e->Number == 53) {
			this->settingsErrorLb->Text = "Problem z baza danych. Spróbuj ponownie za kilka minut.";
			return;
		}
		if (e->Number == 2627) {
			this->settingsErrorLb->Text = "EMail, Numer telefonu jest juz zajety!";
			return;
		}
		MessageBox::Show(e->Message, "Blad polaczenia", MessageBoxButtons::OK);
	}
}
