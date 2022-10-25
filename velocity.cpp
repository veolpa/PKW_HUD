#include "velocity.h"

Velocity::Velocity(double p_iso) : iso{p_iso}
{

}

double Velocity::get_kmh(){ return iso * 3.6; }
double Velocity::get_mph(){ return iso * 2.237; }
double Velocity::get_iso(){ return iso;}

void   Velocity::set_iso(double p) {
    iso=p;
    emit VelocityChanged();
}


