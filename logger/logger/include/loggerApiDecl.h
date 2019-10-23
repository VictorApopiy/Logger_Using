#if defined(EXPORT_LOGGER)
#define LOGGERAPI __declspec(dllexport)
#else
#define LOGGERAPI __declspec(dllimport)
#endif