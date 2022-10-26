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

    Q_PROPERTY(int accelerate WRITE setAccelerate)
    Q_PROPERTY(int decelerate WRITE setDecelerate)


    bool isMotorRunning{false};

    int velocity{0};
    int maxVelocity{240};

    int accelerate{0};
    int decelerate{0};

    Heading heading;

    QString currentTime;
    QTimer *mileage_measure_timer;
    QTimer *time_timer;

public:
    Vehicle();

    bool getIsMotorRunning();
    void setIsMotorRunning(bool p);

    int getVelocity();      void setVelocity(int p);
    int getMaxVelocity();   void setMaxVelocity(int p);


    QString getCurrentTime();   void setCurrentTime(QString);

    void setAccelerate(int p_amount);
    void setDecelerate(int p_amount);

public slots:
    void measureDistance();
    void updateTime();

signals:
    void velocityChanged();
    void currentTimeChanged();

};

#endif // VEHICLE_H
