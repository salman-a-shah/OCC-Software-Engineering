#pragma once

#include<string>
#include "InventoryMenu.h"
#include "ReservationMenu.h"
#include "dateSelectionCalendar.h"
#include "Hotel.h"
#include "RoomCalendar.h"
#include <msclr\marshal_cppstd.h>
#include <vector>
#include <iostream>


typedef vector<Accounts*>::iterator accountsIter;

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for MyForm
	/// </summary>


	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		MyForm(void)
		{
			Date *current = new Date(5, 12, 2014);
			pTillItHurtsHotel = new Hotel();
			pTillItHurtsHotel->setCurrentDate(*current);
			pTillItHurtsHotel->populateArray();
			InitializeComponent();
			inventorysMenuForm = gcnew InventoryMenu(pTillItHurtsHotel);
			reservationForm = gcnew ReservationMenu(inventorysMenuForm, pTillItHurtsHotel);
			roomCalendarForm = gcnew RoomCalendar(reservationForm, inventorysMenuForm, pTillItHurtsHotel);
			loggedOn = false;
			signedIn = false;
			//
			//TODO: Add the constructor code here
			//
		}
		
		MyForm(bool a, bool b)
		{
			InitializeComponent();
			loggedOn = b;
			signedIn = a;
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>

		~MyForm()
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
	    System::Windows::Forms::Label^  signInButtonLabel;
	    System::Windows::Forms::Label^  cancelButtonLabel;


		System::Windows::Forms::Label^  addReservationButtonLabel;
		System::Windows::Forms::Label^  logOnButtonLabel;

		System::Windows::Forms::Label^  settingsButtonLabel;

		bool loggedOn;
		bool signedIn;
		InventoryMenu^ inventorysMenuForm;
		Hotel *pTillItHurtsHotel;
		System::Windows::Forms::TextBox^  passwordInputBox;
		System::Windows::Forms::TextBox^  userNameInputBox;



		ReservationMenu^ reservationForm;
		RoomCalendar^ roomCalendarForm;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->addReservationButtonLabel = (gcnew System::Windows::Forms::Label());
			this->logOnButtonLabel = (gcnew System::Windows::Forms::Label());
			this->signInButtonLabel = (gcnew System::Windows::Forms::Label());
			this->cancelButtonLabel = (gcnew System::Windows::Forms::Label());
			this->settingsButtonLabel = (gcnew System::Windows::Forms::Label());
			this->passwordInputBox = (gcnew System::Windows::Forms::TextBox());
			this->userNameInputBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// addReservationButtonLabel
			// 
			this->addReservationButtonLabel->BackColor = System::Drawing::Color::Transparent;
			this->addReservationButtonLabel->Enabled = false;
			this->addReservationButtonLabel->Location = System::Drawing::Point(124, 56);
			this->addReservationButtonLabel->Margin = System::Windows::Forms::Padding(300, 0, 3, 0);
			this->addReservationButtonLabel->MaximumSize = System::Drawing::Size(1000000, 1000000);
			this->addReservationButtonLabel->Name = L"addReservationButtonLabel";
			this->addReservationButtonLabel->Size = System::Drawing::Size(174, 161);
			this->addReservationButtonLabel->TabIndex = 0;
			this->addReservationButtonLabel->Click += gcnew System::EventHandler(this, &MyForm::addReservationButtonLabel_Click);
			// 
			// logOnButtonLabel
			// 
			this->logOnButtonLabel->BackColor = System::Drawing::Color::Transparent;
			this->logOnButtonLabel->Location = System::Drawing::Point(124, 217);
			this->logOnButtonLabel->Name = L"logOnButtonLabel";
			this->logOnButtonLabel->Size = System::Drawing::Size(174, 115);
			this->logOnButtonLabel->TabIndex = 1;
			this->logOnButtonLabel->Click += gcnew System::EventHandler(this, &MyForm::logOnButtonLabel_Click);
			// 
			// signInButtonLabel
			// 
			this->signInButtonLabel->BackColor = System::Drawing::Color::Transparent;
			this->signInButtonLabel->Enabled = false;
			this->signInButtonLabel->Location = System::Drawing::Point(113, 447);
			this->signInButtonLabel->Name = L"signInButtonLabel";
			this->signInButtonLabel->Size = System::Drawing::Size(84, 23);
			this->signInButtonLabel->TabIndex = 2;
			this->signInButtonLabel->Click += gcnew System::EventHandler(this, &MyForm::signInButtonLabel_Click);
			// 
			// cancelButtonLabel
			// 
			this->cancelButtonLabel->BackColor = System::Drawing::Color::Transparent;
			this->cancelButtonLabel->Location = System::Drawing::Point(242, 447);
			this->cancelButtonLabel->Name = L"cancelButtonLabel";
			this->cancelButtonLabel->Size = System::Drawing::Size(84, 23);
			this->cancelButtonLabel->TabIndex = 3;
			this->cancelButtonLabel->Click += gcnew System::EventHandler(this, &MyForm::cancelButtonLabel_Click);
			// 
			// settingsButtonLabel
			// 
			this->settingsButtonLabel->BackColor = System::Drawing::Color::Transparent;
			this->settingsButtonLabel->Enabled = false;
			this->settingsButtonLabel->Location = System::Drawing::Point(161, 496);
			this->settingsButtonLabel->Margin = System::Windows::Forms::Padding(300, 0, 3, 0);
			this->settingsButtonLabel->MaximumSize = System::Drawing::Size(1000000, 1000000);
			this->settingsButtonLabel->Name = L"settingsButtonLabel";
			this->settingsButtonLabel->Size = System::Drawing::Size(113, 122);
			this->settingsButtonLabel->TabIndex = 8;
			this->settingsButtonLabel->Click += gcnew System::EventHandler(this, &MyForm::settingsButtonLabel_Click);
			// 
			// passwordInputBox
			// 
			this->passwordInputBox->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->passwordInputBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->passwordInputBox->Enabled = false;
			this->passwordInputBox->Location = System::Drawing::Point(147, 404);
			this->passwordInputBox->Multiline = true;
			this->passwordInputBox->Name = L"passwordInputBox";
			this->passwordInputBox->PasswordChar = '*';
			this->passwordInputBox->Size = System::Drawing::Size(197, 31);
			this->passwordInputBox->TabIndex = 9;
			// 
			// userNameInputBox
			// 
			this->userNameInputBox->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->userNameInputBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->userNameInputBox->Enabled = false;
			this->userNameInputBox->Location = System::Drawing::Point(147, 365);
			this->userNameInputBox->Multiline = true;
			this->userNameInputBox->Name = L"userNameInputBox";
			this->userNameInputBox->Size = System::Drawing::Size(197, 33);
			this->userNameInputBox->TabIndex = 10;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = Image::FromFile("Top Menu (Buttons are off).jpg");
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(421, 643);
			this->Controls->Add(this->userNameInputBox);
			this->Controls->Add(this->passwordInputBox);
			this->Controls->Add(this->settingsButtonLabel);
			this->Controls->Add(this->cancelButtonLabel);
			this->Controls->Add(this->signInButtonLabel);
			this->Controls->Add(this->logOnButtonLabel);
			this->Controls->Add(this->addReservationButtonLabel);
			this->HelpButton = true;
			this->Name = L"MyForm";
			this->Text = L"Hotel Management System";
			this->TransparencyKey = System::Drawing::Color::Transparent;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void logOnButtonLabel_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(loggedOn)
				 {
					 this->BackgroundImage = Image::FromFile("Top Menu (Buttons are off).jpg");
					 this->addReservationButtonLabel->Enabled = false;
					 this->signInButtonLabel->Enabled = false;
					 this->userNameInputBox->Enabled = false;
					 this->passwordInputBox->Enabled = false;
					 this->settingsButtonLabel->Enabled = false;
					 loggedOn = false;
					 signedIn = false;
				 }
				 else if(signedIn)
				 {
					 this->BackgroundImage = Image::FromFile("Top Menu (Buttons are off).jpg");
					 this->signInButtonLabel->Enabled = true;
					 this->cancelButtonLabel->Enabled = true;
					 this->userNameInputBox->Enabled = true;
					 this->passwordInputBox->Enabled = true;
					 loggedOn = true;
					 signedIn = false;
				 }
				 else
				 {
					 this->BackgroundImage = Image::FromFile("LoggedOn.jpg");
					 this->signInButtonLabel->Enabled = true;
					 this->cancelButtonLabel->Enabled = true;
					 this->userNameInputBox->Enabled = true;
					 this->passwordInputBox->Enabled = true;
					 loggedOn = true;
				 }
			 }
