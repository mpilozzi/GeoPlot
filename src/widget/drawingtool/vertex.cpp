#include "src/widget/drawingtool/vertex.h"
#include "src/widget/drawingtool/olygon.h"
#include <QPainter>
#include <QBrush>
#include <QDebug>


Vertex::Vertex(Olygon *pOly, QPointF position)
{
   parentOlygon = pOly;
   pressed = false;
   setPos(position);
   setFlag(ItemIsMovable);
}

void Vertex::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (isUnderMouse()){
        prepareGeometryChange();
        //painter->setBrush(QBrush)
        painter->drawEllipse(boundingRect());
    }
    //*
    else{
        //painter->drawRect(pos().x()-RADIUS,pos().y()-RADIUS,RADIUS,RADIUS);
        painter->drawRect(boundingRect());
        update();
    }
    //*/
}

QRectF Vertex::boundingRect() const
{
    return QRectF(0,0,RADIUS*2,RADIUS*2);
}

void Vertex::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug("clicked vertex");
    pressed = true;
    update();

    if (this == parentOlygon->firstVertex()){
        if (parentOlygon->beingCreated){
            parentOlygon->completeOlygon();
        }
    }

    QGraphicsItem::mousePressEvent(event);
}

void Vertex::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    pressed = false;
    update();
    parentOlygon->updateOlygon();
    QGraphicsItem::mouseReleaseEvent(event);
}

void Vertex::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    parentOlygon->updateOlygon();
    QGraphicsItem::mouseMoveEvent(event);
}
