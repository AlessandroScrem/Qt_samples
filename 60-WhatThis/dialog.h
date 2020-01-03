#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "linkfilter.h"

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
   void ShowLink(const QString &Link);



private:
    Ui::Dialog *ui;

};

#endif // DIALOG_H
