#include "ContractorsUC.h"
#include "Database.h"
#include "StringConversion.h"
#include "CreateContractor.h"
#include "MainForm.h"

using namespace AGHBank;

System::Void ContractorsUC::ContractorsUC_Load(System::Object^ sender, System::EventArgs^ e) {
	try {
		SqlConnection sqlConn(ConvertString::toSystemString(DatabaseConfig::sqlConnectionString));
		sqlConn.Open();

		String^ sqlQuery = "SELECT ContractorID, CustomName, Number FROM Contractors WHERE PersonID = @personID";

		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@personID", loggedUserID);

		SqlDataReader^ reader = command.ExecuteReader();

		int i = 0, initialHeight = 70;

		while (reader->Read()) {
			int contractorID = reader->GetInt32(0);
			String^ customName = reader->GetString(1);
			String^ accountNumber = reader->GetString(2);

			Label^ customNameLabel = gcnew Label();
			customNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			customNameLabel->Dock = DockStyle::Fill;
			customNameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			customNameLabel->Text = customName;

			Label^ numberLabel = gcnew Label();
			numberLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans MT", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			numberLabel->Dock = DockStyle::Fill;
			numberLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			numberLabel->Cursor = System::Windows::Forms::Cursors::Hand;
			numberLabel->Text = accountNumber;

			Button^ deleteBtn = gcnew Button();
			deleteBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			deleteBtn->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 12, System::Drawing::FontStyle::Underline,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			deleteBtn->Dock = DockStyle::Fill;
			deleteBtn->TabIndex = i;
			deleteBtn->Tag = L"" + contractorID;
			deleteBtn->Text = L"Usuñ";
			deleteBtn->UseVisualStyleBackColor = true;
			deleteBtn->Click += gcnew System::EventHandler(this, &ContractorsUC::deleteContractorBtn_Click);

			this->contractorsLayoutPanel->RowCount++;
			this->contractorsLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, (float)initialHeight)));
			this->contractorsLayoutPanel->Size = System::Drawing::Size(1572, initialHeight * this->contractorsLayoutPanel->RowCount);

			this->contractorsLayoutPanel->Controls->Add(customNameLabel, 0, i);
			this->contractorsLayoutPanel->Controls->Add(numberLabel, 1, i);
			this->contractorsLayoutPanel->Controls->Add(deleteBtn, 2, i);
			i++;
		}

		reader->Close();
		sqlConn.Close();

		Button^ createBillBtn = gcnew Button();
		createBillBtn->Cursor = System::Windows::Forms::Cursors::Hand;
		createBillBtn->Dock = System::Windows::Forms::DockStyle::Fill;
		createBillBtn->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 12, System::Drawing::FontStyle::Underline));
		createBillBtn->Dock = DockStyle::Fill;
		createBillBtn->TabIndex = i;
		createBillBtn->Text = L"Dodaj kontrahenta";
		createBillBtn->UseVisualStyleBackColor = true;
		createBillBtn->Click += gcnew System::EventHandler(this, &ContractorsUC::createContractorBtn_Click);

		this->contractorsLayoutPanel->Controls->Add(createBillBtn, 0, i);
	}
	catch (SqlException^ e) {
		MessageBox::Show(e->Message, "B³¹d po³¹czenia", MessageBoxButtons::OK);
	}
	this->contractorsLayoutPanel->AutoScroll = true;
}

System::Void ContractorsUC::createContractorBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	AGHBank::CreateContractor CreateContractor(loggedUserID);
	CreateContractor.ShowDialog();
}

System::Void ContractorsUC::deleteContractorBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	Button^ button = safe_cast<Button^>(sender);
	String^ contractorID = button->Tag->ToString();

	try {
		SqlConnection sqlConn(ConvertString::toSystemString(DatabaseConfig::sqlConnectionString));
		sqlConn.Open();

		String^ sqlQuery = "DELETE FROM Contractors WHERE ContractorID = @contractorID";

		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@contractorID", contractorID);

		command.ExecuteNonQuery();
		sqlConn.Close();

		MessageBox::Show("Kontrahent zosta³ usuniêty", "Informacja", MessageBoxButtons::OK);
	}
	catch (SqlException^ e) {
		MessageBox::Show(e->Message, "B³¹d po³¹czenia", MessageBoxButtons::OK);
	}
}
