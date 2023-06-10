#include "HttpProxyServer.h"

namespace Services { namespace Web {

HttpProxyServer::HttpProxyServer(QObject *parent) : QObject(parent)
{

}

HttpProxyServer::~HttpProxyServer()
{
    this->StopServer();
}

bool HttpProxyServer::StartServer(QString ip_address, quint16 port)
{
    if( this->tcpServer )
    {
        qWarning().nospace().noquote() << "[HttpProxyServer] Proxy server is already listening on " << ip_address << ":" << QString::number(port);
        return false;
    }

    this->tcpServer = new QTcpServer(this);
    connect(this->tcpServer, &QTcpServer::newConnection, [=](){
        QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
        qInfo().nospace().noquote() << "[HttpProxyServer] Incoming connection " << clientConnection->peerAddress().toString() << ":" << QString::number(clientConnection->peerPort());
        connect(clientConnection, &QAbstractSocket::disconnected, clientConnection, &QObject::deleteLater);
        connect(clientConnection, &QTcpSocket::readyRead, [=](){
            qDebug().nospace().noquote() << "[HttpProxyServer] [" << clientConnection->peerAddress().toString() << ":" << QString::number(clientConnection->peerPort()) << "] "
            << "Data available: " << QString(clientConnection->readAll());
        });

        clientConnection->write("it works!");
    });

    if(!this->tcpServer->listen(QHostAddress(ip_address), port))
    {
        this->tcpServer->close();
        delete this->tcpServer;
        this->tcpServer = nullptr;
        qWarning().nospace().noquote() << "[HttpProxyServer] Failed to start proxy server on TCP " << ip_address << ":" << QString::number(port);
        return false;
    }

    qInfo().nospace().noquote() << "[HttpProxyServer] Started proxy server on TCP " << ip_address << ":" << QString::number(port);
    return true;
}

void HttpProxyServer::StopServer()
{
    if( this->tcpServer )
    {
        qInfo().noquote().nospace() << "[HttpProxyServer] Proxy server stopped";
        this->tcpServer->close();
        delete this->tcpServer;
        this->tcpServer = nullptr;
    }
}

}} // Namespaces