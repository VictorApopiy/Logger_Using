#ifndef _LOGGERAPI_H__INCLUDED_
#define _LOGGERAPI_H__INCLUDED_

#include "iloggerapi.h"

class CLoggerApi : public ILoggerApi
{
public:
	CLoggerApi() {};
	virtual ~CLoggerApi() {};
	virtual void WriteMessage() override;
	virtual void DeleteInstance() override;
};
#endif // _LOGGERAPI_H__INCLUDED_
