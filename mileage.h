#ifndef MILEAGE_H
#define MILEAGE_H
#include <QString>
#include <QTextStream>
#include <QFile>

#include <QObject>

class Mileage : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int mileage READ getMileage WRITE setMileage NOTIFY mileageChanged)
    Q_PROPERTY(QString mileage_fname READ getMileageFName WRITE setMileageFName NOTIFY mileageFNameChanged)


protected:
    QString mileage_fname{"mileage.txt"};       // Dateiname der Persistenz gelaufener Kilometer
    int mileage{0};                             // gelaufene Kilometer

public:
    Mileage(int p_mileage=0);                   // std-constructor
    Mileage(QString p_fname);                   // constructor veranlasst das Setzen der gelaufenen km auf den in p_fname hinterlegtem Wert
    ~Mileage();                                 // Destructor - writes mileage to disk

    int getMileage();                           // gibt aktuell gelaufene km zurück
    void setMileage(int p_mileage);             // setzt gelaufene km auf p_mileage
    void addMileage(int p_mileage_delta);       // fügt gelaufenen km p_mileage_delta hinzu

    QString getMileageFName();                  // ergibt den Namen der Datei in der gelaufene km gespeichert werden
    void    setMileageFName(QString p_fname);      // setzt den Namen der Datei in der gelaufene km gespeichert werden
    void    readMileageFromFile();                 // setzt gelaufene km(mileage) auf den in Datei (mileage_fname) hinterlegten Wert
    void    writeMileageToFile();                  // schreibt gelaufene km in Datei(mileage_fname)

signals:
    void mileageChanged();                      // wird emitiert wenn sich der Zustand des Objektes verändert
    void mileageFNameChanged();
};

#endif // MILEAGE_H
