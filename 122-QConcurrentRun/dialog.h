#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QtConcurrent>
#include "myjob.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
signals:
    void on_stop();

private slots:
    void on_btnStart_clicked();
    void on_btnStop_clicked();

public slots:
    void newNumber(QString name, int number);

private:
    Ui::Dialog *ui;
    MyJob mJob;
};
#endif // DIALOG_H
