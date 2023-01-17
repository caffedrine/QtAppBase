#ifndef CRYPTOPOCKETKNIFE_X509CERTIFICATE_H
#define CRYPTOPOCKETKNIFE_X509CERTIFICATE_H

#include <QString>
#include <QByteArray>

#include "base/LibCfg.h"

class DLL_DECL_SPEC X509Certificate
{

};

namespace Core { namespace Crypto { namespace x509 {
    DLL_DECL_SPEC QString GetCertHumanReadableFormat(const QByteArray &certBytes);

}}} //  namespaces


#endif //CRYPTOPOCKETKNIFE_X509CERTIFICATE_H
