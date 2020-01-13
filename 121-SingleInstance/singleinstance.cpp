#include "singleinstance.h"

SingleInstance::SingleInstance(QObject *parent) : QObject(parent)
{

    // old style connection
    //connect(&mServer, SIGNAL(newConnection()), this, SLOT(newConnection()) );
    connect(&mServer, &QLocalServer::newConnection, this, &SingleInstance::newConnection);
}

SingleInstance::~SingleInstance()
{
    qDebug() << "CLOSED!!";
    mServer.close();
}

void SingleInstance::Listen(QString name)
{
    mServer.removeServer(name);
    mServer.listen(name);

    qDebug() << "Listen for: " << name;
    qDebug() << mServer.errorString();
}

bool SingleInstance::HasPrevoious(QString name, QStringList arg)
{
    qDebug() << "Checking for previous instance...";

    QLocalSocket socket;
    socket.connectToServer(name, QLocalSocket::ReadWrite);

    if(socket.waitForConnected())
    {
        qDebug() << "Sendings ars to previous instance...";
        QByteArray buffer;

        foreach (QString item, arg) {
            buffer.append(item + "\n");
        }
        socket.write(buffer);
        socket.waitForBytesWritten();
        return true;
    }

    qDebug() << socket.errorString();
    return false;
}

void SingleInstance::newConnection()
{
    emit newInstance();

    qDebug() << "New connection loading...";
    mSocket = mServer.nextPendingConnection();
    // old style connection
    //connect(mSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(mSocket, &QLocalSocket::readyRead, this, &SingleInstance::readyRead);
}

void SingleInstance::readyRead()
{
    qDebug() << "READ!!";
    qDebug() << "Arg: " << mSocket->readAll();
    mSocket->deleteLater();

}
