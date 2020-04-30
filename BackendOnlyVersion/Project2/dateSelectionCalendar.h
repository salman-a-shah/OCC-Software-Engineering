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
        System::Windows::Forms::MonthCalendar^  monthCal;

		dateSelectionCalendar(void)
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
			this->SuspendLayout();
			// 
			// End
			// 
			this->End->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->End->Location = System::Drawing::Point(230, 323);
			this->End->Name = L"End";
			this->End->Size = System::Drawing::Size(83, 20);
			this->End->TabIndex = 5;
			// 
			// Start
			// 
			this->Start->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Start->Location = System::Drawing::Point(122, 323);
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
			// dateSelectionCalendar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(508, 361);
			this->Controls->Add(this->End);
			this->Controls->Add(this->Start);
			this->Controls->Add(this->monthCal);
			this->Name = L"dateSelectionCalendar";
			this->Text = L"dateSelectionCalendar";
			this->Load += gcnew System::EventHandler(this, &dateSelectionCalendar::dateSelectionCalendar_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void dateSelectionCalendar_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
			 System::Void monthCal_DateChanged(System::Object^ sender, System::Windows::Forms::DateRangeEventArgs^ e)
			 {
				// Update start and end range labels when date changes
				Start->Text = e->Start.Date.ToShortDateString();
				End->Text   = e->End.Date.ToShortDateString();
			 }
	};
}
