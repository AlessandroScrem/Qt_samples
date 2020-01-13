#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::doTask(int &number)
{
    qDebug() << "Starting " << number;

    int max = 10;
    for (int i = 0; i < max; ++i) {
        QThread::currentThread()->msleep(50);
        qDebug() << "Processing " << number << " - " << i << " of " << max;
    }

    qDebug() << "Stopped " << number;
}


void Dialog::on_pushButton_clicked()
{
    QVector<int> vector;
    for (int i = 0; i < ui->spinBox->value(); ++i) {
        vector.append(i);
    }

    QProgressDialog pdialog;
    pdialog.setLabelText("Processing");

    QFutureWatcher<void> watcher;

    connect(&pdialog, &QProgressDialog::canceled, &watcher, &QFutureWatcher<void>::cancel);
    connect(&watcher, &QFutureWatcher<void>::finished, &pdialog, &QProgressDialog::reset );
    connect(&watcher, &QFutureWatcher<void>::progressRangeChanged, &pdialog, &QProgressDialog::setRange);
    connect(&watcher, &QFutureWatcher<void>::progressValueChanged, &pdialog, &QProgressDialog::setValue);

    watcher.setFuture(QtConcurrent::map(vector, &Dialog::doTask));

    pdialog.exec();
    watcher.waitForFinished();

    if(watcher.isCanceled())
    {
        qDebug() << "Canceled!!!";
        QMessageBox::critical(this, "Canceled", "You clicked cancel!");
    }
    else
    {
        qDebug() << "Finished!!!";
        QMessageBox::information(this, "Finished", "All done!");
    }
}
