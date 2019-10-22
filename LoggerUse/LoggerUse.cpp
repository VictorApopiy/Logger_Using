// LoggerUse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include "iloggerapi.h"

#ifdef _WIN32
	#include "WindowsAPI.h"
#else
	#include "LinuxAPI.h"
#endif
int main()
{
	do
	{
		int iResult = 0;
		void* pDllHandler = LoadDll(L"logger", iResult);
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

