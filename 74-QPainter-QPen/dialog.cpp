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
   QPen pointpen(Qt::black);
   pointpen.setWidth(6);

   QPen linepen(Qt::red);
   linepen.setWidth(2);

   QPoint p1;
   p1.setX(10);
   p1.setY(10);

   QPoint p2;
   p2.setX(100);
   p2.setY(100);

   painter.setPen(linepen);
   painter.drawLine(p1, p2);

   painter.setPen(pointpen);
   painter.drawPoint(p1);
   painter.drawPoint(p2);

}
