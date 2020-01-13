#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtConcurrent>
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

    static bool doFilter(QString name);
    static void doReduce(QString &result, const QString item);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
