#include <QCoreApplication>
#include <QtDebug>
#include <QStringList>
#include <QVector>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList List;
    List << "a" << "b" << "c";

    QVector<QString> Vect(3);

    //qCopy(List.begin(),List.end(), Vect.begin()); //Deprecated
    std::copy(List.begin(),List.end(), Vect.begin());

    foreach (QString itm, Vect)
    {
        qDebug() << itm;
    }

    return a.exec();
}
