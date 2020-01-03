#include "dialog.h"
#include "ui_dialog.h"
#include <QPainter>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *e)
{
   QPainter painter(this);

    QLinearGradient grad1(25, 100, 150, 175);
    grad1.setColorAt(0.0, Qt::white);
    grad1.setColorAt(0.2, Qt::green);
    grad1.setColorAt(1.0, Qt::black);

    QRect rect1(10,10,200,200);
    painter.fillRect(rect1, grad1);

    QRadialGradient grad2(QPoint(320,100),100);
    grad2.setColorAt(0.0, Qt::white);
    grad2.setColorAt(0.5, Qt::green);
    grad2.setColorAt(1.0, Qt::black);

    QRect rect2(220, 10 ,200, 200);
    painter.fillRect(rect2, grad2);

    QConicalGradient grad3(QPoint(540,100),100);
    grad3.setColorAt(0.0, Qt::white);
    grad3.setColorAt(0.5, Qt::green);
    grad3.setColorAt(1.0, Qt::black);

    QRect rect3(440,10,200,200);
    painter.fillRect(rect3, grad3);


}
