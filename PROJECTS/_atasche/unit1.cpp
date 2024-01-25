//---------------------------------------------------------------------------

#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
String loggedInEmployeeID ;

void SetLoggedInEmployeeID(String employeeID) {
    loggedInEmployeeID = employeeID;
}

String GetLoggedInEmployeeID() {
   try{
	return loggedInEmployeeID;
   }
   catch (Exception &e) {
        ShowMessage("Error retrieving username: " + e.Message);
        return "";  // or handle the error appropriately
    }
}
#pragma package(smart_init)
