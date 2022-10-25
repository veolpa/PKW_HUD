#ifndef VELOCITY_H
#define VELOCITY_H
#include <QObject>

class Velocity : public QObject
{
    Q_OBJECT

    Q_PROPERTY( double get_kmh  READ get_kmh)
    Q_PROPERTY( double get_mph  READ get_mph)
    Q_PROPERTY( double get_iso  READ get_iso)
    Q_PROPERTY( double set_iso  WRITE set_iso NOTIFY VelocityChanged)

    double iso;
public:
    Velocity(double p_iso=0.0);

    double get_kmh();
    double get_mph();
    double get_iso();   void set_iso(double p);

signals:
    double VelocityChanged();

};

#endif // VELOCITY_H
