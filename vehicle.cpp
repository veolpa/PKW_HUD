#include "vehicle.h"

Vehicle::Vehicle() : Engine()
{

}


//int getVelocity();    void setVelocity(int p);

int Vehicle::getVelocity(){
    return velocity;
}

void Vehicle::setVelocity(int p){
    velocity = p;
    emit velocityChanged();
}
