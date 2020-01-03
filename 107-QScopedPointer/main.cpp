#include <QCoreApplication>
#include <QDebug>
#include <QScopedPointer>

int* test()
{

    QScopedPointer<int>i(new int(23));
    qDebug() << *i;

    return i.take();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QScopedPointer<int>z(test());
    qDebug() << *z;

    return a.exec();
}
