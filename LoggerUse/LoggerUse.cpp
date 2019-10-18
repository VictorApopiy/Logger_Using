// LoggerUse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <Windows.h>
#include "iloggerapi.h"

int main()
{
	do
	{
		int iResult = 0;
		HINSTANCE pDllHandler = LoadLibrary(TEXT("logger.dll"));
		if (pDllHandler != NULL)
		{
			printf("dll loaded successfully \n");
			IloggerApi_factory LoggerApiInit = reinterpret_cast<IloggerApi_factory>(::GetProcAddress(pDllHandler, "CreateLogger"));
			if (LoggerApiInit != NULL)
			{
				printf("Getting a ptr to func is successful \n");
				ILoggerApi* pinstance = LoggerApiInit();
				if (pinstance == NULL)
				{
					printf("LoggerAppInit returned nullptr \n");
					break;
				}
				pinstance->WriteMessage();
				pinstance->DeleteInstance();
				pinstance = NULL;
			}
			else
			{
				printf("Getting func ptr is failed \n");
				::FreeLibrary(pDllHandler);
				iResult = 1;
				break;
			}
			::FreeLibrary(pDllHandler);
		}
		else
		{
			printf("dll isn't loaded \n");
			iResult = 1;
			break;
		}
		if (pDllHandler != NULL)
		{
			::FreeLibrary(pDllHandler);
		}
		return iResult;
	} 
	while (true);
}

