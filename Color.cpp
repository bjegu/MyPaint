#include "Color.h"
#include <iostream>
#include <conio.h>
#include <sstream>

Color::Color()
{
}

Color::Color(const int& alpha, const int& r, const int& b, const int& g)
	: red(r)
	, green(g)
	, blue(b)
	, alpha(alpha)
{}

void Color::setAlpha(float value)
{
	this->alpha = value;
}


int Color::getRed()
{
	return this->red;
}

int Color::getBlue()
{
	return this->blue;
}

int Color::getGreen()
{
	return this->green;
}

int Color::getAlpha()
{
	return this->alpha;
}

Color::~Color()
{
}

