#include "rpm_bar_gauge.h"
#include "qlocale.h"

RPM_Bar_Gauge::RPM_Bar_Gauge(QQuickItem *parent) : QQuickPaintedItem(parent)
{

}

int RPM_Bar_Gauge::rpm(){  return m_rpm; }
void RPM_Bar_Gauge::setRpm(int p) {
    if( p > m_maxRpm) m_rpm = m_maxRpm;
    else if(p < 0) m_rpm=0;
    else m_rpm = p;

    emit rpmChanged();
    this->update();
}

int RPM_Bar_Gauge::maxRpm() {return m_maxRpm; }
void RPM_Bar_Gauge::setMaxRpm(int p) {
    m_maxRpm=p;
    if (m_maxRpm < 0) m_maxRpm=0;
    if (m_rpm > maxRpm()) m_rpm=m_maxRpm;
    emit maxRpmChanged();
    this->update();
}

int RPM_Bar_Gauge::gWidth() { return m_gWidth; }
void RPM_Bar_Gauge::setgWidth(int p)  {
    m_gWidth=p;
    emit gWidthChanged();
    this->update();
}

int RPM_Bar_Gauge::gHeight(){ return m_gHeight;}
void RPM_Bar_Gauge::setgHeight(int p) {
    m_gHeight=p;
    emit gHeightChanged();
    this->update();
}

bool RPM_Bar_Gauge::displayConsumption(){
    return m_display_consumption;
}
void RPM_Bar_Gauge::setDisplayConsumption (bool p){
    m_display_consumption = p;
    emit displayConsumptionChanged();
    this->update();
}


void RPM_Bar_Gauge::paint(QPainter *painter) {
    //painter->save();
    QPen pen = painter->pen();
    int x=0;
    int y=0;
    int width  = m_gWidth;
    int height = m_gHeight;


    std::vector<QString> green_to_red_gradient {

//        QString("#ff0000"),
        QString("#ff1900"),
//      QString("#ff3300"),
        QString("#ff4c00"),
//      QString("#ff6600"),
        QString("#ff7f00"),
//      QString("#ff9900"),
        QString("#ffb200"),
//      QString("#ffcc00"),
        QString("#ffe500"),
//      QString("#ffff00"),
        QString("#ffff00"),
//      QString("#e5ff00"),
        QString("#ccff00"),
//      QString("#b2ff00"),
        QString("#99ff00"),
//      QString("#7fff00"),
        QString("#66ff00"),
//      QString("#4cff00"),
        QString("#33ff00")};


    int max_bars = green_to_red_gradient.size();
    int step = m_maxRpm / max_bars;
    int max_steps = m_rpm / step;



    int bar_height = height / green_to_red_gradient.size();
    QRect rect;
    for (int i=max_steps; i>0; i--) {
        rect=QRect(0,height-(bar_height*i),width, height-(bar_height-(i+1))  );
        painter->fillRect(rect,QColor(green_to_red_gradient[ max_bars-i] ));
    }

    QFont font = painter->font();
    font.setPixelSize(bar_height);
    painter->setFont(font);

    QString rpm_str;
    rpm_str.setNum(m_rpm);
    double dsp = 20.0 / static_cast<double>(m_maxRpm) * static_cast<double>(m_rpm);

    if (m_display_consumption) {
        rpm_str = QLocale().toString(dsp,'g',2);

    }

    int ty= (max_bars*bar_height)-((max_steps)*bar_height);


    painter->drawText(QRect(0, ty, width, bar_height), Qt::AlignCenter,rpm_str );
    //painter->restore();

}
