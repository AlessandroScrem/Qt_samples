#ifndef MYTREAD_H
#define MYTREAD_H
#include <QObject>
#include <QDebug>
#include <QThread>


class MyObject :public QObject
{
    Q_OBJECT
public:
    explicit MyObject(QObject *parent = nullptr);
    void DoSetup(QThread &cThread);

public slots:
    void DoWork();

};

#endif // MYTREAD_H
