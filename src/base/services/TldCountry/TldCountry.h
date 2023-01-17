#ifndef _SERVICES_TLDCOUNTRY_H_
#define _SERVICES_TLDCOUNTRY_H_

#include <QMap>

#include "base/LibCfg.h"

namespace Services { namespace TldCountry
{
    DLL_DECL_SPEC QString GetCountryByTLD(QString tld);
    DLL_DECL_SPEC QString GetTldByCountry(QString country_tld);
}} // Namespaces

#endif //_SERVICES_TLDCOUNTRY_H_
