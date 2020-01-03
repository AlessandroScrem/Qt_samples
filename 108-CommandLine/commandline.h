#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QTextStream>

class CommandLine : public QObject
{
    Q_OBJECT
public:
    explicit CommandLine(QObject *parent = nullptr);

signals:
    void OnReadLine(QString Line);

public slots:
    void ReadSTDIN();
    void HanleSTDIN(QString Line);
    void WriteSTDOUT(QString Line);
private:
    QThread mThread;
};

#endif // COMMANDLINE_H
