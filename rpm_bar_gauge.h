#ifndef RPM_BAR_GAUGE_H
#define RPM_BAR_GAUGE_H

#include <QQuickPaintedItem>
#include <QPainter>
#include <QObject>
#include <vector>

//      Klasse zur Darstellung von Umdrehungen/Minute oder Sprit-Verbrauch in Bezug zu einem maximal möglichen Wert
//      von grün bis rot wachsenden Balkendarstellung



class RPM_Bar_Gauge : public QQuickPaintedItem
{
    Q_OBJECT

    Q_PROPERTY (int rpm       READ rpm      WRITE setRpm        NOTIFY rpmChanged)
    Q_PROPERTY (int maxRpm    READ maxRpm   WRITE setMaxRpm     NOTIFY maxRpmChanged)
    Q_PROPERTY (int gWidth    READ gWidth   WRITE setgWidth     NOTIFY gWidthChanged)
    Q_PROPERTY (int gHeight   READ gHeight  WRITE setgHeight    NOTIFY gHeightChanged)
    Q_PROPERTY (bool displayConsumption READ displayConsumption WRITE setDisplayConsumption NOTIFY displayConsumptionChanged)

    int m_rpm;          // aktuelle Umdrehungen/Minute
    int m_maxRpm;       //
    int m_gWidth;
    int m_gHeight;
    bool m_display_consumption;

public:
    explicit RPM_Bar_Gauge(QQuickItem *parent = nullptr);
    void paint (QPainter *painter) override;

    int rpm();      void setRpm(int p);
    int maxRpm();   void setMaxRpm(int p);
    int gWidth();   void setgWidth(int p);
    int gHeight();  void setgHeight(int p);

    bool displayConsumption();     void setDisplayConsumption (bool p);


signals:
    void rpmChanged();
    void maxRpmChanged();
    void gWidthChanged();
    void gHeightChanged();
    void displayConsumptionChanged();
};

#endif // RPM_BAR_GAUGE_H
