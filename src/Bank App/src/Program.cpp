#include "LoginForm.h"
#include "MainForm.h"
#include "PasswordForm.h"
#include "RegisterForm.h"
#include "User.h"

using namespace System;
using namespace System::Windows::Forms;

int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	User^ person = nullptr;

	while (true) {
		AGHBank::LoginForm LoginForm;
		LoginForm.ShowDialog();

		if (LoginForm.switchToRegister) {
			AGHBank::RegisterForm RegisterForm;
			RegisterForm.ShowDialog();
			if (RegisterForm.switchToLogin) {
				continue;
			}
			else {
				break;
			}
		}
		else {
			person = LoginForm.person;
			if (person == nullptr) {
				return 0;
			}
			else {
				AGHBank::PasswordForm PasswordForm(person->name);
				PasswordForm.ShowDialog();

				if (PasswordForm.switchToLogin) {
					continue;
				}
				else {
					person->auth = PasswordForm.auth;
					break;
				}
			}
		}
	}

	if (person != nullptr && person->auth) {
		AGHBank::MainForm MainForm(person->id, person->name);
		MainForm.ShowDialog();
	}

	return 0;
}