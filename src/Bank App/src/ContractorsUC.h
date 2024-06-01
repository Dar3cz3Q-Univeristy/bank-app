#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Data::SqlClient;

namespace AGHBank {

	/// <summary>
	/// Summary for ContractorsUC
	/// </summary>
	public ref class ContractorsUC : public System::Windows::Forms::UserControl
	{
	public:
		int loggedUserID;
		ContractorsUC(int id)
		{
			loggedUserID = id;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ContractorsUC()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ contractorsLayoutPanel;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->contractorsLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->SuspendLayout();
			// 
			// contractorsLayoutPanel
			// 
			this->contractorsLayoutPanel->ColumnCount = 3;
			this->contractorsLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				29.61319F)));
			this->contractorsLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				53.70957F)));
			this->contractorsLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.67724F)));
			this->contractorsLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->contractorsLayoutPanel->Location = System::Drawing::Point(0, 0);
			this->contractorsLayoutPanel->Name = L"contractorsLayoutPanel";
			this->contractorsLayoutPanel->RowCount = 2;
			this->contractorsLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				70)));
			this->contractorsLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				70)));
			this->contractorsLayoutPanel->Size = System::Drawing::Size(1578, 709);
			this->contractorsLayoutPanel->TabIndex = 0;
			// 
			// ContractorsUC
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->contractorsLayoutPanel);
			this->Name = L"ContractorsUC";
			this->Size = System::Drawing::Size(1578, 709);
			this->Load += gcnew System::EventHandler(this, &ContractorsUC::ContractorsUC_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ContractorsUC_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void createContractorBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void deleteContractorBtn_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
