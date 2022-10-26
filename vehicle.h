#ifndef VEHICLE_H
#define VEHICLE_H

#include <QTimer>
#include "engine.h"
#include "heading.h"



class Vehicle : public Engine
{
    Q_OBJECT

    Q_PROPERTY(int velocity READ getVelocity WRITE setVelocity NOTIFY velocityChanged)
    Q_PROPERTY(int maxVelocity READ getMaxVelocity WRITE setMaxVelocity NOTIFY velocityChanged)

    int velocity{0};
    int maxVelocity{240};
    Heading heading;

    QTimer *mileage_measure_timer;

public:
    Vehicle();

    int getVelocity();      void setVelocity(int p);
    int getMaxVelocity();   void setMaxVelocity(int p);
    void compute_driven_distance();

public slots:
    void measureDistance();

signals:
    void velocityChanged();


};

#endif // VEHICLE_H
