#ifndef LINUXAPI_H__INCLUDEd
#define LINUXAPI_H__INCLUDED
#endif
#ifdef __linux
#include <dlfcn.h>

void* LoadDll(const char* pDllName, int& iResult);
void* GetFuncPtr(void* pDllHandler, const char* FuncName, int& iResult);
void FreeDll(void* pDllHandler, int& iResult);
#endif
