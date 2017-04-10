#include "targetpositiondot.h"
#include <QPainter>
#include <QPen>

QRectF TargetPositionDot::defaultBoundingRect = QRectF(-2.5, -2.5, 5, 5);

TargetPositionDot::TargetPositionDot(QPointF position)
{
    setPos(position);
}

QRectF TargetPositionDot::boundingRect() const
{
    return defaultBoundingRect;
}

void TargetPositionDot::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPen pen(Qt::black,1);
    pen.setBrush(Qt::black);
    painter->setPen(pen);
    painter->setBrush(Qt::black);
    painter->drawEllipse(boundingRect());
}

void TargetPositionDot::setDefaultBoundingRect(QRectF rect)
{
    defaultBoundingRect = rect;
}
