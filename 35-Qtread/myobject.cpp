#include "myobject.h"
#include <QDebug>
#include <QMutex>
#include <QMutexLocker>

MyObject::MyObject(QObject *parent) : QObject (parent)
{

}

void MyObject::DoSetup(QThread &cThread)
{
    connect (&cThread, &QThread::started, this, &MyObject::DoWork);
}

void MyObject::DoWork()
{
    for (int i = 0; i<100; i++)
    {
        qDebug() <<  i;
    }

}
