#ifndef VELOCITYGAUGE_H
#define VELOCITYGAUGE_H

#include <QObject>
#include <QQuickPaintedItem>
#include <QPainter>


class VelocityGauge : public QQuickPaintedItem
{
    Q_OBJECT

    Q_PROPERTY(int mwidth READ mwidth WRITE setWidth NOTIFY mwidthChanged)
    Q_PROPERTY(int mheight READ mheight WRITE setHeight NOTIFY mheightChanged)
    Q_PROPERTY(int v_max READ v_max WRITE setV_max NOTIFY v_maxChanged)
    Q_PROPERTY(int v READ v WRITE setV NOTIFY vChanged)

    int m_width;
    int m_height;
    int m_v_max;
    int m_v;

public:
    VelocityGauge( QQuickItem *parent = nullptr);
    void paint(QPainter *painter) override;

    int mwidth();        void setWidth(int p);
    int mheight();       void setHeight(int p);
    int v_max();        void setV_max(int p);
    int v();            void setV(int p);

signals:
    void mwidthChanged();
    void mheightChanged();
    void v_maxChanged();
    void vChanged();

};

#endif // VELOCITYGAUGE_H
