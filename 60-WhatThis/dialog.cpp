#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    ui->setupUi(this);

    LinkFilter *filter = new LinkFilter(this);
    this->installEventFilter(filter);
    connect(filter, &LinkFilter::linkClicked, this, &Dialog::ShowLink);

    ui->pushButton1->setWhatsThis("For more information <a href='www.google.com'>Click here</a>");

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::ShowLink(const QString &Link)
{
    QMessageBox::information(this, "Link Clicked", Link);
}


