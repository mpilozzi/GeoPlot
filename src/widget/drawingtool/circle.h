#ifndef CIRCLE_H
#define CIRCLE_H

#include <QGraphicsEllipseItem>
#include <QPointF>
#include "src/widget/targets/target.h"

class Circle : public QGraphicsEllipseItem
{
public:
    Circle(QPointF position, float radius);
    Circle(Target *target);
};

#endif // CIRCLE_H
