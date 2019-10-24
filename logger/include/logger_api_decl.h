#ifndef _LOGGER_API_DECL_H__INCLUDED_
#define _LOGGER_API_DECL_H__INCLUDED_

#if defined(EXPORT_LOGGER)
#define LOGGERAPI extern "C" __declspec(dllexport)
#else
#define LOGGERAPI extern "C" __declspec(dllimport)
#endif

#endif // _LOGGER_API_DECL_H__INCLUDED_