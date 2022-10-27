#include "velocitygauge.h"

VelocityGauge::VelocityGauge(QQuickItem *parent){
    this->update();
}

int VelocityGauge::mwidth()              {return m_width;}
void VelocityGauge::setWidth(int p)     {
    m_width=p;
    emit widthChanged();
    this->update();
}
int VelocityGauge::mheight()             {return m_height;}
void VelocityGauge::setHeight(int p)    {
    m_height = p;
    emit heightChanged();
    this->update();
}
int VelocityGauge::v_max()              {return m_v_max;}
void VelocityGauge::setV_max(int p)     {
    m_v_max = p;
    emit v_maxChanged();
    this->update();
}
int VelocityGauge::v()                  {return m_v;};
void VelocityGauge::setV(int p)         {
    m_v = p;
    if (p > m_v_max) m_v = m_v_max;
    else if(p < 0) m_v=0;
    emit vChanged();
    this->update();
}

bool VelocityGauge::isRpm(){ return isRPM; }
void VelocityGauge::setIsRpm(bool p){
    isRPM=p;
}


void VelocityGauge::paint(QPainter *painter){
    QPen pen = painter->pen();


    pen.setWidth(1);
    pen.setColor(QColor("#a6023b"));
    painter->setPen(pen);
    painter->drawRect(0,0,m_width-1, m_height-1);
    painter->drawEllipse(0,0,m_width-1,m_height-1);

    int x0{m_width/2};
    int y0{m_height/2};
//    int w{m_width/2};
//    int h{m_height/2};

//    int xc{x0 };
//    int yc{y0 };


    pen.setColor("lightblue");
    painter->setPen(pen);


    //painter->drawLine(m_width/2, m_height/2, 0, m_height/2);
    double steps = 270 / static_cast<double>(m_v_max) ;
    const double angle = 225-(static_cast<double>(m_v) * steps);

    QString v_str;
    QString unit_name;
    if (isRPM) unit_name="Rot/m";
    else unit_name="km/h";
    QFont font = painter->font();
    font.setPixelSize(20);
    pen.setColor("lightblue");
    painter->setPen(pen);
    painter->setFont(font);

    v_str.setNum(m_v);
    painter->drawText(QRect(0,0,m_width,m_height/2),Qt::AlignCenter, v_str);


    font.setPixelSize(12);
    pen.setColor("lightblue");
    painter->setPen(pen);
    painter->setFont(font);
    painter->drawText(QRect(0,0,m_width,m_height/2+30),Qt::AlignCenter, unit_name);


    QLineF l1,l2;
    QPoint mpoint(m_width/2, m_height/2);

    std::array<double,5> RPMlst = {-40,23,90, 157,225};
    std::array<int,5> RPMDesclst = {800,2000,4000,6000,8000};

    std::array<double,8> Vlst = {191,168, 135, 112,  77,  46,   1, -45};
    std::array<int,8> VDesclst = {30, 50, 80, 100, 130, 160, 200, 240};

    if (isRPM){
        for (int i=0;i<RPMlst.size(); i++ ) {
            l1.setP1(mpoint);
            l1.setAngle(RPMlst[i]);
            l1.setLength(m_width/2-10);
            l2.setP1(l1.p2());
            l2.setAngle( RPMlst[i] );
            l2.setLength(10);
            painter->drawLine(l2);
            //painter->drawText( QRectF(l1.p2().x(),l1.p2().y(),50,20), QString::number(RPMDesclst[i]));
        }
    } else {
        for (double i : Vlst) {
            l1.setP1(mpoint);
            l1.setAngle(i);
            l1.setLength(m_width/2-10);
            l2.setP1(l1.p2());
            l2.setAngle(i);
            l2.setLength(10);
            painter->drawLine(l2);
        }
    }



    QLineF line;
    line.setP1(QPoint(m_width/2,m_height/2));
    line.setLength(m_width/2);
    line.setAngle(angle);
    pen.setColor("#3d0217");
    pen.setWidth(6);
    painter->setPen(pen);
    painter->drawLine(line);

    pen.setColor("#a6023b");
    pen.setWidth(4);
    painter->setPen(pen);
    painter->drawLine(line);

//    painter->translate(xc,yc);
//    painter->rotate(angle);
//    painter->translate(-xc,-yc);

//    pen.setColor("#3d0217");
//    pen.setWidth(6);
//    painter->setPen(pen);
//    painter->drawLine(m_width/2, m_height/2, 0, m_height/2);

//    pen.setColor("#a6023b");
//    pen.setWidth(4);
//    painter->setPen(pen);
//    painter->drawLine(m_width/2, m_height/2, 0, m_height/2);
//    pen.setColor("white");
//    pen.setWidth(1);
//    painter->setPen(pen);
//    painter->drawLine(m_width/2, m_height/2, 0, m_height/2);

}
