#ifndef OLYGON_H
#define OLYGON_H
#include "src/widget/drawingtool/vertex.h"
#include <QVector>

class Olygon : public QGraphicsPathItem
{
public:
    bool beingCreated;
    bool pressed;
//    QVector<Vertex *> vertices;
    QGraphicsItemGroup group;

    Olygon(QPointF position);

//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
//    QRectF boundingRect() const;
//    QPainterPath shape() const;

    QPolygonF getPoints() const;
    void updateOlygon();
    void completeOlygon();

    Vertex *firstVertex() const;
    void addVertex(QPointF point);
    void makePolygon(QVector<QPointF> *polygonPoints);
private:
    QVector<Vertex *> vertices;
//    void mousePressEvent(QGraphicsSceneMouseEvent *event);
//    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
//    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
protected:
};

#endif // OLYGON_H
