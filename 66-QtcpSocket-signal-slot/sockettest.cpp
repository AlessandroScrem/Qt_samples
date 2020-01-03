#include "sockettest.h"

SocketTest::SocketTest(QObject *parent) : QObject(parent)
{

}

void SocketTest::Test()
{
    socket = new QTcpSocket(this);

    connect(socket, &QTcpSocket::connected, this, &SocketTest::connected);
    connect(socket, &QTcpSocket::disconnected, this, &SocketTest::disconnected);
    connect(socket, &QTcpSocket::readyRead, this, &SocketTest::readyRead);
    connect(socket, &QTcpSocket::bytesWritten, this, &SocketTest::bytesWritten);

    qDebug() << "Connecting...";

    socket->connectToHost("google.com",80);

    if(!socket->waitForConnected(500))// milliconds
    {
        qDebug() << "Error: " << socket->errorString();
    }
}

void SocketTest::connected()
{
    qDebug() << "Connected:";

    socket->write("HEAD / HTTP/1.0\r\n\r\n\r\n");

}
void SocketTest::disconnected()
{
    qDebug() << "Disonnected:";

}
void SocketTest::bytesWritten(qint64 bytes)
{
    qDebug() << "Writed: " << bytes ;

}

void SocketTest::readyRead()
{

    qDebug() << "Reading...";
    qDebug().noquote() << socket->readAll();


}
