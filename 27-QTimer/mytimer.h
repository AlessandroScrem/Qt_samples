#ifndef MYTIMER_H
#define MYTIMER_H

#include <QObject>
#include <QTimer>


class MyTimer : public QObject
{
    Q_OBJECT

public:
    MyTimer();
    QTimer *timer;

public slots:
    void Myslot();
};

#endif // MYTIMER_H
