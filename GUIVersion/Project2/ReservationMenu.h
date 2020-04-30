#pragma once 
#include "Room\Room.h"
#include "Reservation\Reservation.h"
#include <msclr\marshal_cppstd.h>
#include <iostream>
#include "dateSelectionCalendar.h"
#include "InventoryMenu.cpp"
#include "Hotel.h"

namespace Project2 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;
	/// <summary>
	/// Summary for ReservationMenu
	/// </summary>
	public ref class ReservationMenu : public System::Windows::Forms::Form
	{
	public:
		typedef list<Reservation*>::iterator reservationIter;
		ReservationMenu(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			inventoryMenu = gcnew InventoryMenu(theHotel);
			setInventoryMenu(inventoryMenu);
		}
		ReservationMenu(InventoryMenu^ oldinventoryMenu, Hotel *aHotel)
		{
			InitializeComponent();
			setInventoryMenu(oldinventoryMenu);
			theHotel = aHotel;
		}
		System::Void setInventoryMenu(InventoryMenu^ newInventoryMenu)
		{
			 inventoryMenu = newInventoryMenu;
			 if(roomTypeComboBox->Items->Count >= inventoryMenu->roomTypeComboBox->Items->Count)
			 {
				roomTypeComboBox->Items->Clear();
			 }
			 for (int i = 0; i < inventoryMenu->roomTypeComboBox->Items->Count; i++)
			 {		
				if(roomTypeComboBox->Items->IndexOf(inventoryMenu->roomTypeComboBox->Items[i]) < 0)
				{
					roomTypeComboBox->Items->Add(inventoryMenu->roomTypeComboBox->Items[i]);
				}
            }
			 cout << "in setInventory " << marshal_as<std::string>(roomTypeComboBox->Items->ToString()) << endl;
			 if(roomNumberComboBox->Items->Count >= inventoryMenu->getRoomNumberComboBox()->Items->Count)
			 {
					roomNumberComboBox->Items->Clear();
			 }
			 for (int i = 0; i < inventoryMenu->getRoomNumberComboBox()->Items->Count; i++)
			 {		
				if(roomNumberComboBox->Items->IndexOf(inventoryMenu->getRoomNumberComboBox()->Items[i]) < 0)
				{
					roomNumberComboBox->Items->Add(inventoryMenu->getRoomNumberComboBox()->Items[i]);
				}
            }
		}
		Void setWindow(Reservation *reservationTemp)
		{
			 this->nameInputTextbox->Text = gcnew String(reservationTemp->getGeneralInfo().getName().c_str());
			 this->addressInputTextbox->Text = gcnew String(reservationTemp->getGeneralInfo().getAddress().c_str());
			 this->cityInputTextbox->Text = gcnew String(reservationTemp->getGeneralInfo().getCity().c_str());
			 this->countryInputTextbox->Text = gcnew String(reservationTemp->getGeneralInfo().getCountry().c_str());
			 this->stateInputTextbox->Text = gcnew String(reservationTemp->getGeneralInfo().getState().c_str());
			/* this->zipcodeInputTextbox->Text = gcnew String(reservationTemp.getGeneralInfo().getZipCode().c_str());
			 this->emailInputTextbox->Text = gcnew String(reservationTemp.getGeneralInfo().getEmail().c_str());
			 this->phoneInputTextbox->Text = gcnew String(reservationTemp.getGeneralInfo().getPhoneNumber().c_str());
			 this->arrivalInputTextbox->Text = gcnew String((reservationTemp).getRequiredInfo().getArrivalDate().dateToString().c_str());
			 this->departureInputTextbox->Text = gcnew String((reservationTemp).getRequiredInfo().getDepartureDate().dateToString().c_str());
			 this->adultsInputTextBox->Text = gcnew String(reservationTemp.getGeneralInfo().getNumOfAdults().c_str());
			 this->childrenInputTextBox->Text = gcnew String(reservationTemp.getGeneralInfo().getNumOfChildren().c_str());
			 this->creditCardNumberInputTextBox->Text = gcnew String(reservationTemp.getCreditInfo().getCreditCardNumber().c_str());
			 this->expirationInputTextBox->Text = gcnew String(reservationTemp.getCreditInfo().getExpirationDate().c_str());*/
			 //this->messagesInputTextBox->Text = gcnew String((*iter)->getGeneralInfo().
			 //this->roomFeaturesInputTextBox->Text = gcnew String((*iter)->
			 //this->priceInputTextBox->Text = gcnew String((*iter)->getGeneralInfo().getName().c_str());
			 //this->discountInputTextBox->Text = gcnew String((*iter)->getGeneralInfo().getName().c_str());;
			 //this->taxInputTextBox->Text = gcnew String((*iter)->getGeneralInfo().getName().c_str());
			 //this->subtotalInputTextBox->Text = gcnew String((*iter)->getGeneralInfo().getName().c_str());
			 //this->totalNightsInputTextBox->Text = gcnew String((*iter)->getGeneralInfo().getName().c_str());
			 //this->grandTotalInputTextBox->Text = gcnew String((*iter)->getGeneralInfo().getName().c_str());
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ReservationMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  roomCalendarButton;
				InventoryMenu^ inventoryMenu;
				Hotel *theHotel;
	protected: 
	private: System::Windows::Forms::Label^  settingsButton;
	private: System::Windows::Forms::Label^  logOutButton;
	private: System::Windows::Forms::Label^  newReservationButton;
	private: System::Windows::Forms::Label^  deleteReservationButton;
	private: System::Windows::Forms::Label^  saveReservationButton;
	private: System::Windows::Forms::Label^  exitReservationButton;
	private: System::Windows::Forms::TextBox^  nameInputTextbox;
	private: System::Windows::Forms::TextBox^  addressInputTextbox;
	private: System::Windows::Forms::TextBox^  cityInputTextbox;
	private: System::Windows::Forms::TextBox^  emailInputTextbox;
	private: System::Windows::Forms::TextBox^  phoneInputTextbox;





	private: System::Windows::Forms::TextBox^  countryInputTextbox;
	private: System::Windows::Forms::TextBox^  stateInputTextbox;
	private: System::Windows::Forms::TextBox^  zipcodeInputTextbox;
	private: System::Windows::Forms::TextBox^  arrivalInputTextbox;
	private: System::Windows::Forms::TextBox^  departureInputTextbox;

	private: System::Windows::Forms::TextBox^  creditCardNumberInputTextBox;
	private: System::Windows::Forms::TextBox^  expirationInputTextBox;
	private: System::Windows::Forms::TextBox^  messagesInputTextBox;
	private: System::Windows::Forms::TextBox^  roomFeaturesInputTextBox;
	private: System::Windows::Forms::TextBox^  priceInputTextBox;
	private: System::Windows::Forms::TextBox^  discountInputTextBox;
	private: System::Windows::Forms::TextBox^  taxInputTextBox;
	private: System::Windows::Forms::TextBox^  subtotalInputTextBox;
	private: System::Windows::Forms::TextBox^  totalNightsInputTextBox;
	private: System::Windows::Forms::TextBox^  grandTotalInputTextBox;
	private: System::Windows::Forms::TextBox^  statusInputTextBox;




















	private: System::Windows::Forms::TextBox^  adultsInputTextBox;

	private: System::Windows::Forms::TextBox^  childrenInputTextBox;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  searchButton;
	private: System::Windows::Forms::Button^  arrivalDateCalendar;
	private: System::Windows::Forms::ComboBox^  roomTypeComboBox;
	private: System::Windows::Forms::ComboBox^  roomNumberComboBox;
	private: System::Windows::Forms::ComboBox^  creditCardComboBox;




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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ReservationMenu::typeid));
			this->roomCalendarButton = (gcnew System::Windows::Forms::Label());
			this->settingsButton = (gcnew System::Windows::Forms::Label());
			this->logOutButton = (gcnew System::Windows::Forms::Label());
			this->newReservationButton = (gcnew System::Windows::Forms::Label());
			this->deleteReservationButton = (gcnew System::Windows::Forms::Label());
			this->saveReservationButton = (gcnew System::Windows::Forms::Label());
			this->exitReservationButton = (gcnew System::Windows::Forms::Label());
			this->nameInputTextbox = (gcnew System::Windows::Forms::TextBox());
			this->addressInputTextbox = (gcnew System::Windows::Forms::TextBox());
			this->cityInputTextbox = (gcnew System::Windows::Forms::TextBox());
			this->emailInputTextbox = (gcnew System::Windows::Forms::TextBox());
			this->phoneInputTextbox = (gcnew System::Windows::Forms::TextBox());
			this->countryInputTextbox = (gcnew System::Windows::Forms::TextBox());
			this->stateInputTextbox = (gcnew System::Windows::Forms::TextBox());
			this->zipcodeInputTextbox = (gcnew System::Windows::Forms::TextBox());
			this->arrivalInputTextbox = (gcnew System::Windows::Forms::TextBox());
			this->departureInputTextbox = (gcnew System::Windows::Forms::TextBox());
			this->creditCardNumberInputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->expirationInputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->messagesInputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->roomFeaturesInputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->priceInputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->discountInputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->taxInputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->subtotalInputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->totalNightsInputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->grandTotalInputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->statusInputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->adultsInputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->childrenInputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->searchButton = (gcnew System::Windows::Forms::Label());
			this->arrivalDateCalendar = (gcnew System::Windows::Forms::Button());
			this->roomTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->roomNumberComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->creditCardComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// roomCalendarButton
			// 
			this->roomCalendarButton->BackColor = System::Drawing::Color::Transparent;
			this->roomCalendarButton->Location = System::Drawing::Point(21, 9);
			this->roomCalendarButton->Name = L"roomCalendarButton";
			this->roomCalendarButton->Size = System::Drawing::Size(116, 38);
			this->roomCalendarButton->TabIndex = 0;
			this->roomCalendarButton->Click += gcnew System::EventHandler(this, &ReservationMenu::roomCalendarButton_Click);
			// 
			// settingsButton
			// 
			this->settingsButton->BackColor = System::Drawing::Color::Transparent;
			this->settingsButton->Location = System::Drawing::Point(491, 9);
			this->settingsButton->Name = L"settingsButton";
			this->settingsButton->Size = System::Drawing::Size(104, 38);
			this->settingsButton->TabIndex = 1;
			this->settingsButton->Click += gcnew System::EventHandler(this, &ReservationMenu::settingsButton_Click);
			// 
			// logOutButton
			// 
			this->logOutButton->BackColor = System::Drawing::Color::Transparent;
			this->logOutButton->Location = System::Drawing::Point(601, 9);
			this->logOutButton->Name = L"logOutButton";
			this->logOutButton->Size = System::Drawing::Size(104, 38);
			this->logOutButton->TabIndex = 2;
			this->logOutButton->Click += gcnew System::EventHandler(this, &ReservationMenu::logOutButton_Click);
			// 
			// newReservationButton
			// 
			this->newReservationButton->BackColor = System::Drawing::Color::Transparent;
			this->newReservationButton->Location = System::Drawing::Point(12, 58);
			this->newReservationButton->Name = L"newReservationButton";
			this->newReservationButton->Size = System::Drawing::Size(88, 23);
			this->newReservationButton->TabIndex = 3;
			this->newReservationButton->Click += gcnew System::EventHandler(this, &ReservationMenu::newReservationButton_Click);
			// 
			// deleteReservationButton
			// 
			this->deleteReservationButton->BackColor = System::Drawing::Color::Transparent;
			this->deleteReservationButton->Location = System::Drawing::Point(106, 58);
			this->deleteReservationButton->Name = L"deleteReservationButton";
			this->deleteReservationButton->Size = System::Drawing::Size(88, 23);
			this->deleteReservationButton->TabIndex = 4;
			this->deleteReservationButton->Click += gcnew System::EventHandler(this, &ReservationMenu::deleteReservationButton_Click);
			// 
			// saveReservationButton
			// 
			this->saveReservationButton->BackColor = System::Drawing::Color::Transparent;
			this->saveReservationButton->Location = System::Drawing::Point(523, 58);
			this->saveReservationButton->Name = L"saveReservationButton";
			this->saveReservationButton->Size = System::Drawing::Size(88, 23);
			this->saveReservationButton->TabIndex = 5;
			this->saveReservationButton->Click += gcnew System::EventHandler(this, &ReservationMenu::saveReservationButton_Click);
			// 
			// exitReservationButton
			// 
			this->exitReservationButton->BackColor = System::Drawing::Color::Transparent;
			this->exitReservationButton->Location = System::Drawing::Point(617, 58);
			this->exitReservationButton->Name = L"exitReservationButton";
			this->exitReservationButton->Size = System::Drawing::Size(88, 23);
			this->exitReservationButton->TabIndex = 6;
			this->exitReservationButton->Click += gcnew System::EventHandler(this, &ReservationMenu::exitReservationButton_Click);
			// 
			// nameInputTextbox
			// 
			this->nameInputTextbox->BackColor = System::Drawing::Color::Black;
			this->nameInputTextbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->nameInputTextbox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->nameInputTextbox->ForeColor = System::Drawing::Color::White;
			this->nameInputTextbox->Location = System::Drawing::Point(86, 128);
			this->nameInputTextbox->Name = L"nameInputTextbox";
			this->nameInputTextbox->Size = System::Drawing::Size(245, 13);
			this->nameInputTextbox->TabIndex = 7;
			this->nameInputTextbox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// addressInputTextbox
			// 
			this->addressInputTextbox->BackColor = System::Drawing::Color::Black;
			this->addressInputTextbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->addressInputTextbox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->addressInputTextbox->ForeColor = System::Drawing::Color::White;
			this->addressInputTextbox->Location = System::Drawing::Point(86, 156);
			this->addressInputTextbox->Name = L"addressInputTextbox";
			this->addressInputTextbox->Size = System::Drawing::Size(245, 13);
			this->addressInputTextbox->TabIndex = 8;
			this->addressInputTextbox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// cityInputTextbox
			// 
			this->cityInputTextbox->BackColor = System::Drawing::Color::Black;
			this->cityInputTextbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->cityInputTextbox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->cityInputTextbox->ForeColor = System::Drawing::Color::White;
			this->cityInputTextbox->Location = System::Drawing::Point(86, 175);
			this->cityInputTextbox->Name = L"cityInputTextbox";
			this->cityInputTextbox->Size = System::Drawing::Size(245, 13);
			this->cityInputTextbox->TabIndex = 9;
			this->cityInputTextbox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// emailInputTextbox
			// 
			this->emailInputTextbox->BackColor = System::Drawing::Color::Black;
			this->emailInputTextbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->emailInputTextbox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->emailInputTextbox->ForeColor = System::Drawing::Color::White;
			this->emailInputTextbox->Location = System::Drawing::Point(86, 225);
			this->emailInputTextbox->Name = L"emailInputTextbox";
			this->emailInputTextbox->Size = System::Drawing::Size(245, 13);
			this->emailInputTextbox->TabIndex = 13;
			this->emailInputTextbox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// phoneInputTextbox
			// 
			this->phoneInputTextbox->BackColor = System::Drawing::Color::Black;
			this->phoneInputTextbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->phoneInputTextbox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->phoneInputTextbox->ForeColor = System::Drawing::Color::White;
			this->phoneInputTextbox->Location = System::Drawing::Point(86, 253);
			this->phoneInputTextbox->Margin = System::Windows::Forms::Padding(4);
			this->phoneInputTextbox->Name = L"phoneInputTextbox";
			this->phoneInputTextbox->Size = System::Drawing::Size(245, 13);
			this->phoneInputTextbox->TabIndex = 14;
			this->phoneInputTextbox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// countryInputTextbox
			// 
			this->countryInputTextbox->BackColor = System::Drawing::Color::Black;
			this->countryInputTextbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->countryInputTextbox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->countryInputTextbox->ForeColor = System::Drawing::Color::White;
			this->countryInputTextbox->Location = System::Drawing::Point(86, 206);
			this->countryInputTextbox->Name = L"countryInputTextbox";
			this->countryInputTextbox->Size = System::Drawing::Size(80, 13);
			this->countryInputTextbox->TabIndex = 10;
			this->countryInputTextbox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// stateInputTextbox
			// 
			this->stateInputTextbox->BackColor = System::Drawing::Color::Black;
			this->stateInputTextbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->stateInputTextbox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->stateInputTextbox->ForeColor = System::Drawing::Color::White;
			this->stateInputTextbox->Location = System::Drawing::Point(209, 206);
			this->stateInputTextbox->Name = L"stateInputTextbox";
			this->stateInputTextbox->Size = System::Drawing::Size(30, 13);
			this->stateInputTextbox->TabIndex = 11;
			this->stateInputTextbox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// zipcodeInputTextbox
			// 
			this->zipcodeInputTextbox->BackColor = System::Drawing::Color::Black;
			this->zipcodeInputTextbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->zipcodeInputTextbox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->zipcodeInputTextbox->ForeColor = System::Drawing::Color::White;
			this->zipcodeInputTextbox->Location = System::Drawing::Point(273, 206);
			this->zipcodeInputTextbox->Name = L"zipcodeInputTextbox";
			this->zipcodeInputTextbox->Size = System::Drawing::Size(58, 13);
			this->zipcodeInputTextbox->TabIndex = 12;
			this->zipcodeInputTextbox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// arrivalInputTextbox
			// 
			this->arrivalInputTextbox->BackColor = System::Drawing::Color::Black;
			this->arrivalInputTextbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->arrivalInputTextbox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->arrivalInputTextbox->ForeColor = System::Drawing::Color::White;
			this->arrivalInputTextbox->Location = System::Drawing::Point(127, 298);
			this->arrivalInputTextbox->Margin = System::Windows::Forms::Padding(4);
			this->arrivalInputTextbox->Multiline = true;
			this->arrivalInputTextbox->Name = L"arrivalInputTextbox";
			this->arrivalInputTextbox->Size = System::Drawing::Size(123, 13);
			this->arrivalInputTextbox->TabIndex = 15;
			this->arrivalInputTextbox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// departureInputTextbox
			// 
			this->departureInputTextbox->BackColor = System::Drawing::Color::Black;
			this->departureInputTextbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->departureInputTextbox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->departureInputTextbox->ForeColor = System::Drawing::Color::White;
			this->departureInputTextbox->Location = System::Drawing::Point(127, 319);
			this->departureInputTextbox->Margin = System::Windows::Forms::Padding(4);
			this->departureInputTextbox->Multiline = true;
			this->departureInputTextbox->Name = L"departureInputTextbox";
			this->departureInputTextbox->Size = System::Drawing::Size(123, 17);
			this->departureInputTextbox->TabIndex = 16;
			this->departureInputTextbox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// creditCardNumberInputTextBox
			// 
			this->creditCardNumberInputTextBox->BackColor = System::Drawing::Color::Black;
			this->creditCardNumberInputTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->creditCardNumberInputTextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->creditCardNumberInputTextBox->ForeColor = System::Drawing::Color::White;
			this->creditCardNumberInputTextBox->Location = System::Drawing::Point(127, 489);
			this->creditCardNumberInputTextBox->Margin = System::Windows::Forms::Padding(4);
			this->creditCardNumberInputTextBox->Multiline = true;
			this->creditCardNumberInputTextBox->Name = L"creditCardNumberInputTextBox";
			this->creditCardNumberInputTextBox->Size = System::Drawing::Size(204, 15);
			this->creditCardNumberInputTextBox->TabIndex = 22;
			this->creditCardNumberInputTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// expirationInputTextBox
			// 
			this->expirationInputTextBox->BackColor = System::Drawing::Color::Black;
			this->expirationInputTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->expirationInputTextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->expirationInputTextBox->ForeColor = System::Drawing::Color::White;
			this->expirationInputTextBox->Location = System::Drawing::Point(127, 512);
			this->expirationInputTextBox->Margin = System::Windows::Forms::Padding(4);
			this->expirationInputTextBox->Name = L"expirationInputTextBox";
			this->expirationInputTextBox->Size = System::Drawing::Size(204, 13);
			this->expirationInputTextBox->TabIndex = 23;
			this->expirationInputTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// messagesInputTextBox
			// 
			this->messagesInputTextBox->BackColor = System::Drawing::Color::Black;
			this->messagesInputTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->messagesInputTextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->messagesInputTextBox->ForeColor = System::Drawing::Color::White;
			this->messagesInputTextBox->Location = System::Drawing::Point(441, 128);
			this->messagesInputTextBox->Margin = System::Windows::Forms::Padding(4);
			this->messagesInputTextBox->Multiline = true;
			this->messagesInputTextBox->Name = L"messagesInputTextBox";
			this->messagesInputTextBox->Size = System::Drawing::Size(242, 60);
			this->messagesInputTextBox->TabIndex = 24;
			this->messagesInputTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// roomFeaturesInputTextBox
			// 
			this->roomFeaturesInputTextBox->BackColor = System::Drawing::Color::Black;
			this->roomFeaturesInputTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->roomFeaturesInputTextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->roomFeaturesInputTextBox->ForeColor = System::Drawing::Color::White;
			this->roomFeaturesInputTextBox->Location = System::Drawing::Point(441, 206);
			this->roomFeaturesInputTextBox->Margin = System::Windows::Forms::Padding(4);
			this->roomFeaturesInputTextBox->Multiline = true;
			this->roomFeaturesInputTextBox->Name = L"roomFeaturesInputTextBox";
			this->roomFeaturesInputTextBox->Size = System::Drawing::Size(242, 60);
			this->roomFeaturesInputTextBox->TabIndex = 25;
			this->roomFeaturesInputTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// priceInputTextBox
			// 
			this->priceInputTextBox->BackColor = System::Drawing::Color::Black;
			this->priceInputTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->priceInputTextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->priceInputTextBox->ForeColor = System::Drawing::Color::White;
			this->priceInputTextBox->Location = System::Drawing::Point(441, 298);
			this->priceInputTextBox->Margin = System::Windows::Forms::Padding(4);
			this->priceInputTextBox->Multiline = true;
			this->priceInputTextBox->Name = L"priceInputTextBox";
			this->priceInputTextBox->Size = System::Drawing::Size(242, 13);
			this->priceInputTextBox->TabIndex = 26;
			// 
			// discountInputTextBox
			// 
			this->discountInputTextBox->BackColor = System::Drawing::Color::Black;
			this->discountInputTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->discountInputTextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->discountInputTextBox->ForeColor = System::Drawing::Color::White;
			this->discountInputTextBox->Location = System::Drawing::Point(441, 323);
			this->discountInputTextBox->Margin = System::Windows::Forms::Padding(4);
			this->discountInputTextBox->Multiline = true;
			this->discountInputTextBox->Name = L"discountInputTextBox";
			this->discountInputTextBox->Size = System::Drawing::Size(242, 13);
			this->discountInputTextBox->TabIndex = 27;
			// 
			// taxInputTextBox
			// 
			this->taxInputTextBox->BackColor = System::Drawing::Color::Black;
			this->taxInputTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->taxInputTextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->taxInputTextBox->ForeColor = System::Drawing::Color::White;
			this->taxInputTextBox->Location = System::Drawing::Point(441, 344);
			this->taxInputTextBox->Margin = System::Windows::Forms::Padding(4);
			this->taxInputTextBox->Multiline = true;
			this->taxInputTextBox->Name = L"taxInputTextBox";
			this->taxInputTextBox->Size = System::Drawing::Size(242, 13);
			this->taxInputTextBox->TabIndex = 28;
			// 
			// subtotalInputTextBox
			// 
			this->subtotalInputTextBox->BackColor = System::Drawing::Color::Black;
			this->subtotalInputTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->subtotalInputTextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->subtotalInputTextBox->ForeColor = System::Drawing::Color::White;
			this->subtotalInputTextBox->Location = System::Drawing::Point(441, 365);
			this->subtotalInputTextBox->Margin = System::Windows::Forms::Padding(4);
			this->subtotalInputTextBox->Multiline = true;
			this->subtotalInputTextBox->Name = L"subtotalInputTextBox";
			this->subtotalInputTextBox->Size = System::Drawing::Size(242, 13);
			this->subtotalInputTextBox->TabIndex = 29;
			// 
			// totalNightsInputTextBox
			// 
			this->totalNightsInputTextBox->BackColor = System::Drawing::Color::Black;
			this->totalNightsInputTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->totalNightsInputTextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->totalNightsInputTextBox->ForeColor = System::Drawing::Color::White;
			this->totalNightsInputTextBox->Location = System::Drawing::Point(441, 395);
			this->totalNightsInputTextBox->Margin = System::Windows::Forms::Padding(4);
			this->totalNightsInputTextBox->Multiline = true;
			this->totalNightsInputTextBox->Name = L"totalNightsInputTextBox";
			this->totalNightsInputTextBox->Size = System::Drawing::Size(242, 13);
			this->totalNightsInputTextBox->TabIndex = 30;
			// 
			// grandTotalInputTextBox
			// 
			this->grandTotalInputTextBox->BackColor = System::Drawing::Color::Black;
			this->grandTotalInputTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->grandTotalInputTextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->grandTotalInputTextBox->ForeColor = System::Drawing::Color::White;
			this->grandTotalInputTextBox->Location = System::Drawing::Point(441, 416);
			this->grandTotalInputTextBox->Margin = System::Windows::Forms::Padding(4);
			this->grandTotalInputTextBox->Multiline = true;
			this->grandTotalInputTextBox->Name = L"grandTotalInputTextBox";
			this->grandTotalInputTextBox->Size = System::Drawing::Size(242, 13);
			this->grandTotalInputTextBox->TabIndex = 31;
			// 
			// statusInputTextBox
			// 
			this->statusInputTextBox->BackColor = System::Drawing::Color::Black;
			this->statusInputTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->statusInputTextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->statusInputTextBox->ForeColor = System::Drawing::Color::White;
			this->statusInputTextBox->Location = System::Drawing::Point(441, 465);
			this->statusInputTextBox->Margin = System::Windows::Forms::Padding(4);
			this->statusInputTextBox->Multiline = true;
			this->statusInputTextBox->Name = L"statusInputTextBox";
			this->statusInputTextBox->Size = System::Drawing::Size(242, 13);
			this->statusInputTextBox->TabIndex = 32;
			this->statusInputTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// adultsInputTextBox
			// 
			this->adultsInputTextBox->BackColor = System::Drawing::Color::Black;
			this->adultsInputTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->adultsInputTextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->adultsInputTextBox->ForeColor = System::Drawing::Color::White;
			this->adultsInputTextBox->Location = System::Drawing::Point(127, 369);
			this->adultsInputTextBox->Margin = System::Windows::Forms::Padding(4);
			this->adultsInputTextBox->Multiline = true;
			this->adultsInputTextBox->Name = L"adultsInputTextBox";
			this->adultsInputTextBox->Size = System::Drawing::Size(204, 17);
			this->adultsInputTextBox->TabIndex = 18;
			this->adultsInputTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// childrenInputTextBox
			// 
			this->childrenInputTextBox->BackColor = System::Drawing::Color::Black;
			this->childrenInputTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->childrenInputTextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->childrenInputTextBox->ForeColor = System::Drawing::Color::White;
			this->childrenInputTextBox->Location = System::Drawing::Point(127, 390);
			this->childrenInputTextBox->Margin = System::Windows::Forms::Padding(4);
			this->childrenInputTextBox->Multiline = true;
			this->childrenInputTextBox->Name = L"childrenInputTextBox";
			this->childrenInputTextBox->Size = System::Drawing::Size(204, 17);
			this->childrenInputTextBox->TabIndex = 19;
			this->childrenInputTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Location = System::Drawing::Point(209, 12);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(276, 35);
			this->textBox1->TabIndex = 33;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// searchButton
			// 
			this->searchButton->BackColor = System::Drawing::Color::Transparent;
			this->searchButton->Location = System::Drawing::Point(134, 12);
			this->searchButton->Name = L"searchButton";
			this->searchButton->Size = System::Drawing::Size(81, 35);
			this->searchButton->TabIndex = 34;
			// 
			// arrivalDateCalendar
			// 
			this->arrivalDateCalendar->BackColor = System::Drawing::Color::Transparent;
			this->arrivalDateCalendar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"arrivalDateCalendar.BackgroundImage")));
			this->arrivalDateCalendar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->arrivalDateCalendar->ForeColor = System::Drawing::Color::Transparent;
			this->arrivalDateCalendar->Location = System::Drawing::Point(273, 293);
			this->arrivalDateCalendar->Name = L"arrivalDateCalendar";
			this->arrivalDateCalendar->Size = System::Drawing::Size(58, 23);
			this->arrivalDateCalendar->TabIndex = 35;
			this->arrivalDateCalendar->UseVisualStyleBackColor = false;
			this->arrivalDateCalendar->Click += gcnew System::EventHandler(this, &ReservationMenu::arrivalDateCalendar_Click);
			// 
			// roomTypeComboBox
			// 
			this->roomTypeComboBox->BackColor = System::Drawing::Color::Black;
			this->roomTypeComboBox->ForeColor = System::Drawing::Color::White;
			this->roomTypeComboBox->FormattingEnabled = true;
			this->roomTypeComboBox->Location = System::Drawing::Point(127, 341);
			this->roomTypeComboBox->Name = L"roomTypeComboBox";
			this->roomTypeComboBox->Size = System::Drawing::Size(204, 21);
			this->roomTypeComboBox->TabIndex = 36;
			this->roomTypeComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ReservationMenu::roomTypeComboBox_SelectedIndexChanged);
			// 
			// roomNumberComboBox
			// 
			this->roomNumberComboBox->BackColor = System::Drawing::Color::Black;
			this->roomNumberComboBox->ForeColor = System::Drawing::Color::White;
			this->roomNumberComboBox->FormattingEnabled = true;
			this->roomNumberComboBox->Location = System::Drawing::Point(127, 416);
			this->roomNumberComboBox->Name = L"roomNumberComboBox";
			this->roomNumberComboBox->Size = System::Drawing::Size(204, 21);
			this->roomNumberComboBox->TabIndex = 37;
			// 
			// creditCardComboBox
			// 
			this->creditCardComboBox->BackColor = System::Drawing::Color::Black;
			this->creditCardComboBox->ForeColor = System::Drawing::Color::White;
			this->creditCardComboBox->FormattingEnabled = true;
			this->creditCardComboBox->Location = System::Drawing::Point(127, 461);
			this->creditCardComboBox->Name = L"creditCardComboBox";
			this->creditCardComboBox->Size = System::Drawing::Size(204, 21);
			this->creditCardComboBox->TabIndex = 38;
			// 
			// ReservationMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(717, 579);
			this->Controls->Add(this->creditCardComboBox);
			this->Controls->Add(this->roomNumberComboBox);
			this->Controls->Add(this->roomTypeComboBox);
			this->Controls->Add(this->arrivalDateCalendar);
			this->Controls->Add(this->searchButton);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->childrenInputTextBox);
			this->Controls->Add(this->adultsInputTextBox);
			this->Controls->Add(this->statusInputTextBox);
			this->Controls->Add(this->grandTotalInputTextBox);
			this->Controls->Add(this->totalNightsInputTextBox);
			this->Controls->Add(this->subtotalInputTextBox);
			this->Controls->Add(this->taxInputTextBox);
			this->Controls->Add(this->discountInputTextBox);
			this->Controls->Add(this->priceInputTextBox);
			this->Controls->Add(this->roomFeaturesInputTextBox);
			this->Controls->Add(this->messagesInputTextBox);
			this->Controls->Add(this->expirationInputTextBox);
			this->Controls->Add(this->creditCardNumberInputTextBox);
			this->Controls->Add(this->departureInputTextbox);
			this->Controls->Add(this->arrivalInputTextbox);
			this->Controls->Add(this->zipcodeInputTextbox);
			this->Controls->Add(this->stateInputTextbox);
			this->Controls->Add(this->countryInputTextbox);
			this->Controls->Add(this->phoneInputTextbox);
			this->Controls->Add(this->emailInputTextbox);
			this->Controls->Add(this->cityInputTextbox);
			this->Controls->Add(this->addressInputTextbox);
			this->Controls->Add(this->nameInputTextbox);
			this->Controls->Add(this->exitReservationButton);
			this->Controls->Add(this->saveReservationButton);
			this->Controls->Add(this->deleteReservationButton);
			this->Controls->Add(this->newReservationButton);
			this->Controls->Add(this->logOutButton);
			this->Controls->Add(this->settingsButton);
			this->Controls->Add(this->roomCalendarButton);
			this->ForeColor = System::Drawing::Color::White;
			this->Name = L"ReservationMenu";
			this->Load += gcnew System::EventHandler(this, &ReservationMenu::ReservationMenu_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
private: System::Void ReservationMenu_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void exitReservationButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
			 Application::Exit();
		 }
