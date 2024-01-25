//---------------------------------------------------------------------------

#include <fmx.h>

#pragma hdrstop

#include "LoginForm.h"
#include "HomePage.h"
#include "AdminRegistrationFrom.h"
#include "TaskListEmployee.h"
#include "Vcl.Bind.Consts.hpp"
#include "Unit3.h"
#include "Unit4.h"
#include "AdminProfile.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TLogin *Login;

//---------------------------------------------------------------------------
__fastcall TLogin::TLogin(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TLogin::LoginButtonAClick(TObject *Sender)
{
    String username = UsernameAdminEdit->Text;
	String password = PasswordEdit->Text;
    AdminUsername = username;

    try {
        // Set up the SQL query to check user credentials.
		FDQuery1->SQL->Text = "SELECT * FROM Admin WHERE Username = :username AND Password = :password";
        FDQuery1->Params->ParamByName("username")->Value = username;
        FDQuery1->Params->ParamByName("password")->Value = password;

        // Execute the query.
        FDQuery1->Open();

        // Check if a matching record was found.
        if (!FDQuery1->Eof) {
            // Login successful; show the next form or perform other actions.
            ShowMessage("Login successful!");
			// Open the next form:
			Form5->Show();
        } else {
            // Login failed; display an error message.
            ShowMessage("Login failed. Please check your username and password.");
		}

    } catch (Exception &e) {
        ShowMessage("Error: " + e.Message);
	}
	FDQuery1->Close();
	UsernameAdminEdit->Text="";
	PasswordEdit->Text="";

}



//---------------------------------------------------------------------------

void __fastcall TLogin::RegisterButtonClick(TObject *Sender)
{
     AdminRegistrationForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TLogin::LoginButtonBClick(TObject *Sender)
{

   String usernameEmployee = EmployeeUsernameEdit->Text;
   SharedUsername = usernameEmployee;


	try {
		// Set up the SQL query to check user credentials.
		FDQuery2->SQL->Text = "SELECT * FROM Employee WHERE Username = :username";
		FDQuery2->Params->ParamByName("username")->Value = usernameEmployee;


        // Execute the query.
		FDQuery2->Open();

        // Check if a matching record was found.
		if (!FDQuery2->Eof) {
			// Login successful; show the next form or perform other actions.
            SharedName = FDQuery2->FieldByName("Name")->AsString;
            ShowMessage("Login successful!");
			// Open the next form:

			EmployeeProfile->Show();
        } else {
            // Login failed; display an error message.
			ShowMessage("Login failed. Please check your username provided by the company.");
        }
    } catch (Exception &e) {
        ShowMessage("Error: " + e.Message);
	}
	FDQuery2->Close();
    EmployeeUsernameEdit->Text = "";






}
//---------------------------------------------------------------------------



