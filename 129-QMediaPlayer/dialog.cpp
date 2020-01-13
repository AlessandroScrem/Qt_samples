#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);

    connect(player, &QMediaPlayer::positionChanged, this, &Dialog::on_positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &Dialog::on_durationChanged);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_sliderProgress_sliderMoved(int position)
{
    player->setPosition(position);
}

void Dialog::on_sliderVolume_sliderMoved(int position)
{
    player->setVolume(position);
}

void Dialog::on_pushButton_clicked()
{
    //Load the file
    player->setMedia(QUrl::fromLocalFile("file_example_MP3_700KB.mp3"));
    player->play();
    qDebug() << player->errorString();
}

void Dialog::on_pushButton_2_clicked()
{

    player->stop();
}

void Dialog::on_positionChanged(uint64_t position)
{

    ui->sliderProgress->setValue(position);
}

void Dialog::on_durationChanged(uint64_t position)
{
    ui->sliderProgress->setMaximum(position);
}
