#pragma once

namespace AGHBank {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for SelectContractor
	/// </summary>
	public ref class SelectContractor : public System::Windows::Forms::Form
	{
	public:
		int loggedUserID;
		SelectContractor(int id)
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
		~SelectContractor()
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
			this->contractorsLayoutPanel->AutoScroll = true;
			this->contractorsLayoutPanel->ColumnCount = 1;
			this->contractorsLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->contractorsLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->contractorsLayoutPanel->Location = System::Drawing::Point(0, 0);
			this->contractorsLayoutPanel->Name = L"contractorsLayoutPanel";
			this->contractorsLayoutPanel->RowCount = 2;
			this->contractorsLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				100)));
			this->contractorsLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				100)));
			this->contractorsLayoutPanel->Size = System::Drawing::Size(878, 594);
			this->contractorsLayoutPanel->TabIndex = 0;
			// 
			// SelectContractor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(878, 594);
			this->Controls->Add(this->contractorsLayoutPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"SelectContractor";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Wybierz kontrahenta";
			this->Load += gcnew System::EventHandler(this, &SelectContractor::SelectContractor_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	public:
		String^ selectedContractorNumber;
	private: System::Void SelectContractor_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void selectContractorBtn_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
