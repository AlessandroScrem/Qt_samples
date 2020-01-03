#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //LoadSettings();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::SaveSettings()
{
    QSettings settings("MyCompany", "myapp");
    settings.beginGroup("MainWindow");
    settings.setValue("position", this->geometry());
    settings.endGroup();

    qDebug() << "Saved";
}

void Dialog::LoadSettings()
{
    QSettings settings("MyCompany", "myapp");
    settings.beginGroup("MainWindow");
    QRect myrect = settings.value("position").toRect();
    setGeometry(myrect);
    settings.endGroup();

    qDebug() << "Loaded";

}

void Dialog::on_pushButton_clicked()
{
    //Load
    LoadSettings();
}


void Dialog::on_pushButton_2_clicked()
{
    //Save
    SaveSettings();
}

