#include "combatantlinecarrier.h"
#include <QPen>
#include <QPainter>
#include <qmath.h>
#include "backgrounddrawer.h"

CombatantLineCarrier::CombatantLineCarrier() : Target()
{
}

void CombatantLineCarrier::drawBackground(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) const
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    BackgroundDrawer::drawBackgroundSymbol(this, painter);
}

void CombatantLineCarrier::drawForeground(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) const
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QRectF rect = boundingRect();

    static const QPointF pointsCombatantLine1[4] = {
        QPointF(rect.x()+rect.width()/8.0,rect.y()+rect.height()/2.0+rect.height()/32.0),
        QPointF(rect.x()+rect.width()/2.0,rect.y()+rect.height()/2.0+rect.height()/16.0),
        QPointF(rect.x()+rect.width()-rect.width()/8.0,rect.y()+rect.height()/2.0+rect.height()/32.0),
        QPointF(rect.x()+rect.width()/2.0,rect.y()+rect.height()-rect.height()/5.0)
    };

    QPen pen;
    pen.setBrush(Qt::black);
    painter->setPen(pen);
    painter->setBrush(Qt::black);
    painter->drawRect(rect.x()+rect.width()/4.0,rect.y()+rect.height()/3-rect.height()/32.0,rect.width()/2.0,rect.height()/16.0);//mast horizontal
    painter->drawRect(rect.x()+rect.width()/2.0-rect.width()/16.0,rect.y()+rect.height()/8.0+rect.height()/16.0,rect.width()/8.0,rect.height()/3.0);//mast vertical
    painter->drawConvexPolygon(pointsCombatantLine1, 4.0);//boat bottom
    painter->drawRect(rect.x()+rect.width()/2.5,/**/rect.y()+rect.height()/2.0-rect.height()/8.0,/**/rect.width()/5,/**/rect.height()/8.0);//boat top
}
