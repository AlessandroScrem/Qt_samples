#include <QCoreApplication>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> List;

    List << 5 << 2 << 3 << 4;

    //QList<int>::const_iterator Iter = qFind(List.begin(), List.end(), 2); //Deprecated
    QList<int>::const_iterator Iter = std::find(List.begin(), List.end(), 2);

    if(Iter != List.end())
    {
        qDebug() << "Found " << *Iter;
    }
    else
    {
        qDebug() << "Not Found";
    }


    return a.exec();
}
