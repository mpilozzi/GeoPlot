#include "backgrounddrawer.h"
#include <qmath.h>

BackgroundDrawer::BackgroundDrawer()
{

}

void BackgroundDrawer::drawBackgroundSymbol(const Target *tar, QPainter *painter)
{
    switch(tar->getThreat())
    {
        case TargetThreat::FRIENDLY:
            switch(tar->getCategory())
            {
                case TargetCategory::SUBSURFACE:
                    drawFriendlySubSurface(painter, tar->boundingRect());
                    break;
                case TargetCategory::SURFACE:
                    drawFriendlySurface(painter, tar->boundingRect());
                    break;
                case TargetCategory::AIR:
                    drawFriendlyAir(painter, tar->boundingRect());
                    break;
            }
            break;

        case TargetThreat::HOSTILE:
            switch(tar->getCategory())
            {
                case TargetCategory::SUBSURFACE:
                    drawHostileSubSurface(painter, tar->boundingRect());
                    break;
                case TargetCategory::SURFACE:
                    drawHostileSurface(painter, tar->boundingRect());
                    break;
                case TargetCategory::AIR:
                   drawHostileAir(painter, tar->boundingRect());
                    break;
            }
            break;

        case TargetThreat::NEUTRAL:
            switch(tar->getCategory())
            {
                case TargetCategory::SUBSURFACE:
                    drawNeutralSubSurface(painter, tar->boundingRect());
                    break;
                case TargetCategory::SURFACE:
                    drawNeutralSurface(painter, tar->boundingRect());
                    break;
                case TargetCategory::AIR:
                    drawNeutralAir(painter, tar->boundingRect());
                    break;
            }
            break;

        case TargetThreat::UNKNOWN:
            switch(tar->getCategory())
            {
                case TargetCategory::SUBSURFACE:
                    drawUnknownSubSurface(painter, tar->boundingRect());
                    break;
                case TargetCategory::SURFACE:
                    drawUnknownSurface(painter, tar->boundingRect());
                    break;
                case TargetCategory::AIR:
                    drawUnknownAir(painter, tar->boundingRect());
                    break;
            }
            break;
    }

}


void BackgroundDrawer::drawUnknownAir(QPainter *painter, QRectF rect)
{
    QPen pen(QColor::fromRgb(255,255,128,255));

    painter->setPen(pen);
    painter->setBrush(QColor::fromRgb(255,255,128,255));
    painter->drawEllipse(rect.x()+rect.width()/4.0,rect.y(),rect.width()/2.0,rect.height()/2.0);
    painter->drawEllipse(rect.x(),rect.y()+rect.height()/4.0,rect.width()/2.0,rect.height()/2.0);
    painter->drawEllipse(rect.x()+rect.width()/2.0,rect.y()+rect.height()/4.0,rect.width()/2.0,rect.height()/2.0);
    pen.setBrush(Qt::black);
    painter->setPen(pen);
    painter->drawArc(rect.x()+rect.width()/4.0,rect.y(),rect.width()/2.0,rect.height()/2.0, 0.0*16.0, 180.0*16.0);
    painter->drawArc(rect.x(),rect.y()+rect.height()/4.0,rect.width()/2.0,rect.height()/2.0, 90.0*16.0, 180.0*16.0);
    painter->drawArc(rect.x()+rect.width()/2.0,rect.y()+rect.height()/4.0,rect.width()/2.0,rect.height()/2.0, 270.0*16.0, 180.0*16.0);
}

void BackgroundDrawer::drawFriendlyAir(QPainter *painter, QRectF rect)
{
    QPen pen(Qt::black, 2);

    pen.setBrush(QColor::fromRgb(128,224,225,255));
    painter->setPen(pen);
    painter->setBrush(QColor::fromRgb(128,224,225,255));
    painter->drawEllipse(-rect.width()/2, -rect.height()*0.75, rect.width(), rect.height()*1.5);

    pen.setBrush(Qt::black);
    painter->setPen(pen);
    painter->drawArc(-rect.width()/2, -rect.height()*0.75, rect.width(), rect.height()*1.5, 320*16, 260*16);
}

