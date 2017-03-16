#ifndef COMPASSFACTORY_H
#define COMPASSFACTORY_H
#include <QObject>
#include <qwt_compass.h>
#include <qwt_compass_rose.h>
#include <qwt_dial_needle.h>

class QwtCompass;

class CompassFactory: public QObject
{
    Q_OBJECT
public:
    explicit CompassFactory(QObject *parent);
    QwtCompass *createCompass(int pos);
};

#endif // COMPASSFACTORY_H
