#include "mythread.h"
#include <QMutex>
#include <QMutexLocker>

MyThread::MyThread(QObject *parent) : QThread(parent)
{

}

void MyThread::run()
{
    for (int i = 1; i < 10000; i++)
    {
        QMutexLocker locker(&mutex); // il mutex si sblocca quando viene distrutto locker.
        if (this->Stop) break;
        emit NumberChanged(i);

        this->msleep(10);
    }
}
