#include <stdio.h>
#include <stdarg.h>
#include <new>
#include "logger_api.h"
#include "logger_api_decl.h"

void CLoggerApi::WriteMessage(const char* szcFormat, ...)
{
	va_list pArgList;
	va_start(pArgList, szcFormat);
	vprintf(szcFormat, pArgList);
	va_end(pArgList);
}

void CLoggerApi::DeleteInstance()
{
	delete this;
}

LOGGERAPI ILoggerApi * CreateLogger()
{
	return new(std::nothrow) CLoggerApi();
}