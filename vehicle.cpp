#include "vehicle.h"

Vehicle::Vehicle() : Engine()
{
    mileage_measure_timer = new QTimer(this);
    mileage_measure_timer->setTimerType(Qt::CoarseTimer);
    connect (mileage_measure_timer, &QTimer::timeout, this, &Vehicle::measureDistance);

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

void Vehicle::measureDistance(){
    double traveled_distance = velocity * 0.1;
    addMileage(static_cast<int>(traveled_distance));
}
