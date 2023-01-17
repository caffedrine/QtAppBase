#ifndef _NETWORKUTILS_H_
#define _NETWORKUTILS_H_

#include <QString>
#include <QStringList>
#include "base/LibCfg.h"

namespace utils { namespace network
{
    namespace ipv4
    {
        DLL_DECL_SPEC bool IsValidIP(QString ip);
        DLL_DECL_SPEC QStringList ExtractIpAddresses(QString input);
        DLL_DECL_SPEC QStringList ExtractIpPortProxies(QString input);
        DLL_DECL_SPEC quint32 Dotted2Long(QString ip);
        DLL_DECL_SPEC QString Dec2Dotted(quint32 ip);
        DLL_DECL_SPEC void SortIpAddressesAsc(QStringList &input_list);
    }

    namespace ipv6
    {
        DLL_DECL_SPEC bool IsValidIP(QString ip);
        DLL_DECL_SPEC QStringList ExtractIpAddresses(QString input);
        DLL_DECL_SPEC QStringList ExtractIpPortProxies(QString input);
    }
}} // Namespaces

#endif // _NETWORKUTILS_H_
