#include "checkbox.h"
#include "ui_checkbox.h"
#include <QMessageBox>

Checkbox::Checkbox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Checkbox)
{
    ui->setupUi(this);
    ui->checkBox->setChecked(true);
}

Checkbox::~Checkbox()
{
    delete ui;
}

void Checkbox::on_pushButton_clicked()
{
    if( ui->checkBox->isChecked()){
        QMessageBox::information(this,"Cats","You like cats");
    }
    else{
        QMessageBox::information(this,"Cats","You don't like cats");

    }
}
