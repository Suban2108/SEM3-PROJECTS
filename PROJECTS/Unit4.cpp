//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit4.h"
#include "TaskListEmployee.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TEmployeeProfile *EmployeeProfile;
//---------------------------------------------------------------------------
__fastcall TEmployeeProfile::TEmployeeProfile(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TEmployeeProfile::TaskListButtonClick(TObject *Sender)
{
	TaskList->Show();

}
//---------------------------------------------------------------------------
void __fastcall TEmployeeProfile::FormShow(TObject *Sender)
{
		String Email,Phone,Department,usernameEmployee;
        usernameEmployee = SharedUsername;
    	try {
		// Set up the SQL query to check user credentials.
		FDQuery1->SQL->Text = "SELECT * FROM Employee WHERE Username = :username";
		FDQuery1->Params->ParamByName("username")->Value = usernameEmployee;


		// Execute the query.
		FDQuery1->Open();

		// Check if a matching record was found.
		if (!FDQuery1->Eof) {
			// Login successful; show the next form or perform other actions.
			SharedName = FDQuery1->FieldByName("Name")->AsString;
			Email = FDQuery1->FieldByName("Email")->AsString;
			Phone = FDQuery1->FieldByName("Phone")->AsString;
			Department = FDQuery1->FieldByName("Department")->AsString;

		}

		}
	 catch (Exception &e) {
        ShowMessage("Error: " + e.Message);
	}
	FDQuery1->Close();

	NameLabel->Text = "Name: " + SharedName;
	EmailLabel->Text = "Email: " + Email;
	ContactLabel->Text = "Contact: " + Phone;
    DepartmentLabel->Text = "Department: " + Department;



}
//---------------------------------------------------------------------------
