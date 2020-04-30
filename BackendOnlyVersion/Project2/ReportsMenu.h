#pragma once

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ReportsMenu
	/// </summary>
	public ref class ReportsMenu : public System::Windows::Forms::Form
	{
	public:
		ReportsMenu(void)
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
		~ReportsMenu()
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ReportsMenu::typeid));
			this->SuspendLayout();
			// 
			// ReportsMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(715, 565);
			this->Name = L"ReportsMenu";
			this->Text = L"ReportsMenu";
			this->Load += gcnew System::EventHandler(this, &ReportsMenu::ReportsMenu_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ReportsMenu_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	};
}
