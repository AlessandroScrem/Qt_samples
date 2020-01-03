#include <QCoreApplication>
#include <QtDebug>
#include "watercooler.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    WaterCooler watercooler;


    return a.exec();
}
