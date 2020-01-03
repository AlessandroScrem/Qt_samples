#include <QCoreApplication>
#include <QStringList>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList List;
    QString Line = "a,b,c,d,e,f,g";
    List = Line.split(",");
    List.replaceInStrings("b", "Batman");


    foreach (QString itm, List)
    {
        qDebug() << itm;
    }

    QString After = List.join(",");
    qDebug() << After;

    return a.exec();
}
