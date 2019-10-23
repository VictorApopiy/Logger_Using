#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "OsApi.h"
#include "framework.h"

void* LoadDll(const char* pDllName)
{
	do
	{
		if (pDllName != NULL)
		{
#ifdef _WIN32
			std::string sDllName = const_cast<char*>(pDllName);
			sDllName = sDllName + ".dll";
			HINSTANCE pDllHandler = LoadLibrary(sDllName.c_str());
#elif defined __linux
			std::string sDllName = const_cast<char*>(pDllName);;
			sDllName = sDllName + ".so";
			void* pDllHandler = dlopen(sDllName.c_str());
#endif

			if (pDllHandler != NULL)
			{
				printf("dll loaded successfully \n");
			}
			else
			{
				printf("dll isn't loaded \n");
				break;
			}
			return pDllHandler;
		}
		else
		{
			printf("pDllName equals NULL \n");
			break;
		}
	} while (false);
		return NULL;
}

void* GetFuncPtr(void* pDllHandler, const char* FuncName)
{
	do
	{
		if (pDllHandler != NULL && FuncName != NULL)
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
				break;
			}
		}
		else
		{
			printf("pDllHandler or FuncName equals NULL \n");
			break;
		}
	} while (false);
		return NULL;
}
void FreeDll(void* pDllHandler)
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