#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace AGHBank {

	/// <summary>
	/// Summary for PaymentUC
	/// </summary>
	public ref class PaymentUC : public System::Windows::Forms::UserControl
	{
	public:
		int loggedUserID;
		PaymentUC(int id)
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
		~PaymentUC()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RadioButton^ paymentRadioBtn;
	private: System::Windows::Forms::Panel^ typePanel;
	private: System::Windows::Forms::RadioButton^ paycheckRadioBtn;
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
			this->paymentRadioBtn = (gcnew System::Windows::Forms::RadioButton());
			this->typePanel = (gcnew System::Windows::Forms::Panel());
			this->paycheckRadioBtn = (gcnew System::Windows::Forms::RadioButton());
			this->typePanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// paymentRadioBtn
			// 
			this->paymentRadioBtn->Appearance = System::Windows::Forms::Appearance::Button;
			this->paymentRadioBtn->Checked = true;
			this->paymentRadioBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->paymentRadioBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->paymentRadioBtn->Location = System::Drawing::Point(23, 3);
			this->paymentRadioBtn->Name = L"paymentRadioBtn";
			this->paymentRadioBtn->Size = System::Drawing::Size(735, 60);
			this->paymentRadioBtn->TabIndex = 2;
			this->paymentRadioBtn->TabStop = true;
			this->paymentRadioBtn->Text = L"Wp³ata gotówki";
			this->paymentRadioBtn->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->paymentRadioBtn->UseVisualStyleBackColor = true;
			// 
			// typePanel
			// 
			this->typePanel->Controls->Add(this->paycheckRadioBtn);
			this->typePanel->Controls->Add(this->paymentRadioBtn);
			this->typePanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->typePanel->Location = System::Drawing::Point(0, 0);
			this->typePanel->Name = L"typePanel";
			this->typePanel->Padding = System::Windows::Forms::Padding(20, 5, 20, 5);
			this->typePanel->Size = System::Drawing::Size(1578, 70);
			this->typePanel->TabIndex = 4;
			// 
			// paycheckRadioBtn
			// 
			this->paycheckRadioBtn->Appearance = System::Windows::Forms::Appearance::Button;
			this->paycheckRadioBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->paycheckRadioBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 18, System::Drawing::FontStyle::Bold));
			this->paycheckRadioBtn->Location = System::Drawing::Point(820, 3);
			this->paycheckRadioBtn->Name = L"paycheckRadioBtn";
			this->paycheckRadioBtn->Size = System::Drawing::Size(735, 60);
			this->paycheckRadioBtn->TabIndex = 3;
			this->paycheckRadioBtn->Text = L"Wyp³ata gotówki";
			this->paycheckRadioBtn->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->paycheckRadioBtn->UseVisualStyleBackColor = true;
			// 
			// PaymentUC
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->typePanel);
			this->Name = L"PaymentUC";
			this->Size = System::Drawing::Size(1578, 709);
			this->Load += gcnew System::EventHandler(this, &PaymentUC::PaymentUC_Load);
			this->typePanel->ResumeLayout(false);
			this->ResumeLayout(false);
		}
#pragma endregion
	private: System::Void PaymentUC_Load(System::Object^ sender, System::EventArgs^ e);
	};
}
