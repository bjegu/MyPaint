#include "ColorButton.h"

ColorButton::ColorButton()
{
	
}

ColorButton::ColorButton(int alpha, int red, int blue, int green)
{
	this->value = gcnew Color(alpha,red, blue, green);
	InitializeComponent();
}

ColorButton::ColorButton(const ColorButton ^ copy)
{
	this->value = gcnew Color(copy->value->getAlpha(), copy->value->getRed(), copy->value->getGreen(), copy->value->getBlue());
	InitializeComponent();
}

System::Drawing::Color ColorButton::getDrawingColor()
{
	System::Drawing::Color out;
	out = System::Drawing::Color::FromArgb(this->value->getAlpha(), this->value->getRed(), this->value->getGreen(), this->value->getBlue());
	return out;
}
