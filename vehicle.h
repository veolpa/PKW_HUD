#ifndef VEHICLE_H
#define VEHICLE_H

#include "engine.h"
#include "heading.h"

class Vehicle : public Engine
{
    Q_OBJECT

    Q_PROPERTY(int velocity READ getVelocity WRITE setVelocity NOTIFY velocityChanged)

    int velocity;
    Heading heading;
public:
    Vehicle();

    int getVelocity();    void setVelocity(int p);

signals:
    void velocityChanged();
};

#endif // VEHICLE_H
