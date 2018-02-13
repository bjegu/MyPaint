#pragma once
#include "ColorButton.h"
#include "list"
#include "Shape.h"
#include "IOxml.h"


namespace MyPaint {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm: public System::Windows::Forms::Form
	{
	public:
		MyForm ( void )
		{
			InitializeComponent ();
			InitCustoms ();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm ()
		{
			if(components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::GroupBox^  Canvas;
	private: System::Windows::Forms::PictureBox^  board;
	private: Graphics^ canvasGraphic;


	private: ColorButton^  White;
	private: ColorButton^  Yellow;
	private: ColorButton^  Purple;
	private: ColorButton^  BlueMin;
	private: ColorButton^  BlueHalf;
	private: ColorButton^  BlueFull;
	private: ColorButton^  GreenMin;
	private: ColorButton^  GreenHalf;
	private: ColorButton^  GreenFull;
	private: ColorButton^  RedMin;
	private: ColorButton^  RedHalf;
	private: ColorButton^  RedFull;
	private: ColorButton^  BlackMin;
	private: ColorButton^  BlackHafl;
	private: ColorButton^  BlackFull;
	private: ColorButton^  EditColor;

	private:  System::Drawing::Color^  actualColor;
	private:  System::Drawing::Color^  canvasBackgroundColor;
	private:  int  actualTools;
	private: int firstX = -1;
			 int firstY = -1;
	private: System::Windows::Forms::GroupBox^  Tools;
	private: System::Windows::Forms::GroupBox^  Colors;
	private: Generic::List<Shape::Shape^>^ listOfShape = gcnew Generic::List<Shape::Shape^> ();
	private: Comparison<Shape::Shape^> ^ indexComparision = gcnew Comparison<Shape::Shape^> ( &Shape::Shape::shapeIndexComparator );
	private: Shape::Shape^ selectedItem = nullptr;

	private: System::Windows::Forms::Button^  undo;
	private: System::Windows::Forms::Button^  saveToJPEG;
	private: System::Windows::Forms::Button^  Import;
	private: System::Windows::Forms::Button^  Export;

	private: System::Windows::Forms::Button^  eclipseTool;
	private: System::Windows::Forms::Button^  circleTool;
	private: System::Windows::Forms::Button^  rectangleTool;
	private: System::Windows::Forms::Button^  lineTool;
	private: System::Windows::Forms::ComboBox^  existringItemsComboBox;
	private: System::Windows::Forms::GroupBox^  EditGroup;
	private: System::Windows::Forms::TextBox^  edit2Y;
	private: System::Windows::Forms::TextBox^  edit1Y;

	private: System::Windows::Forms::TextBox^  edit2X;


	private: System::Windows::Forms::TextBox^  edit1X;
	private: System::Windows::Forms::Label^  Point1X;
	private: System::Windows::Forms::Label^  Point2Y;

	private: System::Windows::Forms::Label^  Point1Y;

	private: System::Windows::Forms::Label^  Point2X;
	private: System::Windows::Forms::Label^  labelIndex;

	private: System::Windows::Forms::TextBox^  editIndex;
	private: System::Windows::Forms::ErrorProvider^  errorValidation;
	private: System::Windows::Forms::Label^  validatorText;
	private: System::Windows::Forms::Button^  applyChangeButton;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::CheckBox^  filledCheckBox;
	private: System::Windows::Forms::CheckBox^  editFilled;
	private: System::Windows::Forms::Label^  labelEditColor;
	private: System::Windows::Forms::ComboBox^  penSize;
	private: System::Windows::Forms::Label^  penWidthLabel;
	private: System::Windows::Forms::Label^  editPenWidthLabel;
	private: System::Windows::Forms::ComboBox^  editPenWidth;




	private: System::ComponentModel::IContainer^  components;



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent ( void )
		{
			// Contianers
			this->components = (gcnew System::ComponentModel::Container ());
			this->Canvas = (gcnew System::Windows::Forms::GroupBox ());
			this->Tools = (gcnew System::Windows::Forms::GroupBox());
			this->Colors = (gcnew System::Windows::Forms::GroupBox());
			this->EditGroup = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			// Drawing board
			this->board = (gcnew System::Windows::Forms::PictureBox ());
			// Tools
			this->eclipseTool = (gcnew System::Windows::Forms::Button ());
			this->circleTool = (gcnew System::Windows::Forms::Button ());
			this->rectangleTool = (gcnew System::Windows::Forms::Button ());
			this->lineTool = (gcnew System::Windows::Forms::Button ());
			// Property of tools
			this->penSize = (gcnew System::Windows::Forms::ComboBox());
			this->filledCheckBox = (gcnew System::Windows::Forms::CheckBox());

			// IO buttons
			this->undo = (gcnew System::Windows::Forms::Button ());
			this->saveToJPEG = (gcnew System::Windows::Forms::Button ());
			this->Import = (gcnew System::Windows::Forms::Button ());
			this->Export = (gcnew System::Windows::Forms::Button ());
		
			// EditBox 
			this->labelIndex = (gcnew System::Windows::Forms::Label ());
			this->existringItemsComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->applyChangeButton = (gcnew System::Windows::Forms::Button());
			this->validatorText = (gcnew System::Windows::Forms::Label());
			this->errorValidation = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->labelEditColor = (gcnew System::Windows::Forms::Label());
			this->penWidthLabel = (gcnew System::Windows::Forms::Label());
			// EditBox Fields
			this->editIndex = (gcnew System::Windows::Forms::TextBox ());
			this->Point2Y = (gcnew System::Windows::Forms::Label ());
			this->Point1Y = (gcnew System::Windows::Forms::Label ());
			this->Point2X = (gcnew System::Windows::Forms::Label ());
			this->Point1X = (gcnew System::Windows::Forms::Label ());
			this->edit2Y = (gcnew System::Windows::Forms::TextBox ());
			this->edit1Y = (gcnew System::Windows::Forms::TextBox ());
			this->edit2X = (gcnew System::Windows::Forms::TextBox ());
			this->edit1X = (gcnew System::Windows::Forms::TextBox ());
			this->editFilled = (gcnew System::Windows::Forms::CheckBox());
			this->editPenWidthLabel = (gcnew System::Windows::Forms::Label ());
			this->editPenWidth = (gcnew System::Windows::Forms::ComboBox ());

			this->Canvas->SuspendLayout ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->board))->BeginInit ();
			this->Tools->SuspendLayout ();
			this->EditGroup->SuspendLayout ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorValidation))->BeginInit ();
			this->groupBox1->SuspendLayout ();
			this->SuspendLayout ();
			// 
			// Canvas
			// 
			this->Canvas->AutoSize = true;
			this->Canvas->Controls->Add ( this->board );
			this->Canvas->Location = System::Drawing::Point ( 170, 21 );
			this->Canvas->Name = L"Canvas";
			this->Canvas->Size = System::Drawing::Size ( 1019, 498 );
			this->Canvas->TabIndex = 2;
			this->Canvas->TabStop = false;
			this->Canvas->Text = L"Canvas";
			// 
			// board
			// 
			this->board->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->board->Location = System::Drawing::Point ( 23, 20 );
			this->board->Name = L"board";
			this->board->Size = System::Drawing::Size ( 979, 459 );
			this->board->TabIndex = 0;
			this->board->TabStop = false;
			this->board->MouseClick += gcnew System::Windows::Forms::MouseEventHandler ( this, &MyForm::boardClick );
			// 
			// Tools
			// 
			this->Tools->Controls->Add ( this->eclipseTool );
			this->Tools->Controls->Add ( this->circleTool );
			this->Tools->Controls->Add ( this->rectangleTool );
			this->Tools->Controls->Add ( this->lineTool );
			this->Tools->Location = System::Drawing::Point ( 29, 21 );
			this->Tools->Name = L"Tools";
			this->Tools->Size = System::Drawing::Size ( 101, 151 );
			this->Tools->TabIndex = 0;
			this->Tools->TabStop = false;
			this->Tools->Text = L"Tools";
			// 
			// eclipseTool
			// 
			this->eclipseTool->Location = System::Drawing::Point ( 15, 111 );
			this->eclipseTool->Name = L"eclipseTool";
			this->eclipseTool->Size = System::Drawing::Size ( 71, 24 );
			this->eclipseTool->TabIndex = 3;
			this->eclipseTool->Text = L"Elipse";
			this->eclipseTool->UseVisualStyleBackColor = true;
			this->eclipseTool->Click += gcnew System::EventHandler ( this, &MyForm::changeTool );
			// 
			// circleTool
			// 
			this->circleTool->Location = System::Drawing::Point ( 15, 81 );
			this->circleTool->Name = L"circleTool";
			this->circleTool->Size = System::Drawing::Size ( 71, 24 );
			this->circleTool->TabIndex = 2;
			this->circleTool->Text = L"Circle";
			this->circleTool->UseVisualStyleBackColor = true;
			this->circleTool->Click += gcnew System::EventHandler ( this, &MyForm::changeTool );
			// 
			// rectangleTool
			// 
			this->rectangleTool->Location = System::Drawing::Point ( 15, 51 );
			this->rectangleTool->Name = L"rectangleTool";
			this->rectangleTool->Size = System::Drawing::Size ( 71, 24 );
			this->rectangleTool->TabIndex = 1;
			this->rectangleTool->Text = L"Rectangle";
			this->rectangleTool->UseVisualStyleBackColor = true;
			this->rectangleTool->Click += gcnew System::EventHandler ( this, &MyForm::changeTool );
			// 
			// lineTool
			// 
			this->lineTool->Location = System::Drawing::Point ( 14, 21 );
			this->lineTool->Name = L"lineTool";
			this->lineTool->Size = System::Drawing::Size ( 71, 24 );
			this->lineTool->TabIndex = 0;
			this->lineTool->Text = L"Line";
			this->lineTool->UseVisualStyleBackColor = true;
			this->lineTool->Click += gcnew System::EventHandler ( this, &MyForm::changeTool );
			// 
			// Colors
			// 
			this->Colors->Location = System::Drawing::Point ( 30, 290 );
			this->Colors->Name = L"Colors";
			this->Colors->Size = System::Drawing::Size ( 101, 187 );
			this->Colors->TabIndex = 1;
			this->Colors->TabStop = false;
			this->Colors->Text = L"Colors";
			// 
			// undo
			// 
			this->undo->Location = System::Drawing::Point ( 29, 483 );
			this->undo->Name = L"undo";
			this->undo->Size = System::Drawing::Size ( 60, 30 );
			this->undo->TabIndex = 3;
			this->undo->Text = L"Undo";
			this->undo->UseVisualStyleBackColor = true;
			this->undo->Click += gcnew System::EventHandler ( this, &MyForm::undo_Click );
			// 
			// saveToJPEG
			// 
			this->saveToJPEG->Location = System::Drawing::Point ( 99, 483 );
			this->saveToJPEG->Name = L"saveToJPEG";
			this->saveToJPEG->Size = System::Drawing::Size ( 60, 30 );
			this->saveToJPEG->TabIndex = 3;
			this->saveToJPEG->Text = L"To JPEG";
			this->saveToJPEG->UseVisualStyleBackColor = true;
			this->saveToJPEG->Click += gcnew System::EventHandler ( this, &MyForm::exportToJPEG );
			// 
			// Import
			// 
			this->Import->Location = System::Drawing::Point ( 29, 533 );
			this->Import->Name = L"Import";
			this->Import->Size = System::Drawing::Size ( 60, 30 );
			this->Import->TabIndex = 3;
			this->Import->Text = L"Import";
			this->Import->UseVisualStyleBackColor = true;
			this->Import->Click += gcnew System::EventHandler ( this, &MyForm::importFile );
			// 
			// Export
			// 
			this->Export->Location = System::Drawing::Point ( 99, 533 );
			this->Export->Name = L"Export";
			this->Export->Size = System::Drawing::Size ( 60, 30 );
			this->Export->TabIndex = 3;
			this->Export->Text = L"Export";
			this->Export->UseVisualStyleBackColor = true;
			this->Export->Click += gcnew System::EventHandler ( this, &MyForm::exportFile );
			// 
			// comboBox1
			// 
			this->existringItemsComboBox->FormattingEnabled = true;
			this->existringItemsComboBox->Location = System::Drawing::Point ( 194, 543 );
			this->existringItemsComboBox->Margin = System::Windows::Forms::Padding ( 2 );
			this->existringItemsComboBox->Name = L"existringItems";
			this->existringItemsComboBox->Size = System::Drawing::Size ( 151, 21 );
			this->existringItemsComboBox->TabIndex = 4;
			this->existringItemsComboBox->SelectedIndexChanged += gcnew System::EventHandler ( this, &MyForm::comboBox1_SelectedIndexChanged );
			// 
			// EditGroup
			// 
			this->EditGroup->Controls->Add ( this->editPenWidthLabel );
			this->EditGroup->Controls->Add ( this->labelEditColor );
			this->EditGroup->Controls->Add ( this->editPenWidth );
			this->EditGroup->Controls->Add ( this->editFilled );
			this->EditGroup->Controls->Add ( this->applyChangeButton );
			this->EditGroup->Controls->Add ( this->validatorText );
			this->EditGroup->Controls->Add ( this->labelIndex );
			this->EditGroup->Controls->Add ( this->editIndex );
			this->EditGroup->Controls->Add ( this->Point2Y );
			this->EditGroup->Controls->Add ( this->Point1Y );
			this->EditGroup->Controls->Add ( this->Point2X );
			this->EditGroup->Controls->Add ( this->Point1X );
			this->EditGroup->Controls->Add ( this->edit2Y );
			this->EditGroup->Controls->Add ( this->edit1Y );
			this->EditGroup->Controls->Add ( this->edit2X );
			this->EditGroup->Controls->Add ( this->edit1X );
			this->EditGroup->Location = System::Drawing::Point ( 359, 543 );
			this->EditGroup->Margin = System::Windows::Forms::Padding ( 2 );
			this->EditGroup->Name = L"EditGroup";
			this->EditGroup->Padding = System::Windows::Forms::Padding ( 2 );
			this->EditGroup->Size = System::Drawing::Size ( 307, 185 );
			this->EditGroup->TabIndex = 5;
			this->EditGroup->TabStop = false;
			this->EditGroup->Text = L"Item property";
			// 
			// labelEditColor
			// 
			this->labelEditColor->AutoSize = true;
			this->labelEditColor->Location = System::Drawing::Point ( 235, 27 );
			this->labelEditColor->Name = L"labelEditColor";
			this->labelEditColor->Size = System::Drawing::Size ( 31, 13 );
			this->labelEditColor->TabIndex = 12;
			this->labelEditColor->Text = L"Color";
			// 
			// editFilled
			// 
			this->editFilled->AutoSize = true;
			this->editFilled->Location = System::Drawing::Point ( 22, 129 );
			this->editFilled->Name = L"editFilled";
			this->editFilled->Size = System::Drawing::Size ( 57, 17 );
			this->editFilled->TabIndex = 1;
			this->editFilled->Text = L"isFilled";
			this->editFilled->UseVisualStyleBackColor = true;
			this->editFilled->CheckedChanged += gcnew System::EventHandler ( this, &MyForm::editFilled_CheckedChanged );
			// 
			// applyChangeButton
			// 
			this->applyChangeButton->Location = System::Drawing::Point ( 162, 90 );
			this->applyChangeButton->Name = L"applyChanges";
			this->applyChangeButton->Size = System::Drawing::Size ( 91, 23 );
			this->applyChangeButton->TabIndex = 11;
			this->applyChangeButton->Text = L"Apply Changes";
			this->applyChangeButton->UseVisualStyleBackColor = true;
			this->applyChangeButton->Click += gcnew System::EventHandler ( this, &MyForm::applyEditChange );
			// 
			// validatorText
			// 
			this->validatorText->AutoSize = true;
			this->validatorText->Location = System::Drawing::Point ( 275, 27 );
			this->validatorText->Name = L"validatorText";
			this->validatorText->Size = System::Drawing::Size ( 0, 13 );
			this->validatorText->TabIndex = 10;
			// 
			// labelIndex
			// 
			this->labelIndex->AutoSize = true;
			this->labelIndex->Location = System::Drawing::Point ( 159, 27 );
			this->labelIndex->Name = L"labelIndex";
			this->labelIndex->Size = System::Drawing::Size ( 33, 13 );
			this->labelIndex->TabIndex = 9;
			this->labelIndex->Text = L"Index";
			// 
			// editIndex
			// 
			this->editIndex->Location = System::Drawing::Point ( 162, 42 );
			this->editIndex->Margin = System::Windows::Forms::Padding ( 2 );
			this->editIndex->Name = L"editIndex";
			this->editIndex->Size = System::Drawing::Size ( 52, 20 );
			this->editIndex->TabIndex = 8;
			this->editIndex->Validating += gcnew System::ComponentModel::CancelEventHandler ( this, &MyForm::validatePoints );
			// 
			// Point2Y
			// 
			this->Point2Y->AutoSize = true;
			this->Point2Y->Location = System::Drawing::Point ( 76, 77 );
			this->Point2Y->Name = L"Point2Y";
			this->Point2Y->Size = System::Drawing::Size ( 47, 13 );
			this->Point2Y->TabIndex = 7;
			this->Point2Y->Text = L"Point2 Y";
			// 
			// Point1Y
			// 
			this->Point1Y->AutoSize = true;
			this->Point1Y->Location = System::Drawing::Point ( 19, 77 );
			this->Point1Y->Name = L"Point1Y";
			this->Point1Y->Size = System::Drawing::Size ( 47, 13 );
			this->Point1Y->TabIndex = 6;
			this->Point1Y->Text = L"Point1 Y";
			this->Point1Y->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// Point2X
			// 
			this->Point2X->AutoSize = true;
			this->Point2X->Location = System::Drawing::Point ( 76, 27 );
			this->Point2X->Name = L"Point2X";
			this->Point2X->Size = System::Drawing::Size ( 47, 13 );
			this->Point2X->TabIndex = 5;
			this->Point2X->Text = L"Point2 X";
			// 
			// Point1X
			// 
			this->Point1X->AutoSize = true;
			this->Point1X->Location = System::Drawing::Point ( 19, 27 );
			this->Point1X->Name = L"Point1X";
			this->Point1X->Size = System::Drawing::Size ( 47, 13 );
			this->Point1X->TabIndex = 4;
			this->Point1X->Text = L"Point1 X";
			// 
			// edit2Y
			// 
			this->edit2Y->Location = System::Drawing::Point ( 79, 92 );
			this->edit2Y->Margin = System::Windows::Forms::Padding ( 2 );
			this->edit2Y->Name = L"edit2Y";
			this->edit2Y->Size = System::Drawing::Size ( 52, 20 );
			this->edit2Y->TabIndex = 3;
			this->edit2Y->Validating += gcnew System::ComponentModel::CancelEventHandler ( this, &MyForm::validatePoints );
			// 
			// edit1Y
			// 
			this->edit1Y->Location = System::Drawing::Point ( 22, 92 );
			this->edit1Y->Margin = System::Windows::Forms::Padding ( 2 );
			this->edit1Y->Name = L"edit1Y";
			this->edit1Y->Size = System::Drawing::Size ( 53, 20 );
			this->edit1Y->TabIndex = 2;
			this->edit1Y->Validating += gcnew System::ComponentModel::CancelEventHandler ( this, &MyForm::validatePoints );
			// 
			// edit2X
			// 
			this->edit2X->Location = System::Drawing::Point ( 79, 42 );
			this->edit2X->Margin = System::Windows::Forms::Padding ( 2 );
			this->edit2X->Name = L"edit2X";
			this->edit2X->Size = System::Drawing::Size ( 52, 20 );
			this->edit2X->TabIndex = 1;
			this->edit2X->Validating += gcnew System::ComponentModel::CancelEventHandler ( this, &MyForm::validatePoints );
			// 
			// edit1X
			// 
			this->edit1X->Location = System::Drawing::Point ( 22, 42 );
			this->edit1X->Margin = System::Windows::Forms::Padding ( 2 );
			this->edit1X->Name = L"edit1X";
			this->edit1X->Size = System::Drawing::Size ( 53, 20 );
			this->edit1X->TabIndex = 0;
			this->edit1X->Validating += gcnew System::ComponentModel::CancelEventHandler ( this, &MyForm::validatePoints );
			// 
			// errorValidation
			// 
			this->errorValidation->ContainerControl = this;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add ( this->penWidthLabel );
			this->groupBox1->Controls->Add ( this->penSize );
			this->groupBox1->Controls->Add ( this->filledCheckBox );
			this->groupBox1->Location = System::Drawing::Point ( 30, 178 );
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size ( 100, 106 );
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			// 
			// penSize
			// 
			this->penSize->FormattingEnabled = true;
			this->penSize->Items->AddRange ( gcnew cli::array< System::Object^  > ( 10 ) {
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10
			} );
			this->penSize->Location = System::Drawing::Point ( 14, 69 );
			this->penSize->Name = L"penSize";
			this->penSize->Size = System::Drawing::Size ( 71, 21 );
			this->penSize->TabIndex = 1;
			// 
			// filledCheckBox
			// 
			this->filledCheckBox->AutoSize = true;
			this->filledCheckBox->Location = System::Drawing::Point ( 14, 19 );
			this->filledCheckBox->Name = L"filledCheckBox";
			this->filledCheckBox->Size = System::Drawing::Size ( 57, 17 );
			this->filledCheckBox->TabIndex = 0;
			this->filledCheckBox->Text = L"isFilled";
			this->filledCheckBox->UseVisualStyleBackColor = true;
			this->filledCheckBox->CheckedChanged += gcnew System::EventHandler ( this, &MyForm::filledCheckBox_CheckedChanged );
			// 
			// penWidthLabel
			// 
			this->penWidthLabel->AutoSize = true;
			this->penWidthLabel->Location = System::Drawing::Point ( 14, 50 );
			this->penWidthLabel->Name = L"penWidthLabel";
			this->penWidthLabel->Size = System::Drawing::Size ( 57, 13 );
			this->penWidthLabel->TabIndex = 2;
			this->penWidthLabel->Text = L"Pen Width";
			// 
			// editPenWidthLabel
			// 
			this->editPenWidthLabel->AutoSize = true;
			this->editPenWidthLabel->Location = System::Drawing::Point ( 79, 130 );
			this->editPenWidthLabel->Name = L"editPenWidthLabel";
			this->editPenWidthLabel->Size = System::Drawing::Size ( 57, 13 );
			this->editPenWidthLabel->TabIndex = 4;
			this->editPenWidthLabel->Text = L"Pen Width";
			// 
			// editPenWidth
			// 
			this->editPenWidth->FormattingEnabled = true;
			this->editPenWidth->Items->AddRange ( gcnew cli::array< System::Object^  > ( 10 ) {
				1, 2, 3, 4, 5, 6, 7, 8,9, 10
			} );
			this->editPenWidth->Location = System::Drawing::Point ( 79, 146 );
			this->editPenWidth->Name = L"editPenWidth";
			this->editPenWidth->Size = System::Drawing::Size ( 71, 21 );
			this->editPenWidth->TabIndex = 3;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF ( 6, 13 );
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size ( 1201, 751 );
			this->Controls->Add ( this->groupBox1 );
			this->Controls->Add ( this->EditGroup );
			this->Controls->Add ( this->existringItemsComboBox );
			this->Controls->Add ( this->undo );
			this->Controls->Add ( this->saveToJPEG );
			this->Controls->Add ( this->Import );
			this->Controls->Add ( this->Export );
			this->Controls->Add ( this->Colors );
			this->Controls->Add ( this->Tools );
			this->Controls->Add ( this->Canvas );
			this->Name = L"MyForm";
			this->Text = L"MYPaint";
			this->Load += gcnew System::EventHandler ( this, &MyForm::MyForm_Load );
			this->Canvas->ResumeLayout ( false );
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->board))->EndInit ();
			this->Tools->ResumeLayout ( false );
			this->EditGroup->ResumeLayout ( false );
			this->EditGroup->PerformLayout ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorValidation))->EndInit ();
			this->groupBox1->ResumeLayout ( false );
			this->groupBox1->PerformLayout ();
			this->ResumeLayout ( false );
			this->PerformLayout ();

		}
