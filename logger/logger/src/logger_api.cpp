#include <stdio.h>
#include "logger_api.h"
#include "logger_api_decl.h"

void CLoggerApi::WriteMessage()
{
	printf("Hello, World! \n");
}

void CLoggerApi::DeleteInstance()
{
	delete this;
}

extern "C" LOGGERAPI ILoggerApi * __cdecl CreateLogger()
{
	return new CLoggerApi();
}