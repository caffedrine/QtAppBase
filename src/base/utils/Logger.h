#ifndef _BASE_LOGGER_H_
#define _BASE_LOGGER_H_

#ifdef QT_WIDGETS_ENABLED
    #include <QPlainTextEdit>
#endif

#include <base/LibCfg.h>
#include <spdlog/spdlog.h>

namespace base
{
	/* Logger instance - multi-threaded */
    DLL_DECL_SPEC
    extern spdlog::logger *logger;

#ifdef QT_WIDGETS_ENABLED
	/* Logger viewer inside application */
    DLL_DECL_SPEC
    extern QPlainTextEdit *loggerContentGui;
#endif

    DLL_DECL_SPEC
    void setup_logger(bool consoleMode);
}
#endif // _BASE_LOGGER_H_