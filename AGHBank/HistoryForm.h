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
	/// Summary for HistoryForm
	/// </summary>
	public ref class HistoryForm : public System::Windows::Forms::Form
	{
	public:
		int choosedBillID;
		HistoryForm(int id)
		{
			choosedBillID = id;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~HistoryForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ headerPanel;
	private: System::Windows::Forms::Label^ incomeLb;
	private: System::Windows::Forms::Label^ historyHeaderLb;
	private: System::Windows::Forms::Panel^ HistoryListPanel;
	private: System::Windows::Forms::Label^ expensesLb;
	private: System::Windows::Forms::TableLayoutPanel^ historyListTableLayoutPanel;
	private: System::Windows::Forms::Label^ typeLb;
	private: System::Windows::Forms::Label^ dateLb;
	private: System::Windows::Forms::Label^ amountLb;
	private: System::Windows::Forms::Label^ titleLb;
	private: System::Windows::Forms::Label^ contractorLb;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->headerPanel = (gcnew System::Windows::Forms::Panel());
			this->expensesLb = (gcnew System::Windows::Forms::Label());
			this->incomeLb = (gcnew System::Windows::Forms::Label());
			this->historyHeaderLb = (gcnew System::Windows::Forms::Label());
			this->HistoryListPanel = (gcnew System::Windows::Forms::Panel());
			this->historyListTableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->typeLb = (gcnew System::Windows::Forms::Label());
			this->dateLb = (gcnew System::Windows::Forms::Label());
			this->amountLb = (gcnew System::Windows::Forms::Label());
			this->titleLb = (gcnew System::Windows::Forms::Label());
			this->contractorLb = (gcnew System::Windows::Forms::Label());
			this->headerPanel->SuspendLayout();
			this->HistoryListPanel->SuspendLayout();
			this->historyListTableLayoutPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// headerPanel
			// 
			this->headerPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(221)));
			this->headerPanel->Controls->Add(this->expensesLb);
			this->headerPanel->Controls->Add(this->incomeLb);
			this->headerPanel->Controls->Add(this->historyHeaderLb);
			this->headerPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->headerPanel->Location = System::Drawing::Point(0, 0);
			this->headerPanel->Name = L"headerPanel";
			this->headerPanel->Size = System::Drawing::Size(1528, 93);
			this->headerPanel->TabIndex = 0;
			// 
			// expensesLb
			// 
			this->expensesLb->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->expensesLb->Font = (gcnew System::Drawing::Font(L"Century Gothic", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->expensesLb->ForeColor = System::Drawing::SystemColors::ControlText;
			this->expensesLb->Location = System::Drawing::Point(1004, 0);
			this->expensesLb->Name = L"expensesLb";
			this->expensesLb->Size = System::Drawing::Size(498, 93);
			this->expensesLb->TabIndex = 2;
			this->expensesLb->Text = L"$expenses$";
			this->expensesLb->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// incomeLb
			// 
			this->incomeLb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->incomeLb->Font = (gcnew System::Drawing::Font(L"Century Gothic", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->incomeLb->Location = System::Drawing::Point(392, 0);
			this->incomeLb->Name = L"incomeLb";
			this->incomeLb->Size = System::Drawing::Size(606, 93);
			this->incomeLb->TabIndex = 1;
			this->incomeLb->Text = L"$income$";
			this->incomeLb->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// historyHeaderLb
			// 
			this->historyHeaderLb->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 20, System::Drawing::FontStyle::Underline,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->historyHeaderLb->Location = System::Drawing::Point(0, 0);
			this->historyHeaderLb->Name = L"historyHeaderLb";
			this->historyHeaderLb->Size = System::Drawing::Size(301, 93);
			this->historyHeaderLb->TabIndex = 0;
			this->historyHeaderLb->Text = L"Historia rachunku";
			this->historyHeaderLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// HistoryListPanel
			// 
			this->HistoryListPanel->Controls->Add(this->historyListTableLayoutPanel);
			this->HistoryListPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->HistoryListPanel->Location = System::Drawing::Point(0, 93);
			this->HistoryListPanel->Name = L"HistoryListPanel";
			this->HistoryListPanel->Size = System::Drawing::Size(1528, 751);
			this->HistoryListPanel->TabIndex = 1;
			// 
			// historyListTableLayoutPanel
			// 
			this->historyListTableLayoutPanel->BackColor = System::Drawing::Color::WhiteSmoke;
			this->historyListTableLayoutPanel->ColumnCount = 5;
			this->historyListTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				27.55236F)));
			this->historyListTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25.589F)));
			this->historyListTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				18.58639F)));
			this->historyListTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				14.13613F)));
			this->historyListTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				14.07068F)));
			this->historyListTableLayoutPanel->Controls->Add(this->typeLb, 2, 0);
			this->historyListTableLayoutPanel->Controls->Add(this->dateLb, 4, 0);
			this->historyListTableLayoutPanel->Controls->Add(this->amountLb, 3, 0);
			this->historyListTableLayoutPanel->Controls->Add(this->titleLb, 1, 0);
			this->historyListTableLayoutPanel->Controls->Add(this->contractorLb, 0, 0);
			this->historyListTableLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->historyListTableLayoutPanel->Location = System::Drawing::Point(0, 0);
			this->historyListTableLayoutPanel->Name = L"historyListTableLayoutPanel";
			this->historyListTableLayoutPanel->RowCount = 2;
			this->historyListTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				50)));
			this->historyListTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				70)));
			this->historyListTableLayoutPanel->Size = System::Drawing::Size(1528, 751);
			this->historyListTableLayoutPanel->TabIndex = 0;
			// 
			// typeLb
			// 
			this->typeLb->AutoSize = true;
			this->typeLb->Dock = System::Windows::Forms::DockStyle::Fill;
			this->typeLb->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->typeLb->Location = System::Drawing::Point(815, 0);
			this->typeLb->Name = L"typeLb";
			this->typeLb->Size = System::Drawing::Size(278, 50);
			this->typeLb->TabIndex = 5;
			this->typeLb->Text = L"Typ";
			this->typeLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// dateLb
			// 
			this->dateLb->AutoSize = true;
			this->dateLb->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dateLb->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->dateLb->Location = System::Drawing::Point(1315, 0);
			this->dateLb->Name = L"dateLb";
			this->dateLb->Size = System::Drawing::Size(210, 50);
			this->dateLb->TabIndex = 4;
			this->dateLb->Text = L"Data";
			this->dateLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// amountLb
			// 
			this->amountLb->AutoSize = true;
			this->amountLb->Dock = System::Windows::Forms::DockStyle::Fill;
			this->amountLb->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->amountLb->Location = System::Drawing::Point(1099, 0);
			this->amountLb->Name = L"amountLb";
			this->amountLb->Size = System::Drawing::Size(210, 50);
			this->amountLb->TabIndex = 3;
			this->amountLb->Text = L"Kwota";
			this->amountLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// titleLb
			// 
			this->titleLb->AutoSize = true;
			this->titleLb->Dock = System::Windows::Forms::DockStyle::Fill;
			this->titleLb->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->titleLb->Location = System::Drawing::Point(424, 0);
			this->titleLb->Name = L"titleLb";
			this->titleLb->Size = System::Drawing::Size(385, 50);
			this->titleLb->TabIndex = 1;
			this->titleLb->Text = L"Tytu³";
			this->titleLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// contractorLb
			// 
			this->contractorLb->AutoSize = true;
			this->contractorLb->Dock = System::Windows::Forms::DockStyle::Fill;
			this->contractorLb->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->contractorLb->Location = System::Drawing::Point(3, 0);
			this->contractorLb->Name = L"contractorLb";
			this->contractorLb->Size = System::Drawing::Size(415, 50);
			this->contractorLb->TabIndex = 0;
			this->contractorLb->Text = L"Kontrahent";
			this->contractorLb->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// HistoryForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1528, 844);
			this->Controls->Add(this->HistoryListPanel);
			this->Controls->Add(this->headerPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"HistoryForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Historia rachunku";
			this->Load += gcnew System::EventHandler(this, &HistoryForm::HistoryForm_Load);
			this->headerPanel->ResumeLayout(false);
			this->HistoryListPanel->ResumeLayout(false);
			this->historyListTableLayoutPanel->ResumeLayout(false);
			this->historyListTableLayoutPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void HistoryForm_Load(System::Object^ sender, System::EventArgs^ e);
	};
}
