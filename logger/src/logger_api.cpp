#include <stdio.h>
#include <stdarg.h>
#include "logger_api.h"
#include "logger_api_decl.h"

void CLoggerApi::WriteMessage(const char* pFormat, ...)
{
	va_list pArgList;
	va_start(pArgList, pFormat);
	vprintf(pFormat, pArgList);
	va_end(pArgList);
}

void CLoggerApi::DeleteInstance()
{
	delete this;
}

extern "C" LOGGERAPI ILoggerApi * __cdecl CreateLogger()
{
	return new CLoggerApi();
}