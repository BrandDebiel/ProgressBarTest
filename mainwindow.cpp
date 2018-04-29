#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->spinBox->setValue(1000);

    connect(&intervalTimer, SIGNAL(timeout()), this, SLOT(changeProgressbar()));
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(startTheTimer()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeProgressbar()
{
    if(ui->progressBar->value() <= 50)
    {
        ui->progressBar->setValue(75);
    }
    else
    {
        ui->progressBar->setValue(25);
    }
    qDebug() << "Value set at: " << ui->progressBar->value();
}

void MainWindow::startTheTimer()
{
    intervalTimer.setInterval(ui->spinBox->value());

    if(intervalTimer.isActive())
        intervalTimer.stop();
    else
        intervalTimer.start();
}
