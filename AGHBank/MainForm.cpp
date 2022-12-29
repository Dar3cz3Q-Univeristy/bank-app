#include "MainForm.h"
#include "User.h"
#include "Database.h"
#include "StringConversion.h"
#include "AccountUC.h"
#include "BillsUC.h"
#include "PaymentUC.h"

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
			this->UserNameLb->Text = nameToShow;
		}

		reader->Close();
		sqlConn.Close();
	}
	catch (SqlException^ e) {
		MessageBox::Show(e->Message, "B³¹d po³¹czenia", MessageBoxButtons::OK);
	}
}

void MainForm::resetColorsBtns(void) {
	this->AccountBtn->ForeColor = Color::FromArgb(1, 0, 0, 0);
	this->BillBtn->ForeColor = Color::FromArgb(1, 0, 0, 0);
	this->CardsBtn->ForeColor = Color::FromArgb(1, 0, 0, 0);
	this->ContractorsBtn->ForeColor = Color::FromArgb(1, 0, 0, 0);
	this->TransferBtn->ForeColor = Color::FromArgb(1, 0, 0, 0);
	this->PaymentBtn->ForeColor = Color::FromArgb(1, 0, 0, 0);
}

System::Void MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	downloadBasicData();
	AccountUC^ userControl = gcnew AccountUC(loggedUserID);
	addUserControl(userControl);
}

System::Void MainForm::AccountBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	AccountUC^ userControl = gcnew AccountUC(loggedUserID);
	addUserControl(userControl);
	resetColorsBtns();
	this->AccountBtn->ForeColor = Color::FromArgb(1, 193, 13, 20);
}

System::Void MainForm::BillBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	BillsUC^ userControl = gcnew BillsUC(loggedUserID);
	addUserControl(userControl);
	resetColorsBtns();
	this->BillBtn->ForeColor = Color::FromArgb(1, 193, 13, 20);
}

System::Void MainForm::PaymentBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	PaymentUC^ userControl = gcnew PaymentUC(loggedUserID);
	addUserControl(userControl);
	resetColorsBtns();
	this->PaymentBtn->ForeColor = Color::FromArgb(1, 193, 13, 20);
}