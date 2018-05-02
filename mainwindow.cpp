#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    m_intervalTime = 1000;  //Initialiseer de variabele

/****************************************************************************************************************************************/

    bool setupGeslaagd = m_adcConverter.configAdcConverter();    //aan 'setupGeslaagd' kan je nog bepaalde voorwaarde
                                                                 // hangen, bijvoorbeeld dat je dan geen ADC conversie mag doen

//  m_adcConverter.configAdcConverter();                        //Zo mag  het ook, de teruggestuurde bool wordt nu genegeerd

/****************************************************************************************************************************************/

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
//    if(ui->progressBar->value() <= 50)
//    {
//        ui->progressBar->setValue(75);
//    }
//    else
//    {
//        ui->progressBar->setValue(25);
//    }

    /****************************************************************************************************************************************/

    int meetWaarde = m_adcConverter.doAdcConversie(1);

    ui->progressBar->setValue(meetWaarde); //Doe een meting op adc nr. 1 en return deze direct naar de progressbar,
                                                                 //je kan deze ook eerst los opslaan en later gebruiken
                                                                 //VB: int meeting = m_adcConverter.doAdcConversie(1);

    /****************************************************************************************************************************************/

    qDebug() << "Value set at: " << meetWaarde;   //Geef debug informatie in de application output
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
