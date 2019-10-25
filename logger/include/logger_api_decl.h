#ifndef _LOGGER_API_DECL_H__INCLUDED_
#define _LOGGER_API_DECL_H__INCLUDED_
#ifdef WIN32
#if defined(EXPORT_LOGGER)
#define LOGGERAPI extern "C" __declspec(dllexport)
#else
#define LOGGERAPI extern "C" __declspec(dllimport)
#endif

#else
#if defined(EXPORT_LOGGER)
#define LOGGERAPI extern "C"
#endif

#endif

#endif // _LOGGER_API_DECL_H__INCLUDED_