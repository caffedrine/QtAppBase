#ifndef _WEB_HTTPPROXYSERVER_H_
#define _WEB_HTTPPROXYSERVER_H_

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include "base/LibCfg.h"

namespace Services { namespace Web {

class DLL_DECL_SPEC HttpProxyServer: public QObject
{
Q_OBJECT
public:
    HttpProxyServer(QObject *parent = nullptr);
    ~HttpProxyServer();
    bool StartServer(QString ip_address, quint16 port);
    void StopServer();

    void SetRequestManualApproval(bool approval) { this->RequestWaitForManualApproval = approval; };

signals:

private:
    bool RequestWaitForManualApproval = false;
    QTcpServer *tcpServer = nullptr;


};

}} // Namespaces

#endif // _WEB_HTTPPROXYSERVER_H_
