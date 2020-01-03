#ifndef MYTREAD_H
#define MYTREAD_H
#include <QThread>



class MyThread :public QThread
{
    Q_OBJECT

public:
    explicit  MyThread(QObject *parent = nullptr);

    void run();

};

#endif // MYTREAD_H
