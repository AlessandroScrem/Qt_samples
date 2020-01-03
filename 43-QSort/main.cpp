#include <QCoreApplication>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> List;
    List << 2 << 3 << 1 << 0;

    //qSort(List.begin(),List.end()); //Deprecated
    std::sort(List.begin(),List.end());

    foreach (int i, List)
    {
        qDebug() << i;
    }

    return a.exec();
}
