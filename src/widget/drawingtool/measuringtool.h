#ifndef MEASURINGTOOL_H
#define MEASURINGTOOL_H

#include <QGraphicsItem>
#include <QPointF>
#include <QLine>
#include <QString>

class MeasuringTool : public QGraphicsItem
{
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    MeasuringTool(QPointF point);

    void updateMeasureLine(QPointF cursorPoint);

private:
    QPointF startPoint;
    QLine line;
    QString distanceString;
};

#endif // MEASURINGTOOL_H
