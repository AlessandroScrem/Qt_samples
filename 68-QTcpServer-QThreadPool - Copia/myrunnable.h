#ifndef MYRUNNABLE_H
#define MYRUNNABLE_H

#include <QRunnable>
#include <QTcpSocket>
#include <QtDebug>

class MyRunnable : public QRunnable
{

public:
     MyRunnable();
     qintptr SocketDesctriptor;

protected:
     void run();


};

#endif // MYRUNNABLE_H
