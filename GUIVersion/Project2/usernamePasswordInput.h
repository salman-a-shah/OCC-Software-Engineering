#pragma once
#include "Accounts\AccountsEmployee.h"
#include "Accounts\AccountsManager.h"
#include "Accounts\AccountsVector.h"
#include <msclr\marshal_cppstd.h>
#include <iostream>
using namespace std;

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for usernamePasswordInput
	/// </summary>
	public ref class usernamePasswordInput : public System::Windows::Forms::Form
	{
	public:
		usernamePasswordInput(Accounts& newAccount)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			temp = &newAccount;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~usernamePasswordInput()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  usernamePromptLabel;
	private: System::Windows::Forms::TextBox^  usernameInput;
	private: System::Windows::Forms::Label^  passwordPromptLabel;
	private: System::Windows::Forms::TextBox^  passwordInput;
	private: System::Windows::Forms::Button^  saveButton;
	protected: 


	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		Accounts *temp;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->usernamePromptLabel = (gcnew System::Windows::Forms::Label());
			this->usernameInput = (gcnew System::Windows::Forms::TextBox());
			this->passwordPromptLabel = (gcnew System::Windows::Forms::Label());
			this->passwordInput = (gcnew System::Windows::Forms::TextBox());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// usernamePromptLabel
			// 
			this->usernamePromptLabel->BackColor = System::Drawing::Color::Black;
			this->usernamePromptLabel->ForeColor = System::Drawing::Color::White;
			this->usernamePromptLabel->Location = System::Drawing::Point(36, 35);
			this->usernamePromptLabel->Name = L"usernamePromptLabel";
			this->usernamePromptLabel->Size = System::Drawing::Size(215, 25);
			this->usernamePromptLabel->TabIndex = 0;
			this->usernamePromptLabel->Text = L"Enter desired username for this account:";
			// 
			// usernameInput
			// 
			this->usernameInput->BackColor = System::Drawing::Color::Black;
			this->usernameInput->ForeColor = System::Drawing::Color::White;
			this->usernameInput->Location = System::Drawing::Point(39, 54);
			this->usernameInput->Name = L"usernameInput";
			this->usernameInput->Size = System::Drawing::Size(190, 20);
			this->usernameInput->TabIndex = 1;
			// 
			// passwordPromptLabel
			// 
			this->passwordPromptLabel->ForeColor = System::Drawing::Color::White;
			this->passwordPromptLabel->Location = System::Drawing::Point(39, 104);
			this->passwordPromptLabel->Name = L"passwordPromptLabel";
			this->passwordPromptLabel->Size = System::Drawing::Size(212, 23);
			this->passwordPromptLabel->TabIndex = 2;
			this->passwordPromptLabel->Text = L"Enter desired password for this account:";
			// 
			// passwordInput
			// 
			this->passwordInput->BackColor = System::Drawing::Color::Black;
			this->passwordInput->ForeColor = System::Drawing::Color::White;
			this->passwordInput->Location = System::Drawing::Point(39, 121);
			this->passwordInput->Name = L"passwordInput";
			this->passwordInput->PasswordChar = '*';
			this->passwordInput->Size = System::Drawing::Size(190, 20);
			this->passwordInput->TabIndex = 3;
			// 
			// saveButton
			// 
			this->saveButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->saveButton->ForeColor = System::Drawing::Color::Black;
			this->saveButton->Location = System::Drawing::Point(87, 171);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(75, 23);
			this->saveButton->TabIndex = 4;
			this->saveButton->Text = L"Save";
			this->saveButton->UseVisualStyleBackColor = false;
			this->saveButton->Click += gcnew System::EventHandler(this, &usernamePasswordInput::saveButton_Click);
			// 
			// usernamePasswordInput
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->passwordInput);
			this->Controls->Add(this->passwordPromptLabel);
			this->Controls->Add(this->usernameInput);
			this->Controls->Add(this->usernamePromptLabel);
			this->Name = L"usernamePasswordInput";
			this->Text = L"Required Information";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void saveButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 string userName = marshal_as<std::string>(this->usernameInput->Text->ToString());
				 string passWord = marshal_as<std::string>(this->passwordInput->Text->ToString());

				 temp->setUsername(userName);
				 temp->setPassword(passWord);

				 this->Close();
			 }
};
}
