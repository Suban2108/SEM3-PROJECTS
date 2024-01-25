//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("LoginForm.cpp", Login);
USEFORM("TaskListEmployee.cpp", TaskList);
USEFORM("Unit3.cpp", DataModule3); /* TDataModule: File Type */
USEFORM("Unit4.cpp", EmployeeProfile);
USEFORM("AdminRegistrationFrom.cpp", AdminRegistrationForm);
USEFORM("HomePage.cpp", DataPage);
USEFORM("AdminProfile.cpp", Form5);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TLogin), &Login);
		Application->CreateForm(__classid(TDataPage), &DataPage);
		Application->CreateForm(__classid(TTaskList), &TaskList);
		Application->CreateForm(__classid(TAdminRegistrationForm), &AdminRegistrationForm);
		Application->CreateForm(__classid(TDataModule3), &DataModule3);
		Application->CreateForm(__classid(TEmployeeProfile), &EmployeeProfile);
		Application->CreateForm(__classid(TForm5), &Form5);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
