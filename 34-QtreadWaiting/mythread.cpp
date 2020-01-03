#include "mythread.h"
#include <QDebug>
#include <QMutex>
#include <QMutexLocker>

MyThread::MyThread(QObject *parent) : QThread (parent)
{


}

void MyThread::run()
{

    for (int i = 0; i < 1000; i++)
    {
        qDebug() << i;
    }
}
