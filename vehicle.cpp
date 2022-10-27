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

    connect (this, &Engine::engineStateChanged, this, &Vehicle::updateEngineState);


}


void Vehicle::updateEngineState(){

}


int Vehicle::getVelocity(){

    return velocity;

}
void Vehicle::setVelocity(int p){

    int v = velocity;

    if ( gear > 0)
        v = static_cast<int>((rpm * 0.0125 * pow(1.35, (gear-1))) );

    if (v > maxVelocity) velocity = maxVelocity;
    else if (v <= 0) velocity = 0;
    else velocity = v;

    if (velocity > 0 ) mileage_measure_timer->start(500);
    if (velocity  <= 0) mileage_measure_timer->stop();

    emit velocityChanged();
}

int Vehicle::getMaxVelocity() { return maxVelocity; }
void Vehicle::setMaxVelocity(int p){
        maxVelocity = p;
        emit velocityChanged();
}


//void Vehicle::setAccelerate(int p){
//    brakes = 0;
//    int RPM_increase = 500;

//    if (gear == 0) {
//        if      (rpm >  600) RPM_increase = 200;
//        else if (rpm > 4000) RPM_increase = 400;
//        else if (rpm > 5000) RPM_increase = 450;
//        else if (rpm > 7332) RPM_increase = 10;
//        else if (rpm > 7894) RPM_increase = 1;
//        else if (rpm > maxRPM) RPM_increase = 0;
//    } else if (gear > 0) RPM_increase=50;

//    rpm += RPM_increase;

//    velocity = static_cast<int>(rpm * 0.0125 * pow(1.35, (gear-1)));
//    emit velocityChanged();


//}
//void Vehicle::setDecelerate(int p){
//    throttle = 0;
//    if ( (velocity*3.6) > 80 ) velocity -= 10;
//    else velocity -= 1;
//    if (gear > 0){
//        rpm = 80*velocity/pow(1.35,(gear-1));
//        if(rpm < 100 ) {
//            // engine.shutdown();
//            rpm =0;
//        }
//    }

//    emit velocityChanged();
//}



QString Vehicle::getCurrentTime() {
    return currentTime;
}
void Vehicle::setCurrentTime(QString p) {
    currentTime = p;

    emit currentTimeChanged();
}

void Vehicle::measureDistance(){
    double traveled_distance = velocity * 0.25;
    addMileage(static_cast<int>(traveled_distance));
}

void Vehicle::updateTime(){
    setCurrentTime(QTime::currentTime().toString("hh:mm:ss"));
}

