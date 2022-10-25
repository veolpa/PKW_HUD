#ifndef HEADING_H
#define HEADING_H
#include <QString>
#include <QObject>

//enum {north,northeast,east, southeast,south,southwest,west, northwest};
//enum class Heavenly_Orientation {north=0, northeast=45, east=90, southeast=135, south=180, southwest=225, west=270, northwest=315 };

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

int heading;
public:

    Heading(int p_heading=0);

    int getHeading();    void setHeading(int p);
    QString to_NEWS();
signals:
    void headingChanged();
};

#endif // HEADING_H
