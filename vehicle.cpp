#include "vehicle.h"

Vehicle::Vehicle() : Engine()
{
    mileage_measure_timer = new QTimer(this);
    mileage_measure_timer->setTimerType(Qt::CoarseTimer);

    time_timer = new QTimer(this);
    time_timer->setTimerType(Qt::CoarseTimer);
    time_timer->start(1000);

    connect (mileage_measure_timer, &QTimer::timeout, this, &Vehicle::measureDistance);
    connect (time_timer, &QTimer::timeout, this, &Vehicle::updateTime);

}


//int getVelocity();    void setVelocity(int p);

int Vehicle::getVelocity(){ return velocity; }
void Vehicle::setVelocity(int p){
    if (velocity <= 0 && p  > 0) mileage_measure_timer->start(100);
    if (velocity  > 0 && p <= 0) mileage_measure_timer->stop();

    if (p > maxVelocity) velocity=maxVelocity;
    else if (p < 0) velocity=0;
    else velocity = p;
    emit velocityChanged();
}

int Vehicle::getMaxVelocity() { return maxVelocity; }
void Vehicle::setMaxVelocity(int p){
        maxVelocity = p;
        emit velocityChanged();
}

QString Vehicle::getCurrentTime() {
    return currentTime;
}
void Vehicle::setCurrentTime(QString p) {
    currentTime = p;

    emit currentTimeChanged();
}

void Vehicle::measureDistance(){
    double traveled_distance = velocity * 0.1;
    addMileage(static_cast<int>(traveled_distance));
}

void Vehicle::updateTime(){
    setCurrentTime(QTime::currentTime().toString("hh:mm:ss"));
}

//void Vehicle::currentTimeChanged(){}
