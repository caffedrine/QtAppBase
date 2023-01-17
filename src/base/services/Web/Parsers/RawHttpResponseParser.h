#ifndef _RAWHTTPRESPONSEPARSER_H_
#define _RAWHTTPRESPONSEPARSER_H_

#include <QByteArray>
#include <QMap>

#include "base/LibCfg.h"
#include "base/utils/utils.h"
#include "HttpParsersBase.h"

namespace Services { namespace Parsers {

class DLL_DECL_SPEC RawHttpResponseParser: public Services::Parsers::HttpParsersBase
    {
    public:
        RawHttpResponseParser();
        RawHttpResponseParser(QByteArray responseChunk);

        int GetHttpResponseCode() { return this->ResponseCode; };
        QByteArray GetResponseCodeDescription() { return this->ResponseCodeDesc; };
        bool IsKeepAliveEnabled();
        QByteArray GetHttpResponseCodeDescription() { return this->ResponseCodeDesc; };
        QByteArray GetFirstLine();
        void ConnectionCloseReceived();

        void clear();

    protected:
        int ResponseCode = -1;
        QByteArray ResponseCodeDesc;
        void ParseFirstLine();
    };

}} // Namespaces

#endif //_RAWHTTPRESPONSEPARSER_H_
