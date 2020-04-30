#pragma once
#include <msclr\marshal_cppstd.h>

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for dateSelectionCalendar
	/// </summary>
	public ref class dateSelectionCalendar : public System::Windows::Forms::Form
	{
	public:
	    System::Windows::Forms::Label^  End;
        System::Windows::Forms::Label^  Start;
	

		dateSelectionCalendar(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			numberOfDays = -1;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~dateSelectionCalendar()
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
		System::Windows::Forms::Label^  label1;
		System::Windows::Forms::Label^  label2;
		System::Windows::Forms::Button^  okButton;
		System::Windows::Forms::Button^  cancelButton;
		System::Windows::Forms::MonthCalendar^  monthCal;
		int numberOfDays;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->End = (gcnew System::Windows::Forms::Label());
			this->Start = (gcnew System::Windows::Forms::Label());
			this->monthCal = (gcnew System::Windows::Forms::MonthCalendar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// End
			// 
			this->End->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->End->Location = System::Drawing::Point(289, 324);
			this->End->Name = L"End";
			this->End->Size = System::Drawing::Size(83, 20);
			this->End->TabIndex = 5;
			// 
			// Start
			// 
			this->Start->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Start->Location = System::Drawing::Point(96, 324);
			this->Start->Name = L"Start";
			this->Start->Size = System::Drawing::Size(83, 20);
			this->Start->TabIndex = 4;
			// 
			// monthCal
			// 
			this->monthCal->AnnuallyBoldedDates = gcnew cli::array< System::DateTime >(1) {System::DateTime(2007, 7, 4, 0, 0, 0, 0)};
			this->monthCal->CalendarDimensions = System::Drawing::Size(2, 2);
			this->monthCal->Location = System::Drawing::Point(1, 1);
			this->monthCal->MaxSelectionCount = 365;
			this->monthCal->MonthlyBoldedDates = gcnew cli::array< System::DateTime >(2) {System::DateTime(2007, 10, 1, 0, 0, 0, 0), System::DateTime(2007, 
				10, 15, 0, 0, 0, 0)};
			this->monthCal->Name = L"monthCal";
			this->monthCal->ShowWeekNumbers = true;
			this->monthCal->TabIndex = 3;
			this->monthCal->DateChanged += gcnew System::Windows::Forms::DateRangeEventHandler(this, &dateSelectionCalendar::monthCal_DateChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F));
			this->label1->Location = System::Drawing::Point(16, 329);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 15);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Arrival Date:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(185, 329);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(89, 15);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Departure Date:";
			// 
			// okButton
			// 
			this->okButton->Location = System::Drawing::Point(255, 367);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(75, 23);
			this->okButton->TabIndex = 8;
			this->okButton->Text = L"OK";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &dateSelectionCalendar::okButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->Location = System::Drawing::Point(376, 367);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(75, 23);
			this->cancelButton->TabIndex = 9;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = true;
			this->cancelButton->Click += gcnew System::EventHandler(this, &dateSelectionCalendar::cancelButton_Click);
			// 
			// dateSelectionCalendar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(508, 410);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->End);
			this->Controls->Add(this->Start);
			this->Controls->Add(this->monthCal);
			this->Name = L"dateSelectionCalendar";
			this->Text = L"dateSelectionCalendar";
			this->Load += gcnew System::EventHandler(this, &dateSelectionCalendar::dateSelectionCalendar_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dateSelectionCalendar_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
			 System::Void monthCal_DateChanged(System::Object^ sender, System::Windows::Forms::DateRangeEventArgs^ e)
			 {
				// Update start and end range labels when date changes
				Start->Text = e->Start.Date.ToShortDateString();
				End->Text   = e->End.Date.ToShortDateString();

				numberOfDays = e->End.Date.DayOfYear - e->Start.Date.DayOfYear;
			 }
private: System::Void okButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void cancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
public:  System::String^ getNumberOfDays()
		 {
			 return numberOfDays.ToString();
		 }
};
}
