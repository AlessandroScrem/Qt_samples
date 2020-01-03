#include <QCoreApplication>
#include "test.h"
#include "consumer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Consumer cConsumer;

    //From the object
    //Tester::Instance()->doSomething();

    //No object
    test::doSomething();

    return a.exec();
}
