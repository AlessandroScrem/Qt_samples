#include "myserver.h"

MyServer::MyServer(QObject *parent) : QTcpServer(parent)
{


}

void MyServer::StartServer()
{
    if (!this->listen(QHostAddress::Any, 1234))
    {
        qDebug() << "Could mot start server";

    }
    else
    {
       qDebug() << "Listening...";
    }
}

void MyServer::incomingConnection(qintptr socketDesctriptor)
{
    qDebug() << socketDesctriptor <<  " Connecting...";
    MyThread *thread = new MyThread(socketDesctriptor, this);

    //connect(thread, SIGNAL(finished()),thread, SLOT(deleteLater()) );
    connect(thread, &MyThread::finished, thread, &MyThread::deleteLater);

    thread->start();

}

