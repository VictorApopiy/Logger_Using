// LoggerUse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <Windows.h>
#include "iloggerapi.h"

int main()
{
	do
	{
		int IResult = 0;
		HINSTANCE dll_handler;
		dll_handler = LoadLibrary(TEXT("logger.dll"));
		if (dll_handler != NULL)
		{
			printf("dll loaded successfully \n");
			IloggerApi_factory LoggerApiInit = (IloggerApi_factory)::GetProcAddress((HMODULE)dll_handler, "CreateLogger");
			if (LoggerApiInit != NULL)
			{
				printf("Getting a ptr to func is successful \n");
				ILoggerApi* pinstance = LoggerApiInit();
				pinstance->WriteMessage();
				pinstance->DeleteInstance();
			}
			else
			{
				printf("Getting func ptr is failed \n");
				::FreeLibrary(dll_handler);
				IResult = 1;
				break;
			}
			::FreeLibrary(dll_handler);
		}
		else
		{
			printf("dll isn't loaded \n");
			IResult = 1;
			break;
		}
		return IResult;
	} 
	while (true);
}

