#ifndef CHILD_H
#define CHILD_H

#include <QObject>
#include <QDebug>

class Child : public QObject
{
    Q_OBJECT
public:
    explicit Child(QObject *parent = nullptr);

signals:

public:
    void DoSomethings();


};

#endif // CHILD_H
