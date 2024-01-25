//---------------------------------------------------------------------------


#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "FMX.Controls.TControl"
#pragma resource "*.dfm"
TDataModule3 *DataModule3;
String SharedUsername;
String SharedName;
String AdminUsername;
//---------------------------------------------------------------------------
__fastcall TDataModule3::TDataModule3(TComponent* Owner)
	: TDataModule(Owner)
{
}



//---------------------------------------------------------------------------
