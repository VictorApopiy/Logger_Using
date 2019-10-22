#ifndef WINDOWSAPI_H__INCLUDEd
#define WINDOWSAPI_H__INCLUDED
#endif
#ifdef _WIN32
#include <Windows.h>

void* LoadDll(const wchar_t* pDllName, int& iResult);
void* GetFuncPtr(void* pDllHandler, const char* FuncName, int& iResult);
void FreeDll(void* pDllHandler, int& iResult);
#endif