private: System::Void logOutButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void saveReservationButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 //Creates a GeneralInfo object based on the users given information.
			 GeneralInfo *r1  = new GeneralInfo(marshal_as<std::string>(this->nameInputTextbox->Text->ToString()), 
											   marshal_as<std::string>(this->addressInputTextbox->Text->ToString()),
											   marshal_as<std::string>(this->cityInputTextbox->Text->ToString()),
											   marshal_as<std::string>(this->stateInputTextbox->Text->ToString()),
											   marshal_as<std::string>(this->zipcodeInputTextbox->Text->ToString()),
											   marshal_as<std::string>(this->countryInputTextbox->Text->ToString()),
											   marshal_as<std::string>(this->emailInputTextbox->Text->ToString()),
											   marshal_as<std::string>(this->phoneInputTextbox->Text->ToString()),
											   marshal_as<std::string>(this->adultsInputTextBox->Text->ToString()),
											   marshal_as<std::string>(this->childrenInputTextBox->Text->ToString()));
			 
			 //Creates a RequiredInfo object based on the users given information.
			 string tempDate = marshal_as<std::string>(this->arrivalInputTextbox->Text->ToString());
			 Date *arrDate = new Date(tempDate);
			 tempDate = marshal_as<std::string>(this->departureInputTextbox->Text->ToString());
			 Date *depDate = new Date(tempDate);
			 string aRoomType = marshal_as<std::string>(this->roomTypeComboBox->SelectedItem->ToString());
			 RequiredInfo *r2 = new RequiredInfo(*arrDate, *depDate, aRoomType);

			 //Creates an ExtraFeatures object based on the users given information.
			 ExtraFeatures *exF = new  ExtraFeatures(marshal_as<std::string>(this->messagesInputTextBox->Text->ToString()));

			 //Creates a CreditCard object based on the users given information.
			 CreditCard *credCard = new CreditCard(marshal_as<std::string>(this->nameInputTextbox->Text->ToString()),
												   marshal_as<std::string>(this->addressInputTextbox->Text->ToString()),
												   marshal_as<std::string>(this->cityInputTextbox->Text->ToString()),
												   marshal_as<std::string>(this->stateInputTextbox->Text->ToString()),
												   marshal_as<std::string>(this->zipcodeInputTextbox->Text->ToString()),
												   marshal_as<std::string>(this->creditCardNumberInputTextBox->Text->ToString()),
												   marshal_as<std::string>(this->expirationInputTextBox->Text->ToString()),
												   "test",
												   marshal_as<std::string>(this->creditCardComboBox->Text->ToString()));
			 
			 //Creates a Reservation object based on the users given information.
			 Reservation *aReservation = new Reservation(*r1, *r2, *exF, *credCard);
			 //aReservation->print();
			 theHotel->addReservation(*aReservation);
			 theHotel->printReservationArray();
			 //int locationIndex = theHotel->calculateDateIndex(aReservation->getArrivalDate());
			 //cout << "\nTest\n";
			 //reservationIter iter = theHotel->findReservation(locationIndex, aReservation->getID());
			 //(*iter)->print();
		 }
