#pragma once

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for RatesMenu
	/// </summary>
	public ref class RatesMenu : public System::Windows::Forms::Form
	{
	public:
		RatesMenu(void)
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
		~RatesMenu()
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(RatesMenu::typeid));
			this->SuspendLayout();
			// 
			// RatesMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(742, 589);
			this->Name = L"RatesMenu";
			this->Text = L"RatesMenu";
			this->Load += gcnew System::EventHandler(this, &RatesMenu::RatesMenu_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void RatesMenu_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	};
}
