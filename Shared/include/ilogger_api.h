#ifndef _ILOGGERAPI_H__INCLUDED_
#define _ILOGGERAPI_H__INCLUDED_
#define EXPORT_LOGGER
class ILoggerApi
{
public:
	ILoggerApi() {};
	virtual ~ILoggerApi() {};
	virtual void WriteMessage(const char* pFormat, ...) = 0;
	virtual void DeleteInstance() = 0;
};
typedef ILoggerApi* (__cdecl PtrFunc_CreateLogger)();
#endif // _ILOGGERAPI_H__INCLUDED_