void BackgroundDrawer::drawNeutralAir(QPainter *painter, QRectF rect)
{

    QPen pen(Qt::black, 2);

    pen.setBrush(Qt::black);
    painter->setPen(pen);
    painter->setBrush(QColor::fromRgb(170,255,170,255));
    painter->drawRect(rect);
    pen.setColor(QColor::fromRgb(170,255,170,255));
    painter->setPen(pen);
    painter->drawLine(rect.topLeft(), rect.topRight());

}

void BackgroundDrawer::drawHostileAir(QPainter *painter, QRectF rect)
{
    QPen pen(Qt::black, 2);

    static const QPointF pointsHostile[5] = {
        QPointF(rect.bottomRight()), //bottom right
        QPointF(rect.bottomLeft()), //bottom left
        QPointF(-rect.width()/2, rect.height()/16.0), //top left
        QPointF(0, -rect.height()/2), //middle top
        QPointF(rect.width()/2, rect.height()/16.0) //top right
    };
    pen.setBrush(Qt::black);
    painter->setPen(pen);
    painter->setBrush(QColor::fromRgb(255,128,128,255));
    painter->drawConvexPolygon(pointsHostile, 5);
    pen.setColor(QColor::fromRgb(255,128,128,255));
    painter->setPen(pen);
    painter->drawLine(rect.bottomLeft(), rect.bottomRight());
}

void BackgroundDrawer::drawUnknownSubSurface(QPainter *painter, QRectF rect)
{
    QPen pen(QColor::fromRgb(255,255,128,255));

    painter->setPen(pen);
    painter->setBrush(QColor::fromRgb(255,255,128,255));
//    painter->drawEllipse(rect.x()+rect.width()/4.0,rect.y(),rect.width()/2.0,rect.height()/2.0);
    painter->drawEllipse(rect.x()+rect.width()/4.0,rect.y()+rect.height()/2.0,rect.width()/2.0,rect.height()/2.0);
    painter->drawEllipse(rect.x(),rect.y()+rect.height()/4.0,rect.width()/2.0,rect.height()/2.0);
    painter->drawEllipse(rect.x()+rect.width()/2.0,rect.y()+rect.height()/4.0,rect.width()/2.0,rect.height()/2.0);
    pen.setBrush(Qt::black);
    painter->setPen(pen);
//    painter->drawArc(rect.x()+rect.width()/4.0,rect.y(),rect.width()/2.0,rect.height()/2.0, 0.0*16.0, 180.0*16.0);
    painter->drawArc(rect.x()+rect.width()/4.0,rect.y()+rect.height()/2.0,rect.width()/2.0,rect.height()/2.0, 180.0*16.0, 180.0*16.0);
    painter->drawArc(rect.x(),rect.y()+rect.height()/4.0,rect.width()/2.0,rect.height()/2.0, 90.0*16.0, 180.0*16.0);
    painter->drawArc(rect.x()+rect.width()/2.0,rect.y()+rect.height()/4.0,rect.width()/2.0,rect.height()/2.0, 270.0*16.0, 180.0*16.0);
}

void BackgroundDrawer::drawFriendlySubSurface(QPainter *painter, QRectF rect)
{
    QPen pen(Qt::black, 2);

    pen.setBrush(QColor::fromRgb(128,224,225,255));
    painter->setPen(pen);
    painter->setBrush(QColor::fromRgb(128,224,225,255));
    painter->drawEllipse(-rect.width()/2, -rect.height()*0.75, rect.width(), rect.height()*1.5);

    pen.setBrush(Qt::black);
    painter->setPen(pen);
    painter->drawArc(-rect.width()/2, -rect.height()*0.75, rect.width(), rect.height()*1.5, 140*16, 260*16);
}

void BackgroundDrawer::drawNeutralSubSurface(QPainter *painter, QRectF rect)
{

    QPen pen(Qt::black, 2);

    pen.setBrush(Qt::black);
    painter->setPen(pen);
    painter->setBrush(QColor::fromRgb(170,255,170,255));
    painter->drawRect(rect);
    pen.setColor(QColor::fromRgb(170,255,170,255));

    painter->setPen(pen);
    painter->drawLine(rect.bottomLeft(), rect.bottomRight());
}

