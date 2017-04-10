#ifndef TARGETPOSITIONDOT_H
#define TARGETPOSITIONDOT_H

#include <QGraphicsItem>

class TargetPositionDot : public QGraphicsItem
{
    public:
        TargetPositionDot(QPointF position);

        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

        static void setDefaultBoundingRect(QRectF rect);

    private:
        static QRectF defaultBoundingRect;
};

#endif // TARGETPOSITIONDOT_H
