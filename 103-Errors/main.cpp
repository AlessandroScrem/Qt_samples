#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include "myerror.h"

void Test()
{
    qDebug() <<"Starting";

    try
    {
        MyError *cErr = new MyError(/*this*/); // put inside a CObject class to avoid mem leaks
        cErr->SetMessage("lol");
        throw cErr;

        throw QString("The cat ate my homework");

    }
    catch (const char*  cerr)
    {
        qDebug() << cerr;
    }
    catch (QString sErr)
    {
        qDebug() << "QSTRING = "<< sErr;
    }
    catch (MyError *cErrMsg)
    {
        qDebug() << "MyError = "<< cErrMsg->Message();
    }
     catch (...)
    {
        qDebug() << "Unknown Error has occurred";
    }

    qDebug() <<"Glad that's has over";

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test();

    return a.exec();
}
