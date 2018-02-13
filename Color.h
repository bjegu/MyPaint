#pragma once
public ref class Color
{
public:
		Color();
		Color(const int& alpha, const int& r, const int& b, const int& g);
		void setAlpha(float value);
		int getRed();
		int getBlue();
		int getGreen();
		int getAlpha();
		~Color();

private:
	int red, green, blue;
	float alpha;
};

