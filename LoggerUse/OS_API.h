#ifndef OS_API_H__INCLUDED
#define OS_API_H__INCLUDED
#endif

void* LoadDll(const char* pDllName, int& iResult);
void* GetFuncPtr(void* pDllHandler, const char* FuncName, int& iResult);
void FreeDll(void* pDllHandler, int& iResult);