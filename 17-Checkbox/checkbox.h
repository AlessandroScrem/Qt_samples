#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <QDialog>

namespace Ui {
class Checkbox;
}

class Checkbox : public QDialog
{
    Q_OBJECT

public:
    explicit Checkbox(QWidget *parent = nullptr);
    ~Checkbox();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Checkbox *ui;
};

#endif // CHECKBOX_H
