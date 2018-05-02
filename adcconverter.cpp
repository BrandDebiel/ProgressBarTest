#include "adcconverter.h"

AdcConverter::AdcConverter(QObject *parent) : QObject(parent)
{

}

bool AdcConverter::configAdcConverter()
{
    //Setup de i2c bus en de ADC converter
    bool setupIsGeslaagd = false;

    //Setup geslaagd dan:
    setupIsGeslaagd = true;

    //Setup niet geslaagd
    //setupIsGeslaagd = false;

    return setupIsGeslaagd;
}

int AdcConverter::doAdcConversie(int poortNummer)
{
    //Doe hier de ADC meting

    //Doe de adcConversie van pin = poortNummer en sla de waarde op in dit geval in een integer
    int adcWaarde = 658; //In dit geval is 658 gemeten


    return adcWaarde;
}
