#include "consumer.h"

Consumer::Consumer(QObject *parent) :
    QObject(parent)
{
    connect(Tester::Instance(),SIGNAL(testSignal()), this,SLOT(testSlot()));
}

void Consumer::testSlot()
{
    qDebug() << "It's working!!!!";
}