void BackgroundDrawer::drawHostileSubSurface(QPainter *painter, QRectF rect)
{
    QPen pen(Qt::black, 2);

    static const QPointF pointsHostile[5] = {
        QPointF(rect.topLeft()), //top left
        QPointF(rect.topRight()), //top right
        QPointF(rect.width()/2, rect.height()/16.0), //bottom right
        QPointF(0, rect.height()/2), //middle bottom
        QPointF(-rect.width()/2, rect.height()/16.0) //bottom left
    };
    pen.setBrush(Qt::black);
    painter->setPen(pen);
    painter->setBrush(QColor::fromRgb(255,128,128,255));
    painter->drawConvexPolygon(pointsHostile, 5);
    pen.setColor(QColor::fromRgb(255,128,128,255));
    painter->setPen(pen);
    painter->drawLine(rect.topLeft(), rect.topRight());
}

void BackgroundDrawer::drawUnknownSurface(QPainter *painter, QRectF rect)
{
    QPen pen(QColor::fromRgb(255,255,128,255));

    painter->setPen(pen);
    painter->setBrush(QColor::fromRgb(255,255,128,255));
    painter->drawEllipse(rect.x()+rect.width()/4.0,rect.y(),rect.width()/2.0,rect.height()/2.0);
    painter->drawEllipse(rect.x()+rect.width()/4.0,rect.y()+rect.height()/2.0,rect.width()/2.0,rect.height()/2.0);
    painter->drawEllipse(rect.x(),rect.y()+rect.height()/4.0,rect.width()/2.0,rect.height()/2.0);
    painter->drawEllipse(rect.x()+rect.width()/2.0,rect.y()+rect.height()/4.0,rect.width()/2.0,rect.height()/2.0);
    pen.setBrush(Qt::black);
    painter->setPen(pen);
    painter->drawArc(rect.x()+rect.width()/4.0,rect.y(),rect.width()/2.0,rect.height()/2.0, 0.0*16.0, 180.0*16.0);
    painter->drawArc(rect.x()+rect.width()/4.0,rect.y()+rect.height()/2.0,rect.width()/2.0,rect.height()/2.0, 180.0*16.0, 180.0*16.0);
    painter->drawArc(rect.x(),rect.y()+rect.height()/4.0,rect.width()/2.0,rect.height()/2.0, 90.0*16.0, 180.0*16.0);
    painter->drawArc(rect.x()+rect.width()/2.0,rect.y()+rect.height()/4.0,rect.width()/2.0,rect.height()/2.0, 270.0*16.0, 180.0*16.0);
}

void BackgroundDrawer::drawFriendlySurface(QPainter *painter, QRectF rect)
{
    QPen pen(Qt::black, 2);

    pen.setBrush(Qt::black);
    painter->setPen(pen);
    painter->setBrush(QColor::fromRgb(128,224,225,255));
    painter->drawEllipse(rect);
}

void BackgroundDrawer::drawNeutralSurface(QPainter *painter, QRectF rect)
{
    QPen pen(Qt::black, 2);

    pen.setBrush(Qt::black);
    painter->setPen(pen);
    painter->setBrush(QColor::fromRgb(170,255,170,255));
    painter->drawRect(rect);
}

void BackgroundDrawer::drawHostileSurface(QPainter *painter, QRectF rect)
{
    QPen pen(Qt::black, 2);

    static const QPointF pointsHostile[4] = {
        QPointF(rect.x()+rect.width()/2.0,rect.y()),
        QPointF(rect.x()+rect.width(),rect.y()+rect.height()/2.0),
        QPointF(rect.x()+rect.width()/2.0,rect.y()+rect.height()),
        QPointF(rect.x(),rect.y()+rect.height()/2.0),
    };
    pen.setBrush(Qt::black);
    painter->setPen(pen);
    painter->setBrush(QColor::fromRgb(255,128,128,255));
    painter->drawConvexPolygon(pointsHostile, 4);
}


