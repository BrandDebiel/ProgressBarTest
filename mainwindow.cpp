#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    m_intervalTime = 1000;  //Initialiseer de variabele

    ui->spinBox->setValue(m_intervalTime);  //Zet de waarde in de spinbox

    connect(&m_intervalTimer, SIGNAL(timeout()), this, SLOT(changeProgressbar()));  //Connect de timer aan de progressbar functie
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(startTheTimer()));    //Connect de drukknop aan de timer functie
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeProgressbar()
{
    //Als de progressbar een hoge waarde heeft maak deze dan laag en andersom,
    //iedere keer wanneer de timer deze functie aanroept.
    if(ui->progressBar->value() <= 50)
    {
        ui->progressBar->setValue(75);
    }
    else
    {
        ui->progressBar->setValue(25);
    }


    qDebug() << "Value set at: " << ui->progressBar->value();   //Geef dubug informatie in de application output
}

void MainWindow::startTheTimer()
{
    m_intervalTime = ui->spinBox->value();  //Welke waarde staat er nu in de spinbox, zet deze in de gedeelde (member) variabele

    m_intervalTimer.setInterval(m_intervalTime);    //Zet de variabele als timer interval, let op!! de waarde wordt pas
                                                    //gebruikt wanneer de drukknop weer aan/ uit wordt gedrukt

    //Als de timer actief is stop deze en andersom, iedere keer dat de knop wordt ingedrukt
    if(m_intervalTimer.isActive())
        m_intervalTimer.stop();
    else
        m_intervalTimer.start();
}
