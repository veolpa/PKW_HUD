#include "engine.h"

Engine::Engine() : Mileage()
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

int Engine::getRPM() {  return rpm;  }
void Engine::setRPM(int p){
    if (p < 0)              rpm = 0;
    else if ( p > maxRPM )  rpm = maxRPM;
    else                    rpm = p;
    emit engineStateChanged();
}

int Engine::getMaxRPM(){ return maxRPM; }
void Engine::setMaxRPM(int p){
    maxRPM = p;
    emit engineStateChanged();
}

int Engine::getGear() {  return gear;  }
void Engine::setGear(int p) {
    if ( p < 1 )            gear = -1;
    else if ( p > maxGear)  gear = maxGear;
    else                    gear = p;
    emit engineStateChanged();
}

int Engine::getMaxGear(){ return maxGear; }
void Engine::setMaxGear(int p){
    if (p < 1) maxGear=1;
    else maxGear = p;
    emit engineStateChanged();
}
