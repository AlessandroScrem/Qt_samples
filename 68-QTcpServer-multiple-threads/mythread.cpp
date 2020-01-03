#include "mythread.h"

MyThread::MyThread(qintptr id, QObject *parent) : QThread(parent)
{
    this->socketDesctriptor = id;
}

void MyThread::run()
{
    //thread start here

    qDebug() << socketDesctriptor<< "Starting thread";

    socket = new QTcpSocket();
    if (!socket->setSocketDescriptor(this->socketDesctriptor))
    {
        emit error(socket->error());
        return;
    }

//    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, &QTcpSocket::readyRead, this, &MyThread::readyRead, Qt::DirectConnection);
    connect(socket, &QTcpSocket::disconnected, this, &MyThread::disconnected, Qt::DirectConnection);

    qDebug() << socketDesctriptor<< "Client connected";

    exec();

}

void MyThread::readyRead()
{
    QByteArray Data = socket->readAll();

    qDebug() << socketDesctriptor << " Data in: " << Data;

    socket->write(Data);

}

void MyThread::disconnected()
{
    qDebug() << socketDesctriptor << " Disconnected";

    socket->deleteLater();
    exit();
}

