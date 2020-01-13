#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

bool Dialog::doFiltered(QString name)
{
    if(name.toLower() == "bob" || name.toLower() == "heather") return true;

    return false;
}


void Dialog::on_pushButton_clicked()
{
    QStringList people;
    people << "Mark" << "Heather" << "Bob" << "Chad";

    ui->listWidget->clear();
    ui->listWidget_2->clear();

    QStringList allowList = QtConcurrent::blockingFiltered(people, &Dialog::doFiltered);

    ui->listWidget->addItems(people);
    ui->listWidget_2->addItems(allowList);

}
