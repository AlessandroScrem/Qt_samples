#include <QCoreApplication>
#include "test.h"
#include <QPointer>
#include "child.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test cTest;

    // use qpointer when class is not  qobject parent
    // you can't pass qobject pointer
    QPointer<Child> cChild = new Child;

    cChild->DoSomethings();

    return a.exec();

}
