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


void VelocityGauge::paint(QPainter *painter){
    QPen pen = painter->pen();


    pen.setWidth(1);
    pen.setColor(QColor("#a6023b"));
    painter->setPen(pen);
    painter->drawRect(0,0,m_width-1, m_height-1);
    painter->drawEllipse(0,0,m_width-1,m_height-1);

    int x0{m_width/2};
    int y0{m_height/2};
    int w{m_width/2};
    int h{m_height/2};

    int xc{x0 };
    int yc{y0 };


    pen.setColor("blue");
    painter->setPen(pen);


    //painter->drawLine(m_width/2, m_height/2, 0, m_height/2);
    double steps = 270 / static_cast<double>(m_v_max) ;
    double angle = -45 +(static_cast<double>(m_v) * steps);

    QString v_str;
    QFont font = painter->font();
    font.setPixelSize(20);
    pen.setColor("blue");
    painter->setPen(pen);
    painter->setFont(font);




    v_str.setNum(m_v);
    painter->drawText(QRect(0,0,m_width,m_height/2),Qt::AlignCenter, v_str);


    painter->translate(xc,yc);
    painter->rotate(angle);
    painter->translate(-xc,-yc);

    pen.setColor("#3d0217");
    pen.setWidth(6);
    painter->setPen(pen);
    painter->drawLine(m_width/2, m_height/2, 0, m_height/2);


    pen.setColor("#a6023b");
    pen.setWidth(4);
    painter->setPen(pen);
    painter->drawLine(m_width/2, m_height/2, 0, m_height/2);
    pen.setColor("white");
    pen.setWidth(1);
    painter->setPen(pen);
    painter->drawLine(m_width/2, m_height/2, 0, m_height/2);

}
