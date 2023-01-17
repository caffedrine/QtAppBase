#ifndef _CFG_PORTSSCANNER_H_
#define _CFG_PORTSSCANNER_H_

#include "base/LibCfg.h"
#include "base/app/UserSettings.h"

namespace Services { namespace PortsScanner { namespace Settings
{
    static inline QStringList GetUserDataPaths()
    {
        return  QStringList( UserSettings->Get_UserDataPathAbs());
    }
}}} // Namespaces

#endif // _CFG_PORTSSCANNER_H_
