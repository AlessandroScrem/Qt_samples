#include "myserver.h"

MyServer::MyServer(QObject *parent) : QTcpServer(parent)
{
    pool = new QThreadPool(this);
    pool->setMaxThreadCount(5);

}

void MyServer::StartServer()
{
    if (this->listen(QHostAddress::Any, 1234))
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
    MyRunnable *task = new MyRunnable();
    task->setAutoDelete(true);

    task->SocketDesctriptor = socketDesctriptor;
    pool->start(task);

}