private: System::Void settingsButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Visible = false;
			 inventoryMenu->ShowDialog();
			 setInventoryMenu(inventoryMenu);
			 this->Visible = true;

		 }
private: System::Void newReservationButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->nameInputTextbox->Clear();
			 this->addressInputTextbox->Clear();
			 this->cityInputTextbox->Clear();
			 this->countryInputTextbox->Clear();
			 this->stateInputTextbox->Clear();
			 this->zipcodeInputTextbox->Clear();
			 this->emailInputTextbox->Clear();
			 this->phoneInputTextbox->Clear();
			 this->arrivalInputTextbox->Clear();
			 this->departureInputTextbox->Clear();
			 this->adultsInputTextBox->Clear();
			 this->childrenInputTextBox->Clear();
			 this->creditCardNumberInputTextBox->Clear();
			 this->expirationInputTextBox->Clear();
			 this->messagesInputTextBox->Clear();
			 this->roomFeaturesInputTextBox->Clear();
			 this->priceInputTextBox->Clear();
			 this->discountInputTextBox->Clear();
			 this->taxInputTextBox->Clear();
			 this->subtotalInputTextBox->Clear();
			 this->totalNightsInputTextBox->Clear();
			 this->grandTotalInputTextBox->Clear();


		 }
private: System::Void deleteReservationButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->nameInputTextbox->Clear();
			 this->addressInputTextbox->Clear();
			 this->cityInputTextbox->Clear();
			 this->countryInputTextbox->Clear();
			 this->stateInputTextbox->Clear();
			 this->zipcodeInputTextbox->Clear();
			 this->emailInputTextbox->Clear();
			 this->phoneInputTextbox->Clear();
			 this->arrivalInputTextbox->Clear();
			 this->departureInputTextbox->Clear();
			 this->adultsInputTextBox->Clear();
			 this->childrenInputTextBox->Clear();
			 this->creditCardNumberInputTextBox->Clear();
			 this->expirationInputTextBox->Clear();
			 this->messagesInputTextBox->Clear();
			 this->roomFeaturesInputTextBox->Clear();
			 this->priceInputTextBox->Clear();
			 this->discountInputTextBox->Clear();
			 this->taxInputTextBox->Clear();
			 this->subtotalInputTextBox->Clear();
			 this->totalNightsInputTextBox->Clear();
			 this->grandTotalInputTextBox->Clear();
		 }
private: System::Void arrivalDateCalendar_Click(System::Object^  sender, System::EventArgs^  e) {
			 dateSelectionCalendar ^calendar = gcnew dateSelectionCalendar;
			 calendar->ShowDialog();
			 arrivalInputTextbox->Text = calendar->Start->Text;
			 departureInputTextbox->Text = calendar->End->Text;
		 }
private: System::Void roomTypeComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void roomCalendarButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
};
}