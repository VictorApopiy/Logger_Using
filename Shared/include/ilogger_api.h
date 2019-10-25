#ifndef _ILOGGERAPI_H__INCLUDED_
#define _ILOGGERAPI_H__INCLUDED_

class ILoggerApi
{
public:
	ILoggerApi() {};
	virtual ~ILoggerApi() {};
	virtual void WriteMessage(const char* szcFormat, ...) = 0;
	virtual void DeleteInstance() = 0;
};
typedef ILoggerApi* ( *PtrFunc_CreateLogger)();
#endif // _ILOGGERAPI_H__INCLUDED_