#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <V3d_View.hxx>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Handle(V3d_View)myview;
}

MainWindow::~MainWindow()
{
    delete ui;
}
