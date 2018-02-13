#pragma once
#include "Color.h"

ref class ColorButton : System::Windows::Forms::Control
{
public:	
	ColorButton();
	ColorButton(int alpha, int red, int blue, int green);
	ColorButton(const ColorButton^ copy);
	System::Drawing::Color getDrawingColor();
	System::Windows::Forms::Button^  button;
private:
	Color^ value;
	System::Void InitializeComponent() {
	this->button = (gcnew System::Windows::Forms::Button());
	this->SuspendLayout();
	this->button->Location = System::Drawing::Point(0, 0);
	this->button->Name = L"button1";
	this->button->Size = System::Drawing::Size(26, 26);
	this->button->TabIndex = 0;
	this->button->Text = L"";	
	this->button->BackColor = getDrawingColor(); //System::Drawing::Color::FromArgb(1,255, 255, 255);
	this->ResumeLayout(false);
	this->Controls->Add(this->button);
	}
	System::Void InitializeCustom() {
	}
	

};

