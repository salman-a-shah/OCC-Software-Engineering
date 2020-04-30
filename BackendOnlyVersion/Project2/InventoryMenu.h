#pragma once
#include "AccountMenu.h"
#include "RatesMenu.h"
#include "ReportsMenu.h"
#include "ReservationMenu.h"



namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for InventoryMenu
	/// </summary>
	public ref class InventoryMenu : public System::Windows::Forms::Form
	{
	public:
		InventoryMenu(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			isOnAdd = true;
			isOnModify = false;
			isOnRemove = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~InventoryMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  inventoryButtonLabel;
	private: System::Windows::Forms::Label^  addRoomtypeButtonLabel;
	protected: 

	private: System::Windows::Forms::Label^  ratesButtonLabel;
	private: System::Windows::Forms::Label^  reportsButtonLabel;
	private: System::Windows::Forms::Label^  accountsButtonLabel;
	private: System::Windows::Forms::Label^  addButtonLabel;
	private: System::Windows::Forms::Label^  removeButtonLabel;
	private: System::Windows::Forms::Label^  modifyButtonLabel;
	private: System::Windows::Forms::Label^  removeRoomtypeButtonLabel;
	private: System::Windows::Forms::Label^  modifyRoomtypeButtonLabel;


	private: System::Windows::Forms::ComboBox^  roomNumberComboBox;

	private: System::Windows::Forms::TextBox^  typeNameInputTextBox;
	private: System::Windows::Forms::TextBox^  typeCodeInputTextBox;
	private: System::Windows::Forms::TextBox^  numOfBedsTextBox;
	private: System::Windows::Forms::TextBox^  maxAdultsInputTextBox4;
	private: System::Windows::Forms::TextBox^  maxChildrenInputTextBox5;
	private: System::Windows::Forms::TextBox^  featuresInputTextBox;
	private: System::Windows::Forms::TextBox^  descriptionInputTextBox;
	private: System::Windows::Forms::Label^  exitButtonLabel;











	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		bool isOnAdd;
		bool isOnRemove;
	private: System::Windows::Forms::ComboBox^  roomTypeComboBox;

	private: System::Windows::Forms::ComboBox^  typeNameComboBox;
	private: System::Windows::Forms::Label^  roomButton;
	private: System::Windows::Forms::Label^  addRoomTypeButton;

	private: System::Windows::Forms::Label^  removeRoomTypeButton;
	private: System::Windows::Forms::Label^  modifyRoomTypeButton;
	private: System::Windows::Forms::Label^  reservationButton;
			 bool isOnModify;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(InventoryMenu::typeid));
			this->inventoryButtonLabel = (gcnew System::Windows::Forms::Label());
			this->addRoomtypeButtonLabel = (gcnew System::Windows::Forms::Label());
			this->ratesButtonLabel = (gcnew System::Windows::Forms::Label());
			this->reportsButtonLabel = (gcnew System::Windows::Forms::Label());
			this->accountsButtonLabel = (gcnew System::Windows::Forms::Label());
			this->addButtonLabel = (gcnew System::Windows::Forms::Label());
			this->removeButtonLabel = (gcnew System::Windows::Forms::Label());
			this->modifyButtonLabel = (gcnew System::Windows::Forms::Label());
			this->removeRoomtypeButtonLabel = (gcnew System::Windows::Forms::Label());
			this->modifyRoomtypeButtonLabel = (gcnew System::Windows::Forms::Label());
			this->roomNumberComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->typeNameInputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->typeCodeInputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->numOfBedsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->maxAdultsInputTextBox4 = (gcnew System::Windows::Forms::TextBox());
			this->maxChildrenInputTextBox5 = (gcnew System::Windows::Forms::TextBox());
			this->featuresInputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->descriptionInputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->exitButtonLabel = (gcnew System::Windows::Forms::Label());
			this->roomTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->typeNameComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->roomButton = (gcnew System::Windows::Forms::Label());
			this->addRoomTypeButton = (gcnew System::Windows::Forms::Label());
			this->removeRoomTypeButton = (gcnew System::Windows::Forms::Label());
			this->modifyRoomTypeButton = (gcnew System::Windows::Forms::Label());
			this->reservationButton = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// inventoryButtonLabel
			// 
			this->inventoryButtonLabel->BackColor = System::Drawing::Color::Transparent;
			this->inventoryButtonLabel->ForeColor = System::Drawing::Color::Transparent;
			this->inventoryButtonLabel->Location = System::Drawing::Point(12, 9);
			this->inventoryButtonLabel->Name = L"inventoryButtonLabel";
			this->inventoryButtonLabel->Size = System::Drawing::Size(120, 39);
			this->inventoryButtonLabel->TabIndex = 0;
			// 
			// addRoomtypeButtonLabel
			// 
			this->addRoomtypeButtonLabel->BackColor = System::Drawing::Color::Transparent;
			this->addRoomtypeButtonLabel->Location = System::Drawing::Point(37, 269);
			this->addRoomtypeButtonLabel->Name = L"addRoomtypeButtonLabel";
			this->addRoomtypeButtonLabel->Size = System::Drawing::Size(35, 13);
			this->addRoomtypeButtonLabel->TabIndex = 1;
			this->addRoomtypeButtonLabel->Click += gcnew System::EventHandler(this, &InventoryMenu::addRoomtypeButtonLabel_Click);
			// 
			// ratesButtonLabel
			// 
			this->ratesButtonLabel->BackColor = System::Drawing::Color::Transparent;
			this->ratesButtonLabel->ForeColor = System::Drawing::Color::Transparent;
			this->ratesButtonLabel->Location = System::Drawing::Point(138, 9);
			this->ratesButtonLabel->Name = L"ratesButtonLabel";
			this->ratesButtonLabel->Size = System::Drawing::Size(111, 39);
			this->ratesButtonLabel->TabIndex = 2;
			this->ratesButtonLabel->Click += gcnew System::EventHandler(this, &InventoryMenu::ratesButtonLabel_Click);
			// 
			// reportsButtonLabel
			// 
			this->reportsButtonLabel->BackColor = System::Drawing::Color::Transparent;
			this->reportsButtonLabel->ForeColor = System::Drawing::Color::Transparent;
			this->reportsButtonLabel->Location = System::Drawing::Point(255, 9);
			this->reportsButtonLabel->Name = L"reportsButtonLabel";
			this->reportsButtonLabel->Size = System::Drawing::Size(120, 39);
			this->reportsButtonLabel->TabIndex = 3;
			this->reportsButtonLabel->Click += gcnew System::EventHandler(this, &InventoryMenu::reportsButtonLabel_Click);
			// 
			// accountsButtonLabel
			// 
			this->accountsButtonLabel->BackColor = System::Drawing::Color::Transparent;
			this->accountsButtonLabel->ForeColor = System::Drawing::Color::Transparent;
			this->accountsButtonLabel->Location = System::Drawing::Point(381, 9);
			this->accountsButtonLabel->Name = L"accountsButtonLabel";
			this->accountsButtonLabel->Size = System::Drawing::Size(109, 39);
			this->accountsButtonLabel->TabIndex = 4;
			this->accountsButtonLabel->Click += gcnew System::EventHandler(this, &InventoryMenu::accountsButtonLabel_Click);
			// 
			// addButtonLabel
			// 
			this->addButtonLabel->BackColor = System::Drawing::Color::Transparent;
			this->addButtonLabel->Location = System::Drawing::Point(37, 69);
			this->addButtonLabel->Name = L"addButtonLabel";
			this->addButtonLabel->Size = System::Drawing::Size(40, 23);
			this->addButtonLabel->TabIndex = 5;
			this->addButtonLabel->Click += gcnew System::EventHandler(this, &InventoryMenu::addButtonLabel_Click);
			// 
			// removeButtonLabel
			// 
			this->removeButtonLabel->BackColor = System::Drawing::Color::Transparent;
			this->removeButtonLabel->Location = System::Drawing::Point(92, 69);
			this->removeButtonLabel->Name = L"removeButtonLabel";
			this->removeButtonLabel->Size = System::Drawing::Size(49, 23);
			this->removeButtonLabel->TabIndex = 6;
			this->removeButtonLabel->Click += gcnew System::EventHandler(this, &InventoryMenu::removeButtonLabel_Click);
			// 
			// modifyButtonLabel
			// 
			this->modifyButtonLabel->BackColor = System::Drawing::Color::Transparent;
			this->modifyButtonLabel->Location = System::Drawing::Point(163, 69);
			this->modifyButtonLabel->Name = L"modifyButtonLabel";
			this->modifyButtonLabel->Size = System::Drawing::Size(49, 23);
			this->modifyButtonLabel->TabIndex = 7;
			this->modifyButtonLabel->Click += gcnew System::EventHandler(this, &InventoryMenu::modifyButtonLabel_Click);
			// 
			// removeRoomtypeButtonLabel
			// 
			this->removeRoomtypeButtonLabel->BackColor = System::Drawing::Color::Transparent;
			this->removeRoomtypeButtonLabel->Location = System::Drawing::Point(92, 260);
			this->removeRoomtypeButtonLabel->Name = L"removeRoomtypeButtonLabel";
			this->removeRoomtypeButtonLabel->Size = System::Drawing::Size(49, 22);
			this->removeRoomtypeButtonLabel->TabIndex = 8;
			this->removeRoomtypeButtonLabel->Click += gcnew System::EventHandler(this, &InventoryMenu::removeRoomtypeButtonLabel_Click);
			// 
			// modifyRoomtypeButtonLabel
			// 
			this->modifyRoomtypeButtonLabel->BackColor = System::Drawing::Color::Transparent;
			this->modifyRoomtypeButtonLabel->Location = System::Drawing::Point(163, 269);
			this->modifyRoomtypeButtonLabel->Name = L"modifyRoomtypeButtonLabel";
			this->modifyRoomtypeButtonLabel->Size = System::Drawing::Size(49, 22);
			this->modifyRoomtypeButtonLabel->TabIndex = 9;
			this->modifyRoomtypeButtonLabel->Click += gcnew System::EventHandler(this, &InventoryMenu::modifyRoomtypeButtonLabel_Click);
			// 
			// roomNumberComboBox
			// 
			this->roomNumberComboBox->BackColor = System::Drawing::Color::Black;
			this->roomNumberComboBox->ForeColor = System::Drawing::Color::White;
			this->roomNumberComboBox->FormattingEnabled = true;
			this->roomNumberComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(10) {L"1", L"2", L"3", L"4", L"5", L"6", L"7", 
				L"8", L"9", L"10"});
			this->roomNumberComboBox->Location = System::Drawing::Point(131, 140);
			this->roomNumberComboBox->Name = L"roomNumberComboBox";
			this->roomNumberComboBox->Size = System::Drawing::Size(226, 21);
			this->roomNumberComboBox->TabIndex = 11;
			// 
			// typeNameInputTextBox
			// 
			this->typeNameInputTextBox->BackColor = System::Drawing::Color::Black;
			this->typeNameInputTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->typeNameInputTextBox->ForeColor = System::Drawing::Color::White;
			this->typeNameInputTextBox->Location = System::Drawing::Point(141, 304);
			this->typeNameInputTextBox->Name = L"typeNameInputTextBox";
			this->typeNameInputTextBox->Size = System::Drawing::Size(207, 13);
			this->typeNameInputTextBox->TabIndex = 12;
			// 
			// typeCodeInputTextBox
			// 
			this->typeCodeInputTextBox->BackColor = System::Drawing::Color::Black;
			this->typeCodeInputTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->typeCodeInputTextBox->ForeColor = System::Drawing::Color::White;
			this->typeCodeInputTextBox->Location = System::Drawing::Point(141, 333);
			this->typeCodeInputTextBox->Name = L"typeCodeInputTextBox";
			this->typeCodeInputTextBox->Size = System::Drawing::Size(207, 13);
			this->typeCodeInputTextBox->TabIndex = 13;
			this->typeCodeInputTextBox->TextChanged += gcnew System::EventHandler(this, &InventoryMenu::typeCodeInputTextBox_TextChanged);
			// 
			// numOfBedsTextBox
			// 
			this->numOfBedsTextBox->BackColor = System::Drawing::Color::Black;
			this->numOfBedsTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->numOfBedsTextBox->ForeColor = System::Drawing::Color::White;
			this->numOfBedsTextBox->Location = System::Drawing::Point(141, 365);
			this->numOfBedsTextBox->Name = L"numOfBedsTextBox";
			this->numOfBedsTextBox->Size = System::Drawing::Size(207, 13);
			this->numOfBedsTextBox->TabIndex = 14;
			// 
			// maxAdultsInputTextBox4
			// 
			this->maxAdultsInputTextBox4->BackColor = System::Drawing::Color::Black;
			this->maxAdultsInputTextBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->maxAdultsInputTextBox4->ForeColor = System::Drawing::Color::White;
			this->maxAdultsInputTextBox4->Location = System::Drawing::Point(141, 395);
			this->maxAdultsInputTextBox4->Name = L"maxAdultsInputTextBox4";
			this->maxAdultsInputTextBox4->Size = System::Drawing::Size(207, 13);
			this->maxAdultsInputTextBox4->TabIndex = 15;
			// 
			// maxChildrenInputTextBox5
			// 
			this->maxChildrenInputTextBox5->BackColor = System::Drawing::Color::Black;
			this->maxChildrenInputTextBox5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->maxChildrenInputTextBox5->ForeColor = System::Drawing::Color::White;
			this->maxChildrenInputTextBox5->Location = System::Drawing::Point(141, 427);
			this->maxChildrenInputTextBox5->Name = L"maxChildrenInputTextBox5";
			this->maxChildrenInputTextBox5->Size = System::Drawing::Size(207, 13);
			this->maxChildrenInputTextBox5->TabIndex = 16;
			// 
			// featuresInputTextBox
			// 
			this->featuresInputTextBox->BackColor = System::Drawing::Color::Black;
			this->featuresInputTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->featuresInputTextBox->ForeColor = System::Drawing::Color::White;
			this->featuresInputTextBox->Location = System::Drawing::Point(471, 111);
			this->featuresInputTextBox->Multiline = true;
			this->featuresInputTextBox->Name = L"featuresInputTextBox";
			this->featuresInputTextBox->Size = System::Drawing::Size(207, 92);
			this->featuresInputTextBox->TabIndex = 17;
			// 
			// descriptionInputTextBox
			// 
			this->descriptionInputTextBox->BackColor = System::Drawing::Color::Black;
			this->descriptionInputTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->descriptionInputTextBox->ForeColor = System::Drawing::Color::White;
			this->descriptionInputTextBox->Location = System::Drawing::Point(471, 304);
			this->descriptionInputTextBox->Multiline = true;
			this->descriptionInputTextBox->Name = L"descriptionInputTextBox";
			this->descriptionInputTextBox->Size = System::Drawing::Size(207, 42);
			this->descriptionInputTextBox->TabIndex = 18;
			// 
			// exitButtonLabel
			// 
			this->exitButtonLabel->BackColor = System::Drawing::Color::Transparent;
			this->exitButtonLabel->ForeColor = System::Drawing::Color::Transparent;
			this->exitButtonLabel->Location = System::Drawing::Point(592, 9);
			this->exitButtonLabel->Name = L"exitButtonLabel";
			this->exitButtonLabel->Size = System::Drawing::Size(111, 39);
			this->exitButtonLabel->TabIndex = 19;
			this->exitButtonLabel->Click += gcnew System::EventHandler(this, &InventoryMenu::exitButtonLabel_Click);
			// 
			// roomTypeComboBox
			// 
			this->roomTypeComboBox->BackColor = System::Drawing::Color::Black;
			this->roomTypeComboBox->ForeColor = System::Drawing::Color::White;
			this->roomTypeComboBox->FormattingEnabled = true;
			this->roomTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Single", L"Double", L"Suite", L"VIlla"});
			this->roomTypeComboBox->Location = System::Drawing::Point(131, 108);
			this->roomTypeComboBox->Name = L"roomTypeComboBox";
			this->roomTypeComboBox->Size = System::Drawing::Size(226, 21);
			this->roomTypeComboBox->TabIndex = 20;
			// 
			// typeNameComboBox
			// 
			this->typeNameComboBox->BackColor = System::Drawing::Color::Black;
			this->typeNameComboBox->Enabled = false;
			this->typeNameComboBox->ForeColor = System::Drawing::Color::White;
			this->typeNameComboBox->FormattingEnabled = true;
			this->typeNameComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Single", L"Double", L"Suite", L"VIlla"});
			this->typeNameComboBox->Location = System::Drawing::Point(131, 301);
			this->typeNameComboBox->Name = L"typeNameComboBox";
			this->typeNameComboBox->Size = System::Drawing::Size(226, 21);
			this->typeNameComboBox->TabIndex = 21;
			this->typeNameComboBox->Visible = false;
			// 
			// roomButton
			// 
			this->roomButton->BackColor = System::Drawing::Color::Transparent;
			this->roomButton->Location = System::Drawing::Point(29, 190);
			this->roomButton->Name = L"roomButton";
			this->roomButton->Size = System::Drawing::Size(148, 26);
			this->roomButton->TabIndex = 22;
			// 
			// addRoomTypeButton
			// 
			this->addRoomTypeButton->BackColor = System::Drawing::Color::Transparent;
			this->addRoomTypeButton->Location = System::Drawing::Point(29, 511);
			this->addRoomTypeButton->Name = L"addRoomTypeButton";
			this->addRoomTypeButton->Size = System::Drawing::Size(148, 26);
			this->addRoomTypeButton->TabIndex = 23;
			this->addRoomTypeButton->Click += gcnew System::EventHandler(this, &InventoryMenu::roomTypeButtonLabel_Click);
			// 
			// removeRoomTypeButton
			// 
			this->removeRoomTypeButton->BackColor = System::Drawing::Color::Transparent;
			this->removeRoomTypeButton->Enabled = false;
			this->removeRoomTypeButton->Location = System::Drawing::Point(29, 511);
			this->removeRoomTypeButton->Name = L"removeRoomTypeButton";
			this->removeRoomTypeButton->Size = System::Drawing::Size(148, 26);
			this->removeRoomTypeButton->TabIndex = 24;
			this->removeRoomTypeButton->Click += gcnew System::EventHandler(this, &InventoryMenu::removeRoomTypeButton_Click);
			// 
			// modifyRoomTypeButton
			// 
			this->modifyRoomTypeButton->BackColor = System::Drawing::Color::Transparent;
			this->modifyRoomTypeButton->Enabled = false;
			this->modifyRoomTypeButton->Location = System::Drawing::Point(29, 511);
			this->modifyRoomTypeButton->Name = L"modifyRoomTypeButton";
			this->modifyRoomTypeButton->Size = System::Drawing::Size(148, 26);
			this->modifyRoomTypeButton->TabIndex = 25;
			this->modifyRoomTypeButton->Click += gcnew System::EventHandler(this, &InventoryMenu::modifyRoomTypeButton_Click);
			// 
			// reservationButton
			// 
			this->reservationButton->BackColor = System::Drawing::Color::Transparent;
			this->reservationButton->ForeColor = System::Drawing::Color::Transparent;
			this->reservationButton->Location = System::Drawing::Point(496, 9);
			this->reservationButton->Name = L"reservationButton";
			this->reservationButton->Size = System::Drawing::Size(98, 39);
			this->reservationButton->TabIndex = 26;
			this->reservationButton->Click += gcnew System::EventHandler(this, &InventoryMenu::reservationButton_Click);
			// 
			// InventoryMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(715, 568);
			this->Controls->Add(this->reservationButton);
			this->Controls->Add(this->modifyRoomTypeButton);
			this->Controls->Add(this->removeRoomTypeButton);
			this->Controls->Add(this->addRoomTypeButton);
			this->Controls->Add(this->roomButton);
			this->Controls->Add(this->typeNameComboBox);
			this->Controls->Add(this->roomTypeComboBox);
			this->Controls->Add(this->exitButtonLabel);
			this->Controls->Add(this->descriptionInputTextBox);
			this->Controls->Add(this->featuresInputTextBox);
			this->Controls->Add(this->maxChildrenInputTextBox5);
			this->Controls->Add(this->maxAdultsInputTextBox4);
			this->Controls->Add(this->numOfBedsTextBox);
			this->Controls->Add(this->typeCodeInputTextBox);
			this->Controls->Add(this->typeNameInputTextBox);
			this->Controls->Add(this->roomNumberComboBox);
			this->Controls->Add(this->modifyRoomtypeButtonLabel);
			this->Controls->Add(this->removeRoomtypeButtonLabel);
			this->Controls->Add(this->modifyButtonLabel);
			this->Controls->Add(this->removeButtonLabel);
			this->Controls->Add(this->addButtonLabel);
			this->Controls->Add(this->accountsButtonLabel);
			this->Controls->Add(this->reportsButtonLabel);
			this->Controls->Add(this->ratesButtonLabel);
			this->Controls->Add(this->addRoomtypeButtonLabel);
			this->Controls->Add(this->inventoryButtonLabel);
			this->Name = L"InventoryMenu";
			this->Text = L"InventoryMenu";
			this->Load += gcnew System::EventHandler(this, &InventoryMenu::InventoryMenu_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void InventoryMenu_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void removeButtonLabel_Click(System::Object^  sender, System::EventArgs^  e) {
			 isOnAdd = false;
			 isOnModify = false;
			 isOnRemove = true;

			 this->BackgroundImage = Image::FromFile("Backgrounds/Remove-Add.jpg");
			 this->roomTypeComboBox->Visible = true;
			 this->roomTypeComboBox->Enabled = true;
			 this->featuresInputTextBox->Visible = false;
			 this->featuresInputTextBox->Enabled = false;

			 this->typeNameInputTextBox->Clear();
			 this->typeNameInputTextBox->Focus();
			 this->typeCodeInputTextBox->Clear();
			 this->numOfBedsTextBox->Clear();
			 this->maxAdultsInputTextBox4->Clear();
			 this->maxChildrenInputTextBox5->Clear();

			 this->typeNameInputTextBox->Enabled = true;
			 this->typeNameInputTextBox->Visible = true;
			 this->typeCodeInputTextBox->Enabled = true;
			 this->typeCodeInputTextBox->Show();
			 this->numOfBedsTextBox->Enabled = true;
			 this->numOfBedsTextBox->Show();
			 this->maxAdultsInputTextBox4->Enabled = true;
			 this->maxAdultsInputTextBox4->Show();
			 this->maxChildrenInputTextBox5->Enabled = true;
			 this->maxChildrenInputTextBox5->Show();
			 this->featuresInputTextBox->Enabled = true;

			 this->typeNameComboBox->Enabled = false;
			 this->typeNameComboBox->Visible = false;


			 }
private: System::Void addButtonLabel_Click(System::Object^  sender, System::EventArgs^  e) {
			 isOnAdd = true;
			 isOnModify = false;
			 isOnRemove = false;

			 this->BackgroundImage = Image::FromFile("Backgrounds/Add-Add.jpg");
			 this->roomTypeComboBox->Visible = true;
			 this->roomTypeComboBox->Enabled = true;
			 this->featuresInputTextBox->Visible = true;
			 this->featuresInputTextBox->Enabled = true;

			 this->typeNameInputTextBox->Clear();
			 this->typeNameInputTextBox->Focus();
			 this->typeCodeInputTextBox->Clear();
			 this->numOfBedsTextBox->Clear();
			 this->maxAdultsInputTextBox4->Clear();
			 this->maxChildrenInputTextBox5->Clear();

			 this->typeNameInputTextBox->Enabled = true;
			 this->typeNameInputTextBox->Visible = true;
			 this->typeCodeInputTextBox->Enabled = true;
			 this->typeCodeInputTextBox->Show();
			 this->numOfBedsTextBox->Enabled = true;
			 this->numOfBedsTextBox->Show();
			 this->maxAdultsInputTextBox4->Enabled = true;
			 this->maxAdultsInputTextBox4->Show();
			 this->maxChildrenInputTextBox5->Enabled = true;
			 this->maxChildrenInputTextBox5->Show();
			 this->featuresInputTextBox->Enabled = true;

			 this->typeNameComboBox->Enabled = false;
			 this->typeNameComboBox->Visible = false;
		 }
private: System::Void addRoomtypeButtonLabel_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(isOnAdd)
			 {
				 this->BackgroundImage = Image::FromFile("Backgrounds/Add-Add.jpg");
			 }
			 else if(isOnModify)
			 {
				 this->BackgroundImage = Image::FromFile("Backgrounds/Modify-Add.jpg");
			 }
			 else if(isOnRemove)
			 {
				 this->BackgroundImage = Image::FromFile("Backgrounds/Remove-Add.jpg");
			 }
			 this->typeNameInputTextBox->Clear();
			 this->typeNameInputTextBox->Focus();
			 this->typeCodeInputTextBox->Clear();
			 this->numOfBedsTextBox->Clear();
			 this->maxAdultsInputTextBox4->Clear();
			 this->maxChildrenInputTextBox5->Clear();

			 this->typeNameInputTextBox->Enabled = true;
			 this->typeNameInputTextBox->Visible = true;
			 this->typeCodeInputTextBox->Enabled = true;
			 this->typeCodeInputTextBox->Show();
			 this->numOfBedsTextBox->Enabled = true;
			 this->numOfBedsTextBox->Show();
			 this->maxAdultsInputTextBox4->Enabled = true;
			 this->maxAdultsInputTextBox4->Show();
			 this->maxChildrenInputTextBox5->Enabled = true;
			 this->maxChildrenInputTextBox5->Show();
			 this->featuresInputTextBox->Enabled = true;

			 this->typeNameComboBox->Enabled = false;
			 this->typeNameComboBox->Visible = false;

			 this->addRoomTypeButton->Enabled = true;
			 this->addRoomTypeButton->Visible = true;
			 this->modifyRoomTypeButton->Enabled = false;
			 this->modifyRoomTypeButton->Visible = false;
			 this->removeRoomTypeButton->Enabled = true;
			 this->removeRoomTypeButton->Visible = true;


		 }
