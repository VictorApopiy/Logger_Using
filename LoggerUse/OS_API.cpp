#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "OS_API.h"
#ifdef _WIN32
#include <Windows.h>
#elif defined __linux
#include
#include <dlfcn.h>
#endif

void* LoadDll(const char* pDllName, int& iResult)
{
#ifdef _WIN32
	std::string dllNameStr = const_cast<char*>(pDllName);
	std::wstring dllNameWStr(dllNameStr.begin(), dllNameStr.end());
	dllNameWStr = dllNameWStr + L".dll";
	HINSTANCE pDllHandler = LoadLibraryW(dllNameWStr.c_str());
#elif defined __linux
	std::string dllNameStr = const_cast<char*>(pDllName);;
	dllNameStr = dllNameStr + ".so";
	void* pDllHandler = dlopen(dllNameStr.c_str());
#endif

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
#ifdef _WIN32
		void* pFuncptr = reinterpret_cast<void*>(GetProcAddress(reinterpret_cast<HINSTANCE>(pDllHandler), FuncName));
#elif defined __linux
		void* pFuncptr = dlsym(pDllHandler, FuncName);
#endif
		if (pFuncptr != NULL)
		{
			printf("Getting a ptr to func is successful \n");
			return pFuncptr;
		}
		else
		{
			printf("Getting func ptr is failed \n");
#ifdef _WIN32
			::FreeLibrary(reinterpret_cast<HINSTANCE>(pDllHandler));
#elif defined __linux
			dlclose(pDllHandler);
#endif
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
#ifdef _WIN32
		::FreeLibrary(reinterpret_cast<HINSTANCE>(pDllHandler));
#elif defined __linux
		dlclose(pDllHandler);
#endif
		pDllHandler = NULL;
		printf("Dll is free! \n");
	}
}