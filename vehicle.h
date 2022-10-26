#ifndef VEHICLE_H
#define VEHICLE_H

#include <QTimer>
#include <QTime>
#include "engine.h"
#include "heading.h"



class Vehicle : public Engine
{
    Q_OBJECT

    Q_PROPERTY(int velocity READ getVelocity WRITE setVelocity NOTIFY velocityChanged)
    Q_PROPERTY(int maxVelocity READ getMaxVelocity WRITE setMaxVelocity NOTIFY velocityChanged)
    Q_PROPERTY(QString currentTime READ getCurrentTime WRITE setCurrentTime NOTIFY currentTimeChanged)


    int velocity{0};
    int maxVelocity{240};
    Heading heading;

    QString currentTime;
    QTimer *mileage_measure_timer;
    QTimer *time_timer;

public:
    Vehicle();

    int getVelocity();      void setVelocity(int p);
    int getMaxVelocity();   void setMaxVelocity(int p);
    void compute_driven_distance();

    QString getCurrentTime();   void setCurrentTime(QString);

public slots:
    void measureDistance();
    void updateTime();

signals:
    void velocityChanged();
    void currentTimeChanged();

};

#endif // VEHICLE_H