private: System::Void removeRoomtypeButtonLabel_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(isOnAdd)
			 {
				 this->BackgroundImage = Image::FromFile("Backgrounds/Add-Remove.jpg");
			 }
			 else if(isOnModify)
			 {
				 this->BackgroundImage = Image::FromFile("Backgrounds/Modify-Remove.jpg");
			 }
			 else if(isOnRemove)
			 {
				 this->BackgroundImage = Image::FromFile("Backgrounds/Remove-Remove.jpg");
			 }
			 this->typeNameInputTextBox->Clear();
			 this->typeNameInputTextBox->Focus();
			 this->typeCodeInputTextBox->Clear();
			 this->numOfBedsTextBox->Clear();
			 this->maxAdultsInputTextBox4->Clear();
			 this->maxChildrenInputTextBox5->Clear();

			 this->typeNameComboBox->Enabled = true;
			 this->typeNameComboBox->Visible = true;
			 this->removeRoomTypeButton->Enabled = true;
			 this->removeRoomTypeButton->Visible = true;

			 this->typeNameInputTextBox->Enabled =false;
			 this->typeNameInputTextBox->Visible = false;
			 this->typeCodeInputTextBox->Enabled = false;
			 this->typeCodeInputTextBox->Hide();
			 this->numOfBedsTextBox->Enabled = false;
			 this->numOfBedsTextBox->Hide();
			 this->maxAdultsInputTextBox4->Enabled = false;
			 this->maxAdultsInputTextBox4->Hide();
			 this->maxChildrenInputTextBox5->Enabled = false;
			 this->maxChildrenInputTextBox5->Hide();
			 this->addRoomTypeButton->Enabled = false;
			 this->addRoomTypeButton->Visible = false;
			 this->modifyRoomTypeButton->Enabled = false;
			 this->modifyRoomTypeButton->Visible = false;
		 }
