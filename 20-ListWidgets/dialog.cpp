#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    for (int i = 0 ;i<9;i++) {
        ui->listWidget->addItem(QString::number(i)+" number here");
    }

}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_pushButton_clicked()
{
    ui->listWidget->currentItem()->setText("Fuzzy Bunny");
    QListWidgetItem *item = ui->listWidget->currentItem();
    item->setText("Funny Bumnny of doom");
    item->setTextColor(Qt::red);
    item->setBackgroundColor(Qt::gray);
}
