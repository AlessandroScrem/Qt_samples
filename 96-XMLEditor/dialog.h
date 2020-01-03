#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtXml/QtXml>
#include <QStandardItemModel>

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
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    QStandardItemModel *model;
    QString Filename;
    void ReadFile();
    void WriteFile();

};
#endif // DIALOG_H
