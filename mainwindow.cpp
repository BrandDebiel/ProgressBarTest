#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    m_intervalTime = 1000;

    ui->spinBox->setValue(m_intervalTime);

    connect(&m_intervalTimer, SIGNAL(timeout()), this, SLOT(changeProgressbar()));
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
    m_intervalTime = ui->spinBox->value();

    m_intervalTimer.setInterval(m_intervalTime);

    if(m_intervalTimer.isActive())
        m_intervalTimer.stop();
    else
        m_intervalTimer.start();
}
