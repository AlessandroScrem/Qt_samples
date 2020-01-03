#include "test.h"

test::test(QObject *parent) :
    QObject(parent)
{
}

void test::doSomething()
{
   //emit testSignal();
    Tester::Instance()->testSignal();
}
