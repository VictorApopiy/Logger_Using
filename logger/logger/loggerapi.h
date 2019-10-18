#pragma once
#include "iloggerapi.h"
class CLoggerApi : public ILoggerApi
{
public:
	CLoggerApi();
	~CLoggerApi();
	virtual void WriteMessage() override;
	virtual void DeleteInstance() override;
};
