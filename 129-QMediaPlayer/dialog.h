#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMediaPlayer>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_sliderProgress_sliderMoved(int position);
    void on_sliderVolume_sliderMoved(int position);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_positionChanged(uint64_t position);
    void on_durationChanged(uint64_t position);

private:
    Ui::Dialog *ui;
    QMediaPlayer* player;
};
#endif // DIALOG_H
