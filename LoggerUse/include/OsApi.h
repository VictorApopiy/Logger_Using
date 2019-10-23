#ifndef _OS_API_H__INCLUDED_
#define _OS_API_H__INCLUDED_
#endif

namespace CDllWorkFuncs
{
	void* LoadDll(const char* pDllName);
	void* GetFuncPtr(void* pDllHandler, const char* FuncName);
	void FreeDll(void* pDllHandler);
}