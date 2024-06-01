#include "LoginForm.h"

#include "Database.h"
#include "StringConversion.h"
#include "User.h"

using namespace AGHBank;

System::Void LoginForm::nextBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	this->nextBtn->Enabled = false;
	String^ username = this->loginInput->Text;
	this->loginErrorLb->Text = "";
	if (username->Length == 0) {
		this->loginErrorLb->Text = "Nie wpisano nazwy uzytkownika!";
		this->nextBtn->Enabled = true;
		return;
	}
	try {
		SqlConnection sqlConn(ConvertString::toSystemString(DatabaseConfig::sqlConnectionString));
		sqlConn.Open();

		String^ sqlQuery = "SELECT PersonID, Username FROM PersonLogins WHERE Username = "
			"@Username AND Active = 1;";

		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@Username", username);

		SqlDataReader^ reader = command.ExecuteReader();

		if (reader->Read()) {
			person = gcnew User;
			person->id = reader->GetInt32(0);
			person->name = reader->GetString(1);
			this->Close();
		}
		else {
			person = nullptr;
			this->nextBtn->Enabled = true;
			this->loginErrorLb->Text = "Nie istnieje taki uzytkownik!";
		}
		reader->Close();
		sqlConn.Close();
	}
	catch (SqlException^ e) {
		this->nextBtn->Enabled = true;
		if (e->Number == 53) {
			this->loginErrorLb->Text = "Problem z baza danych. Spróbuj ponownie za kilka minut.";
			return;
		}
		MessageBox::Show(e->Message, "Blad polaczenia", MessageBoxButtons::OK);
	}
}

System::Void LoginForm::noAccountLink_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	this->switchToRegister = true;
	this->Close();
}
