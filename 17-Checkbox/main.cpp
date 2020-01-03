#include "checkbox.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Checkbox w;
    w.show();

    return a.exec();
}
