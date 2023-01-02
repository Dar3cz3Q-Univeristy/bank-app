#include "MainForm.h"
#include "User.h"
#include "Database.h"
#include "StringConversion.h"
#include "AccountUC.h"
#include "BillsUC.h"
#include "PaymentUC.h"
#include "TransferUC.h"
#include "ContractorsUC.h"

using namespace AGHBank;

void MainForm::addUserControl(UserControl^ userControl) {
	userControl->Dock = DockStyle::Fill;
	this->PanelContainer->Controls->Clear();
	this->PanelContainer->Controls->Add(userControl);
	userControl->BringToFront();
}

void MainForm::downloadBasicData(void) {
	try {
		SqlConnection sqlConn(ConvertString::toSystemString(DatabaseConfig::sqlConnectionString));
		sqlConn.Open();

		String^ sqlQuery = "SELECT Forename, Surname FROM PersonDetails WHERE PersonID = @ID;";

		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@ID", loggedUserID);

		SqlDataReader^ reader = command.ExecuteReader();

		if (reader->Read()) {
			String^ nameToShow = reader->GetString(0) + " " + reader->GetString(1);
			this->userNameLb->Text = nameToShow;
		}

		reader->Close();
		sqlConn.Close();
	}
	catch (SqlException^ e) {
		MessageBox::Show(e->Message, "B³¹d po³¹czenia", MessageBoxButtons::OK);
	}
}

void MainForm::resetColorsBtns(void) {
	this->accountBtn->ForeColor = Color::FromArgb(1, 0, 0, 0);
	this->billBtn->ForeColor = Color::FromArgb(1, 0, 0, 0);
	this->cardsBtn->ForeColor = Color::FromArgb(1, 0, 0, 0);
	this->contractorsBtn->ForeColor = Color::FromArgb(1, 0, 0, 0);
	this->transferBtn->ForeColor = Color::FromArgb(1, 0, 0, 0);
	this->paymentBtn->ForeColor = Color::FromArgb(1, 0, 0, 0);
}

System::Void MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	downloadBasicData();
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