#ifndef _SERVICES_PORTSSCANPROFILE_H_
#define _SERVICES_PORTSSCANPROFILE_H_

#include <QString>
#include <QList>
#include <QMap>

#include "PortScanTargetType.h"
#include "base/LibCfg.h"

namespace Services { namespace PortsScanner
{

class DLL_DECL_SPEC PortsScanProfileType
{
public:
    PortsScanProfileType() = default;
    ~PortsScanProfileType()= default;

    QString ProfileName;
    QString DeviceCategoryIfProfileMatch = "ICS";
    bool BuiltInProfile;

    QList<PortsScanTargetType> Targets;

protected:

private:

};

}} // Namespaces

#endif // _SERVICES_PORTSSCANPROFILE_H_