private: System::Void modifyRoomtypeButtonLabel_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(isOnAdd)
			 {
				 this->BackgroundImage = Image::FromFile("Backgrounds/Add-Modify.jpg");
			 }
			 else if(isOnModify)
			 {
				 this->BackgroundImage = Image::FromFile("Backgrounds/Modify-Modify.jpg");
			 }
			 else if(isOnRemove)
			 {
				 this->BackgroundImage = Image::FromFile("Backgrounds/Remove-Modify.jpg");
			 }
			 this->typeNameInputTextBox->Clear();
			 this->typeNameInputTextBox->Focus();
			 this->typeCodeInputTextBox->Clear();
			 this->numOfBedsTextBox->Clear();
			 this->maxAdultsInputTextBox4->Clear();
			 this->maxChildrenInputTextBox5->Clear();

			 this->typeNameComboBox->Enabled = true;
			 this->typeNameComboBox->Visible = true;
			 this->modifyRoomTypeButton->Enabled = true;
			 this->modifyRoomTypeButton->Visible = true;

			 this->typeNameInputTextBox->Enabled =false;
			 this->typeNameInputTextBox->Visible = false;
			 this->addRoomTypeButton->Enabled = false;
			 this->addRoomTypeButton->Visible = false;
			 this->removeRoomTypeButton->Enabled = false;
			 this->removeRoomTypeButton->Visible = false;

			 this->typeCodeInputTextBox->Enabled = true;
			 this->typeCodeInputTextBox->Show();
			 this->numOfBedsTextBox->Enabled = true;
			 this->numOfBedsTextBox->Show();
			 this->maxAdultsInputTextBox4->Enabled = true;
			 this->maxAdultsInputTextBox4->Show();
			 this->maxChildrenInputTextBox5->Enabled = true;
			 this->maxChildrenInputTextBox5->Show();
			 this->featuresInputTextBox->Enabled = true;
		 }
