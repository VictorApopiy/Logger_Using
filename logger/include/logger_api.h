#ifndef _LOGGERAPI_H__INCLUDED_
#define _LOGGERAPI_H__INCLUDED_

#include "ilogger_api.h"

class CLoggerApi : public ILoggerApi
{
public:
	CLoggerApi() {};
	virtual ~CLoggerApi() {};
	virtual void WriteMessage(const char* pFormat, ...) override;
	virtual void DeleteInstance() override;
};
#endif // _LOGGERAPI_H__INCLUDED_
