#include "test.h"

Test::Test(QObject *parent) : QObject(parent)
{
    // child class is automatically destroyed
    mChild = new Child(this);

}
