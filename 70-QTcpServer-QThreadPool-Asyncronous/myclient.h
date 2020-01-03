#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QThreadPool>
#include <QDebug>
#include "mytask.h"

class MyClient : public QObject
{
    Q_OBJECT
public:
    explicit MyClient(QObject *parent = nullptr);
    void SetSocket(qintptr Desctriptor);

signals:

public slots:
    void connected();
    void disconnected();
    void readyRead();
    void TaskResult(int Number);

private:
    QTcpSocket *socket;

};

#endif // MYCLIENT_H