#pragma endregion
		/* my code added*/
	private: void InitCustoms () {

		// Initiation of colors elements
		this->White = (gcnew ColorButton ( 255, 255, 255, 255 ));
		this->Yellow = (gcnew ColorButton ( 255, 255, 255, 0 ));
		this->Purple = (gcnew ColorButton ( 255, 184, 3, 255 ));
		this->BlueMin = (gcnew ColorButton ( 255, 130, 130, 255 ));
		this->BlueHalf = (gcnew ColorButton ( 255, 0, 0, 150 ));
		this->BlueFull = (gcnew ColorButton ( 255, 0, 0, 255 ));
		this->GreenMin = (gcnew ColorButton ( 255, 130, 255, 130 ));
		this->GreenHalf = (gcnew ColorButton ( 255, 0, 150, 0 ));
		this->GreenFull = (gcnew ColorButton ( 255, 0, 255, 0 ));
		this->RedMin = (gcnew ColorButton ( 255, 255, 130, 130 ));
		this->RedHalf = (gcnew ColorButton ( 255, 150, 0, 0 ));
		this->RedFull = (gcnew ColorButton ( 255, 255, 0, 0 ));
		this->BlackMin = (gcnew ColorButton ( 255, 150, 150, 150 ));
		this->BlackHafl = (gcnew ColorButton ( 255, 75, 75, 75 ));
		this->BlackFull = (gcnew ColorButton ( 255, 0, 0, 0 ));
		this->EditColor = (gcnew ColorButton ( 255, 0, 0, 0 ));

		this->Colors->Controls->Add ( this->White );
		this->Colors->Controls->Add ( this->Yellow );
		this->Colors->Controls->Add ( this->Purple );
		this->Colors->Controls->Add ( this->BlueMin );
		this->Colors->Controls->Add ( this->BlueHalf );
		this->Colors->Controls->Add ( this->BlueFull );
		this->Colors->Controls->Add ( this->GreenMin );
		this->Colors->Controls->Add ( this->GreenHalf );
		this->Colors->Controls->Add ( this->GreenFull );
		this->Colors->Controls->Add ( this->RedMin );
		this->Colors->Controls->Add ( this->RedHalf );
		this->Colors->Controls->Add ( this->RedFull );
		this->Colors->Controls->Add ( this->BlackMin );
		this->Colors->Controls->Add ( this->BlackHafl );
		this->Colors->Controls->Add ( this->BlackFull );

		//Define UI property of colours components
		// 
		// White
		// 
		this->White->Location = System::Drawing::Point ( 68, 151 );
		this->White->Name = L"White";
		this->White->Size = System::Drawing::Size ( 26, 26 );
		this->White->TabIndex = 18;
		this->White->button->Click += gcnew EventHandler ( this, &MyForm::colorClick );
		// 
		// Yellow
		// 
		this->Yellow->Location = System::Drawing::Point ( 38, 151 );
		this->Yellow->Name = L"Yellow";
		this->Yellow->Size = System::Drawing::Size ( 26, 26 );
		this->Yellow->TabIndex = 17;
		this->Yellow->button->Click += gcnew EventHandler ( this, &MyForm::colorClick );
		// 
		// Purple
		// 
		this->Purple->Location = System::Drawing::Point ( 6, 151 );
		this->Purple->Name = L"Purple";
		this->Purple->Size = System::Drawing::Size ( 26, 26 );
		this->Purple->TabIndex = 16;
		this->Purple->button->Click += gcnew EventHandler ( this, &MyForm::colorClick );
		// 
		// BlueMin
		// 
		this->BlueMin->Location = System::Drawing::Point ( 68, 119 );
		this->BlueMin->Name = L"BlueMin";
		this->BlueMin->Size = System::Drawing::Size ( 26, 26 );
		this->BlueMin->TabIndex = 15;
		this->BlueMin->button->Click += gcnew EventHandler ( this, &MyForm::colorClick );
		// BlueHalf
		// 
		this->BlueHalf->Location = System::Drawing::Point ( 38, 119 );
		this->BlueHalf->Name = L"BlueHalf";
		this->BlueHalf->Size = System::Drawing::Size ( 26, 26 );
		this->BlueHalf->TabIndex = 14;
		this->BlueHalf->button->Click += gcnew EventHandler ( this, &MyForm::colorClick );
		// 
		// BlueFull
		// 
		this->BlueFull->Location = System::Drawing::Point ( 6, 119 );
		this->BlueFull->Name = L"BlueFull";
		this->BlueFull->Size = System::Drawing::Size ( 26, 26 );
		this->BlueFull->TabIndex = 13;
		this->BlueFull->button->Click += gcnew EventHandler ( this, &MyForm::colorClick );
		// 
		// GreenMin
		// 
		this->GreenMin->Location = System::Drawing::Point ( 68, 87 );
		this->GreenMin->Name = L"GreenMin";
		this->GreenMin->Size = System::Drawing::Size ( 26, 26 );
		this->GreenMin->TabIndex = 12;
		this->GreenMin->button->Click += gcnew EventHandler ( this, &MyForm::colorClick );
		// 
		// GreenHalf
		// 
		this->GreenHalf->Location = System::Drawing::Point ( 38, 87 );
		this->GreenHalf->Name = L"GreenHalf";
		this->GreenHalf->Size = System::Drawing::Size ( 26, 26 );
		this->GreenHalf->TabIndex = 11;
		this->GreenHalf->button->Click += gcnew EventHandler ( this, &MyForm::colorClick );
		// 
		// GreenFull
		// 
		this->GreenFull->Location = System::Drawing::Point ( 6, 87 );
		this->GreenFull->Name = L"GreenFull";
		this->GreenFull->Size = System::Drawing::Size ( 26, 26 );
		this->GreenFull->TabIndex = 10;
		this->GreenFull->button->Click += gcnew EventHandler ( this, &MyForm::colorClick );
		// 
		// RedMin
		// 
		this->RedMin->Location = System::Drawing::Point ( 68, 55 );
		this->RedMin->Name = L"RedMin";
		this->RedMin->Size = System::Drawing::Size ( 26, 26 );
		this->RedMin->TabIndex = 9;
		this->RedMin->button->Click += gcnew EventHandler ( this, &MyForm::colorClick );
		// 
		// RedHalf
		// 
		this->RedHalf->Location = System::Drawing::Point ( 38, 55 );
		this->RedHalf->Name = L"RedHalf";
		this->RedHalf->Size = System::Drawing::Size ( 26, 26 );
		this->RedHalf->TabIndex = 8;
		this->RedHalf->button->Click += gcnew EventHandler ( this, &MyForm::colorClick );
		// 
		// RedFull
		// 
		this->RedFull->Location = System::Drawing::Point ( 6, 55 );
		this->RedFull->Name = L"RedFull";
		this->RedFull->Size = System::Drawing::Size ( 26, 26 );
		this->RedFull->TabIndex = 7;
		this->RedFull->button->Click += gcnew EventHandler ( this, &MyForm::colorClick );
		// 
		// BlackMin
		// 
		this->BlackMin->Location = System::Drawing::Point ( 68, 23 );
		this->BlackMin->Name = L"BlackMin";
		this->BlackMin->Size = System::Drawing::Size ( 26, 26 );
		this->BlackMin->TabIndex = 6;
		this->BlackMin->button->Click += gcnew EventHandler ( this, &MyForm::colorClick );
		// 
		// BlackHafl
		// 
		this->BlackHafl->Location = System::Drawing::Point ( 38, 23 );
		this->BlackHafl->Name = L"BlackHafl";
		this->BlackHafl->Size = System::Drawing::Size ( 26, 26 );
		this->BlackHafl->TabIndex = 5;
		this->BlackHafl->button->Click += gcnew EventHandler ( this, &MyForm::colorClick );
		// 
		// BlackFull
		// 
		this->BlackFull->Location = System::Drawing::Point ( 6, 23 );
		this->BlackFull->Name = L"BlackFull";
		this->BlackFull->Size = System::Drawing::Size ( 26, 26 );
		this->BlackFull->TabIndex = 4;
		this->BlackFull->button->Click += gcnew EventHandler ( this, &MyForm::colorClick );

		// 
		// BlackFull
		// 
		this->EditColor->Location = System::Drawing::Point ( 235, 39 );
		this->EditColor->Name = L"EditColor";
		this->EditColor->Size = System::Drawing::Size ( 26, 26 );
		this->EditColor->TabIndex = 4;
		this->EditColor->button->Click += gcnew EventHandler ( this, &MyForm::editColorClick );
		this->EditGroup->Controls->Add ( this->EditColor );

		//Defaults value of tools parameters

		this->actualTools = 1;
		this->actualColor = System::Drawing::Color::Red;
		this->canvasGraphic = this->board->CreateGraphics ();
		this->canvasBackgroundColor = System::Drawing::Color::White;
		this->filledCheckBox->Checked = false;
		this->penSize->SelectedIndex = 5;
		this->penSize->SelectedItem = 5;

	}
	private: System::Void MyForm_Load ( System::Object^  sender, System::EventArgs^  e ) {
	}

	private: System::Void clearCanvas () {
		this->canvasGraphic->Clear ( (System::Drawing::Color) this->canvasBackgroundColor );
	}

	private: System::Void colorClick ( System::Object^  sender, EventArgs^  e ) {

		System::Windows::Forms::Button^ o = safe_cast<System::Windows::Forms::Button^>(sender);
		this->actualColor = o->BackColor;

	}
	private: System::Void editColorClick ( System::Object^  sender, EventArgs^  e ) {

		System::Windows::Forms::Button^ o = safe_cast<System::Windows::Forms::Button^>(sender);
		o->BackColor = System::Drawing::Color::FromArgb(this->actualColor->ToArgb()); 

	}

	private: System::Void boardClick ( System::Object^  sender, MouseEventArgs^  e ) {

		// Drawing mechanism

		if(firstX != -1 && firstY != -1) {
			int color = this->actualColor->ToArgb ();
			int penWidth = (this->penSize->SelectedItem)?(int)this->penSize->SelectedItem:3;

			switch(this->actualTools) {
				case 1:
					listOfShape->Add ( gcnew Shape::Line ( canvasGraphic, penWidth,color, firstX, firstY, e->X, e->Y ) );
					break;
				case 2:
					listOfShape->Add ( gcnew Shape::Rectangle ( canvasGraphic, this->filledCheckBox->Checked, penWidth, color, firstX, firstY, e->X, e->Y ) );
					break;
				case 3:
					listOfShape->Add ( gcnew Shape::Circle ( canvasGraphic,  this->filledCheckBox->Checked, penWidth,  color, firstX, firstY, e->X, e->Y ) );
					break;
				case 4:
					listOfShape->Add ( gcnew Shape::Elipse ( canvasGraphic,  this->filledCheckBox->Checked, penWidth, color, firstX, firstY, e->X, e->Y ) );
					break;
				default:
					listOfShape->Add ( gcnew Shape::Line ( canvasGraphic, penWidth, color, firstX, firstY, e->X, e->Y ) );
			}


			firstX = firstY = -1;
			this->existringItemsComboBox->Items->Add ( listOfShape[listOfShape->Count - 1] );
			drawList ();
		}
		else {
			firstX = e->X;
			firstY = e->Y;
		}

	}
	private: void drawList () {
		this->clearCanvas ();
		this->listOfShape->Sort ( indexComparision );
		this->listOfShape->ForEach ( gcnew Action<Shape::Shape^> ( &Shape::Shape::draw ) );
	}
	private: System::Void undo_Click ( System::Object^  sender, System::EventArgs^  e ) {
		if(this->listOfShape->Count > 0) {
			this->listOfShape->RemoveAt ( this->listOfShape->Count - 1 );
			this->existringItemsComboBox->Items->RemoveAt(this->existringItemsComboBox->Items->Count-1);
			this->clearEditBox();
			drawList ();
		}
	}

	private: System::Void changeTool ( System::Object^  sender, System::EventArgs^  e ) {
		if(sender->Equals ( this->lineTool )) {
			this->actualTools = 1;
		}
		else if(sender->Equals ( this->rectangleTool )) {
			this->actualTools = 2;
		}
		else if(sender->Equals ( this->circleTool )) {
			this->actualTools = 3;
		}
		else if(sender->Equals ( this->eclipseTool )) {
			this->actualTools = 4;
		}
	}

	private: System::Void importFile ( System::Object^  sender, System::EventArgs^  e ) {
		this->listOfShape = IOxml::ImportBinary ();
		setGraphicToList ( this->canvasGraphic );
		drawList ();
		clearEditBox ();
	}
	private: System::Void exportFile ( System::Object^  sender, System::EventArgs^  e ) {
		IOxml::ExportBinary ( this->listOfShape );
	}
	private: System::Void exportToJPEG ( System::Object^  sender, System::EventArgs^  e ) {

		System::Drawing::Bitmap^ bmp = gcnew System::Drawing::Bitmap ( 979, 459 );
		System::Drawing::Graphics^ grBmp = System::Drawing::Graphics::FromImage ( bmp );
		Generic::List<Shape::Shape^>^ list = gcnew Generic::List<Shape::Shape^> ( this->listOfShape );
		for each(Shape::Shape^ shape in list) {
			shape->setGraphic ( grBmp );
		}
		grBmp->Clear ( (System::Drawing::Color) this->canvasBackgroundColor );
		list->ForEach ( gcnew Action<Shape::Shape^> ( &Shape::Shape::draw ) );
		IOxml::SaveToJPG ( bmp );
		setGraphicToList ( this->canvasGraphic );
	}
	private: System::Void setGraphicToList ( System::Drawing::Graphics^ gr ) {
		for each(Shape::Shape^ shape in this->listOfShape) {
			shape->setGraphic ( gr );
		}
		this->existringItemsComboBox->Items->Clear ();
		this->existringItemsComboBox->Items->AddRange ( listOfShape->ToArray () );
	}

	private: System::Void comboBox1_SelectedIndexChanged ( System::Object^  sender, System::EventArgs^  e ) {
		this->selectedItem = (Shape::Shape^)((System::Windows::Forms::ComboBox^) sender)->SelectedItem;
		setEditBox ( this->selectedItem );
	}
	private: void setEditBox ( Shape::Shape^ shape ) {
		this->edit1X->Text = shape->startX.ToString ();
		this->edit1Y->Text = shape->startY.ToString ();
		this->edit2X->Text = shape->endX.ToString ();
		this->edit2Y->Text = shape->endY.ToString ();
		this->editIndex->Text = shape->index.ToString ();
		this->editFilled->Checked = shape->filled;
		this->EditColor->button->BackColor = System::Drawing::Color::FromArgb (shape->colorArgb);
		this->editPenWidth->SelectedItem = shape->penWidth;
	}

	private: System::Void validatePoints ( System::Object^  sender, System::ComponentModel::CancelEventArgs^  e ) {
		System::Windows::Forms::TextBox ^ obj = (System::Windows::Forms::TextBox ^) sender;
		bool valid = validateNumber ( getMaxSizeByLine ( obj ), obj->Text );
		if(!valid) {
			e->Cancel = true;
		}
	}
	private: int getMaxSizeByLine ( System::Windows::Forms::TextBox ^ obj ) {
		if(obj->Name->EndsWith ( "X" )) {
			return this->board->Size.Width;
		}
		else if(obj->Name->EndsWith ( "Y" )) {
			return this->board->Size.Height;
		}
		else {
			return 20;
		}
	}
	private: bool validateNumber ( int max, System::String^ text ) {
		bool out = false;
		try
		{
			int x = Int32::Parse ( text );
			if(x < 0 || x > max) {
				out = false;
				this->errorValidation->SetError ( validatorText, "Wartoœæ Pola wykracza poza zakres 0-" + max );
			}
			else {
				this->errorValidation->SetError ( validatorText, "" );
				out = true;
			}
		}
		catch(System::Exception ^ ex)
		{
			out = false;
		}
		return out;
	}

	private: System::Void clearEditBox () {
		this->edit1X->Text = "";
		this->edit1Y->Text = "";
		this->edit2X->Text = "";
		this->edit2Y->Text = "";
		this->editIndex->Text = "";
	}

	private: System::Void applyEditChange ( System::Object^  sender, System::EventArgs^  e ) {
		this->selectedItem->applyChange (
			this->edit1X->Text,
			this->edit1Y->Text,
			this->edit2X->Text,
			this->edit2Y->Text,
			this->editIndex->Text,
			this->EditColor->button->BackColor.ToArgb (),
			this->editFilled->Checked,
			(this->editPenWidth->SelectedItem)?(int)this->editPenWidth->SelectedItem:3
		);
		drawList ();
	}
private: System::Void filledCheckBox_CheckedChanged ( System::Object^  sender, System::EventArgs^  e ) {
	if(((System::Windows::Forms::CheckBox^)sender)->Checked){
		this->penSize->Visible = false;
	}
	else {
		this->penSize->Visible = true;
	}
}
private: System::Void editFilled_CheckedChanged ( System::Object^  sender, System::EventArgs^  e ) {
	if(((System::Windows::Forms::CheckBox^)sender)->Checked) {
		this->editPenWidth->Visible = false;
	}
	else {
		this->editPenWidth->Visible = true;
	}
}
};
}
