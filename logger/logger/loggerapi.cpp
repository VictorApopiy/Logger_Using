#include "pch.h"
#include <stdio.h>
#include "loggerapi.h"

CLoggerApi::CLoggerApi()
{

}

CLoggerApi::~CLoggerApi()
{

}

void CLoggerApi::WriteMessage()
{
	printf("Hello, World! \n");
}

void CLoggerApi::DeleteInstance()
{
	delete this;
}

extern "C" __declspec(dllexport) ILoggerApi * __cdecl CreateLogger()
{
	return new CLoggerApi();
}