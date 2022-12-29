#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace AGHBank {

	/// <summary>
	/// Summary for BillsUC
	/// </summary>
	public ref class BillsUC : public System::Windows::Forms::UserControl
	{
	public:
		int loggedUserID;
		BillsUC(int id)
		{
			InitializeComponent();
			loggedUserID = id;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~BillsUC()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ billsTable;
	private: System::ComponentModel::IContainer^ components;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->billsTable = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->SuspendLayout();
			// 
			// billsTable
			// 
			this->billsTable->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->billsTable->ColumnCount = 4;
			this->billsTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->billsTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35)));
			this->billsTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 30)));
			this->billsTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->billsTable->Location = System::Drawing::Point(3, 3);
			this->billsTable->MaximumSize = System::Drawing::Size(1572, 703);
			this->billsTable->MinimumSize = System::Drawing::Size(1572, 70);
			this->billsTable->Name = L"billsTable";
			this->billsTable->Padding = System::Windows::Forms::Padding(10, 0, 10, 0);
			this->billsTable->RowCount = 1;
			this->billsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 75)));
			this->billsTable->Size = System::Drawing::Size(1572, 75);
			this->billsTable->TabIndex = 0;
			// 
			// BillsUC
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->Controls->Add(this->billsTable);
			this->Name = L"BillsUC";
			this->Size = System::Drawing::Size(1578, 709);
			this->Load += gcnew System::EventHandler(this, &BillsUC::BillsUC_Load);
			this->ResumeLayout(false);
		}
#pragma endregion
	private: System::Void BillsUC_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void createBillBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void removeBillBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void historyBtn_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
