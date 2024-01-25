//---------------------------------------------------------------------------

#ifndef AdminRegistrationFromH
#define AdminRegistrationFromH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Colors.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Comp.UI.hpp>
#include <FireDAC.FMXUI.Wait.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.Phys.SQLite.hpp>
#include <FireDAC.Phys.SQLiteDef.hpp>
#include <FireDAC.Phys.SQLiteWrapper.Stat.hpp>
#include <FireDAC.Stan.ExprFuncs.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.DBScope.hpp>
#include <Data.Bind.EngExt.hpp>
#include <Data.Bind.Grid.hpp>
#include <Fmx.Bind.DBEngExt.hpp>
#include <Fmx.Bind.Editors.hpp>
#include <Fmx.Bind.Grid.hpp>
#include <FMX.Grid.hpp>
#include <FMX.Grid.Style.hpp>
#include <FMX.ScrollBox.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
#include <FireDAC.Phys.MySQL.hpp>
#include <FireDAC.Phys.MySQLDef.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
//---------------------------------------------------------------------------
class TAdminRegistrationForm : public TForm
{
__published:	// IDE-managed Components
	TColorBox *ColorBox1;
	TLabel *Label1;
	TEdit *NameEditAdminR;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *UsernameEditAdminR;
	TLabel *Label5;
	TEdit *PasswordEditAdminR;
	TEdit *EmailEditAdminR;
	TSpeedButton *RegisterButton;
	TLabel *Label4;
	TFDConnection *Sqlite_demoConnection;
	TFDQuery *AdminTable;
	TFDQuery *FDQuery1;
	TLabel *Label6;
	TEdit *IdEditAdminR;
	TSQLQuery *SQLQuery1;
	void __fastcall RegisterButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TAdminRegistrationForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAdminRegistrationForm *AdminRegistrationForm;
//---------------------------------------------------------------------------
#endif