private: System::Void cancelButtonLabel_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
			 }
private: System::Void signInButtonLabel_Click(System::Object^  sender, System::EventArgs^  e) {
			if(this->userNameInputBox->Text->Length == 0 || this->passwordInputBox->Text->Length == 0)
			{
				MessageBox::Show("Please Enter a Username and Password");
				this->userNameInputBox->Clear();
				this->passwordInputBox->Clear();
				this->userNameInputBox->Focus();
			}
			else
			{
				(this->userNameInputBox->Text == "Felipe" && this->passwordInputBox->Text == "Corona") ||
					(this->userNameInputBox->Text == "Jahiro" && this->passwordInputBox->Text == "Otzoy") ||
					(this->userNameInputBox->Text == "Salman" && this->passwordInputBox->Text == "Shah") ||
					(this->userNameInputBox->Text == "Brian" && this->passwordInputBox->Text == "Vu") ||
					(this->userNameInputBox->Text == "Mauricio" && this->passwordInputBox->Text == "Luna");
				string userName = (marshal_as<std::string>(this->userNameInputBox->Text->ToString()));
				string passWord = (marshal_as<std::string>(this->passwordInputBox->Text->ToString()));
				accountsIter iter;
				bool check = pTillItHurtsHotel->accountExistsByUsername(userName);
				
				if(check)
				{
					iter = pTillItHurtsHotel->findAccountByUsername(userName);
				}
				

				if(check && (*iter)->getPassword() == passWord)
				{
					signedIn = true;
					this->addReservationButtonLabel->Enabled = true;
					this->settingsButtonLabel->Enabled = true;
					this->userNameInputBox->Clear();
					this->passwordInputBox->Clear();
					this->userNameInputBox->Focus();
				}
				else
				{
					this->userNameInputBox->Clear();
					this->passwordInputBox->Clear();
					this->userNameInputBox->Focus();
				}
				if(signedIn)
				{
					 this->BackgroundImage = Image::FromFile("Top Menu (Buttons are on).jpg");
				}
			}
		 }
private: System::Void settingsButtonLabel_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(signedIn)
			 {
				 this->Visible = false;
				 inventorysMenuForm->ShowDialog();
				 this->Visible = true;
			 }
		 }
private: System::Void addReservationButtonLabel_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(signedIn)
			 {
				 this->Hide();
				 roomCalendarForm->ShowDialog();
				 this->Visible = true;
			 }
		 }
};
}
