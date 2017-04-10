#include "circle.h"

Circle::Circle(QPointF position, float radius) : QGraphicsEllipseItem(position.x(), position.y(), radius * 2, radius * 2)
{
    setPos(position);
    setFlag(ItemIsMovable);
}

Circle::Circle(Target *target)
{
    setPos(target->pos());
    setParentItem(target);
    setFlag(ItemIsMovable);
}
