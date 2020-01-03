#include "myclient.h"

MyClient::MyClient(QObject *parent) : QObject(parent)
{
    QThreadPool::globalInstance()->setMaxThreadCount(15);
}

void MyClient::SetSocket(qintptr Desctriptor)
{
    socket = new QTcpSocket(this);

    connect(socket, &QTcpSocket::connected, this, &MyClient::connected);
    connect(socket, &QTcpSocket::disconnected, this, &MyClient::disconnected);
    connect(socket, &QTcpSocket::readyRead, this, &MyClient::readyRead);

    socket->setSocketDescriptor(Desctriptor);

    qDebug() << "client connected";
}

void MyClient::connected()
{
    qDebug() << "client connected event";

}

void MyClient::disconnected()
{
    qDebug() << "client disconnected";

}

void MyClient::readyRead()
{
    qDebug() << socket->readAll();

    //time consumer
    MyTask *mytask = new MyTask();
    mytask->setAutoDelete(true);
    connect(mytask, &MyTask::Result, this, &MyClient::TaskResult, Qt::QueuedConnection);
    QThreadPool::globalInstance()->start(mytask);
}

void MyClient::TaskResult(int Number)
{
   QByteArray Buffer;
   Buffer.append("\r\nTask Result = ");
   Buffer.append(QString::number(Number));

   socket->write(Buffer);

}
