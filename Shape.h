#include <math.h>  

using namespace System;
using namespace System::Xml;
using namespace System::Xml::Serialization;
using namespace System::Runtime::Serialization;
using namespace System::IO;

#pragma once
namespace Shape {
	[Serializable]
	public ref class Shape	{
	public:
		Shape ();
		Shape ( System::Drawing::Graphics^ gr, bool filled, int penWidth,int colorArgb, int startX, int startY, int endX, int endY );
		[XmlAttribute]
		int startX, startY, endX, endY, type, colorArgb, index, penWidth;
		bool filled;

		[XmlIgnore]
		[NonSerialized]
		System::Drawing::Pen^ pen;
		[NonSerialized]
		System::Drawing::Brush^ brush;

		[XmlIgnore]
		[NonSerialized]
		System::Drawing::Graphics^ gr;		
	public:
		virtual void draw ();
		void setGraphic ( System::Drawing::Graphics^ gr );
		void remakeTool ();
		void applyChange (System::String^ sX, System::String^ sY, System::String^ eX, System::String^ eY, System::String^  index, int color, bool isFilled,int penWidth );
		static int shapeIndexComparator ( Shape^ s1, Shape^ s2 ) {
			return s1->index.CompareTo ( s2->index );
		}
	};
	[Serializable]
	public ref class Line: public Shape {
	public:
		Line () {};
		Line ( System::Drawing::Graphics^ gr, int penWidth, int colorArgb, int startX, int startY, int endX, int endY );
		void draw () override {
			this->Shape::draw ();
			this->gr->DrawLine ( this->pen, startX, startY, endX, endY );
		}
	};
	[Serializable]
	public ref class Rectangle: public Shape {
	public:
		Rectangle () {};
		Rectangle ( System::Drawing::Graphics^ gr, bool filled, int penWidth, int colorArgb, int startX, int startY, int endX, int endY );
		void draw () override {
			this->Shape::draw ();
			if(this->filled) {
				this->gr->FillRectangle ( this->brush, startX, startY, endX - startX, endY - startY );
			}
			else {
			this->gr->DrawRectangle ( this->pen, startX, startY, endX - startX, endY - startY );
			}
		}
	};
	[Serializable]
	public ref class Elipse: public Shape {
	public:
		Elipse () {};
		Elipse ( System::Drawing::Graphics^ gr, bool filled, int penWidth, int colorArgb, int startX, int startY, int endX, int endY );
		void draw () override {
			this->Shape::draw ();
			if(this->filled) {
				this->gr->FillEllipse ( this->brush, startX, startY, endX - startX, endY - startY );
			}
			else {
				this->gr->DrawEllipse ( this->pen, startX, startY, endX - startX, endY - startY );
			}		
		}
	};
	[Serializable]
	public ref class Circle: public Shape {
	public:
		Circle () {};
		Circle ( System::Drawing::Graphics^ gr, bool filled, int penWidth, int colorArgb, int startX, int startY, int endX, int endY );
		void draw () override {
			this->Shape::draw ();
			int round = (int) sqrt ( pow ( endX - startX, 2 ) + pow ( endY - startY, 2 ));
			if(this->filled) {
				this->gr->FillEllipse ( this->brush, startX - round, startY - round, 2 * round, 2 * round );
			}
			else {
				this->gr->DrawEllipse ( this->pen, startX - round, startY - round, 2 * round, 2 * round );
			}	
		}

	};
}
