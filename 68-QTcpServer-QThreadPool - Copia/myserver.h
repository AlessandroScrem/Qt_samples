#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QThreadPool>
#include <QDebug>
#include "myrunnable.h"



class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = nullptr);    
    void StartServer();

signals:

public slots:

private:
    QThreadPool *pool;

protected:
    void incomingConnection(qintptr  socketDesctriptor);




};

#endif // MYSERVER_H
