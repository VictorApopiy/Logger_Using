#ifndef LOGGERAPI_H__INCLUDED
#define LOGGERAPI_H__INCLUDED

#include "iloggerapi.h"

class CLoggerApi : public ILoggerApi
{
public:
	CLoggerApi() {};
	virtual ~CLoggerApi() {};
	virtual void WriteMessage() override;
	virtual void DeleteInstance() override;
};
#endif
