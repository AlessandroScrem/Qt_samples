#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qlabel.h>
#include <qprogressbar.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionDo_Something_triggered();

private:
    Ui::MainWindow *ui;
    QLabel *Statlabel;
    QProgressBar *StatProgress;
};

#endif // MAINWINDOW_H
