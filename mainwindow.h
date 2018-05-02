#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "adcconverter.h"   //Voeg header file toe!!!

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTimer m_intervalTimer;     //Declareer timer object
    int m_intervalTime;         //Declareer gedeelde variabele

public slots:
    void changeProgressbar();   //Maak functie die kan fungeren als slot
    void startTheTimer();       //Maak functie die kan fungeren als slot

private:
    Ui::MainWindow *ui;

    /****************************************************************************************************************************************/
    AdcConverter m_adcConverter;    //Declareer het object (m_ omdat het een member variabele is, dit is cosmetisch)
    /****************************************************************************************************************************************/
};

#endif // MAINWINDOW_H
