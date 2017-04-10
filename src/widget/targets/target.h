#ifndef TARGET_H
#define TARGET_H

#include <QPoint>
#include <QGraphicsItem>
#include "targetenums.h"
#include <QList>
#include "src/widget/units/units.h"
#include "src/widget/targets/targetpositiondot.h"

class GeoScene;

class Target : public QGraphicsObject
{
    Q_OBJECT

    public:
        Target();
        Target(Target* start, QPointF delta);

        QString getAnnotationString() const;
        double getDirection() const;
        TargetCategory getCategory() const;
        double getSpeed() const;
        TargetThreat getThreat() const;

        void setAnnotationString(QString str);
        void setDirection(double dir);
        void setCategory(TargetCategory category);
        void setSpeed(double speed);
        void setThreat(TargetThreat threat);

        void setPos(const QPointF point);
        void setPos(qreal x, qreal y);
        void setPos(QPointF origin, Length distance, Angle bearing);

        void placePositionDot();
        void clearPositionDots();

        virtual void drawBackground(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) const;
        virtual void drawForeground(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) const = 0;
        void drawAnnotationText(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) const;

        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

        virtual void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
        virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
        virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

        static void setScenePointer(GeoScene *ptr);
        static void setDefaultBoundingRect(QRectF rect);
        static void setMaxPositionDots(int maxPositionDots);

    private:
        double _speed;
        double _direction;

        QString _annotationString;
        TargetCategory _category;
        TargetThreat _threat;

        static QRectF s_defaultBoundingRect;
        static int _maxPositionDots;
        static GeoScene *sp_scene;

    protected:
        QList<TargetPositionDot *> _positionDots;
        bool _hoverFlag = false;

    private slots:
        void destruct();
};

#endif // TARGET_H
