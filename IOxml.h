#pragma once
#include "Shape.h"
#include "Color.h"

using namespace System::Collections;
using namespace System;
using namespace System::Xml;
using namespace System::Xml::Serialization;
using namespace System::Runtime::Serialization;
using namespace System::Runtime::Serialization::Formatters::Binary;
using namespace System::IO;

static ref class IOxml
{
private :
	Stream^ fs = gcnew FileStream ( "temp.xml", FileMode::Create );
	XmlWriterSettings ^settings = gcnew XmlWriterSettings ();
	XmlWriter^ writer;
	XmlSerializer^ x;
public:
	IOxml();
	~IOxml();
	static Generic::List<Shape::Shape^>^ xmlImport(System::String^ path);
	static bool xmlExport(Generic::List<Shape::Shape^>^ data);
	static bool IOxml::xmlExport ( Shape::Shape^ data );
	static bool ExportBinary ( Generic::List<Shape::Shape^>^ data );
	static Generic::List<Shape::Shape^>^ IOxml::ImportBinary (void);
	static bool IOxml::SaveToJPG(System::Drawing::Bitmap^ bmp);
};

