#pragma once

class ILoggerApi
{
public:
	ILoggerApi() {};
	virtual ~ILoggerApi() {};
	virtual void WriteMessage() = 0;
	virtual void DeleteInstance() = 0;
};