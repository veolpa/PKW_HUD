#ifndef ENGINE_H
#define ENGINE_H

#include "mileage.h"

class Engine : public Mileage
{
    Q_OBJECT

    Q_PROPERTY(int rpm      READ getRPM     WRITE setRPM        NOTIFY engineStateChanged)
    Q_PROPERTY(int maxRPM   READ getMaxRPM  WRITE setMaxRPM     NOTIFY engineStateChanged)
    Q_PROPERTY(int gear     READ getGear    WRITE setGear       NOTIFY engineStateChanged)
    Q_PROPERTY(int maxGear  READ getMaxGear WRITE setMaxGear    NOTIFY engineStateChanged)
    Q_PROPERTY(double consumption      READ getConsumption         WRITE setConsumption    NOTIFY engineStateChanged)
    Q_PROPERTY(double maxConsumption   READ getMaxConsumption      WRITE setMaxConsumption NOTIFY engineStateChanged)


protected:
    QString designation;        // Modell Bezeichnung                       (getter / setter siehe unten)

    int performance{75};        // kW                                       (getter / setter siehe unten)

    int rpm{0};                 // Umdrehungen / Minute                     (getter / setter siehe unten)
    int maxRPM{8000};           // Maximale Umdrehungen / Minute            (getter / setter siehe unten)
    int gear{0};                // aktueller Gang (Annahme: -1 bis maxGear) (getter / setter siehe unten)
    int maxGear{6};             // letzter Gang                             (getter / setter siehe unten)
    double consumption{0.0};         // Verbrauch (direkt proportional zur Umdrehung)
    double maxConsumption{30.0};     // Maximaler Verbrauch

public:
    Engine();

    QString getDesignation();       void setDesignation(QString p);
    int getPerformance();           void setPerformance(int p);

    int getRPM();                   void setRPM(int p);
    int getMaxRPM();                void setMaxRPM(int p);
    int getGear();                  void setGear(int p);
    int getMaxGear();               void setMaxGear(int p);
    double getConsumption();           void setConsumption(double p);
    double getMaxConsumption();        void setMaxConsumption(double p);


signals:
    void engineStateChanged();
};

#endif // ENGINE_H
