#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QStandardItemModel>
#include <delegate.h>

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
    QStandardItemModel *model;
    Delegate *mydelegate;
};

#endif // DIALOG_H
