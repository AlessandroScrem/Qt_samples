#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGraphicsScene>
#include "mysquare.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:

private:
    Ui::Dialog *ui;
    QGraphicsScene *scene;
    MySquare *square;

private:

};

#endif // DIALOG_H
