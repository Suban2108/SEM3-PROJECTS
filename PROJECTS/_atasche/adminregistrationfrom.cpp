//---------------------------------------------------------------------------

#include <fmx.h>
#include <string>
#include <FireDAC.Phys.SQLite.hpp>
#include <FireDAC.UI.Intf.hpp>



#pragma hdrstop

#include "AdminRegistrationFrom.h"
#include "Vcl.Bind.Consts.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TAdminRegistrationForm *AdminRegistrationForm;
//---------------------------------------------------------------------------
__fastcall TAdminRegistrationForm::TAdminRegistrationForm(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------





void __fastcall TAdminRegistrationForm::RegisterButtonClick(TObject *Sender)
{
    String name = NameEditAdminR->Text;
	String Username = UsernameEditAdminR->Text;
	String Email =  EmailEditAdminR->Text;
	String Password = PasswordEditAdminR->Text;
	String Id =  IdEditAdminR->Text;

    try {
        // Ensure the database connection is active.
        Sqlite_demoConnection->Connected = true;

		// Construct the SQL INSERT statement.
		FDQuery1->SQL->Text = "INSERT INTO Admin (Name, Username,Email,Password,Id) VALUES (:value1, :value2,:value3,:value4,:value5)";
        FDQuery1->Params->ParamByName("value1")->Value = name;
		FDQuery1->Params->ParamByName("value2")->Value = Username;
		FDQuery1->Params->ParamByName("value3")->Value = Email;
		FDQuery1->Params->ParamByName("value4")->Value = Password;
        FDQuery1->Params->ParamByName("value5")->Value = Id;

        // Execute the SQL INSERT statement.
        FDQuery1->ExecSQL();
		ShowMessage(" Registration Successfull. "); // Display a success message.
	} catch (Exception &e) {
        // Display an error message if an exception occurs.
        ShowMessage("Error: " + e.Message);
    }

    // Deactivate the query and close the connection when done.
    Sqlite_demoConnection->Connected = false;
}
//---------------------------------------------------------------------------


