#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QProgressDialog>
#include <QtConcurrent>
#include <QThread>
#include <QFutureWatcher>
#include <QDebug>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    static void doTask(int & number);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
