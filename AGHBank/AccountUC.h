#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace AGHBank {

	/// <summary>
	/// Summary for AccountUC
	/// </summary>
	public ref class AccountUC : public System::Windows::Forms::UserControl
	{
	public:
		int loggedUserID;
		AccountUC(int id)
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
		~AccountUC()
		{
			if (components)
			{
				delete components;
			}
		}
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
			this->SuspendLayout();
			// 
			// AccountUC
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Name = L"AccountUC";
			this->Size = System::Drawing::Size(1578, 703);
			this->Load += gcnew System::EventHandler(this, &AccountUC::AccountUC_Load);
			this->ResumeLayout(false);
		}
#pragma endregion
	private: System::Void AccountUC_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	};
}