private: System::Void exitButtonLabel_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void modifyButtonLabel_Click(System::Object^  sender, System::EventArgs^  e) {
			 isOnAdd = false;
			 isOnModify = true;
			 isOnRemove = false;

			 this->BackgroundImage = Image::FromFile("Backgrounds/Modify-Add.jpg");
			 this->roomTypeComboBox->Visible = true;
			 this->roomTypeComboBox->Enabled = true;
			 this->featuresInputTextBox->Visible = true;
			 this->featuresInputTextBox->Enabled = true;

			 this->typeNameInputTextBox->Clear();
			 this->typeNameInputTextBox->Focus();
			 this->typeCodeInputTextBox->Clear();
			 this->numOfBedsTextBox->Clear();
			 this->maxAdultsInputTextBox4->Clear();
			 this->maxChildrenInputTextBox5->Clear();

			 this->typeNameInputTextBox->Enabled = true;
			 this->typeNameInputTextBox->Visible = true;
			 this->typeCodeInputTextBox->Enabled = true;
			 this->typeCodeInputTextBox->Show();
			 this->numOfBedsTextBox->Enabled = true;
			 this->numOfBedsTextBox->Show();
			 this->maxAdultsInputTextBox4->Enabled = true;
			 this->maxAdultsInputTextBox4->Show();
			 this->maxChildrenInputTextBox5->Enabled = true;
			 this->maxChildrenInputTextBox5->Show();
			 this->featuresInputTextBox->Enabled = true;

			 this->typeNameComboBox->Enabled = false;
			 this->typeNameComboBox->Visible = false;
		 }
