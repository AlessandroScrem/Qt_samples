#include "child.h"

Child::Child(QObject *parent) : QObject(parent)
{

}

void Child::DoSomethings()
{
    qDebug() << "Do Somethings";


}
