#include "engine.h"


Engine::Engine() : Mileage("mileage.txt")
{

}

QString Engine::getDesignation(){ return designation; }
void Engine::setDesignation(QString p){
    designation = p;
    emit engineStateChanged();
}

int Engine::getPerformance(){ return performance; }
void Engine::setPerformance(int p){
    performance = p;
    emit engineStateChanged();
}

int Engine::getIdleRPM(){  return idleRPM; }
void Engine::setIdleRPM(int p) {
    idleRPM = p;
    emit engineStateChanged();
}

int Engine::getRPM() {  return rpm;  }
void Engine::setRPM(int p){
    //if (p < idleRPM)        rpm = idleRPM;
    if ( p > maxRPM )  rpm = maxRPM;
    else                    rpm = p;

    double divisor {static_cast<double>(maxRPM)};                               // Der Verbrauch ist direkt proportional
    if (divisor == 0.0) divisor = 0.1;                                          // zur Drehzahl und wird daher
    consumption = ( static_cast<double>(rpm) / divisor ) * maxConsumption;      // Verhältnismässig berechnet

    emit engineStateChanged();
}

int Engine::getMaxRPM(){ return maxRPM; }
void Engine::setMaxRPM(int p){
    maxRPM = p;
    emit engineStateChanged();
}

int Engine::getGear() {  return gear;  }
void Engine::setGear(int p) {
    if ( p <= -1 )     {
        gear = -1;
        rpm = idleRPM;
    }
    else if ( p > maxGear)  gear = maxGear;
    else{
        if (p < gear){
            rpm = static_cast<int>(static_cast<double>(gear-p)*1.3*rpm);
        }
        else if(p>gear) {
            rpm =  static_cast<int>(static_cast<double>(p-gear)*0.7*rpm);
        }
        gear = p;
    }
    emit engineStateChanged();
}

int Engine::getMaxGear(){ return maxGear; }
void Engine::setMaxGear(int p){
    if (p < 1) maxGear=1;
    else maxGear = p;
    emit engineStateChanged();
}

int Engine::getThrottle() { return throttle;  }
void Engine::setThrottle(int p) {
    int thr_inc = p;

    throttle = p;
    emit engineStateChanged();
}

int Engine::getBrakes() { return brakes; }
void Engine::setBrakes(int p) {
    brakes = p;
    emit engineStateChanged();
}

double Engine::getConsumption() {  return consumption; }
void Engine::setConsumption(double p) {
    if (p > maxConsumption)     consumption = maxConsumption;
    else if (p < 0.0)           consumption = 0.0;
    else                        consumption = p;
    emit engineStateChanged();
}

double Engine::getMaxConsumption(){  return maxConsumption;}
void Engine::setMaxConsumption(double p){
    if (p < 0.0) maxConsumption = 0.0;
    else         maxConsumption = p;
    emit engineStateChanged();
}


