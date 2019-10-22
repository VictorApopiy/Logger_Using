// LoggerUse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include "iloggerapi.h"
#include "OsApi.h"

int main()
{
	do
	{
		void* pDllHandler = LoadDll("logger");
		ILoggerApiFactory LoggerApiInit = reinterpret_cast<ILoggerApiFactory>(GetFuncPtr(pDllHandler, "CreateLogger"));
		if (LoggerApiInit != NULL)
		{
			ILoggerApi* pInstance = LoggerApiInit();
			if (pInstance == NULL)
			{
				printf("LoggerAppInit returned nullptr \n");
				break;
			}
			pInstance->WriteMessage();
			pInstance->DeleteInstance();
			pInstance = NULL;
			FreeDll(pDllHandler);
			return 0;
		}
	} 
	while (false);
	return 1;
}

