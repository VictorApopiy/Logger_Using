#include "pch.h"
#include <stdio.h>
#include "loggerapi.h"
#if defined(LOGGERAPI_H__INCLUDED)
#define LOGGERAPI __declspec(dllexport)
#else
#define LOGGERAPI __declspec(dllimport)
#endif
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