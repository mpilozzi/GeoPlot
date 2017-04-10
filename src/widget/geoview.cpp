#include "geoview.h"
#include <QtMath>
#include <QWheelEvent>
#include <QScrollBar>

GeoView::GeoView()
{
    setDragMode(ScrollHandDrag);

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

// Zoom in/out with mouse wheel
void GeoView::wheelEvent(QWheelEvent *event)
{
    const QPointF scenePoint = mapToScene(event->pos());

    double scalingFactor = qPow(1.2, event->delta() / 320.0);
    scale(scalingFactor, scalingFactor);

    const QPointF mousePos = mapFromScene(scenePoint);
    const QPointF scrollAmount = mousePos - event->pos(); // Amount to scroll to recenter mouse on original point

    // Recenter mouse on original point
    horizontalScrollBar()->setValue(scrollAmount.x() + horizontalScrollBar()->value());
    verticalScrollBar()->setValue(scrollAmount.y() + verticalScrollBar()->value());
}

void GeoView::mouseMoveEvent(QMouseEvent *event)
{
    invalidateScene(rect(), QGraphicsScene::ForegroundLayer);
    QGraphicsView::mouseMoveEvent(event);
}

void GeoView::drawForeground(QPainter *painter, const QRectF &rect)
{
    //Get current scale of the view
    float viewScale = (float)(rect.width())/(scene()->width());
    //qDebug("viewScale: %f", viewScale);
    QGraphicsView::size();

    //Get position to draw scale
    QPointF mapCoords(rect.x()/viewScale + 10, rect.y()/viewScale + 10);
    //Check if coords are outside of scene
    //TODO: This will probably not be necessary if the view is changed so that it can't zoom out farther than the scene.
    /*if(mapCoords.x() < 10)
        mapCoords.setX(10);
    if(mapCoords.y() < 10)
        mapCoords.setY(10);
    */

    //Set painter's pen and scale for drawing Scale Display
    painter->setPen(Qt::black);
    painter->scale(viewScale,viewScale);
    //Draw Scale Display
    QString distanceString;
    distanceString.setNum(100.0*viewScale);
    distanceString.append(" pixels");
    painter->drawText(QRectF(mapCoords.x(), mapCoords.y(), 100, 15), Qt::AlignCenter, distanceString);
    painter->drawLine(mapCoords.x(), mapCoords.y()+20, mapCoords.x()+100, mapCoords.y()+20);
}
