#include <QCoreApplication>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector <QString> Vec(5);

    //qFill(Vec, "Hello"); //Deprecated
    std::fill(Vec.begin(),Vec.end(), "Hello");

    foreach (QString itm , Vec)
    {
        qDebug() << itm;
    }

    return a.exec();
}
