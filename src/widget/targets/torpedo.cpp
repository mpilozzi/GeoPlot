#include "torpedo.h"
#include <QPainter>
#include <QRectF>
#include <QDebug>
#include "backgrounddrawer.h"

Torpedo::Torpedo() : Target()
{
    ;
}

void Torpedo::drawBackground(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) const
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    BackgroundDrawer::drawBackgroundSymbol(this, painter);
}

void Torpedo::drawForeground(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) const
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QRectF rect = boundingRect();

    static const QPointF pointsTorpedo[7] = {
        QPointF(-rect.width()/4.0 - rect.width()/8.00, 0.0), //point
        QPointF(-rect.width()/4.0, -rect.height()/12.00), //lower point
        QPointF( rect.width()/4.0, - rect.height()/12.00), //lower body end
        QPointF( rect.width()/4.0 +  rect.width()/8.00, +rect.height()/12.00), //upper tail
        QPointF( rect.width()/4.0 +  rect.width()/8.00, -rect.height()/12.00), //lower tail
        QPointF( rect.width()/4.0, + rect.height()/12.00), //upper body end
        QPointF(-rect.width()/4.0,  +rect.height()/12.00) //upper point
    };

    QPen pen(Qt::black,1);
    pen.setBrush(Qt::black);
    painter->setPen(pen);
    painter->setBrush(Qt::black);
    painter->drawConvexPolygon(pointsTorpedo, 7);
}
