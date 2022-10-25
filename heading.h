#ifndef HEADING_H
#define HEADING_H
#include <QString>
#include <QObject>


constexpr int north=0;
constexpr int northeast=45;
constexpr int east=90;
constexpr int southeast=135;
constexpr int south=180;
constexpr int southwest=225;
constexpr int west=270;
constexpr int northwest=315;

class Heading : public QObject
{
    Q_OBJECT

    Q_PROPERTY( QString to_NEWS READ to_NEWS)
    Q_PROPERTY( int heading READ getHeading WRITE setHeading NOTIFY headingChanged)

int heading;                        // Himmelsrichtung 0-360°       (getter / setter siehe unten)
public:

    Heading(int p_heading=0);

    int getHeading();
    void setHeading(int p);
    QString to_NEWS();              // gibt Himmelsrichtung zurück (N, NW etc)

signals:
    void headingChanged();          // wird emitiert wenn sich Richtung ändert
};

#endif // HEADING_H
