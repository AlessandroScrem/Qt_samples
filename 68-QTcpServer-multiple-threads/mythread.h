#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QtDebug>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(qintptr id, QObject *parent = nullptr);
    void run();

signals:
    void error(QTcpSocket::SocketError socketerror);


public slots:  
    void readyRead();
    void disconnected();

private:
    QTcpSocket *socket;
    qintptr socketDesctriptor;


};

#endif // MYTHREAD_H
