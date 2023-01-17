#ifndef _SERVICES_PORTSSCANPROFILESMANAGER_H_
#define _SERVICES_PORTSSCANPROFILESMANAGER_H_

#include <QObject>

#include "base/LibCfg.h"
#include "base/utils/Singleton.h"
#include "base/services/PortsScanner/PortsScanBuiltInProfiles.h"

namespace Services { namespace PortsScanner
{

class DLL_DECL_SPEC PortsScanProfilesManager: protected QObject, public Singleton<PortsScanProfilesManager>
{
public:
    QList<PortsScanProfileType> GetAll();
    PortsScanProfileType GetByName(QString profile_name);

protected:

private:

};

}} // Namespaces

#endif // _SERVICES_PORTSSCANPROFILESMANAGER_H_
