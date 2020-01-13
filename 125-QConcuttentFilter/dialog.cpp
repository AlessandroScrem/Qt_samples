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

bool Dialog::doFilter(const QString name)
{
    if(name.toLower() == "bob") return false;

    return true;
}


void Dialog::on_pushButton_clicked()
{
    ui->listWidget->clear();
    ui->listWidget_2->clear();

    QStringList people;
    people << "Chad" << "Mary" << "Bob" << "Heather";

    ui->listWidget->addItems(people);

    QtConcurrent::blockingFilter(people, &Dialog::doFilter);

    ui->listWidget_2->addItems(people);
}
