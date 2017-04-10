#include "target.h"
#include <QGraphicsSceneMouseEvent>
#include "src/widget/dropdown.h"
#include "backgrounddrawer.h"
#include "src/widget/geoscene.h"

GeoScene* Target::sp_scene = nullptr;
QRectF Target::s_defaultBoundingRect = QRectF(-10, -10, 20, 20);
int Target::_maxPositionDots = 20;

Target::Target() : QGraphicsObject(nullptr)
{
    setAcceptHoverEvents(true);
}

QString Target::getAnnotationString() const
{
    return _annotationString;
}

double Target::getDirection() const
{
    return _direction;
}

TargetCategory Target::getCategory() const
{
    return _category;
}

double Target::getSpeed() const
{
    return _speed;
}

TargetThreat Target::getThreat() const
{
    return _threat;
}

void Target::setAnnotationString(QString str)
{
    _annotationString.clear();
    _annotationString.append(str);
}

void Target::setDirection(double dir)
{
    _direction = dir;
}

void Target::setCategory(TargetCategory category)
{
    _category = category;
}

void Target::setSpeed(double speed)
{
    _speed = speed;
}

void Target::setThreat(TargetThreat threat)
{
    _threat = threat;
}

void Target::setPos(const QPointF point)
{
    QGraphicsItem::setPos(point);
}

void Target::setPos(qreal x, qreal y)
{
    QGraphicsItem::setPos(x, y);
}

void Target::setPos(QPointF origin, Length distance, Angle bearing)
{
    if(sp_scene == nullptr)
    {
        qDebug("The static plot pointer was not set. Aborting setPos()");
        return;
    }

    QPointF delta;
    delta.setX(sp_scene->distanceToPixels(distance * cos(bearing.toRadians())));
    delta.setY(sp_scene->distanceToPixels(distance * sin(bearing.toRadians())));

    this->setPos(origin + delta);
}

void Target::placePositionDot()
{
    TargetPositionDot *newDot = new TargetPositionDot(pos());
    _positionDots.append(newDot);
    sp_scene->addItem(newDot);

    while(_positionDots.size() > _maxPositionDots)
    {
        delete _positionDots.first(); // Free the memory
        _positionDots.removeFirst(); // Remove the nullptr from the list
    }

    qDebug("%d", _positionDots.size());
}

void Target::clearPositionDots()
{
    // Free and remove all dots from list from back to front
    for(QList<TargetPositionDot *>::ConstIterator iterator = _positionDots.end(), beginning = _positionDots.begin(); iterator != beginning; --iterator)
    {
        delete *iterator; // Free the dot
        _positionDots.removeLast();
    }
}

void Target::drawBackground(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) const
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Target::drawAnnotationText(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) const
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QRectF rect = boundingRect();

    // Make rect an extremely wide rectangle 5 units below the target
    rect.setTop(rect.bottom());
    rect.setBottom(rect.top() + 15); // 15 is about the size of the default text's height
    rect.setLeft(rect.left() - 1000000);
    rect.setRight(rect.right() + 1000000);

    painter->drawText(rect, Qt::AlignVCenter | Qt::AlignHCenter, getAnnotationString());
}

QRectF Target::boundingRect() const
{
    return s_defaultBoundingRect;
}

void Target::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    drawBackground(painter, option, widget);
    drawForeground(painter, option, widget);
    drawAnnotationText(painter, option, widget);
    scene()->update();
}

void Target::hoverEnterEvent(QGraphicsSceneHoverEvent * event)
{
    Q_UNUSED(event);

    _hoverFlag = true;
    update();
}

void Target::hoverLeaveEvent(QGraphicsSceneHoverEvent * event)
{
    Q_UNUSED(event);

    _hoverFlag = false;
    update();
}

void Target::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);

    if(event->button() == Qt::RightButton)
    {
        Dropdown *d = new Dropdown(this);
        d->exec(QCursor::pos());

    }
}

void Target::setScenePointer(GeoScene *ptr)
{
    sp_scene = ptr;
}

void Target::setDefaultBoundingRect(QRectF rect)
{
    s_defaultBoundingRect = rect;
}

void Target::setMaxPositionDots(int maxPositionDots)
{
    _maxPositionDots = maxPositionDots;
}

void Target::destruct()
{
    delete this;
}
