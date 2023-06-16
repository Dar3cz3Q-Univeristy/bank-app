#include "SelectContractor.h"
#include "StringConversion.h"
#include "Database.h"

using namespace AGHBank;

System::Void SelectContractor::SelectContractor_Load(System::Object^ sender, System::EventArgs^ e) {
	try {
		SqlConnection sqlConn(ConvertString::toSystemString(DatabaseConfig::sqlConnectionString));
		sqlConn.Open();

		String^ sqlQuery = "SELECT CustomName, Number FROM Contractors WHERE PersonID = @userID";

		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@userID", loggedUserID);

		SqlDataReader^ reader = command.ExecuteReader();

		int i = 0, initialHeight = 100;

		if (!reader->HasRows) {
			Label^ infoLabel = gcnew Label();
			infoLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			infoLabel->Dock = DockStyle::Fill;
			infoLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			infoLabel->ForeColor = Color::FromArgb(1, 193, 13, 20);
			infoLabel->Text = "Brak zapisanych kontrahentów";
			this->contractorsLayoutPanel->Controls->Add(infoLabel, 0, 0);
		}

		while (reader->Read()) {
			String^ contractorName = reader->GetString(0);
			String^ accountNumber = reader->GetString(1);

			Button^ selectContractorBtn = gcnew Button();
			selectContractorBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			selectContractorBtn->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 14, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			selectContractorBtn->Dock = DockStyle::Fill;
			selectContractorBtn->TabIndex = i;
			selectContractorBtn->Tag = L"" + accountNumber;
			selectContractorBtn->Text = L"" + contractorName + " - " + accountNumber;
			selectContractorBtn->UseVisualStyleBackColor = true;
			selectContractorBtn->Click += gcnew System::EventHandler(this, &SelectContractor::selectContractorBtn_Click);

			this->contractorsLayoutPanel->RowCount++;
			this->contractorsLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->contractorsLayoutPanel->Controls->Add(selectContractorBtn, 0, i);

			i++;
		}

		reader->Close();
		sqlConn.Close();
	}
	catch (SqlException^ e) {
		MessageBox::Show(e->Message, "B³¹d po³¹czenia", MessageBoxButtons::OK);
	}
}

System::Void SelectContractor::selectContractorBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	Button^ button = safe_cast<Button^>(sender);
	selectedContractorNumber = button->Tag->ToString();
	this->Close();
}

