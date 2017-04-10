#ifndef GEOSCENE_H
#define GEOSCENE_H

#include <QGraphicsScene>
#include <QPixmap>
#include "src/widget/drawingtool/drawingtoolstateenum.h"
#include <QList>
#include "src/widget/units/units.h"
#include "QTimer"

// Class delcarations
class DrawingTool;
class Target;

class GeoScene : public QGraphicsScene
{
    Q_OBJECT

    private:
        QPixmap _backgroundImage;
        DrawingTool *p_drawingTool;

        QList<Target *> _targetList;
        double _distanceScale; // Pixels per unit distance (meter)
        double _targetPositionDotMsec;
        QTimer _timer;

    private slots:
        void placeTargetPositionDots();

    public:
        GeoScene();
        ~GeoScene();

        void drawBackground(QPainter *painter, const QRectF &rect);
        void setBackground(const char *imagePath);
        int getBackgroundWidth();

        void setDrawingToolState(DrawingToolState state);
        DrawingToolState getDrawingToolState();

        void addTarget(Target *target);
        double getDistanceScale();
        void setDistanceScale(double scale);
        double distanceToPixels(Length len);
        Length pixelsToDistance(double pixels);

        void clearAllPositionDots();
        void setPositionDotTimerInterval(int msec);
        void activatePositionDotTracking(bool activate);

        // Overides
        void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
        void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
        void timerEvent(QTimerEvent *event);
};

#endif // GEOSCENE_H
