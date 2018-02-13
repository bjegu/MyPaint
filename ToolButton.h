#pragma once
ref class ToolButton : System::Windows::Forms::Button
{
private: System::Windows::Forms::Button^  button;

public:
	ToolButton();
private: System::Void InitializeComponent() {
	this->button1 = (gcnew System::Windows::Forms::Button());
	this->SuspendLayout();
	// 
	// button1
	// 
	this->button1->Location = System::Drawing::Point(0, 0);
	this->button1->Name = L"button1";
	this->button1->Size = System::Drawing::Size(75, 23);
	this->button1->TabIndex = 0;
	this->button1->Text = L"button1";
	this->button1->UseVisualStyleBackColor = true;
	this->ResumeLayout(false);
}
};

