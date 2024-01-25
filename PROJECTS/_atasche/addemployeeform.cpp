//---------------------------------------------------------------------------

#include <fmx.h>
#include <fstream>
#pragma hdrstop

#include "AddEmployeeForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TEmployeeAddForm *EmployeeAddForm;
//---------------------------------------------------------------------------
__fastcall TEmployeeAddForm::TEmployeeAddForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TEmployeeAddForm::AddButtonClick(TObject *Sender)
{
	  fstream employeeFile;
	  employeeFile.open("EmployeeData.txt", ios::app);
	  if(employeeFile.is_open())
	  {
		  AnsiString name = EmployeeNameEditAdd->Text;
		  AnsiString Id = EmployeeIdEditAdd->Text;
		  AnsiString Phone = EmployeePhoneEditAdd->Text;
		  AnsiString Department = EmployeeDepartmentEditAdd->Text;

		  employeeFile<<name<<","<<Id<<","<<Phone<<","<<Department<<"\n";
		  employeeFile.close();
          this->Close();

	  }
}
//---------------------------------------------------------------------------

