#include <fmx.h>
#pragma hdrstop
#include "TaskListEmployee.h"
#include "LoginForm.h"

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TTaskList *TaskList;

//---------------------------------------------------------------------------
__fastcall TTaskList::TTaskList(TComponent* Owner)
	: TForm(Owner)
{

}


//---------------------------------------------------------------------------


void __fastcall TTaskList::LogoutButtonClick(TObject *Sender)
{
   this->Hide();
   Login->Show();
}



void __fastcall TTaskList::AddTaskButtonClick(TObject *Sender)
{
	String taskText = AddTaskEdit->Text;
	ListBox->Items->Add(taskText);
	AddTaskEdit->Text="";

}
//---------------------------------------------------------------------------

void __fastcall TTaskList::ListBoxItemClick(TCustomListBox * const Sender, TListBoxItem * const Item)

{

	int index = Item->Index;

	UnicodeString selectedItemText = ListBox->Items->Strings[ListBox->ItemIndex];
	ListBox->Items->Delete(index);
	ListComp->Items->Add(selectedItemText);
}


//---------------------------------------------------------------------------


void __fastcall TTaskList::ShowAssignedTasksButtonClick(TObject *Sender)
{
	
	String Username = SharedUsername;

	String task;
	 try {
        // Ensure the database connection is active.
		Sqlite_demoConnection->Connected = true;
		FDQuery2->SQL->Text = "SELECT Tasks FROM Employee WHERE Username = :Username";
		FDQuery2->Params->ParamByName("Username")->DataType = ftString;
		FDQuery2->Params->ParamByName("Username")->Value = Username;
		FDQuery2->Open();
		while (!FDQuery2->Eof) {
		task = FDQuery2->FieldByName("Tasks")->AsString;
		ListBox->Items->Add(task);
		FDQuery2->Next();
	}
        


	 }
	 catch (Exception &e) {
        // Display an error message if an exception occurs.
        ShowMessage("Error: " + e.Message);
	}
      Sqlite_demoConnection->Connected = false;
}
//---------------------------------------------------------------------------





void __fastcall TTaskList::FormShow(TObject *Sender)
{
   Label1->Text =  "Welcome Back, "  + SharedName;
}
//---------------------------------------------------------------------------

