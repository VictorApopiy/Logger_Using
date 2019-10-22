#include <stdio.h>
#include "loggerapi.h"
#include "loggerApiDecl.h"

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