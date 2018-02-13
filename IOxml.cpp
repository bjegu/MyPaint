#include "IOxml.h"
#include "Color.h"


IOxml::IOxml()
{
}

IOxml::~IOxml()
{
}

Generic::List<Shape::Shape^>^ IOxml::xmlImport(System::String ^ path)
{
	Generic::List<Shape::Shape^>^ list;
	return list;
}

bool IOxml::xmlExport(Generic::List<Shape::Shape^>^ data)
{
	FileStream^ fs = gcnew FileStream ( "temp.xml", FileMode::Create );

	XmlWriterSettings ^settings = gcnew XmlWriterSettings ();
	settings->Indent = true;
	settings->IndentChars = ("    ");
	settings->NewLineOnAttributes = false;
	XmlWriter^ writer = gcnew XmlTextWriter ( fs, System::Text::Encoding::Unicode );
	writer = XmlWriter::Create ( "exportring.xml", settings );

//	XmlSerializer^ x; 
	array<Shape::Shape^>^ temp = data->ToArray ();
//	for(int i = 0; i < temp->Length;i++) {
//		x = gcnew XmlSerializer ( temp->GetValue(i)->GetType () );
//		x->Serialize ( writer, temp->GetValue ( i ) );
//	}
	XmlSerializer^ x = gcnew XmlSerializer ( data->GetType () );
	for each ( Shape::Shape^  shape in data) {
		x = gcnew XmlSerializer ( shape->GetType () );
		x->Serialize ( writer, shape);
	}
	//x->Serialize ( writer, data);

	writer->Close ();
	fs->Close ();
	return true;
}
bool IOxml::xmlExport (Shape::Shape^ data)
{
	Stream^ fs = gcnew FileStream ( "temp.xml", FileMode::Create );
	
	XmlWriterSettings ^settings = gcnew XmlWriterSettings ();
	settings->Indent = true;
	settings->IndentChars = ("    ");
	settings->NewLineOnAttributes = false;
	XmlWriter^ writer = gcnew XmlTextWriter ( fs, System::Text::Encoding::Unicode );
	writer = XmlWriter::Create ( "exportring.xml", settings );

	XmlSerializer^ x = gcnew XmlSerializer ( data->GetType());
	x->Serialize (writer , data );
	writer->Close ();
	return true;
}

bool IOxml::ExportBinary ( Generic::List<Shape::Shape^>^ data )
{
	IFormatter^ Formatter = gcnew BinaryFormatter ();

	FileStream^  fs = gcnew FileStream ( "binaryExport.txt", FileMode::Create );
		try
		{
			Formatter->Serialize ( fs, data );
			return true;
		}
		catch(SerializationException^ ex) {
			return false;
		}
		finally
		{
			fs->Close ();
		}
		
}

Generic::List<Shape::Shape^>^ IOxml::ImportBinary (void)
{
	Generic::List<Shape::Shape^>^ shapes = nullptr;
	FileStream^ fs;
	try {
		fs = gcnew FileStream ( "binaryExport.txt", FileMode::Open );
	}
	catch(System::IO::FileNotFoundException^ ex) {
		return gcnew Generic::List<Shape::Shape^> ();
	}
		
	try
	{
		BinaryFormatter^ formatter = gcnew BinaryFormatter;

		shapes = dynamic_cast<Generic::List<Shape::Shape^>^>(formatter->Deserialize ( fs ));
		return shapes;

	}
	catch(SerializationException^ e)
	{
		Console::WriteLine ( "Failed to deserialize. Reason: {0}", e->Message );
		throw;
	}
	finally
	{
		fs->Close ();
	}

}

bool IOxml::SaveToJPG(System::Drawing::Bitmap^ bmp)
{
	bmp->Save("image.jpeg", System::Drawing::Imaging::ImageFormat::Jpeg);
	return true;
}



