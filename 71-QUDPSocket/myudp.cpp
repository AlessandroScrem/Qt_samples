#include "myudp.h"

MyUDP::MyUDP(QObject *parent) : QObject(parent)
{
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost, 1234);
    connect(socket, &QUdpSocket::readyRead, this, &MyUDP::readyRead);

}

void MyUDP::SayHello()
{
    QByteArray Data;
    Data.append("Hello from UDP Land");
    socket->writeDatagram(Data, QHostAddress::LocalHost, 1234);


}

void MyUDP::readyRead()
{
    QByteArray Buffer;
    Buffer.resize(static_cast<int>(socket->pendingDatagramSize()));

    QHostAddress sender;
    quint16 senderPort;
    socket->readDatagram(Buffer.data(),Buffer.size(), &sender, &senderPort);

    qDebug() << "Message from: " << sender.toString();
    qDebug() << "Message port: " << senderPort;
    qDebug() << "Message : " << Buffer;

}
