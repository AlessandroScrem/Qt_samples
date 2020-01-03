#include "commandline.h"

CommandLine::CommandLine(QObject *parent) : QObject(parent)
{
    this->moveToThread(&mThread);

    // old style
    //connect(&mThread, SIGNAL(started()), this, SLOT(ReadSTDIN()));
    //connect(this, SIGNAL(OnReadLine(QString)), this, SLOT(HanleSTDIN(QString)));

    connect(&mThread, &QThread::started, this, &CommandLine::ReadSTDIN);
    connect(this, &CommandLine::OnReadLine, this, &CommandLine::HanleSTDIN);

    mThread.start();
}

void CommandLine::ReadSTDIN()
{
    QTextStream stream(stdin);
    QString Line = stream.readLine();
    emit OnReadLine(Line);
    ReadSTDIN();
}

void CommandLine::HanleSTDIN(QString Line)
{
    //qDebug() << Line;
    WriteSTDOUT("You entered: " + Line + '\n');
}

void CommandLine::WriteSTDOUT(QString Line)
{
    QTextStream stream(stdout);
    stream << Line;

}
