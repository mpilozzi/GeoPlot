#ifndef GEOVIEW_H
#define GEOVIEW_H

#include <QGraphicsView>


class GeoView : public QGraphicsView
{
    public:
        GeoView();

        void drawForeground(QPainter *painter, const QRectF &rect);

        void wheelEvent(QWheelEvent *event);
        void mouseMoveEvent(QMouseEvent *event);
};

#endif // GEOVIEW_H
