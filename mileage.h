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

protected:
    QString mileage_fname;
    int mileage;

public:
    Mileage(int p_mileage=0);
    Mileage(QString p_fname);


    int getMileage();
    void setMileage(int p_mileage);
    void addMileage(int p_mileage_delta);

    QString getMileageFName();
    void setMileageFName(QString p_fname);
    void readMileageFromFile();
    void writeMileageToFile();

signals:
    void mileageChanged();
};

#endif // MILEAGE_H
