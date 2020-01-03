#include "sockettest.h"

SocketTest::SocketTest(QObject *parent) : QObject(parent)
{

}

void SocketTest::Connect()
{
    socket = new QTcpSocket(this);

    socket->connectToHost("google.com", 80);


    if(socket->waitForConnected(3000))
    {
        //connected
        qDebug() << "Connected:";


        //send
        socket->write("hello server\r\n\r\n\r\n");
        socket->waitForBytesWritten(1000);
        //read
        socket->waitForReadyRead(3000);

        qDebug() << "Reading: " << socket->bytesAvailable();

        //.noquote() converte /r/n in newline
        qDebug().noquote() << socket->readAll();

        //closed
        socket->close();
    }
    else
    {
        qDebug() << "Not Connected:";
    }



}
