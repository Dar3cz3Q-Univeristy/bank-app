#include "PasswordForm.h"
#include "Database.h"
#include "StringConversion.h"
#include "bcrypt.h"

using namespace AGHBank;

System::Void PasswordForm::PasswordForm_Load(System::Object^ sender, System::EventArgs^ e) {
	this->greetingLb->Text = "Witaj " + loggingUsername + "!";
}

System::Void PasswordForm::nextBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	this->nextBtn->Enabled = false;
	String^ password = this->passwordInput->Text;
	if (password->Length == 0) {
		this->passwordErrorLb->Text = "Nie wpisano has³a!";
		this->nextBtn->Enabled = true;
		return;
	}
	try {
		SqlConnection sqlConn(ConvertString::toSystemString(DatabaseConfig::sqlConnectionString));
		sqlConn.Open();

		String^ sqlQuery = "SELECT Password FROM PersonLogins WHERE Username = @Username;";

		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@Username", loggingUsername);

		SqlDataReader^ reader = command.ExecuteReader();

		if (reader->Read()) {
			String^ downloadedPassword = reader->GetString(0);
			if (bcrypt::validatePassword(ConvertString::toStandardString(password), ConvertString::toStandardString(downloadedPassword))) {
				auth = true;
				this->Close();
			}
			else {
				auth = false;
				this->nextBtn->Enabled = true;
				this->restorePasswordLink->Text = "Odzyskaj has³o";
				this->passwordErrorLb->Text = "B³êdne has³o!";
			}
		}

		reader->Close();
		sqlConn.Close();
	}
	catch (SqlException^ e) {
		this->nextBtn->Enabled = true;
		if (e->Number == 53) {
			this->passwordErrorLb->Text = "Problem z baz¹ danych. Spróbuj ponownie za kilka minut.";
			return;
		}
		MessageBox::Show(e->Message, "B³¹d po³¹czenia", MessageBoxButtons::OK);
	}
}

System::Void PasswordForm::backLink_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	this->switchToLogin = true;
	this->Close();
}