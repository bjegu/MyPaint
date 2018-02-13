#include "Shape.h"



Shape::Shape::Shape ()
{
}

Shape::Shape::Shape ( System::Drawing::Graphics^ gr, bool filled,int penWidth,int colorArgb,  int startX, int startY, int endX, int endY )
	:gr(gr), filled ( filled ), penWidth (penWidth), colorArgb( colorArgb),startX ( startX ), startY( startY ), endX ( endX ), endY ( endY ),index(10)
{
}

void Shape::Shape::draw ( )
{
	if((this->filled && this->brush == nullptr )|| ((this->type == 1 || !this->filled) && this->pen == nullptr)) {
		this->remakeTool ();
	}
}

void Shape::Shape::setGraphic ( System::Drawing::Graphics ^ gr )
{
	this->gr = gr;
}

void Shape::Shape::remakeTool ()
{
	if(this->filled && this->type > 1) {
		this->brush = gcnew System::Drawing::SolidBrush ( System::Drawing::Color::FromArgb ( this->colorArgb ) );
	}
	else {
		this->pen = gcnew System::Drawing::Pen ( System::Drawing::Color::FromArgb ( this->colorArgb ),this->penWidth );
	}

	
}

void Shape::Shape::applyChange ( System::String ^ sX, System::String ^ sY, System::String ^ eX, System::String ^ eY, System::String ^ index, int color , bool isFilled, int penWidth )
{
	this->startX = Int32::Parse ( sX );
	this->startY = Int32::Parse ( sY );
	this->endX   = Int32::Parse ( eX );
	this->endY   = Int32::Parse ( eY );
	this->index  = Int32::Parse ( index );
	this->filled = isFilled;
	this->colorArgb = color;
	this->pen = nullptr;
	this->brush = nullptr;
	this->penWidth = penWidth;
	remakeTool ();
}

Shape::Line::Line ( System::Drawing::Graphics^ gr, int penWidth, int colorArgb, int startX, int startY, int endX, int endY )
	:Shape ( gr, false, penWidth, colorArgb, startX, startY, endX, endY )
{
	this->type = 1;
}

Shape::Rectangle::Rectangle ( System::Drawing::Graphics^ gr, bool filled, int penWidth, int colorArgb, int startX, int startY, int endX, int endY )
	:Shape ( gr, filled, penWidth, colorArgb, startX, startY, endX, endY )
{
	this->type = 2;
	if(startX > endX) {
		this->startX = endX;
		this->endX = startX;
	};
	if(startY > endY) {
		this->startY = endY;
		this->endY = startY;
	};
}
Shape::Elipse::Elipse ( System::Drawing::Graphics^ gr, bool filled, int penWidth, int colorArgb, int startX, int startY, int endX, int endY )
	:Shape ( gr,  filled, penWidth,  colorArgb, startX, startY, endX, endY )
{
	this->type = 4;
	if(startX > endX) {
		this->startX = endX;
		this->endX = startX;
	};
	if(startY > endY) {
		this->startY = endY;
		this->endY = startY;
	};
}

Shape::Circle::Circle ( System::Drawing::Graphics^ gr, bool filled,int penWidth, int colorArgb, int startX, int startY, int endX, int endY )
	:Shape ( gr, filled, penWidth, colorArgb, startX, startY, endX, endY )
{
	this->type = 3;
}
