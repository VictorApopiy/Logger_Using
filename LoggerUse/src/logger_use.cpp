// LoggerUse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include "ilogger_api.h"
#include "os_api.h"

int main()
{
	void* pDllHandler = NULL;
	do
	{
		pDllHandler = DllWorkFuncs::LoadDll("logger");
		if (pDllHandler == NULL)
		{
			printf("Dll is not loaded \n");
			break;
		}
		void* pLoggerCreator = DllWorkFuncs::GetFuncPtr(pDllHandler, "CreateLogger");
		if (pLoggerCreator == NULL)
		{
			printf("LoggerCreator returned NULL \n");
			break;
		}
		PtrFunc_CreateLogger pFunc_LoggerApiInit = reinterpret_cast<PtrFunc_CreateLogger>(pLoggerCreator);
		if (pFunc_LoggerApiInit == NULL)
		{
			printf("LoggerAppInit returned NULL \n");
			break;
		}
		ILoggerApi* pInstance = pFunc_LoggerApiInit();
		if (pInstance == NULL)
		{
			printf("pinstance returned NULL \n");
			break;
		}
		pInstance->WriteMessage("%s  %s  %s   %s   %s \n", "aa", "bb", "cc", "dd", "ee");
		pInstance->DeleteInstance();
		pInstance = NULL;
	} 
	while (false);
	DllWorkFuncs::FreeDll(pDllHandler);
	pDllHandler = NULL;
	return 0;
}

