#ifndef OS_API_H__INCLUDED
#define OS_API_H__INCLUDED
#endif

void* LoadDll(const char* pDllName);
void* GetFuncPtr(void* pDllHandler, const char* FuncName);
void FreeDll(void* pDllHandler);