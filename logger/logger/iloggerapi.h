#ifndef ILOGGERAPI_H__INCLUDED
#define ILOGGERAPI_H__INCLUDED
class ILoggerApi
{
public:
	ILoggerApi() {};
	virtual ~ILoggerApi() {};
	virtual void WriteMessage() = 0;
	virtual void DeleteInstance() = 0;
};
typedef ILoggerApi* (__cdecl* ILoggerApiFactory)();
#endif