#ifndef _BASE_LOGGER_H_
#define _BASE_LOGGER_H_

#include <QPlainTextEdit>
#include <base/LibCfg.h>
#include <spdlog/spdlog.h>

namespace base
{
	/* Logger instance - multi-threaded */
    DLL_DECL_SPEC
    extern spdlog::logger *logger;

	/* Logger viewer inside application */
    DLL_DECL_SPEC
    extern QPlainTextEdit *loggerContentGui;

    DLL_DECL_SPEC
    void setup_logger(bool consoleMode);
}
#endif // _BASE_LOGGER_H_