// LoggerUse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <Windows.h>
#include "iloggerapi.h"
typedef ILoggerApi* (__cdecl* IloggerApi_factory)();

int main()
{
	HINSTANCE dll_handler;
	dll_handler = LoadLibrary(TEXT("logger.dll"));
	if (dll_handler != NULL)
	{
		printf("dll loaded successfully \n");
		IloggerApi_factory LoggerApiInit = (IloggerApi_factory)::GetProcAddress((HMODULE)dll_handler, "CreateLogger");
		if (LoggerApiInit != NULL)
		{
			printf ("Getting a ptr to func is successful \n");
			ILoggerApi* pinstance = LoggerApiInit();
			pinstance->WriteMessage();
			pinstance->DeleteInstance();
		}
		else
		{
			printf("Getting func ptr is failed \n");
			::FreeLibrary(dll_handler);
			return 1;
		}
		::FreeLibrary(dll_handler);
	}
	else
	{
		printf("dll isn't loaded \n");
		return 1;
	}
	return 0;
}

