#include "src/widget/drawingtool/olygon.h"
#include <QPainter>
#include <QDebug>

#include<stdio.h>

Olygon::Olygon(QPointF position)
{
    addVertex(position);
    beingCreated = true;
}
QPolygonF Olygon::getPoints() const
{
    QPolygonF points;
    for(int i = 0; i < vertices.size(); i++){
        points.append(QPointF(vertices.data()[i]->x()+RADIUS,vertices.data()[i]->y()+RADIUS));
//        qDebug("appended point at x:%f y: %f", vertices.data()[i]->x()+RADIUS,vertices.data()[i]->y()+RADIUS);
    }
    if (!beingCreated){
        points.append(QPointF(vertices.at(0)->x()+RADIUS,vertices.at(0)->y()+RADIUS));
    }
    qDebug("points.at(0)->x(): %f", points.at(0).x());
    if(points.size()>1) qDebug("points.at(1)->x(): %f", points.at(1).x());
    qDebug("points size: %d", points.size());
    //for(int i =0; i < points.size(); i++){qDebug("there's a point at x:%f y: %f", vertices.data()[i]->x()+RADIUS,vertices.data()[i]->y()+RADIUS);}
    return points;
}

void Olygon::updateOlygon()
{
    QPainterPath path;

    QPolygonF poly = getPoints();

    //Test that the Olygon has multiple vertices before drawing
    if(vertices.size() > 1)
        path.addPolygon(getPoints());

    prepareGeometryChange();
    setPath(path);
    qDebug("Olygon got updated.");
}

void Olygon::completeOlygon(){
    beingCreated = false;
    setFlag(ItemIsMovable);
    updateOlygon();
    qDebug("Olygon Complete");
}

Vertex* Olygon::firstVertex() const
{
    return vertices.at(0);
}

void Olygon::addVertex(QPointF point)
{
    Vertex *vertex = new Vertex(this, point);
    vertices.append(vertex);
    vertex->setParentItem(this);
    updateOlygon();
}

void Olygon::makePolygon(QVector<QPointF> * polygonPoints){
    if(polygonPoints->size() <= 2){
        qDebug("Attempting to create Polygon with invalid number of vertices");
        return;
    }

    for(int i = 1; i<polygonPoints->size(); i++){
        addVertex(polygonPoints->at(i));
    }
    completeOlygon();
}
