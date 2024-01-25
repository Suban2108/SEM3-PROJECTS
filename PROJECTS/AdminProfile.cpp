//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "AdminProfile.h"
#include "Unit3.h"
#include "HomePage.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm5::FormShow(TObject *Sender)
{
		String Name,Id,Email;
		String username = AdminUsername;
        try {
		// Set up the SQL query to check user credentials.
		FDQuery1->SQL->Text = "SELECT * FROM Admin WHERE Username = :username";
		FDQuery1->Params->ParamByName("username")->Value = username;


		// Execute the query.
		FDQuery1->Open();

		// Check if a matching record was found.
		if (!FDQuery1->Eof) {
			// Login successful; show the next form or perform other actions.
			Name = FDQuery1->FieldByName("Name")->AsString;
			Email = FDQuery1->FieldByName("Email")->AsString;
			Id = FDQuery1->FieldByName("Id")->AsString;


		}

		}
	 catch (Exception &e) {
        ShowMessage("Error: " + e.Message);
	}
	FDQuery1->Close();
	NameLabel->Text = "Welcome Back, " + Name ;
	EmailLabel->Text = "Email: " + Email;
    IdLabel->Text = "Id: " + Id;

}
//---------------------------------------------------------------------------
void __fastcall TForm5::DataButtonClick(TObject *Sender)
{
    DataPage->Show();
}
//---------------------------------------------------------------------------

