#include <QCoreApplication>
#include <QList>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> List;

    for (int i = 0; i <10; i++)
    {

        List.append(i);
    }

    QListIterator<int> Iter(List);
    Iter.toBack();
    while(Iter.hasPrevious())
    {
          qDebug() << Iter.previous();
          if(Iter.hasPrevious())
              qDebug() << "...prev " << Iter.peekPrevious();
    }


//    List.removeOne(5);

//    foreach (int mNumber,  List)
//    {
//        qDebug() << mNumber;
//    }

    return a.exec();
}