private: System::Void roomTypeButtonLabel_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->typeNameInputTextBox->Text->Length > 0)
			 {
				 this->typeNameComboBox->Items->Add( this->typeNameInputTextBox->Text);
				 this->roomTypeComboBox->Items->Add( this->typeNameInputTextBox->Text);

				 this->typeNameInputTextBox->Clear();
				 this->typeNameInputTextBox->Focus();
				 this->typeCodeInputTextBox->Clear();
				 this->numOfBedsTextBox->Clear();
				 this->maxAdultsInputTextBox4->Clear();
				 this->maxChildrenInputTextBox5->Clear();


			 }
		 }
private: System::Void modifyRoomTypeButton_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void addRoomTypeButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->roomTypeComboBox->Items->Add(this->typeNameInputTextBox->Text);
			 this->typeNameComboBox->Items->Add(this->typeNameInputTextBox->Text);
		 }
private: System::Void removeRoomTypeButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->roomTypeComboBox->Items->Remove(this->typeNameComboBox->SelectedItem);
			 this->typeNameComboBox->Items->Remove( this->typeNameComboBox->SelectedItem);
		 }
private: System::Void ratesButtonLabel_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			 RatesMenu^ ratesForm = gcnew RatesMenu;
			 ratesForm->DesktopLocation = this->DesktopLocation;
			 ratesForm->ShowDialog();
			 this->Show();

		 }
private: System::Void reportsButtonLabel_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			 ReportsMenu^ reportsForm = gcnew ReportsMenu;
			 reportsForm->ShowDialog();
			 this->Show();
		 }
private: System::Void accountsButtonLabel_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			 AccountMenu^ accountsForm = gcnew AccountMenu;
			 accountsForm->ShowDialog();
			 this->Show();
		 }
private: System::Void reservationButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			 ReservationMenu^ reservationForm = gcnew ReservationMenu;
			 reservationForm->ShowDialog();
			 this->Show();
		 }
private: System::Void typeCodeInputTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
