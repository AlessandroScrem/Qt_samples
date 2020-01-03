#ifndef TEST_H
#define TEST_H

#include <QObject>
#include "child.h"

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);

signals:
private:
    Child *mChild;

};

#endif // TEST_H
