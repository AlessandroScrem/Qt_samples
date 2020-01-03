#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // setta la progressBar al valore dello horizontalSlider
    ui->progressBar->setValue(ui->horizontalSlider->value());

    // collega  progressBar con horizontalSlider
    connect(ui->horizontalSlider, &QSlider::valueChanged,
            ui->progressBar, &QProgressBar::setValue);


}

Dialog::~Dialog()
{
    delete ui;
}
