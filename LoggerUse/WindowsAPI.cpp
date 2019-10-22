#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include "WindowsAPI.h"

void* LoadDll(const wchar_t* pDllName, int& iResult)
{
	std::wstring dllNameStr = const_cast<wchar_t*>(pDllName);;
	dllNameStr = dllNameStr + L".dll";
	HINSTANCE pDllHandler = LoadLibrary(dllNameStr.c_str());
	if (pDllHandler != NULL)
	{
		printf("dll loaded successfully \n");
	}
	else
	{
		printf("dll isn't loaded \n");
		iResult = 1;
	}
	return pDllHandler;
}

void* GetFuncPtr(void* pDllHandler, const char* FuncName, int& iResult)
{
	if (pDllHandler != NULL)
	{
		void* pFuncptr = reinterpret_cast<void*>(GetProcAddress(reinterpret_cast<HINSTANCE>(pDllHandler), FuncName));
		if (pFuncptr != NULL)
		{
			printf("Getting a ptr to func is successful \n");
			return pFuncptr;
		}
		else
		{
			printf("Getting func ptr is failed \n");
			::FreeLibrary(reinterpret_cast<HINSTANCE>(pDllHandler));
			iResult = 1;
			return NULL;
		}
	}
	else
	{
		iResult = 1;
		return NULL;
	}
}
void FreeDll(void* pDllHandler, int& iResult)
{
	if (pDllHandler != NULL)
	{
		::FreeLibrary(reinterpret_cast<HINSTANCE>(pDllHandler));
		pDllHandler = NULL;
		printf("Dll is free! \n");
	}
}
#endif // _WIN32