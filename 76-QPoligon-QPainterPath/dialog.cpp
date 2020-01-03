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

   //Make our polygon
   QPolygon poly;
   poly << QPoint(10,10);
   poly << QPoint(10,100);
   poly << QPoint(100,10);
   poly << QPoint(100,100);

   //make a pen
   QPen linepen;
   linepen.setWidth(8);
   linepen.setColor(Qt::red);
   //linepen.setJoinStyle(Qt::RoundJoin);
   linepen.setJoinStyle(Qt::MiterJoin);
   linepen.setStyle(Qt::DotLine);
   painter.setPen(linepen);

   //make a brush
   QBrush fillbrush;
   fillbrush.setColor(Qt::green);
   fillbrush.setStyle(Qt::SolidPattern);

   //Fill the polygon
   QPainterPath path;
   path.addPolygon(poly);

   //draw polygon
   painter.drawPolygon(poly);

   painter.fillPath(path, fillbrush);

}
