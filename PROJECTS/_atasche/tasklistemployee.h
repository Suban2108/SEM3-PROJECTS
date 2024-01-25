//---------------------------------------------------------------------------

#ifndef TaskListEmployeeH
#define TaskListEmployeeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Colors.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Edit.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.FMXUI.Wait.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.SQLite.hpp>
#include <FireDAC.Phys.SQLiteDef.hpp>
#include <FireDAC.Phys.SQLiteWrapper.Stat.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.ExprFuncs.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Media.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Ani.hpp>
//---------------------------------------------------------------------------
class TTaskList : public TForm
{
__published:	// IDE-managed Components
	TFDConnection *Sqlite_demoConnection;
	TFDQuery *FDQuery2;
	TImage *Z;
	TLabel *Label2;
	TLabel *Label3;
	TSpeedButton *AddTaskButton;
	TSpeedButton *LogoutButton;
	TEdit *AddTaskEdit;
	TListBox *ListBox;
	TListBox *ListComp;
	TLabel *LabelCompleted;
	TSpeedButton *ShowAssignedTasksButton;
	TColorBox *ColorBox1;
	TColorBox *ColorBox2;
	TLabel *Label1;
	void __fastcall LogoutButtonClick(TObject *Sender);
	void __fastcall AddTaskButtonClick(TObject *Sender);
	void __fastcall ListBoxItemClick(TCustomListBox * const Sender, TListBoxItem * const Item);
	void __fastcall ShowAssignedTasksButtonClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);

private:	// User declarations
     AnsiString FUsername;
public:		// User declarations
	__fastcall TTaskList(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TTaskList *TaskList;
//---------------------------------------------------------------------------
#endif
