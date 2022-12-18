#include "MainForm.h"
#include "LoginForm.h"
#include "PasswordForm.h"
#include "User.h"

using namespace System;
using namespace System::Windows::Forms;

int main(array <String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	AGHBank::MainForm MainForm;
	AGHBank::LoginForm LoginForm;

	LoginForm.ShowDialog();

	User^ user = LoginForm.user;

	if (user == nullptr) {
		MessageBox::Show("U¿ytkownik nie zosta³ autoryzowany. Zamykanie programu.", "B³¹d autoryzacji", MessageBoxButtons::OK);
		return 0;
	}

	AGHBank::PasswordForm PasswordForm(user->name);
	PasswordForm.ShowDialog();

	user->auth = PasswordForm.auth;

	if (user->auth) {
		MainForm.ShowDialog();
	}
	else {
		MessageBox::Show("U¿ytkownik nie zosta³ autoryzowany. Zamykanie programu.", "B³¹d autoryzacji", MessageBoxButtons::OK);
	}

	return 0;
}