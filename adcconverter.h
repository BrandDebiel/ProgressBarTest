#ifndef ADCCONVERTER_H
#define ADCCONVERTER_H

#include <QObject>

class AdcConverter : public QObject
{
    Q_OBJECT

private:


public:
    explicit AdcConverter(QObject *parent = nullptr);

    bool configAdcConverter();
    int doAdcConversie(int poortNummer);


signals:

public slots:


};

#endif // ADCCONVERTER_H
