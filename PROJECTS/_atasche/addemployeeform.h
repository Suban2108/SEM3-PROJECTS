//---------------------------------------------------------------------------

#ifndef AddEmployeeFormH
#define AddEmployeeFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Colors.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
//---------------------------------------------------------------------------
class TEmployeeAddForm : public TForm
{
__published:	// IDE-managed Components
	TColorBox *ColorBox1;
	TLabel *Label1;
	TColorBox *ColorBox2;
	TLabel *Label2;
	TEdit *EmployeeNameEditAdd;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *EmployeePhoneEditAdd;
	TEdit *EmployeeIdEditAdd;
	TEdit *EmployeeDepartmentEditAdd;
	TSpeedButton *AddButton;
	void __fastcall AddButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TEmployeeAddForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TEmployeeAddForm *EmployeeAddForm;
//---------------------------------------------------------------------------
#endif
