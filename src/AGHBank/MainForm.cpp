#include "MainForm.h"
#include "User.h"
#include "Database.h"
#include "StringConversion.h"
#include "AccountUC.h"
#include "BillsUC.h"
#include "PaymentUC.h"
#include "TransferUC.h"
#include "ContractorsUC.h"
#include "SettingsUC.h"

using namespace AGHBank;

void MainForm::addUserControl(UserControl^ userControl) {
	userControl->Dock = DockStyle::Fill;
	this->PanelContainer->Controls->Clear();
	this->PanelContainer->Controls->Add(userControl);
	userControl->BringToFront();
}

void MainForm::resetColorsBtns() {
	this->accountBtn->ForeColor = Color::FromArgb(1, 0, 0, 0);
	this->billBtn->ForeColor = Color::FromArgb(1, 0, 0, 0);
	this->settingsBtn->ForeColor = Color::FromArgb(1, 0, 0, 0);
	this->contractorsBtn->ForeColor = Color::FromArgb(1, 0, 0, 0);
	this->transferBtn->ForeColor = Color::FromArgb(1, 0, 0, 0);
	this->paymentBtn->ForeColor = Color::FromArgb(1, 0, 0, 0);
}

System::Void MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	this->userNameLb->Text = loggedUserName;
	AccountUC^ userControl = gcnew AccountUC(loggedUserID);
	addUserControl(userControl);
}

System::Void MainForm::accountBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	AccountUC^ userControl = gcnew AccountUC(loggedUserID);
	addUserControl(userControl);
	resetColorsBtns();
	this->accountBtn->ForeColor = Color::FromArgb(1, 193, 13, 20);
}

System::Void MainForm::contractorsBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	ContractorsUC^ userControl = gcnew ContractorsUC(loggedUserID);
	addUserControl(userControl);
	resetColorsBtns();
	this->contractorsBtn->ForeColor = Color::FromArgb(1, 193, 13, 20);
}

System::Void MainForm::billBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	BillsUC^ userControl = gcnew BillsUC(loggedUserID);
	addUserControl(userControl);
	resetColorsBtns();
	this->billBtn->ForeColor = Color::FromArgb(1, 193, 13, 20);
}

System::Void MainForm::paymentBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	PaymentUC^ userControl = gcnew PaymentUC(loggedUserID);
	addUserControl(userControl);
	resetColorsBtns();
	this->paymentBtn->ForeColor = Color::FromArgb(1, 193, 13, 20);
}

System::Void MainForm::transferBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	TransferUC^ userControl = gcnew TransferUC(loggedUserID);
	addUserControl(userControl);
	resetColorsBtns();
	this->transferBtn->ForeColor = Color::FromArgb(1, 193, 13, 20);
}

System::Void MainForm::settingsBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	SettingsUC^ userControl = gcnew SettingsUC(loggedUserID);
	addUserControl(userControl);
	resetColorsBtns();
	this->settingsBtn->ForeColor = Color::FromArgb(1, 193, 13, 20);
}