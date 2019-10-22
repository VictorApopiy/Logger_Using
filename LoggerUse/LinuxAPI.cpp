#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#ifdef __linux

#include"LinuxAPI.h"

void* LoadDll(const char* pDllName, int& iResult)
{
	std::string dllNameStr = const_cast<char*>(pDllName);;
	dllNameStr = dllNameStr + ".dll";
	void* pDllHandler = dlopen(dllNameStr.c_str());
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
		void* pFuncptr = dlsym(pDllHandler, FuncName);
		if (pFuncptr != NULL)
		{
			printf("Getting a ptr to func is successful \n");
			return pFuncptr;
		}
		else
		{
			printf("Getting func ptr is failed \n");
			dlclose(pDllHandler);
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
		dlclose(pDllHandler);
		pDllHandler = NULL;
		printf("Dll is free! \n");
	}
}
#endif // __linux