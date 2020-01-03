#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include "myclient.h"


class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = nullptr);    
    void StartServer();

signals:

public slots:

private:


protected:
    void incomingConnection(qintptr  socketDesctriptor);




};

#endif // MYSERVER_H
