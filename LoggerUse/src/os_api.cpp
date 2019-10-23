#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "framework.h"
#include "os_api.h"

void* DllWorkFuncs::LoadDll(const char* pDllName)
{
#ifdef _WIN32
#define LIBRARY_EXTENSION ".dll"
#elif defined __linux
#define LIBRARY_EXTENSION ".so";
#endif
	HINSTANCE pDllHandler = NULL;
	do
	{
		if (pDllName == NULL)
		{
			printf("pDllName equals NULL \n");
			break;
		}
		std::string sDllName = pDllName;
		sDllName += LIBRARY_EXTENSION;
#ifdef _WIN32
		pDllHandler = static_cast<HINSTANCE>(LoadLibrary(sDllName.c_str()));
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

void* DllWorkFuncs::GetFuncPtr(void* pDllHandler, const char* FuncName)
{
	void* pFuncptr = NULL;
	do
	{
		if (pDllHandler == NULL && FuncName == NULL)
		{
			printf("pDllHandler or FuncName equals NULL \n");
			break;
		}
#ifdef _WIN32
		pFuncptr = reinterpret_cast<void*>(GetProcAddress(reinterpret_cast<HINSTANCE>(pDllHandler), FuncName));
#elif defined __linux
		pFuncptr = dlsym(pDllHandler, FuncName);
#endif
		if (pFuncptr == NULL)
		{
			printf("Getting func ptr is failed \n");
			FreeDll(pDllHandler);
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