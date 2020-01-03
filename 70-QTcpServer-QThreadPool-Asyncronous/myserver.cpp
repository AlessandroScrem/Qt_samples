#include "myserver.h"

MyServer::MyServer(QObject *parent) : QTcpServer(parent)
{

}

void MyServer::StartServer()
{
    if (listen(QHostAddress::Any, 1234))
    {
        qDebug() << "Server started";

    }
    else
    {
       qDebug() << "Could mot start the server!";
    }
}

void MyServer::incomingConnection(qintptr socketDesctriptor)
{
    MyClient *client = new MyClient(this);
    client->SetSocket(socketDesctriptor);


}

