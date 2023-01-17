#include "Uri.h"

namespace Services { namespace Parsers {

Uri::Uri(std::string uri) : uri_(uri)
{
    UriParserStateA state_;
    state_.uri = &uriParse_;
    isValid_ = uriParseUriA(&state_, uri_.c_str()) == URI_SUCCESS;
}

Uri::Uri(QString uri) : uri_(uri.toStdString())
{
    UriParserStateA state_;
    state_.uri = &uriParse_;
    isValid_ = uriParseUriA(&state_, uri_.c_str()) == URI_SUCCESS;
}

Uri::~Uri()
{
    uriFreeUriMembersA(&uriParse_);
}

}};

