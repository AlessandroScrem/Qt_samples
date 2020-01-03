#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QThread>
#include <QMutex>

class MyThread : public QThread
{
    Q_OBJECT


public:
    explicit MyThread(QObject *parent = nullptr);
    void run();
    bool Stop = false;

private:
    QMutex mutex;

signals:
    void NumberChanged(int);

public slots:
};

#endif // MYTHREAD_H
