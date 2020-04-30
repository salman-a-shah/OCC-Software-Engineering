#pragma once
#include "ReservationMenu.h"
#include "InventoryMenu.h"
#include "Hotel.h"
#include <vector>
#include <iostream>
typedef list<Reservation*>::iterator reservationIter;

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for RoomCalendar
	/// </summary>
	public ref class RoomCalendar : public System::Windows::Forms::Form
	{
	public:
		static const int MAXWEEKS = 16;

		RoomCalendar(ReservationMenu^ newReservationMenu, InventoryMenu^ newInventoryMenu, Hotel *newHotel)
		{
			reservationMenu = newReservationMenu;
			inventoryMenu = newInventoryMenu;
			ourHotel = newHotel;
			roomPageNumber = 0;
			datePageNumber = 0;
			InitializeComponent();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RoomCalendar()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  roomNumberLabel1;
	private: System::Windows::Forms::Label^  roomNumberLabel2;
	private: System::Windows::Forms::Label^  roomNumberLabel3;
	private: System::Windows::Forms::Label^  roomNumberLabel4;
	private: System::Windows::Forms::Label^  roomNumberLabel5;
	private: System::Windows::Forms::Label^  currentDateLabel;
	private: System::Windows::Forms::Label^  currentDateLabel1;
	private: System::Windows::Forms::Label^  currentDateLabel2;
	private: System::Windows::Forms::Label^  currentDateLabel3;
	private: System::Windows::Forms::Label^  currentDateLabel4;
	private: System::Windows::Forms::Label^  currentDateLabel5;
	private: System::Windows::Forms::Label^  currentDateLabel6;






	private: System::Windows::Forms::Label^  roomLabelCurrentDate6;

	protected: 

	protected: 












	private: System::Windows::Forms::Label^  roomLabelCurrentDate5;

	private: System::Windows::Forms::Label^  roomLabelCurrentDate4;

	private: System::Windows::Forms::Label^  roomLabelCurrentDate3;

	private: System::Windows::Forms::Label^  roomLabelCurrentDate2;

	private: System::Windows::Forms::Label^  roomLabelCurrentDate1;

	private: System::Windows::Forms::Label^  roomLabelCurrentDate;
	private: System::Windows::Forms::Label^  roomLabel2CurrentDate6;


	private: System::Windows::Forms::Label^  roomLabel2CurrentDate5;

	private: System::Windows::Forms::Label^  roomLabel2CurrentDate4;

	private: System::Windows::Forms::Label^  roomLabel2CurrentDate3;

	private: System::Windows::Forms::Label^  roomLabel2CurrentDate2;

	private: System::Windows::Forms::Label^  roomLabel2CurrentDate1;

	private: System::Windows::Forms::Label^  roomLabel2CurrentDate;
	private: System::Windows::Forms::Label^  roomLabel3CurrentDate6;


	private: System::Windows::Forms::Label^  roomLabel3CurrentDate5;

	private: System::Windows::Forms::Label^  roomLabel3CurrentDate4;

	private: System::Windows::Forms::Label^  roomLabel3CurrentDate3;

	private: System::Windows::Forms::Label^  roomLabel3CurrentDate2;

	private: System::Windows::Forms::Label^  roomLabel3CurrentDate1;

	private: System::Windows::Forms::Label^  roomLabel3CurrentDate;
	private: System::Windows::Forms::Label^  roomLabel4CurrentDate6;


private: System::Windows::Forms::Label^  roomLabel4CurrentDate5;

private: System::Windows::Forms::Label^  roomLabel4CurrentDate4;

private: System::Windows::Forms::Label^  roomLabel4CurrentDate3;

private: System::Windows::Forms::Label^  roomLabel4CurrentDate2;

private: System::Windows::Forms::Label^  roomLabel4CurrentDate1;

private: System::Windows::Forms::Label^  roomLabel4CurrentDate;
private: System::Windows::Forms::Label^  roomLabel5CurrentDate6;


private: System::Windows::Forms::Label^  roomLabel5CurrentDate5;

private: System::Windows::Forms::Label^  roomLabel5CurrentDate4;

private: System::Windows::Forms::Label^  roomLabel5CurrentDate3;

private: System::Windows::Forms::Label^  roomLabel5CurrentDate2;

private: System::Windows::Forms::Label^  roomLabel5CurrentDate1;

private: System::Windows::Forms::Label^  roomLabel5CurrentDate;
private: System::Windows::Forms::Label^  nameLabel;
private: System::Windows::Forms::Label^  arrivalDateLabel;
private: System::Windows::Forms::Label^  departureDateLabel;
private: System::Windows::Forms::Label^  statusLabel;
private: System::Windows::Forms::Label^  roomTypeLabel;
private: System::Windows::Forms::Label^  iDLabel;
private: System::Windows::Forms::Label^  messagesLabel;








	private: System::Windows::Forms::Label^  label55;
private: System::Windows::Forms::Label^  settingsButton;
private: System::Windows::Forms::Label^  logOutButton;


private: System::Windows::Forms::Label^  newButton;

private: System::Windows::Forms::Label^  deleteButton;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		Hotel *ourHotel;
		ReservationMenu^ reservationMenu;
		InventoryMenu^ inventoryMenu;
		List<System::Windows::Forms::Label^> roomNumberList;
private: System::Windows::Forms::Label^  unassignedResButton;
private: System::Windows::Forms::Label^  leftArrowButton;
private: System::Windows::Forms::Label^  rightArrowButton;
private: System::Windows::Forms::Label^  upArrowButton;
private: System::Windows::Forms::Label^  downArrowButton;


		 List<System::Windows::Forms::Label^> dateList;
		 List<System::Windows::Forms::Label^> rowList1;
		 List<System::Windows::Forms::Label^> rowList2;
		 List<System::Windows::Forms::Label^> rowList3;
		 List<System::Windows::Forms::Label^> rowList4;
		 List<System::Windows::Forms::Label^> rowList5;

		 
		 int roomPageNumber;
		 int datePageNumber;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(RoomCalendar::typeid));
			this->roomNumberLabel1 = (gcnew System::Windows::Forms::Label());
			this->roomNumberLabel2 = (gcnew System::Windows::Forms::Label());
			this->roomNumberLabel3 = (gcnew System::Windows::Forms::Label());
			this->roomNumberLabel4 = (gcnew System::Windows::Forms::Label());
			this->roomNumberLabel5 = (gcnew System::Windows::Forms::Label());
			this->currentDateLabel = (gcnew System::Windows::Forms::Label());
			this->currentDateLabel1 = (gcnew System::Windows::Forms::Label());
			this->currentDateLabel2 = (gcnew System::Windows::Forms::Label());
			this->currentDateLabel3 = (gcnew System::Windows::Forms::Label());
			this->currentDateLabel4 = (gcnew System::Windows::Forms::Label());
			this->currentDateLabel5 = (gcnew System::Windows::Forms::Label());
			this->currentDateLabel6 = (gcnew System::Windows::Forms::Label());
			this->roomLabelCurrentDate6 = (gcnew System::Windows::Forms::Label());
			this->roomLabelCurrentDate5 = (gcnew System::Windows::Forms::Label());
			this->roomLabelCurrentDate4 = (gcnew System::Windows::Forms::Label());
			this->roomLabelCurrentDate3 = (gcnew System::Windows::Forms::Label());
			this->roomLabelCurrentDate2 = (gcnew System::Windows::Forms::Label());
			this->roomLabelCurrentDate1 = (gcnew System::Windows::Forms::Label());
			this->roomLabelCurrentDate = (gcnew System::Windows::Forms::Label());
			this->roomLabel2CurrentDate6 = (gcnew System::Windows::Forms::Label());
			this->roomLabel2CurrentDate5 = (gcnew System::Windows::Forms::Label());
			this->roomLabel2CurrentDate4 = (gcnew System::Windows::Forms::Label());
			this->roomLabel2CurrentDate3 = (gcnew System::Windows::Forms::Label());
			this->roomLabel2CurrentDate2 = (gcnew System::Windows::Forms::Label());
			this->roomLabel2CurrentDate1 = (gcnew System::Windows::Forms::Label());
			this->roomLabel2CurrentDate = (gcnew System::Windows::Forms::Label());
			this->roomLabel3CurrentDate6 = (gcnew System::Windows::Forms::Label());
			this->roomLabel3CurrentDate5 = (gcnew System::Windows::Forms::Label());
			this->roomLabel3CurrentDate4 = (gcnew System::Windows::Forms::Label());
			this->roomLabel3CurrentDate3 = (gcnew System::Windows::Forms::Label());
			this->roomLabel3CurrentDate2 = (gcnew System::Windows::Forms::Label());
			this->roomLabel3CurrentDate1 = (gcnew System::Windows::Forms::Label());
			this->roomLabel3CurrentDate = (gcnew System::Windows::Forms::Label());
			this->roomLabel4CurrentDate6 = (gcnew System::Windows::Forms::Label());
			this->roomLabel4CurrentDate5 = (gcnew System::Windows::Forms::Label());
			this->roomLabel4CurrentDate4 = (gcnew System::Windows::Forms::Label());
			this->roomLabel4CurrentDate3 = (gcnew System::Windows::Forms::Label());
			this->roomLabel4CurrentDate2 = (gcnew System::Windows::Forms::Label());
			this->roomLabel4CurrentDate1 = (gcnew System::Windows::Forms::Label());
			this->roomLabel4CurrentDate = (gcnew System::Windows::Forms::Label());
			this->roomLabel5CurrentDate6 = (gcnew System::Windows::Forms::Label());
			this->roomLabel5CurrentDate5 = (gcnew System::Windows::Forms::Label());
			this->roomLabel5CurrentDate4 = (gcnew System::Windows::Forms::Label());
			this->roomLabel5CurrentDate3 = (gcnew System::Windows::Forms::Label());
			this->roomLabel5CurrentDate2 = (gcnew System::Windows::Forms::Label());
			this->roomLabel5CurrentDate1 = (gcnew System::Windows::Forms::Label());
			this->roomLabel5CurrentDate = (gcnew System::Windows::Forms::Label());
			this->nameLabel = (gcnew System::Windows::Forms::Label());
			this->arrivalDateLabel = (gcnew System::Windows::Forms::Label());
			this->departureDateLabel = (gcnew System::Windows::Forms::Label());
			this->statusLabel = (gcnew System::Windows::Forms::Label());
			this->roomTypeLabel = (gcnew System::Windows::Forms::Label());
			this->iDLabel = (gcnew System::Windows::Forms::Label());
			this->messagesLabel = (gcnew System::Windows::Forms::Label());
			this->label55 = (gcnew System::Windows::Forms::Label());
			this->settingsButton = (gcnew System::Windows::Forms::Label());
			this->logOutButton = (gcnew System::Windows::Forms::Label());
			this->newButton = (gcnew System::Windows::Forms::Label());
			this->deleteButton = (gcnew System::Windows::Forms::Label());
			this->unassignedResButton = (gcnew System::Windows::Forms::Label());
			this->leftArrowButton = (gcnew System::Windows::Forms::Label());
			this->rightArrowButton = (gcnew System::Windows::Forms::Label());
			this->upArrowButton = (gcnew System::Windows::Forms::Label());
			this->downArrowButton = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// roomNumberLabel1
			// 
			this->roomNumberLabel1->BackColor = System::Drawing::Color::Transparent;
			this->roomNumberLabel1->ForeColor = System::Drawing::Color::White;
			this->roomNumberLabel1->Location = System::Drawing::Point(31, 136);
			this->roomNumberLabel1->Name = L"roomNumberLabel1";
			this->roomNumberLabel1->Size = System::Drawing::Size(40, 14);
			this->roomNumberLabel1->TabIndex = 0;
			this->roomNumberLabel1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// roomNumberLabel2
			// 
			this->roomNumberLabel2->BackColor = System::Drawing::Color::Transparent;
			this->roomNumberLabel2->ForeColor = System::Drawing::Color::White;
			this->roomNumberLabel2->Location = System::Drawing::Point(31, 208);
			this->roomNumberLabel2->Name = L"roomNumberLabel2";
			this->roomNumberLabel2->Size = System::Drawing::Size(40, 14);
			this->roomNumberLabel2->TabIndex = 1;
			this->roomNumberLabel2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// roomNumberLabel3
			// 
			this->roomNumberLabel3->BackColor = System::Drawing::Color::Transparent;
			this->roomNumberLabel3->ForeColor = System::Drawing::Color::White;
			this->roomNumberLabel3->Location = System::Drawing::Point(31, 280);
			this->roomNumberLabel3->Name = L"roomNumberLabel3";
			this->roomNumberLabel3->Size = System::Drawing::Size(40, 14);
			this->roomNumberLabel3->TabIndex = 2;
			this->roomNumberLabel3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// roomNumberLabel4
			// 
			this->roomNumberLabel4->BackColor = System::Drawing::Color::Transparent;
			this->roomNumberLabel4->ForeColor = System::Drawing::Color::White;
			this->roomNumberLabel4->Location = System::Drawing::Point(31, 352);
			this->roomNumberLabel4->Name = L"roomNumberLabel4";
			this->roomNumberLabel4->Size = System::Drawing::Size(40, 14);
			this->roomNumberLabel4->TabIndex = 3;
			this->roomNumberLabel4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// roomNumberLabel5
			// 
			this->roomNumberLabel5->BackColor = System::Drawing::Color::Transparent;
			this->roomNumberLabel5->ForeColor = System::Drawing::Color::White;
			this->roomNumberLabel5->Location = System::Drawing::Point(31, 424);
			this->roomNumberLabel5->Name = L"roomNumberLabel5";
			this->roomNumberLabel5->Size = System::Drawing::Size(40, 14);
			this->roomNumberLabel5->TabIndex = 4;
			this->roomNumberLabel5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// currentDateLabel
			// 
			this->currentDateLabel->BackColor = System::Drawing::Color::Transparent;
			this->currentDateLabel->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->currentDateLabel->Location = System::Drawing::Point(91, 101);
			this->currentDateLabel->Name = L"currentDateLabel";
			this->currentDateLabel->Size = System::Drawing::Size(80, 22);
			this->currentDateLabel->TabIndex = 5;
			this->currentDateLabel->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// currentDateLabel1
			// 
			this->currentDateLabel1->BackColor = System::Drawing::Color::Transparent;
			this->currentDateLabel1->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->currentDateLabel1->Location = System::Drawing::Point(168, 101);
			this->currentDateLabel1->Name = L"currentDateLabel1";
			this->currentDateLabel1->Size = System::Drawing::Size(81, 22);
			this->currentDateLabel1->TabIndex = 6;
			this->currentDateLabel1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// currentDateLabel2
			// 
			this->currentDateLabel2->BackColor = System::Drawing::Color::Transparent;
			this->currentDateLabel2->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->currentDateLabel2->Location = System::Drawing::Point(248, 101);
			this->currentDateLabel2->Name = L"currentDateLabel2";
			this->currentDateLabel2->Size = System::Drawing::Size(83, 22);
			this->currentDateLabel2->TabIndex = 7;
			this->currentDateLabel2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// currentDateLabel3
			// 
			this->currentDateLabel3->BackColor = System::Drawing::Color::Transparent;
			this->currentDateLabel3->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->currentDateLabel3->Location = System::Drawing::Point(328, 101);
			this->currentDateLabel3->Name = L"currentDateLabel3";
			this->currentDateLabel3->Size = System::Drawing::Size(79, 22);
			this->currentDateLabel3->TabIndex = 8;
			this->currentDateLabel3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// currentDateLabel4
			// 
			this->currentDateLabel4->BackColor = System::Drawing::Color::Transparent;
			this->currentDateLabel4->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->currentDateLabel4->Location = System::Drawing::Point(413, 101);
			this->currentDateLabel4->Name = L"currentDateLabel4";
			this->currentDateLabel4->Size = System::Drawing::Size(78, 22);
			this->currentDateLabel4->TabIndex = 9;
			this->currentDateLabel4->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// currentDateLabel5
			// 
			this->currentDateLabel5->BackColor = System::Drawing::Color::Transparent;
			this->currentDateLabel5->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->currentDateLabel5->Location = System::Drawing::Point(488, 101);
			this->currentDateLabel5->Name = L"currentDateLabel5";
			this->currentDateLabel5->Size = System::Drawing::Size(83, 22);
			this->currentDateLabel5->TabIndex = 10;
			this->currentDateLabel5->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// currentDateLabel6
			// 
			this->currentDateLabel6->BackColor = System::Drawing::Color::Transparent;
			this->currentDateLabel6->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->currentDateLabel6->Location = System::Drawing::Point(568, 101);
			this->currentDateLabel6->Name = L"currentDateLabel6";
			this->currentDateLabel6->Size = System::Drawing::Size(102, 22);
			this->currentDateLabel6->TabIndex = 11;
			this->currentDateLabel6->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// roomLabelCurrentDate6
			// 
			this->roomLabelCurrentDate6->BackColor = System::Drawing::Color::Transparent;
			this->roomLabelCurrentDate6->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabelCurrentDate6->Location = System::Drawing::Point(568, 128);
			this->roomLabelCurrentDate6->Name = L"roomLabelCurrentDate6";
			this->roomLabelCurrentDate6->Size = System::Drawing::Size(102, 31);
			this->roomLabelCurrentDate6->TabIndex = 18;
			this->roomLabelCurrentDate6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabelCurrentDate6->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabelCurrentDate6_Click);
			// 
			// roomLabelCurrentDate5
			// 
			this->roomLabelCurrentDate5->BackColor = System::Drawing::Color::Transparent;
			this->roomLabelCurrentDate5->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabelCurrentDate5->Location = System::Drawing::Point(488, 128);
			this->roomLabelCurrentDate5->Name = L"roomLabelCurrentDate5";
			this->roomLabelCurrentDate5->Size = System::Drawing::Size(83, 31);
			this->roomLabelCurrentDate5->TabIndex = 17;
			this->roomLabelCurrentDate5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabelCurrentDate5->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabelCurrentDate5_Click);
			// 
			// roomLabelCurrentDate4
			// 
			this->roomLabelCurrentDate4->BackColor = System::Drawing::Color::Transparent;
			this->roomLabelCurrentDate4->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabelCurrentDate4->Location = System::Drawing::Point(413, 128);
			this->roomLabelCurrentDate4->Name = L"roomLabelCurrentDate4";
			this->roomLabelCurrentDate4->Size = System::Drawing::Size(78, 31);
			this->roomLabelCurrentDate4->TabIndex = 16;
			this->roomLabelCurrentDate4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabelCurrentDate4->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabelCurrentDate4_Click);
			// 
			// roomLabelCurrentDate3
			// 
			this->roomLabelCurrentDate3->BackColor = System::Drawing::Color::Transparent;
			this->roomLabelCurrentDate3->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabelCurrentDate3->Location = System::Drawing::Point(328, 128);
			this->roomLabelCurrentDate3->Name = L"roomLabelCurrentDate3";
			this->roomLabelCurrentDate3->Size = System::Drawing::Size(79, 31);
			this->roomLabelCurrentDate3->TabIndex = 15;
			this->roomLabelCurrentDate3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabelCurrentDate3->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabelCurrentDate3_Click);
			// 
			// roomLabelCurrentDate2
			// 
			this->roomLabelCurrentDate2->BackColor = System::Drawing::Color::Transparent;
			this->roomLabelCurrentDate2->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabelCurrentDate2->Location = System::Drawing::Point(248, 128);
			this->roomLabelCurrentDate2->Name = L"roomLabelCurrentDate2";
			this->roomLabelCurrentDate2->Size = System::Drawing::Size(83, 31);
			this->roomLabelCurrentDate2->TabIndex = 14;
			this->roomLabelCurrentDate2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabelCurrentDate2->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabelCurrentDate2_Click);
			// 
			// roomLabelCurrentDate1
			// 
			this->roomLabelCurrentDate1->BackColor = System::Drawing::Color::Transparent;
			this->roomLabelCurrentDate1->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabelCurrentDate1->Location = System::Drawing::Point(168, 128);
			this->roomLabelCurrentDate1->Name = L"roomLabelCurrentDate1";
			this->roomLabelCurrentDate1->Size = System::Drawing::Size(81, 31);
			this->roomLabelCurrentDate1->TabIndex = 13;
			this->roomLabelCurrentDate1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabelCurrentDate1->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabelCurrentDate1_Click);
			// 
			// roomLabelCurrentDate
			// 
			this->roomLabelCurrentDate->BackColor = System::Drawing::Color::Transparent;
			this->roomLabelCurrentDate->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabelCurrentDate->Location = System::Drawing::Point(91, 128);
			this->roomLabelCurrentDate->Name = L"roomLabelCurrentDate";
			this->roomLabelCurrentDate->Size = System::Drawing::Size(80, 31);
			this->roomLabelCurrentDate->TabIndex = 12;
			this->roomLabelCurrentDate->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabelCurrentDate->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabelCurrentDate_Click);
			// 
			// roomLabel2CurrentDate6
			// 
			this->roomLabel2CurrentDate6->BackColor = System::Drawing::Color::Transparent;
			this->roomLabel2CurrentDate6->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabel2CurrentDate6->Location = System::Drawing::Point(568, 199);
			this->roomLabel2CurrentDate6->Name = L"roomLabel2CurrentDate6";
			this->roomLabel2CurrentDate6->Size = System::Drawing::Size(102, 31);
			this->roomLabel2CurrentDate6->TabIndex = 25;
			this->roomLabel2CurrentDate6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabel2CurrentDate6->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabel2CurrentDate6_Click);
			// 
			// roomLabel2CurrentDate5
			// 
			this->roomLabel2CurrentDate5->BackColor = System::Drawing::Color::Transparent;
			this->roomLabel2CurrentDate5->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabel2CurrentDate5->Location = System::Drawing::Point(488, 199);
			this->roomLabel2CurrentDate5->Name = L"roomLabel2CurrentDate5";
			this->roomLabel2CurrentDate5->Size = System::Drawing::Size(83, 31);
			this->roomLabel2CurrentDate5->TabIndex = 24;
			this->roomLabel2CurrentDate5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabel2CurrentDate5->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabel2CurrentDate5_Click);
			// 
			// roomLabel2CurrentDate4
			// 
			this->roomLabel2CurrentDate4->BackColor = System::Drawing::Color::Transparent;
			this->roomLabel2CurrentDate4->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabel2CurrentDate4->Location = System::Drawing::Point(413, 199);
			this->roomLabel2CurrentDate4->Name = L"roomLabel2CurrentDate4";
			this->roomLabel2CurrentDate4->Size = System::Drawing::Size(78, 31);
			this->roomLabel2CurrentDate4->TabIndex = 23;
			this->roomLabel2CurrentDate4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabel2CurrentDate4->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabel2CurrentDate4_Click);
			// 
			// roomLabel2CurrentDate3
			// 
			this->roomLabel2CurrentDate3->BackColor = System::Drawing::Color::Transparent;
			this->roomLabel2CurrentDate3->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabel2CurrentDate3->Location = System::Drawing::Point(328, 199);
			this->roomLabel2CurrentDate3->Name = L"roomLabel2CurrentDate3";
			this->roomLabel2CurrentDate3->Size = System::Drawing::Size(79, 31);
			this->roomLabel2CurrentDate3->TabIndex = 22;
			this->roomLabel2CurrentDate3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabel2CurrentDate3->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabel2CurrentDate3_Click);
			// 
			// roomLabel2CurrentDate2
			// 
			this->roomLabel2CurrentDate2->BackColor = System::Drawing::Color::Transparent;
			this->roomLabel2CurrentDate2->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabel2CurrentDate2->Location = System::Drawing::Point(248, 199);
			this->roomLabel2CurrentDate2->Name = L"roomLabel2CurrentDate2";
			this->roomLabel2CurrentDate2->Size = System::Drawing::Size(83, 31);
			this->roomLabel2CurrentDate2->TabIndex = 21;
			this->roomLabel2CurrentDate2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabel2CurrentDate2->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabel2CurrentDate2_Click);
			// 
			// roomLabel2CurrentDate1
			// 
			this->roomLabel2CurrentDate1->BackColor = System::Drawing::Color::Transparent;
			this->roomLabel2CurrentDate1->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabel2CurrentDate1->Location = System::Drawing::Point(168, 199);
			this->roomLabel2CurrentDate1->Name = L"roomLabel2CurrentDate1";
			this->roomLabel2CurrentDate1->Size = System::Drawing::Size(81, 31);
			this->roomLabel2CurrentDate1->TabIndex = 20;
			this->roomLabel2CurrentDate1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabel2CurrentDate1->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabel2CurrentDate1_Click);
			// 
			// roomLabel2CurrentDate
			// 
			this->roomLabel2CurrentDate->BackColor = System::Drawing::Color::Transparent;
			this->roomLabel2CurrentDate->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabel2CurrentDate->Location = System::Drawing::Point(91, 199);
			this->roomLabel2CurrentDate->Name = L"roomLabel2CurrentDate";
			this->roomLabel2CurrentDate->Size = System::Drawing::Size(80, 31);
			this->roomLabel2CurrentDate->TabIndex = 19;
			this->roomLabel2CurrentDate->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabel2CurrentDate->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabel2CurrentDate_Click);
			// 
			// roomLabel3CurrentDate6
			// 
			this->roomLabel3CurrentDate6->BackColor = System::Drawing::Color::Transparent;
			this->roomLabel3CurrentDate6->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabel3CurrentDate6->Location = System::Drawing::Point(568, 271);
			this->roomLabel3CurrentDate6->Name = L"roomLabel3CurrentDate6";
			this->roomLabel3CurrentDate6->Size = System::Drawing::Size(102, 31);
			this->roomLabel3CurrentDate6->TabIndex = 32;
			this->roomLabel3CurrentDate6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabel3CurrentDate6->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabel3CurrentDate6_Click);
			// 
			// roomLabel3CurrentDate5
			// 
			this->roomLabel3CurrentDate5->BackColor = System::Drawing::Color::Transparent;
			this->roomLabel3CurrentDate5->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabel3CurrentDate5->Location = System::Drawing::Point(488, 271);
			this->roomLabel3CurrentDate5->Name = L"roomLabel3CurrentDate5";
			this->roomLabel3CurrentDate5->Size = System::Drawing::Size(83, 31);
			this->roomLabel3CurrentDate5->TabIndex = 31;
			this->roomLabel3CurrentDate5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabel3CurrentDate5->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabel3CurrentDate5_Click);
			// 
			// roomLabel3CurrentDate4
			// 
			this->roomLabel3CurrentDate4->BackColor = System::Drawing::Color::Transparent;
			this->roomLabel3CurrentDate4->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabel3CurrentDate4->Location = System::Drawing::Point(413, 271);
			this->roomLabel3CurrentDate4->Name = L"roomLabel3CurrentDate4";
			this->roomLabel3CurrentDate4->Size = System::Drawing::Size(78, 31);
			this->roomLabel3CurrentDate4->TabIndex = 30;
			this->roomLabel3CurrentDate4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabel3CurrentDate4->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabel3CurrentDate4_Click);
			// 
			// roomLabel3CurrentDate3
			// 
			this->roomLabel3CurrentDate3->BackColor = System::Drawing::Color::Transparent;
			this->roomLabel3CurrentDate3->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabel3CurrentDate3->Location = System::Drawing::Point(328, 271);
			this->roomLabel3CurrentDate3->Name = L"roomLabel3CurrentDate3";
			this->roomLabel3CurrentDate3->Size = System::Drawing::Size(79, 31);
			this->roomLabel3CurrentDate3->TabIndex = 29;
			this->roomLabel3CurrentDate3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabel3CurrentDate3->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabel3CurrentDate3_Click);
			// 
			// roomLabel3CurrentDate2
			// 
			this->roomLabel3CurrentDate2->BackColor = System::Drawing::Color::Transparent;
			this->roomLabel3CurrentDate2->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabel3CurrentDate2->Location = System::Drawing::Point(248, 271);
			this->roomLabel3CurrentDate2->Name = L"roomLabel3CurrentDate2";
			this->roomLabel3CurrentDate2->Size = System::Drawing::Size(83, 31);
			this->roomLabel3CurrentDate2->TabIndex = 28;
			this->roomLabel3CurrentDate2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabel3CurrentDate2->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabel3CurrentDate2_Click);
			// 
			// roomLabel3CurrentDate1
			// 
			this->roomLabel3CurrentDate1->BackColor = System::Drawing::Color::Transparent;
			this->roomLabel3CurrentDate1->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabel3CurrentDate1->Location = System::Drawing::Point(168, 271);
			this->roomLabel3CurrentDate1->Name = L"roomLabel3CurrentDate1";
			this->roomLabel3CurrentDate1->Size = System::Drawing::Size(81, 31);
			this->roomLabel3CurrentDate1->TabIndex = 27;
			this->roomLabel3CurrentDate1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabel3CurrentDate1->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabel3CurrentDate1_Click);
			// 
			// roomLabel3CurrentDate
			// 
			this->roomLabel3CurrentDate->BackColor = System::Drawing::Color::Transparent;
			this->roomLabel3CurrentDate->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabel3CurrentDate->Location = System::Drawing::Point(91, 271);
			this->roomLabel3CurrentDate->Name = L"roomLabel3CurrentDate";
			this->roomLabel3CurrentDate->Size = System::Drawing::Size(80, 31);
			this->roomLabel3CurrentDate->TabIndex = 26;
			this->roomLabel3CurrentDate->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabel3CurrentDate->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabel3CurrentDate_Click);
			// 
			// roomLabel4CurrentDate6
			// 
			this->roomLabel4CurrentDate6->BackColor = System::Drawing::Color::Transparent;
			this->roomLabel4CurrentDate6->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabel4CurrentDate6->Location = System::Drawing::Point(568, 343);
			this->roomLabel4CurrentDate6->Name = L"roomLabel4CurrentDate6";
			this->roomLabel4CurrentDate6->Size = System::Drawing::Size(102, 31);
			this->roomLabel4CurrentDate6->TabIndex = 39;
			this->roomLabel4CurrentDate6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabel4CurrentDate6->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabel4CurrentDate6_Click);
			// 
			// roomLabel4CurrentDate5
			// 
			this->roomLabel4CurrentDate5->BackColor = System::Drawing::Color::Transparent;
			this->roomLabel4CurrentDate5->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabel4CurrentDate5->Location = System::Drawing::Point(488, 343);
			this->roomLabel4CurrentDate5->Name = L"roomLabel4CurrentDate5";
			this->roomLabel4CurrentDate5->Size = System::Drawing::Size(83, 31);
			this->roomLabel4CurrentDate5->TabIndex = 38;
			this->roomLabel4CurrentDate5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabel4CurrentDate5->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabel4CurrentDate5_Click);
			// 
			// roomLabel4CurrentDate4
			// 
			this->roomLabel4CurrentDate4->BackColor = System::Drawing::Color::Transparent;
			this->roomLabel4CurrentDate4->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabel4CurrentDate4->Location = System::Drawing::Point(413, 343);
			this->roomLabel4CurrentDate4->Name = L"roomLabel4CurrentDate4";
			this->roomLabel4CurrentDate4->Size = System::Drawing::Size(78, 31);
			this->roomLabel4CurrentDate4->TabIndex = 37;
			this->roomLabel4CurrentDate4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabel4CurrentDate4->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabel4CurrentDate4_Click);
			// 
			// roomLabel4CurrentDate3
			// 
			this->roomLabel4CurrentDate3->BackColor = System::Drawing::Color::Transparent;
			this->roomLabel4CurrentDate3->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabel4CurrentDate3->Location = System::Drawing::Point(328, 343);
			this->roomLabel4CurrentDate3->Name = L"roomLabel4CurrentDate3";
			this->roomLabel4CurrentDate3->Size = System::Drawing::Size(79, 31);
			this->roomLabel4CurrentDate3->TabIndex = 36;
			this->roomLabel4CurrentDate3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabel4CurrentDate3->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabel4CurrentDate3_Click);
			// 
			// roomLabel4CurrentDate2
			// 
			this->roomLabel4CurrentDate2->BackColor = System::Drawing::Color::Transparent;
			this->roomLabel4CurrentDate2->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabel4CurrentDate2->Location = System::Drawing::Point(248, 343);
			this->roomLabel4CurrentDate2->Name = L"roomLabel4CurrentDate2";
			this->roomLabel4CurrentDate2->Size = System::Drawing::Size(83, 31);
			this->roomLabel4CurrentDate2->TabIndex = 35;
			this->roomLabel4CurrentDate2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabel4CurrentDate2->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabel4CurrentDate2_Click);
			// 
			// roomLabel4CurrentDate1
			// 
			this->roomLabel4CurrentDate1->BackColor = System::Drawing::Color::Transparent;
			this->roomLabel4CurrentDate1->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabel4CurrentDate1->Location = System::Drawing::Point(168, 343);
			this->roomLabel4CurrentDate1->Name = L"roomLabel4CurrentDate1";
			this->roomLabel4CurrentDate1->Size = System::Drawing::Size(81, 31);
			this->roomLabel4CurrentDate1->TabIndex = 34;
			this->roomLabel4CurrentDate1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabel4CurrentDate1->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabel4CurrentDate1_Click);
			// 
			// roomLabel4CurrentDate
			// 
			this->roomLabel4CurrentDate->BackColor = System::Drawing::Color::Transparent;
			this->roomLabel4CurrentDate->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabel4CurrentDate->Location = System::Drawing::Point(91, 343);
			this->roomLabel4CurrentDate->Name = L"roomLabel4CurrentDate";
			this->roomLabel4CurrentDate->Size = System::Drawing::Size(80, 31);
			this->roomLabel4CurrentDate->TabIndex = 33;
			this->roomLabel4CurrentDate->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabel4CurrentDate->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabel4CurrentDate_Click);
			// 
			// roomLabel5CurrentDate6
			// 
			this->roomLabel5CurrentDate6->BackColor = System::Drawing::Color::Transparent;
			this->roomLabel5CurrentDate6->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabel5CurrentDate6->Location = System::Drawing::Point(568, 415);
			this->roomLabel5CurrentDate6->Name = L"roomLabel5CurrentDate6";
			this->roomLabel5CurrentDate6->Size = System::Drawing::Size(102, 31);
			this->roomLabel5CurrentDate6->TabIndex = 46;
			this->roomLabel5CurrentDate6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabel5CurrentDate6->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabel5CurrentDate6_Click);
			// 
			// roomLabel5CurrentDate5
			// 
			this->roomLabel5CurrentDate5->BackColor = System::Drawing::Color::Transparent;
			this->roomLabel5CurrentDate5->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabel5CurrentDate5->Location = System::Drawing::Point(488, 415);
			this->roomLabel5CurrentDate5->Name = L"roomLabel5CurrentDate5";
			this->roomLabel5CurrentDate5->Size = System::Drawing::Size(83, 31);
			this->roomLabel5CurrentDate5->TabIndex = 45;
			this->roomLabel5CurrentDate5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabel5CurrentDate5->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabel5CurrentDate5_Click);
			// 
			// roomLabel5CurrentDate4
			// 
			this->roomLabel5CurrentDate4->BackColor = System::Drawing::Color::Transparent;
			this->roomLabel5CurrentDate4->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabel5CurrentDate4->Location = System::Drawing::Point(413, 415);
			this->roomLabel5CurrentDate4->Name = L"roomLabel5CurrentDate4";
			this->roomLabel5CurrentDate4->Size = System::Drawing::Size(78, 31);
			this->roomLabel5CurrentDate4->TabIndex = 44;
			this->roomLabel5CurrentDate4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabel5CurrentDate4->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabel5CurrentDate4_Click);
			// 
			// roomLabel5CurrentDate3
			// 
			this->roomLabel5CurrentDate3->BackColor = System::Drawing::Color::Transparent;
			this->roomLabel5CurrentDate3->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabel5CurrentDate3->Location = System::Drawing::Point(328, 415);
			this->roomLabel5CurrentDate3->Name = L"roomLabel5CurrentDate3";
			this->roomLabel5CurrentDate3->Size = System::Drawing::Size(79, 31);
			this->roomLabel5CurrentDate3->TabIndex = 43;
			this->roomLabel5CurrentDate3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabel5CurrentDate3->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabel5CurrentDate3_Click);
			// 
			// roomLabel5CurrentDate2
			// 
			this->roomLabel5CurrentDate2->BackColor = System::Drawing::Color::Transparent;
			this->roomLabel5CurrentDate2->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabel5CurrentDate2->Location = System::Drawing::Point(248, 415);
			this->roomLabel5CurrentDate2->Name = L"roomLabel5CurrentDate2";
			this->roomLabel5CurrentDate2->Size = System::Drawing::Size(83, 31);
			this->roomLabel5CurrentDate2->TabIndex = 42;
			this->roomLabel5CurrentDate2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabel5CurrentDate2->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabel5CurrentDate2_Click);
			// 
			// roomLabel5CurrentDate1
			// 
			this->roomLabel5CurrentDate1->BackColor = System::Drawing::Color::Transparent;
			this->roomLabel5CurrentDate1->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabel5CurrentDate1->Location = System::Drawing::Point(168, 415);
			this->roomLabel5CurrentDate1->Name = L"roomLabel5CurrentDate1";
			this->roomLabel5CurrentDate1->Size = System::Drawing::Size(81, 31);
			this->roomLabel5CurrentDate1->TabIndex = 41;
			this->roomLabel5CurrentDate1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabel5CurrentDate1->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabel5CurrentDate1_Click);
			// 
			// roomLabel5CurrentDate
			// 
			this->roomLabel5CurrentDate->BackColor = System::Drawing::Color::Transparent;
			this->roomLabel5CurrentDate->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->roomLabel5CurrentDate->Location = System::Drawing::Point(91, 415);
			this->roomLabel5CurrentDate->Name = L"roomLabel5CurrentDate";
			this->roomLabel5CurrentDate->Size = System::Drawing::Size(80, 31);
			this->roomLabel5CurrentDate->TabIndex = 40;
			this->roomLabel5CurrentDate->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->roomLabel5CurrentDate->Click += gcnew System::EventHandler(this, &RoomCalendar::roomLabel5CurrentDate_Click);
			// 
			// nameLabel
			// 
			this->nameLabel->BackColor = System::Drawing::Color::Transparent;
			this->nameLabel->ForeColor = System::Drawing::Color::White;
			this->nameLabel->Location = System::Drawing::Point(107, 508);
			this->nameLabel->Name = L"nameLabel";
			this->nameLabel->Size = System::Drawing::Size(113, 18);
			this->nameLabel->TabIndex = 47;
			// 
			// arrivalDateLabel
			// 
			this->arrivalDateLabel->BackColor = System::Drawing::Color::Transparent;
			this->arrivalDateLabel->ForeColor = System::Drawing::Color::White;
			this->arrivalDateLabel->Location = System::Drawing::Point(131, 526);
			this->arrivalDateLabel->Name = L"arrivalDateLabel";
			this->arrivalDateLabel->Size = System::Drawing::Size(89, 14);
			this->arrivalDateLabel->TabIndex = 48;
			// 
			// departureDateLabel
			// 
			this->departureDateLabel->BackColor = System::Drawing::Color::Transparent;
			this->departureDateLabel->ForeColor = System::Drawing::Color::White;
			this->departureDateLabel->Location = System::Drawing::Point(148, 546);
			this->departureDateLabel->Name = L"departureDateLabel";
			this->departureDateLabel->Size = System::Drawing::Size(72, 14);
			this->departureDateLabel->TabIndex = 49;
			// 
			// statusLabel
			// 
			this->statusLabel->BackColor = System::Drawing::Color::Transparent;
			this->statusLabel->ForeColor = System::Drawing::Color::White;
			this->statusLabel->Location = System::Drawing::Point(279, 508);
			this->statusLabel->Name = L"statusLabel";
			this->statusLabel->Size = System::Drawing::Size(66, 14);
			this->statusLabel->TabIndex = 50;
			// 
			// roomTypeLabel
			// 
			this->roomTypeLabel->BackColor = System::Drawing::Color::Transparent;
			this->roomTypeLabel->ForeColor = System::Drawing::Color::White;
			this->roomTypeLabel->Location = System::Drawing::Point(305, 526);
			this->roomTypeLabel->Name = L"roomTypeLabel";
			this->roomTypeLabel->Size = System::Drawing::Size(67, 14);
			this->roomTypeLabel->TabIndex = 51;
			// 
			// iDLabel
			// 
			this->iDLabel->BackColor = System::Drawing::Color::Transparent;
			this->iDLabel->ForeColor = System::Drawing::Color::White;
			this->iDLabel->Location = System::Drawing::Point(259, 546);
			this->iDLabel->Name = L"iDLabel";
			this->iDLabel->Size = System::Drawing::Size(125, 14);
			this->iDLabel->TabIndex = 52;
			// 
			// messagesLabel
			// 
			this->messagesLabel->BackColor = System::Drawing::Color::Transparent;
			this->messagesLabel->ForeColor = System::Drawing::Color::White;
			this->messagesLabel->Location = System::Drawing::Point(428, 508);
			this->messagesLabel->Name = L"messagesLabel";
			this->messagesLabel->Size = System::Drawing::Size(152, 63);
			this->messagesLabel->TabIndex = 53;
			// 
			// label55
			// 
			this->label55->BackColor = System::Drawing::Color::Transparent;
			this->label55->Location = System::Drawing::Point(23, 13);
			this->label55->Name = L"label55";
			this->label55->Size = System::Drawing::Size(108, 34);
			this->label55->TabIndex = 54;
			// 
			// settingsButton
			// 
			this->settingsButton->BackColor = System::Drawing::Color::Transparent;
			this->settingsButton->Location = System::Drawing::Point(488, 13);
			this->settingsButton->Name = L"settingsButton";
			this->settingsButton->Size = System::Drawing::Size(108, 34);
			this->settingsButton->TabIndex = 55;
			this->settingsButton->Click += gcnew System::EventHandler(this, &RoomCalendar::settingsButton_Click);
			// 
			// logOutButton
			// 
			this->logOutButton->BackColor = System::Drawing::Color::Transparent;
			this->logOutButton->Location = System::Drawing::Point(593, 13);
			this->logOutButton->Name = L"logOutButton";
			this->logOutButton->Size = System::Drawing::Size(108, 34);
			this->logOutButton->TabIndex = 56;
			this->logOutButton->Click += gcnew System::EventHandler(this, &RoomCalendar::logOutButton_Click);
			// 
			// newButton
			// 
			this->newButton->BackColor = System::Drawing::Color::Transparent;
			this->newButton->Location = System::Drawing::Point(12, 58);
			this->newButton->Name = L"newButton";
			this->newButton->Size = System::Drawing::Size(87, 23);
			this->newButton->TabIndex = 57;
			this->newButton->Click += gcnew System::EventHandler(this, &RoomCalendar::newButton_Click);
			// 
			// deleteButton
			// 
			this->deleteButton->BackColor = System::Drawing::Color::Transparent;
			this->deleteButton->Location = System::Drawing::Point(107, 58);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(87, 23);
			this->deleteButton->TabIndex = 58;
			// 
			// unassignedResButton
			// 
			this->unassignedResButton->BackColor = System::Drawing::Color::Transparent;
			this->unassignedResButton->ForeColor = System::Drawing::Color::Transparent;
			this->unassignedResButton->Location = System::Drawing::Point(548, 58);
			this->unassignedResButton->Name = L"unassignedResButton";
			this->unassignedResButton->Size = System::Drawing::Size(153, 23);
			this->unassignedResButton->TabIndex = 59;
			// 
			// leftArrowButton
			// 
			this->leftArrowButton->BackColor = System::Drawing::Color::Transparent;
			this->leftArrowButton->Location = System::Drawing::Point(56, 91);
			this->leftArrowButton->Name = L"leftArrowButton";
			this->leftArrowButton->Size = System::Drawing::Size(29, 33);
			this->leftArrowButton->TabIndex = 60;
			this->leftArrowButton->Click += gcnew System::EventHandler(this, &RoomCalendar::leftArrowButton_Click);
			// 
			// rightArrowButton
			// 
			this->rightArrowButton->BackColor = System::Drawing::Color::Transparent;
			this->rightArrowButton->Location = System::Drawing::Point(672, 91);
			this->rightArrowButton->Name = L"rightArrowButton";
			this->rightArrowButton->Size = System::Drawing::Size(29, 33);
			this->rightArrowButton->TabIndex = 61;
			this->rightArrowButton->Click += gcnew System::EventHandler(this, &RoomCalendar::rightArrowButton_Click);
			// 
			// upArrowButton
			// 
			this->upArrowButton->BackColor = System::Drawing::Color::Transparent;
			this->upArrowButton->Location = System::Drawing::Point(683, 128);
			this->upArrowButton->Name = L"upArrowButton";
			this->upArrowButton->Size = System::Drawing::Size(29, 33);
			this->upArrowButton->TabIndex = 62;
			this->upArrowButton->Click += gcnew System::EventHandler(this, &RoomCalendar::upArrowButton_Click);
			// 
			// downArrowButton
			// 
			this->downArrowButton->BackColor = System::Drawing::Color::Transparent;
			this->downArrowButton->Location = System::Drawing::Point(683, 413);
			this->downArrowButton->Name = L"downArrowButton";
			this->downArrowButton->Size = System::Drawing::Size(29, 33);
			this->downArrowButton->TabIndex = 63;
			this->downArrowButton->Click += gcnew System::EventHandler(this, &RoomCalendar::downArrowButton_Click);
			// 
			// RoomCalendar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(724, 580);
			this->Controls->Add(this->downArrowButton);
			this->Controls->Add(this->upArrowButton);
			this->Controls->Add(this->rightArrowButton);
			this->Controls->Add(this->leftArrowButton);
			this->Controls->Add(this->unassignedResButton);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->newButton);
			this->Controls->Add(this->logOutButton);
			this->Controls->Add(this->settingsButton);
			this->Controls->Add(this->label55);
			this->Controls->Add(this->messagesLabel);
			this->Controls->Add(this->iDLabel);
			this->Controls->Add(this->roomTypeLabel);
			this->Controls->Add(this->statusLabel);
			this->Controls->Add(this->departureDateLabel);
			this->Controls->Add(this->arrivalDateLabel);
			this->Controls->Add(this->nameLabel);
			this->Controls->Add(this->roomLabel5CurrentDate6);
			this->Controls->Add(this->roomLabel5CurrentDate5);
			this->Controls->Add(this->roomLabel5CurrentDate4);
			this->Controls->Add(this->roomLabel5CurrentDate3);
			this->Controls->Add(this->roomLabel5CurrentDate2);
			this->Controls->Add(this->roomLabel5CurrentDate1);
			this->Controls->Add(this->roomLabel5CurrentDate);
			this->Controls->Add(this->roomLabel4CurrentDate6);
			this->Controls->Add(this->roomLabel4CurrentDate5);
			this->Controls->Add(this->roomLabel4CurrentDate4);
			this->Controls->Add(this->roomLabel4CurrentDate3);
			this->Controls->Add(this->roomLabel4CurrentDate2);
			this->Controls->Add(this->roomLabel4CurrentDate1);
			this->Controls->Add(this->roomLabel4CurrentDate);
			this->Controls->Add(this->roomLabel3CurrentDate6);
			this->Controls->Add(this->roomLabel3CurrentDate5);
			this->Controls->Add(this->roomLabel3CurrentDate4);
			this->Controls->Add(this->roomLabel3CurrentDate3);
			this->Controls->Add(this->roomLabel3CurrentDate2);
			this->Controls->Add(this->roomLabel3CurrentDate1);
			this->Controls->Add(this->roomLabel3CurrentDate);
			this->Controls->Add(this->roomLabel2CurrentDate6);
			this->Controls->Add(this->roomLabel2CurrentDate5);
			this->Controls->Add(this->roomLabel2CurrentDate4);
			this->Controls->Add(this->roomLabel2CurrentDate3);
			this->Controls->Add(this->roomLabel2CurrentDate2);
			this->Controls->Add(this->roomLabel2CurrentDate1);
			this->Controls->Add(this->roomLabel2CurrentDate);
			this->Controls->Add(this->roomLabelCurrentDate6);
			this->Controls->Add(this->roomLabelCurrentDate5);
			this->Controls->Add(this->roomLabelCurrentDate4);
			this->Controls->Add(this->roomLabelCurrentDate3);
			this->Controls->Add(this->roomLabelCurrentDate2);
			this->Controls->Add(this->roomLabelCurrentDate1);
			this->Controls->Add(this->roomLabelCurrentDate);
			this->Controls->Add(this->currentDateLabel6);
			this->Controls->Add(this->currentDateLabel5);
			this->Controls->Add(this->currentDateLabel4);
			this->Controls->Add(this->currentDateLabel3);
			this->Controls->Add(this->currentDateLabel2);
			this->Controls->Add(this->currentDateLabel1);
			this->Controls->Add(this->currentDateLabel);
			this->Controls->Add(this->roomNumberLabel5);
			this->Controls->Add(this->roomNumberLabel4);
			this->Controls->Add(this->roomNumberLabel3);
			this->Controls->Add(this->roomNumberLabel2);
			this->Controls->Add(this->roomNumberLabel1);
			this->Name = L"RoomCalendar";
			this->Text = L"RoomCalendar";
			this->Load += gcnew System::EventHandler(this, &RoomCalendar::RoomCalendar_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void RoomCalendar_Load(System::Object^  sender, System::EventArgs^  e) {
				 populateLists();
				 reloadBoarders(0,0);

				 
			 }
			 Void populateLists()
			 {
				 roomNumberList.Add(roomNumberLabel1);
				 roomNumberList.Add(roomNumberLabel2);
				 roomNumberList.Add(roomNumberLabel3);
				 roomNumberList.Add(roomNumberLabel4);
				 roomNumberList.Add(roomNumberLabel5);

				 dateList.Add(currentDateLabel);
				 dateList.Add(currentDateLabel1);
				 dateList.Add(currentDateLabel2);
				 dateList.Add(currentDateLabel3);
				 dateList.Add(currentDateLabel4);
				 dateList.Add(currentDateLabel5);
				 dateList.Add(currentDateLabel6);

				 rowList1.Add(roomLabelCurrentDate);
				 rowList1.Add(roomLabelCurrentDate1);
				 rowList1.Add(roomLabelCurrentDate2);
				 rowList1.Add(roomLabelCurrentDate3);
				 rowList1.Add(roomLabelCurrentDate4);
				 rowList1.Add(roomLabelCurrentDate5);
				 rowList1.Add(roomLabelCurrentDate6);

				 rowList2.Add(roomLabel2CurrentDate);
				 rowList2.Add(roomLabel2CurrentDate1);
				 rowList2.Add(roomLabel2CurrentDate2);
				 rowList2.Add(roomLabel2CurrentDate3);
				 rowList2.Add(roomLabel2CurrentDate4);
				 rowList2.Add(roomLabel2CurrentDate5);
				 rowList2.Add(roomLabel2CurrentDate6);

				 rowList3.Add(roomLabel3CurrentDate);
				 rowList3.Add(roomLabel3CurrentDate1);
				 rowList3.Add(roomLabel3CurrentDate2);
				 rowList3.Add(roomLabel3CurrentDate3);
				 rowList3.Add(roomLabel3CurrentDate4);
				 rowList3.Add(roomLabel3CurrentDate5);
				 rowList3.Add(roomLabel3CurrentDate6);

				 rowList4.Add(roomLabel4CurrentDate);
				 rowList4.Add(roomLabel4CurrentDate1);
				 rowList4.Add(roomLabel4CurrentDate2);
				 rowList4.Add(roomLabel4CurrentDate3);
				 rowList4.Add(roomLabel4CurrentDate4);
				 rowList4.Add(roomLabel4CurrentDate5);
				 rowList4.Add(roomLabel4CurrentDate6);

				 rowList5.Add(roomLabel5CurrentDate);
				 rowList5.Add(roomLabel5CurrentDate1);
				 rowList5.Add(roomLabel5CurrentDate2);
				 rowList5.Add(roomLabel5CurrentDate3);
				 rowList5.Add(roomLabel5CurrentDate4);
				 rowList5.Add(roomLabel5CurrentDate5);
				 rowList5.Add(roomLabel5CurrentDate6);



			 }

			 Void reloadBoarders(int newRoomPageNumber, int newDatePageNumber)
			 {
				 roomPageNumber = newRoomPageNumber;
				 datePageNumber = newDatePageNumber;

				 clearGrid();

				 if(roomPageNumber >= 0 && (roomPageNumber <= ((inventoryMenu->getRoomNumberComboBox()->Items->Count / roomNumberList.Count)+1)))
				 {
					for(int i = 0; i < roomNumberList.Count; i++)
					{
						if((roomPageNumber * roomNumberList.Count) + i < inventoryMenu->getRoomNumberComboBox()->Items->Count)
						{
							roomNumberList[i]->Text = inventoryMenu->getRoomNumberComboBox()->Items[(roomPageNumber * roomNumberList.Count) + i]->ToString();
						}
						else
						{
							roomNumberList[i]->Text = "";
						}
					}
					 
				 }
				 
				 if(datePageNumber >= 0 && (datePageNumber <= MAXWEEKS) )
				 {
					for(int i = 0; i < dateList.Count; i++)
					{
						dateList[i]->Text = gcnew String((ourHotel->getCurrentDate() + ((datePageNumber * dateList.Count)  + i)).dateToString().c_str());
					}
					 
				 }
				 
				 for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 for(int j = 0; j < dateList.Count; j++)
						 {
							 //if((*iter)->getRequiredInfo().getArrivalDate().dateToString() == (ourHotel->getCurrentDate() + ((datePageNumber * dateList.Count)  + j)).dateToString())
							 if(((*iter)->getRequiredInfo().getArrivalDate() <= (ourHotel->getCurrentDate() + ((datePageNumber * dateList.Count)  + j)))
								 && (ourHotel->getCurrentDate() + ((datePageNumber * dateList.Count)  + j)) <= (*iter)->getRequiredInfo().getDepartureDate())
							 {
								 for(int k = 0; k < roomNumberList.Count; k++)
								 {
									 if((*iter)->getRoomNumber().ToString() == roomNumberList[k]->Text->ToString())
									 {

										 if(k == 0)
										 {
											 rowList1[j]->Enabled = true;
											 rowList1[j]->Text = gcnew String((*iter)->getGeneralInfo().getName().c_str());
											 rowList1[j]->BackColor = System::Drawing::Color::Brown;
										 }
										 if(k == 1)
										 {
											 rowList2[j]->Enabled = true;
											 rowList2[j]->Text = gcnew String((*iter)->getGeneralInfo().getName().c_str());
											 rowList2[j]->BackColor = System::Drawing::Color::BlueViolet;
										 }
										 if(k == 2)
										 {
											 rowList3[j]->Enabled = true;
											 rowList3[j]->Text = gcnew String((*iter)->getGeneralInfo().getName().c_str());
											 rowList3[j]->BackColor = System::Drawing::Color::Maroon;
										 }
										 if(k == 3)
										 {
											 rowList4[j]->Enabled = true;
											 rowList4[j]->Text = gcnew String((*iter)->getGeneralInfo().getName().c_str());
											 rowList4[j]->BackColor = System::Drawing::Color::PaleGreen;
										 }
										 if(k == 4)
										 {
											 rowList5[j]->Enabled = true;
											 rowList5[j]->Text = gcnew String((*iter)->getGeneralInfo().getName().c_str());
											 rowList5[j]->BackColor = System::Drawing::Color::DodgerBlue;

										 }
									 }
							 }
						 }
					 }
				 }
			 }
			 }


