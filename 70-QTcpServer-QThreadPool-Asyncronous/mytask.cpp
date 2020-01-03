#include "mytask.h"
#include <QThread>

MyTask::MyTask()
{

}

void MyTask::run()
{
    //time consumer

    qDebug() << "Task Start";

    int iNumber = 0;
    for (int i = 0; i <100; i++ )
    {
        iNumber += i;
        QThread::msleep(10);
    }

    qDebug() << "Task Done";

    emit Result(iNumber);

}
