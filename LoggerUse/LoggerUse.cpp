// LoggerUse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include "iloggerapi.h"
#include "OS_API.h"

int main()
{
	do
	{
		int iResult = 0;
		void* pDllHandler = LoadDll("logger", iResult);
		IloggerApi_factory LoggerApiInit = reinterpret_cast<IloggerApi_factory>(GetFuncPtr(pDllHandler, "CreateLogger", iResult));
		ILoggerApi* pinstance = LoggerApiInit();
		if (pinstance == NULL)
		{
			printf("LoggerAppInit returned nullptr \n");
			break;
		}
		pinstance->WriteMessage();
		pinstance->DeleteInstance();
		pinstance = NULL;
		FreeDll(pDllHandler, iResult);
		return iResult;
	} 
	while (true);
}

