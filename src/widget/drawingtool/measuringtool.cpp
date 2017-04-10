#include "measuringtool.h"

#include <QPainter>

QRectF MeasuringTool::boundingRect() const
{
    QRectF box(line.x1(), line.y1(), line.x2() - line.x1(), line.y2() - line.y1());
    box = box.normalized();
    return box;
}

void MeasuringTool::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black,2));
    painter->drawLine(line);
    painter->drawText(QPointF(startPoint.x() + 4, startPoint.y() + 4), distanceString);
}

MeasuringTool::MeasuringTool(QPointF point)
{
    startPoint = point;
    updateMeasureLine(startPoint);

}

void MeasuringTool::updateMeasureLine(QPointF cursorPoint)
{
    line = QLine(startPoint.x(), startPoint.y(), cursorPoint.x(), cursorPoint.y());
    distanceString = QString("Distance: " + QString::number(cursorPoint.x()));
}