private: System::Void logOutButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void rightArrowButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 datePageNumber++;
			 if(datePageNumber > 16)
			 { 
				 datePageNumber--;
			 }
			 reloadBoarders(roomPageNumber, datePageNumber);

		 }
private: System::Void leftArrowButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 datePageNumber--;
			 if(datePageNumber < 0)
			 {
				 datePageNumber = 0;
			 }
			 reloadBoarders(roomPageNumber, datePageNumber);
		 }
private: System::Void downArrowButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 roomPageNumber++;
			 if(roomPageNumber >= ((inventoryMenu->getRoomNumberComboBox()->Items->Count / roomNumberList.Count)+1))
			 {
				 roomPageNumber--;
			 }
			 reloadBoarders(roomPageNumber, datePageNumber);
		 }
private: System::Void upArrowButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 roomPageNumber--;
			 if(roomPageNumber < 0)
			 {
				 roomPageNumber = 0;
			 }
			 reloadBoarders(roomPageNumber, datePageNumber);
		 }
private: System::Void settingsButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			 inventoryMenu->ShowDialog();
			 this->Visible = true;
		 }
private: System::Void newButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			 reservationMenu->ShowDialog();
			 this->Visible = true;
		 }

		 Void clearGrid()
		 {
			 for(int i = 0; i < dateList.Count; i++)
			 {
				 rowList1[i]->Text = "";
				 rowList2[i]->Text = "";
				 rowList3[i]->Text = "";
				 rowList4[i]->Text = "";
				 rowList5[i]->Text = "";

				 rowList1[i]->BackColor = System::Drawing::Color::Transparent;
				 rowList2[i]->BackColor = System::Drawing::Color::Transparent;
				 rowList3[i]->BackColor = System::Drawing::Color::Transparent;
				 rowList4[i]->BackColor = System::Drawing::Color::Transparent;
				 rowList5[i]->BackColor = System::Drawing::Color::Transparent;

				 rowList1[i]->Enabled = false;
				 rowList2[i]->Enabled = false;
				 rowList3[i]->Enabled = false;
				 rowList4[i]->Enabled = false;
				 rowList5[i]->Enabled = false;
			 }
		 }

