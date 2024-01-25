//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "EmloginBetween.h"
#include "TaskListEmployee.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ShowTasksClick(TObject *Sender)
{
   String Username = GetLoggedInEmployeeID();
   FDQuery2->SQL->Text = "SELECT Tasks FROM Employee  WHERE Username = :Username";
   FDQuery2->ParamByName("Username")->DataType = ftString; // Specify the data type as string
   FDQuery2->ParamByName("Username")->Value = Username;
	FDQuery2->Open();
	while (!FDQuery2->Eof) {
		String task = FDQuery2->FieldByName("Tasks")->AsString;
		ListBox->Items->Add(task);
	}

    TaskList->Show();
}
//---------------------------------------------------------------------------
