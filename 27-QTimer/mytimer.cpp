#include "mytimer.h"
#include <QDebug>

MyTimer::MyTimer()
{
    timer = new QTimer(this);

    //old fashon
    //connect(timer, SIGNAL(timeout()), this, SLOT(Myslot()) );

    connect(timer, &QTimer::timeout, this,  &MyTimer::Myslot);

    timer->start(1000);


}

void MyTimer::Myslot()
{
    qDebug() << "Timer executed";
}
