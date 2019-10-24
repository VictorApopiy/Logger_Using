#ifndef _OS_API_H__INCLUDED_
#define _OS_API_H__INCLUDED_

namespace DllWorkFuncs
{
	void* LoadDll(const char* szcDllName);
	void* GetFuncPtr(void* pDllHandler, const char* szcFuncName);
	void FreeDll(void* pDllHandler);
}
#endif // _OS_API_H__INCLUDED_