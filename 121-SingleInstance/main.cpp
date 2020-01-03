#include <QCoreApplication>
#include <QDebug>

#include "singleinstance.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString name =  "com.company.application";

    SingleInstance cInstance;
    if(cInstance.HasPrevoious(name, QCoreApplication::arguments()))
    {
        qDebug() << "Previous instance detected!";
        return 0;
    }

    qDebug() << "There can be only one!";
    cInstance.Listen(name);


    return a.exec();
}
