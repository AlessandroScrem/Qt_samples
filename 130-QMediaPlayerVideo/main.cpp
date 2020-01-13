#include "dialog.h"

#include <QApplication>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Dialog w;
    //w.show();

    QMediaPlayer* player = new QMediaPlayer;
    QVideoWidget* vw = new QVideoWidget;

    player->setVideoOutput(vw);
    player->setMedia(QUrl("http://hubblesource.stsci.edu/sources/video/clips/details/images/centaur_1.mpg"));

    vw->setGeometry(100, 100, 1280,720);
    vw->show();

    player->play();
    qDebug() << player->state();

    return a.exec();
}
