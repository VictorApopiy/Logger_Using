#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "framework.h"
#include "os_api.h"
#ifdef _WIN32
#define LIBRARY_EXTENSION ".dll"
#elif defined __linux
#define LIBRARY_EXTENSION ".so";
#endif

void* DllWorkFuncs::LoadDll(const char* szcDllName)
{
	void* pDllHandler = NULL;
	do
	{
		if (szcDllName == NULL)
		{
			printf("pDllName equals NULL \n");
			break;
		}
		std::string sDllName = szcDllName;
		sDllName += LIBRARY_EXTENSION;
#ifdef _WIN32
		pDllHandler = static_cast<void*>(LoadLibrary(sDllName.c_str()));
#elif defined __linux
		pDllHandler = dlopen(sDllName.c_str());
#endif
		if (pDllHandler == NULL)
		{
			printf("dll isn't loaded \n");
			break;
		}
		printf("dll loaded successfully \n");
	} 
	while (false);
	return pDllHandler;
}

void* DllWorkFuncs::GetFuncPtr(void* pDllHandler, const char* szcFuncName)
{
	void* pFuncptr = NULL;
	do
	{
		if (pDllHandler == NULL)
		{
			printf("pDllHandler equals NULL \n");
			break;
		}
		if(szcFuncName == NULL)
		{
			printf("FuncName equals NULL \n");
			break;
		}
#ifdef _WIN32
		pFuncptr = reinterpret_cast<void*>(GetProcAddress(reinterpret_cast<HINSTANCE>(pDllHandler), szcFuncName));
#elif defined __linux
		pFuncptr = dlsym(pDllHandler, FuncName);
#endif
		if (pFuncptr == NULL)
		{
			printf("Getting func ptr to %s is failed \n", szcFuncName);
			break;
		}
		printf("Getting a ptr to func is successful \n");
	} 
	while (false);
	return pFuncptr;
}
void DllWorkFuncs::FreeDll(void* pDllHandler)
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