#include "RegisterForm.h"
#include <string>
#include <regex>
#include <ctime>
#include "Database.h"
#include "bcrypt.h"
#include "StringConversion.h"
#include "PersonDetailsConstraints.h"

using namespace AGHBank;

System::Void RegisterForm::RegisterForm_Load(System::Object^ sender, System::EventArgs^ e) {
	std::time_t now = std::time(0);
	std::tm* today = std::localtime(&now);
	this->birthDatePicker->MaxDate = System::DateTime(today->tm_year + 1900, today->tm_mon + 1, today->tm_mday, 0, 0, 0, 0);
	this->birthDatePicker->Value = System::DateTime(today->tm_year + 1882, today->tm_mon + 1, today->tm_mday - 1, 0, 0, 0, 0);
}

System::Void RegisterForm::noAccountLink_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	this->switchToLogin = true;
	this->Close();
}

System::Void RegisterForm::nextBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	this->nextBtn->Enabled = false;
	String^ username = this->usernameInput->Text;
	String^ email = this->emailInput->Text;
	String^ password = this->passwordInput->Text;
	String^ retypedPassword = this->retypedPasswordInput->Text;
	String^ forename = this->forenameInput->Text;
	String^ surname = this->surnameInput->Text;
	String^ pesel = this->peselInput->Text;
	String^ cardID = this->cardIDInput->Text;
	String^ phoneNumber = this->phoneInput->Text;
	DateTime birthDate = this->birthDatePicker->Value;

	this->registerErrorLb->Text = "";

	bool emptyFields = false;

	//Sprawdzenie czy pola nie s¹ puste

	if (username->Length == 0) {
		emptyFields = true;
	}
	if (email->Length == 0) {
		emptyFields = true;
	}
	if (password->Length == 0) {
		emptyFields = true;
	}
	if (retypedPassword->Length == 0) {
		emptyFields = true;
	}
	if (forename->Length == 0) {
		emptyFields = true;
	}
	if (surname->Length == 0) {
		emptyFields = true;
	}
	if (pesel->Length == 0) {
		emptyFields = true;
	}
	if (cardID->Length == 0) {
		emptyFields = true;
	}
	if (phoneNumber->Length == 0) {
		emptyFields = true;
	}

	if (emptyFields) {
		this->registerErrorLb->Text = "Uzupe³nij puste pola!";
		this->nextBtn->Enabled = true;
		return;
	}

	//Dok³adniejsze sprawdzenie wprowadzonych danych

	if (!PersonDetailsCheck::peselSum(ConvertString::toStandardString(pesel))) {
		this->registerErrorLb->Text = "Pesel jest niepoprawny!";
		this->nextBtn->Enabled = true;
		return;
	}

	if (!PersonDetailsCheck::idCardSum(ConvertString::toStandardString(cardID))) {
		this->registerErrorLb->Text = "Numer dowodu osobistego jest niepoprawny!";
		this->nextBtn->Enabled = true;
		return;
	}

	if (phoneNumber->Length != 9) {
		this->registerErrorLb->Text = "Numer telefonu jest niepoprawny!";
		this->nextBtn->Enabled = true;
		return;
	}

	if (!PersonDetailsCheck::isAdult(birthDate)) {
		this->registerErrorLb->Text = "Osoba musi byæ pe³noletnia!";
		this->nextBtn->Enabled = true;
		return;
	}

	const std::string EMAIL_REGEX{ "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+" };

	std::regex regexEmailRule(EMAIL_REGEX);
	std::string emailString = ConvertString::toStandardString(email);
	bool isEmailValid = regex_match(emailString, regexEmailRule);

	if (!isEmailValid) {
		this->registerErrorLb->Text = "E-Mail jest niepoprawny!";
		this->nextBtn->Enabled = true;
		return;
	}

	const std::string PASSWORD_REGEX{ "^(?=.*?[A-Z])(?=(.*[a-z]){1,})(?=(.*[\\d]){1,})(?=(.*[\\W]){1,})(?!.*\\s).{4,16}$" };

	std::regex regexPasswordRule(PASSWORD_REGEX);
	std::string passwordString = ConvertString::toStandardString(password);
	bool isPasswordValid = regex_match(passwordString, regexPasswordRule);

	if (!isPasswordValid) {
		this->registerErrorLb->Text = "Has³o musi posiadaæ od 4 do 16 znaków, du¿¹ literê, ma³¹ literê, liczbê, znak specjalny!";
		this->nextBtn->Enabled = true;
		return;
	}

	if (password != retypedPassword) {
		this->registerErrorLb->Text = "Has³a nie s¹ takie same!";
		this->nextBtn->Enabled = true;
		return;
	}

	String^ hashedPassword = gcnew String(bcrypt::generateHash(passwordString).c_str());

	//Zapis danych w bazie danych

	try {
		SqlConnection sqlConn(ConvertString::toSystemString(DatabaseConfig::sqlConnectionString));
		sqlConn.Open();

		String^ sqlQuery = "exec CreateAccount @Username, @Password, @Forename, @Surname, @EMail, @Phone, @CardID, @Pesel, @Birthdate";

		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@Username", username);
		command.Parameters->AddWithValue("@Password", hashedPassword);
		command.Parameters->AddWithValue("@Forename", forename);
		command.Parameters->AddWithValue("@Surname", surname);
		command.Parameters->AddWithValue("@EMail", email);
		command.Parameters->AddWithValue("@Phone", phoneNumber);
		command.Parameters->AddWithValue("@CardID", cardID);
		command.Parameters->AddWithValue("@Pesel", pesel);
		command.Parameters->AddWithValue("@Birthdate", birthDate);

		command.ExecuteNonQuery();
		sqlConn.Close();

		MessageBox::Show("Konto zosta³o utworzone pomyœlnie", "Informacja", MessageBoxButtons::OK);

		this->switchToLogin = true;
		this->Close();
	}
	catch (SqlException^ e) {
		this->nextBtn->Enabled = true;
		if (e->Number == 53) {
			this->registerErrorLb->Text = "Problem z baz¹ danych. Spróbuj ponownie za kilka minut.";
			return;
		}
		if (e->Number == 2627) {
			this->registerErrorLb->Text = "U¿ytkownk ju¿ istnieje, Pewne dane siê powtarzaj¹!";
			return;
		}
		MessageBox::Show(e->Message, "B³¹d po³¹czenia", MessageBoxButtons::OK);
	}
}