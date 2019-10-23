#ifndef _ILOGGERAPI_H__INCLUDED_
#define _ILOGGERAPI_H__INCLUDED_
class ILoggerApi
{
public:
	ILoggerApi() {};
	virtual ~ILoggerApi() {};
	virtual void WriteMessage() = 0;
	virtual void DeleteInstance() = 0;
};
typedef ILoggerApi* (__cdecl* ILoggerApiFactory)();
#endif // _ILOGGERAPI_H__INCLUDED_