private: System::Void roomLabel5CurrentDate6_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList5[6]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabel5CurrentDate5_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList5[5]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
		 }
private: System::Void roomLabel5CurrentDate4_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList5[4]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
		 }
private: System::Void roomLabel5CurrentDate3_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList5[3]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
		 }
private: System::Void roomLabel5CurrentDate2_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList5[2]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
		 }
private: System::Void roomLabel5CurrentDate1_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList5[1]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
		 }
private: System::Void roomLabel5CurrentDate_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList5[0]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabel4CurrentDate6_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList4[6]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabel4CurrentDate5_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList4[6]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabel4CurrentDate4_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList4[6]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabel4CurrentDate3_Click(System::Object^  sender, System::EventArgs^  e) {
			this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList4[6]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabel4CurrentDate2_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList4[6]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabel4CurrentDate1_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList4[6]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabel4CurrentDate_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList4[6]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabel3CurrentDate6_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList3[6]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabel3CurrentDate5_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList3[5]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabel3CurrentDate4_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList3[4]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabel3CurrentDate3_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList3[3]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabel3CurrentDate2_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList3[2]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabel3CurrentDate1_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList3[1]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabel3CurrentDate_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList3[0]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabel2CurrentDate6_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList2[6]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabel2CurrentDate5_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList2[5]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabel2CurrentDate4_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList2[4]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabel2CurrentDate3_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList2[3]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabel2CurrentDate2_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList2[2]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabel2CurrentDate1_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList2[1]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabel2CurrentDate_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList2[0]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabelCurrentDate6_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList1[6]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabelCurrentDate5_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList1[5]->Text->ToString()))
						 {
							 reservationMenu->ShowDialog();
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabelCurrentDate4_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList1[4]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabelCurrentDate3_Click(System::Object^  sender, System::EventArgs^  e) {
			this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList1[3]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabelCurrentDate2_Click(System::Object^  sender, System::EventArgs^  e) {
			this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList1[2]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabelCurrentDate1_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList1[1]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }
private: System::Void roomLabelCurrentDate_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			  for (int i = 0; i < CAPACITY; i++)	
				 {
					 reservationIter iter;
					 for (iter = ourHotel->calendarArray[i].begin(); iter != ourHotel->calendarArray[i].end(); iter++) 
					 {	
						 if((*iter)->getGeneralInfo().getName() == marshal_as<std::string>(rowList1[0]->Text->ToString()))
						 {
							 reservationMenu->setWindow(*iter);
						 }
					 }
			  }
			 reservationMenu->ShowDialog();
			 this->Show();
		 }


};
}
