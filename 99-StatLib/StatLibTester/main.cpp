#include <QCoreApplication>
#include "statlib.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    StatLib cStat;
    cStat.Test();


    return a.exec();
}
