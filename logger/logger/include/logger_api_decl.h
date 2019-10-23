#ifndef _LOGGER_API_DECL_H__INCLUDED_
#define _LOGGER_API_DECL_H__INCLUDED_

#if defined(EXPORT_LOGGER)
#define LOGGERAPI __declspec(dllexport)
#else
#define LOGGERAPI __declspec(dllimport)
#endif

#endif // _LOGGER_API_DECL_H__INCLUDED_