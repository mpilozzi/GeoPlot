#include "src/widget/geoscene.h"
#include <QDebug>
#include <QPainter>
#include <QRectF>
#include "src/widget/drawingtool/drawingtool.h"
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>

GeoScene::GeoScene()
{
    p_drawingTool = new DrawingTool(this);

    _timer.setInterval(10000); // Default interval is 10 seconds
    connect(&_timer, SIGNAL(timeout()), this, SLOT(placeTargetPositionDots()));
}

GeoScene::~GeoScene()
{
    delete p_drawingTool;
}

void GeoScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    Q_UNUSED(rect);

    if (_backgroundImage.data_ptr() != nullptr)
        painter->drawPixmap(sceneRect().left(), sceneRect().top(), sceneRect().width(), sceneRect().height(), _backgroundImage);
}

void GeoScene::setBackground(const char *imagePath)
{
    if(!_backgroundImage.load(imagePath))
    {
        qDebug("In GeoScene::setBackground:\n  Failed to load image: %s", imagePath);
        return;
    }

    setSceneRect(_backgroundImage.rect());
}

int GeoScene::getBackgroundWidth()
{
    return _backgroundImage.width();
}

void GeoScene::setDrawingToolState(DrawingToolState state)
{
    p_drawingTool->setState(state);
}

DrawingToolState GeoScene::getDrawingToolState()
{
    return p_drawingTool->getState();
}

void GeoScene::addTarget(Target *target)
{
    _targetList.push_back(target);
}

double GeoScene::getDistanceScale()
{
    return _distanceScale;
}

void GeoScene::setDistanceScale(double scale)
{
    double difference = scale / _distanceScale;

    _distanceScale = scale;

    for(QList<Target *>::ConstIterator iterator = _targetList.begin(), end = _targetList.end(); iterator != end; ++iterator)
    {
        Target * target = (Target *)*iterator;
        target->setPos(target->pos() * difference);
    }
}

double GeoScene::distanceToPixels(Length len)
{
    return len.toMeters() * _distanceScale;
}

Length GeoScene::pixelsToDistance(double pixels)
{
    return Length(_distanceScale * pixels, true);
}

void GeoScene::clearAllPositionDots()
{
    for(QList<Target *>::ConstIterator iterator = _targetList.begin(), end = _targetList.end(); iterator != end; ++iterator)
    {
        Target * target = (Target *)*iterator;
        target->clearPositionDots();
    }
}

void GeoScene::setPositionDotTimerInterval(int msec)
{
    _timer.setInterval(msec);
}

void GeoScene::activatePositionDotTracking(bool activate)
{
    if(activate)
        _timer.start(_timer.interval());

    else
        _timer.stop();
}


void GeoScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(mouseEvent->button() == Qt::LeftButton)
    {
        if(p_drawingTool->mousePressSceneEvent(mouseEvent->scenePos()) == false){
            QGraphicsScene::mousePressEvent(mouseEvent);
        }
        else{
            views().at(0)->setDragMode(QGraphicsView::NoDrag);
        }
    }
    else
        QGraphicsScene::mousePressEvent(mouseEvent);
}

void GeoScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(p_drawingTool->mouseMoveSceneEvent(mouseEvent->scenePos()) == false)
        QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void GeoScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(mouseEvent->button() == Qt::LeftButton)
    {
        p_drawingTool->mouseReleaseSceneEvent();
    }
    views().at(0)->setDragMode(QGraphicsView::ScrollHandDrag);
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

void GeoScene::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);

    placeTargetPositionDots();
}

void GeoScene::placeTargetPositionDots()
{
    for(QList<Target *>::ConstIterator iterator = _targetList.begin(), end = _targetList.end(); iterator != end; ++iterator)
    {
        Target * target = (Target *)*iterator;
        target->placePositionDot();
    }
}
