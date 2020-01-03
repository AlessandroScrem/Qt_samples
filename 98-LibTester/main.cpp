#include <QCoreApplication>
#include "mylib.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyLib clib;
    clib.Test();

    return a.exec();
}
