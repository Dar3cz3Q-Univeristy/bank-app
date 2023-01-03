#include "ChangePassword.h"
#include <string>
#include <regex>
#include "Database.h"
#include "bcrypt.h"
#include "StringConversion.h"
#include "PersonDetailsConstraints.h"

using namespace AGHBank;

System::Void ChangePassword::createBillBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	this->errorLb->Text = "";

	String^ oldPassword = this->oldPasswordInput->Text;
	String^ newPassword = this->newPasswordInput->Text;
	String^ retypedNewPassword = this->retypedNewPasswordInput->Text;

	if (oldPassword->Length == 0 || newPassword->Length == 0 || retypedNewPassword->Length == 0) {
		this->errorLb->Text = "Prosz� uzupe�ni� puste pola!";
		return;
	}

	const std::string PASSWORD_REGEX{ "^(?=.*?[A-Z])(?=(.*[a-z]){1,})(?=(.*[\\d]){1,})(?=(.*[\\W]){1,})(?!.*\\s).{4,16}$" };

	std::regex regexPasswordRule(PASSWORD_REGEX);
	std::string passwordString = ConvertString::toStandardString(newPassword);
	bool isPasswordValid = regex_match(passwordString, regexPasswordRule);

	if (!isPasswordValid) {
		this->errorLb->Text = "Nowe has�o musi posiada� od 4 do 16 znak�w, du�� liter�, ma�� liter�, liczb�, znak specjalny!";
		return;
	}

	if (newPassword != retypedNewPassword) {
		this->errorLb->Text = "Has�a nie s� takie same!";
		return;
	}

	try {
		SqlConnection sqlConn(ConvertString::toSystemString(DatabaseConfig::sqlConnectionString));
		sqlConn.Open();

		String^ sqlQuery = "SELECT Password FROM PersonLogins WHERE PersonID = @personID;";

		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@personID", loggedUserID);

		SqlDataReader^ reader = command.ExecuteReader();

		if (reader->Read()) {
			String^ downloadedPassword = reader->GetString(0);
			if (!bcrypt::validatePassword(ConvertString::toStandardString(oldPassword), ConvertString::toStandardString(downloadedPassword))) {
				this->errorLb->Text = "Aktualne has�o jest niepoprawne!";
				return;
			}
		}

		reader->Close();

		String^ newHashedPassword = gcnew String(bcrypt::generateHash(passwordString).c_str());

		sqlQuery = "UPDATE PersonLogins SET Password = @newPassword WHERE PersonID = @personID;";

		SqlCommand secondCommand(sqlQuery, % sqlConn);
		secondCommand.Parameters->AddWithValue("@newPassword", newHashedPassword);
		secondCommand.Parameters->AddWithValue("@personID", loggedUserID);

		secondCommand.ExecuteNonQuery();

		sqlConn.Close();
		MessageBox::Show("Has�o zosta�o pomy�lnie zmienione", "Informacja", MessageBoxButtons::OK);
	}
	catch (SqlException^ e) {
		MessageBox::Show(e->Message, "B��d po��czenia", MessageBoxButtons::OK);
	}
	this->Close();
}

