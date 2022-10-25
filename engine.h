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



protected:
    QString designation;    // Modell Bezeichnung

    int performance{75};        // kW

    int rpm{0};
    int maxRPM{8000};
    int gear{0};
    int maxGear{6};

public:
    Engine();

    QString getDesignation();       void setDesignation(QString p);
    int getPerformance();           void setPerformance(int p);

    int getRPM();                   void setRPM(int p);
    int getMaxRPM();                void setMaxRPM(int p);
    int getGear();                  void setGear(int p);
    int getMaxGear();               void setMaxGear(int p);

signals:
    void engineStateChanged();
};

#endif // ENGINE_H
