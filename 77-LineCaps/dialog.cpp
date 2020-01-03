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

   QPen pen(Qt::black);
   pen.setWidth(15);

   QPoint startpoint(20,30);
   QPoint endpoint(200,30);

   pen.setCapStyle(Qt::FlatCap);
   painter.setPen(pen);
   painter.drawLine(startpoint, endpoint);

   startpoint.setY(50);
   endpoint.setY(50);

   pen.setCapStyle(Qt::SquareCap);
   painter.setPen(pen);
   painter.drawLine(startpoint, endpoint);

   startpoint.setY(70);
   endpoint.setY(70);

   pen.setCapStyle(Qt::RoundCap);
   painter.setPen(pen);
   painter.drawLine(startpoint, endpoint);



}
