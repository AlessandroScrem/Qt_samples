#ifndef TEST_H
#define TEST_H

#include <QObject>
#include "Singleton.h"

class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = 0);

    static void doSomething();

signals:

    void testSignal();

public slots:

};

//Global variable
typedef Singleton<test> Tester;

#endif // TEST_H
