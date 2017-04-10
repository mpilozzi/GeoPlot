#ifndef VERTEX_H
#define VERTEX_H
#include <QGraphicsItem>
#include <QPointF>
#include <QRectF>

#define RADIUS 4

class Olygon;

class Vertex : public QGraphicsItem
{
public:
    bool pressed;

    Vertex(Olygon *pOly, QPointF position);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

//    bool isFirst

private:
    Olygon *parentOlygon;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // VERTEX_H
