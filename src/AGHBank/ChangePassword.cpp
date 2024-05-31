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
		this->errorLb->Text = "Prosze uzupelnic puste pola!";
		return;
	}

	const std::string PASSWORD_REGEX{ "^(?=.*?[A-Z])(?=(.*[a-z]){1,})(?=(.*[\\d]){1,})(?=(.*[\\W]){1,})(?!.*\\s).{4,16}$" };

	std::regex regexPasswordRule(PASSWORD_REGEX);
	std::string passwordString = ConvertString::toStandardString(newPassword);
	bool isPasswordValid = regex_match(passwordString, regexPasswordRule);

	if (!isPasswordValid) {
		this->errorLb->Text = "Nowe haslo musi posiadac od 4 do 16 znaków, duza litere, mala litere, liczbe, znak specjalny!";
		return;
	}

	if (newPassword != retypedNewPassword) {
		this->errorLb->Text = "Hasla nie sa takie same!";
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
				this->errorLb->Text = "Aktualne haslo jest niepoprawne!";
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
		MessageBox::Show("Haslo zostalo pomyslnie zmienione", "Informacja", MessageBoxButtons::OK);
	}
	catch (SqlException^ e) {
		MessageBox::Show(e->Message, "Blad polaczenia", MessageBoxButtons::OK);
	}
	this->Close();
}

