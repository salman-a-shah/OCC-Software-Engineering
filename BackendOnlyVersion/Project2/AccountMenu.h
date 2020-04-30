#pragma once
#include "Accounts\AccountsEmployee.h"
#include "Accounts\AccountsManager.h"
#include "Accounts\AccountsVector.h"

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AccountMenu
	/// </summary>
	public ref class AccountMenu : public System::Windows::Forms::Form
	{
	public:
		AccountMenu(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AccountMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  inventoryButton;
	private: System::Windows::Forms::Label^  reportsButton;
	protected: 


	private: System::Windows::Forms::Label^  ratesButton;
	private: System::Windows::Forms::Label^  accountsButton;
	private: System::Windows::Forms::Label^  reservationsButton;
	private: System::Windows::Forms::Label^  logoutButton;
	private: System::Windows::Forms::Label^  createButton;
	private: System::Windows::Forms::Label^  deleteButton;
	private: System::Windows::Forms::Label^  editButton;







	private: System::Windows::Forms::TextBox^  nameInput;
	private: System::Windows::Forms::TextBox^  ageInput;
	private: System::Windows::Forms::TextBox^  genderInput;
	private: System::Windows::Forms::TextBox^  positionInput;
	private: System::Windows::Forms::TextBox^  accessLevelInput;
	private: System::Windows::Forms::TextBox^  phoneNumberInput;
	private: System::Windows::Forms::TextBox^  emergencyContactInput;
	private: System::Windows::Forms::TextBox^  emailAddressInput;
	private: System::Windows::Forms::TextBox^  cityInput;









	private: System::Windows::Forms::TextBox^  addressInput;
	private: System::Windows::Forms::TextBox^  zipCodeInput;


	private: System::Windows::Forms::TextBox^  countryInput;
	private: System::Windows::Forms::TextBox^  additionalDetailsInput;



	protected: 

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AccountMenu::typeid));
			this->inventoryButton = (gcnew System::Windows::Forms::Label());
			this->reportsButton = (gcnew System::Windows::Forms::Label());
			this->ratesButton = (gcnew System::Windows::Forms::Label());
			this->accountsButton = (gcnew System::Windows::Forms::Label());
			this->reservationsButton = (gcnew System::Windows::Forms::Label());
			this->logoutButton = (gcnew System::Windows::Forms::Label());
			this->createButton = (gcnew System::Windows::Forms::Label());
			this->deleteButton = (gcnew System::Windows::Forms::Label());
			this->editButton = (gcnew System::Windows::Forms::Label());
			this->nameInput = (gcnew System::Windows::Forms::TextBox());
			this->ageInput = (gcnew System::Windows::Forms::TextBox());
			this->genderInput = (gcnew System::Windows::Forms::TextBox());
			this->positionInput = (gcnew System::Windows::Forms::TextBox());
			this->accessLevelInput = (gcnew System::Windows::Forms::TextBox());
			this->phoneNumberInput = (gcnew System::Windows::Forms::TextBox());
			this->emergencyContactInput = (gcnew System::Windows::Forms::TextBox());
			this->emailAddressInput = (gcnew System::Windows::Forms::TextBox());
			this->cityInput = (gcnew System::Windows::Forms::TextBox());
			this->addressInput = (gcnew System::Windows::Forms::TextBox());
			this->zipCodeInput = (gcnew System::Windows::Forms::TextBox());
			this->countryInput = (gcnew System::Windows::Forms::TextBox());
			this->additionalDetailsInput = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// inventoryButton
			// 
			this->inventoryButton->BackColor = System::Drawing::Color::Transparent;
			this->inventoryButton->ForeColor = System::Drawing::Color::Transparent;
			this->inventoryButton->Location = System::Drawing::Point(12, 9);
			this->inventoryButton->Name = L"inventoryButton";
			this->inventoryButton->Size = System::Drawing::Size(121, 38);
			this->inventoryButton->TabIndex = 0;
			this->inventoryButton->Click += gcnew System::EventHandler(this, &AccountMenu::inventoryButton_Click);
			// 
			// reportsButton
			// 
			this->reportsButton->BackColor = System::Drawing::Color::Transparent;
			this->reportsButton->ForeColor = System::Drawing::Color::Transparent;
			this->reportsButton->Location = System::Drawing::Point(255, 9);
			this->reportsButton->Name = L"reportsButton";
			this->reportsButton->Size = System::Drawing::Size(121, 38);
			this->reportsButton->TabIndex = 1;
			// 
			// ratesButton
			// 
			this->ratesButton->BackColor = System::Drawing::Color::Transparent;
			this->ratesButton->ForeColor = System::Drawing::Color::Transparent;
			this->ratesButton->Location = System::Drawing::Point(139, 9);
			this->ratesButton->Name = L"ratesButton";
			this->ratesButton->Size = System::Drawing::Size(121, 38);
			this->ratesButton->TabIndex = 2;
			// 
			// accountsButton
			// 
			this->accountsButton->BackColor = System::Drawing::Color::Transparent;
			this->accountsButton->ForeColor = System::Drawing::Color::Transparent;
			this->accountsButton->Location = System::Drawing::Point(371, 9);
			this->accountsButton->Name = L"accountsButton";
			this->accountsButton->Size = System::Drawing::Size(121, 38);
			this->accountsButton->TabIndex = 3;
			// 
			// reservationsButton
			// 
			this->reservationsButton->BackColor = System::Drawing::Color::Transparent;
			this->reservationsButton->ForeColor = System::Drawing::Color::Transparent;
			this->reservationsButton->Location = System::Drawing::Point(486, 9);
			this->reservationsButton->Name = L"reservationsButton";
			this->reservationsButton->Size = System::Drawing::Size(110, 38);
			this->reservationsButton->TabIndex = 4;
			// 
			// logoutButton
			// 
			this->logoutButton->BackColor = System::Drawing::Color::Transparent;
			this->logoutButton->ForeColor = System::Drawing::Color::Transparent;
			this->logoutButton->Location = System::Drawing::Point(593, 9);
			this->logoutButton->Name = L"logoutButton";
			this->logoutButton->Size = System::Drawing::Size(121, 38);
			this->logoutButton->TabIndex = 5;
			this->logoutButton->Click += gcnew System::EventHandler(this, &AccountMenu::logoutButton_Click);
			// 
			// createButton
			// 
			this->createButton->BackColor = System::Drawing::Color::Transparent;
			this->createButton->ForeColor = System::Drawing::Color::Transparent;
			this->createButton->Location = System::Drawing::Point(15, 524);
			this->createButton->Name = L"createButton";
			this->createButton->Size = System::Drawing::Size(79, 22);
			this->createButton->TabIndex = 6;
			this->createButton->Click += gcnew System::EventHandler(this, &AccountMenu::create_Click);
			// 
			// deleteButton
			// 
			this->deleteButton->BackColor = System::Drawing::Color::Transparent;
			this->deleteButton->ForeColor = System::Drawing::Color::Transparent;
			this->deleteButton->Location = System::Drawing::Point(110, 524);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(79, 22);
			this->deleteButton->TabIndex = 7;
			// 
			// editButton
			// 
			this->editButton->BackColor = System::Drawing::Color::Transparent;
			this->editButton->ForeColor = System::Drawing::Color::Transparent;
			this->editButton->Location = System::Drawing::Point(207, 524);
			this->editButton->Name = L"editButton";
			this->editButton->Size = System::Drawing::Size(79, 22);
			this->editButton->TabIndex = 8;
			// 
			// nameInput
			// 
			this->nameInput->BackColor = System::Drawing::Color::Black;
			this->nameInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->nameInput->ForeColor = System::Drawing::Color::White;
			this->nameInput->Location = System::Drawing::Point(449, 100);
			this->nameInput->Multiline = true;
			this->nameInput->Name = L"nameInput";
			this->nameInput->Size = System::Drawing::Size(226, 12);
			this->nameInput->TabIndex = 9;
			// 
			// ageInput
			// 
			this->ageInput->BackColor = System::Drawing::Color::Black;
			this->ageInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ageInput->ForeColor = System::Drawing::Color::White;
			this->ageInput->Location = System::Drawing::Point(449, 129);
			this->ageInput->Multiline = true;
			this->ageInput->Name = L"ageInput";
			this->ageInput->Size = System::Drawing::Size(226, 12);
			this->ageInput->TabIndex = 10;
			// 
			// genderInput
			// 
			this->genderInput->BackColor = System::Drawing::Color::Black;
			this->genderInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->genderInput->ForeColor = System::Drawing::Color::White;
			this->genderInput->Location = System::Drawing::Point(449, 158);
			this->genderInput->Multiline = true;
			this->genderInput->Name = L"genderInput";
			this->genderInput->Size = System::Drawing::Size(226, 12);
			this->genderInput->TabIndex = 11;
			// 
			// positionInput
			// 
			this->positionInput->BackColor = System::Drawing::Color::Black;
			this->positionInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->positionInput->ForeColor = System::Drawing::Color::White;
			this->positionInput->Location = System::Drawing::Point(449, 185);
			this->positionInput->Multiline = true;
			this->positionInput->Name = L"positionInput";
			this->positionInput->Size = System::Drawing::Size(226, 12);
			this->positionInput->TabIndex = 12;
			// 
			// accessLevelInput
			// 
			this->accessLevelInput->BackColor = System::Drawing::Color::Black;
			this->accessLevelInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->accessLevelInput->ForeColor = System::Drawing::Color::White;
			this->accessLevelInput->Location = System::Drawing::Point(449, 214);
			this->accessLevelInput->Multiline = true;
			this->accessLevelInput->Name = L"accessLevelInput";
			this->accessLevelInput->Size = System::Drawing::Size(226, 10);
			this->accessLevelInput->TabIndex = 13;
			// 
			// phoneNumberInput
			// 
			this->phoneNumberInput->BackColor = System::Drawing::Color::Black;
			this->phoneNumberInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->phoneNumberInput->ForeColor = System::Drawing::Color::White;
			this->phoneNumberInput->Location = System::Drawing::Point(449, 244);
			this->phoneNumberInput->Multiline = true;
			this->phoneNumberInput->Name = L"phoneNumberInput";
			this->phoneNumberInput->Size = System::Drawing::Size(226, 12);
			this->phoneNumberInput->TabIndex = 14;
			// 
			// emergencyContactInput
			// 
			this->emergencyContactInput->BackColor = System::Drawing::Color::Black;
			this->emergencyContactInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->emergencyContactInput->ForeColor = System::Drawing::Color::White;
			this->emergencyContactInput->Location = System::Drawing::Point(449, 276);
			this->emergencyContactInput->Multiline = true;
			this->emergencyContactInput->Name = L"emergencyContactInput";
			this->emergencyContactInput->Size = System::Drawing::Size(226, 12);
			this->emergencyContactInput->TabIndex = 15;
			// 
			// emailAddressInput
			// 
			this->emailAddressInput->BackColor = System::Drawing::Color::Black;
			this->emailAddressInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->emailAddressInput->ForeColor = System::Drawing::Color::White;
			this->emailAddressInput->Location = System::Drawing::Point(449, 304);
			this->emailAddressInput->Multiline = true;
			this->emailAddressInput->Name = L"emailAddressInput";
			this->emailAddressInput->Size = System::Drawing::Size(226, 12);
			this->emailAddressInput->TabIndex = 16;
			// 
			// cityInput
			// 
			this->cityInput->BackColor = System::Drawing::Color::Black;
			this->cityInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->cityInput->ForeColor = System::Drawing::Color::White;
			this->cityInput->Location = System::Drawing::Point(449, 361);
			this->cityInput->Multiline = true;
			this->cityInput->Name = L"cityInput";
			this->cityInput->Size = System::Drawing::Size(226, 12);
			this->cityInput->TabIndex = 17;
			// 
			// addressInput
			// 
			this->addressInput->BackColor = System::Drawing::Color::Black;
			this->addressInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->addressInput->ForeColor = System::Drawing::Color::White;
			this->addressInput->Location = System::Drawing::Point(449, 331);
			this->addressInput->Multiline = true;
			this->addressInput->Name = L"addressInput";
			this->addressInput->Size = System::Drawing::Size(226, 12);
			this->addressInput->TabIndex = 18;
			// 
			// zipCodeInput
			// 
			this->zipCodeInput->BackColor = System::Drawing::Color::Black;
			this->zipCodeInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->zipCodeInput->ForeColor = System::Drawing::Color::White;
			this->zipCodeInput->Location = System::Drawing::Point(449, 389);
			this->zipCodeInput->Multiline = true;
			this->zipCodeInput->Name = L"zipCodeInput";
			this->zipCodeInput->Size = System::Drawing::Size(226, 12);
			this->zipCodeInput->TabIndex = 19;
			// 
			// countryInput
			// 
			this->countryInput->BackColor = System::Drawing::Color::Black;
			this->countryInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->countryInput->ForeColor = System::Drawing::Color::White;
			this->countryInput->Location = System::Drawing::Point(449, 418);
			this->countryInput->Multiline = true;
			this->countryInput->Name = L"countryInput";
			this->countryInput->Size = System::Drawing::Size(226, 12);
			this->countryInput->TabIndex = 20;
			// 
			// additionalDetailsInput
			// 
			this->additionalDetailsInput->BackColor = System::Drawing::Color::Black;
			this->additionalDetailsInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->additionalDetailsInput->ForeColor = System::Drawing::Color::White;
			this->additionalDetailsInput->Location = System::Drawing::Point(440, 449);
			this->additionalDetailsInput->Multiline = true;
			this->additionalDetailsInput->Name = L"additionalDetailsInput";
			this->additionalDetailsInput->Size = System::Drawing::Size(244, 88);
			this->additionalDetailsInput->TabIndex = 21;
			// 
			// AccountMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(737, 575);
			this->Controls->Add(this->additionalDetailsInput);
			this->Controls->Add(this->countryInput);
			this->Controls->Add(this->zipCodeInput);
			this->Controls->Add(this->addressInput);
			this->Controls->Add(this->cityInput);
			this->Controls->Add(this->emailAddressInput);
			this->Controls->Add(this->emergencyContactInput);
			this->Controls->Add(this->phoneNumberInput);
			this->Controls->Add(this->accessLevelInput);
			this->Controls->Add(this->positionInput);
			this->Controls->Add(this->genderInput);
			this->Controls->Add(this->ageInput);
			this->Controls->Add(this->nameInput);
			this->Controls->Add(this->editButton);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->createButton);
			this->Controls->Add(this->logoutButton);
			this->Controls->Add(this->reservationsButton);
			this->Controls->Add(this->accountsButton);
			this->Controls->Add(this->ratesButton);
			this->Controls->Add(this->reportsButton);
			this->Controls->Add(this->inventoryButton);
			this->Name = L"AccountMenu";
			this->Load += gcnew System::EventHandler(this, &AccountMenu::AccountMenu_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AccountMenu_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void inventoryButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void logoutButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
			 }
private: System::Void create_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->nameInput->Clear();
			 this->ageInput->Clear();
			 this->genderInput->Clear();
			 this->positionInput->Clear();
			 this->accessLevelInput->Clear();
			 this->phoneNumberInput->Clear();
			 this->emergencyContactInput->Clear();
			 this->emailAddressInput->Clear();
			 this->addressInput->Clear();
			 this->cityInput->Clear();
			 this->zipCodeInput->Clear();
			 this->countryInput->Clear();
			 this->additionalDetailsInput->Clear();

		 }
};
}
