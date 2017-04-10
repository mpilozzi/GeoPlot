#ifndef DRAWINGTOOL_H
#define DRAWINGTOOL_H

#include <QGraphicsScene>
#include <QPointF>
#include "src/widget/drawingtool/vertex.h"
#include "src/widget/drawingtool/olygon.h"
#include "src/widget/drawingtool/circle.h"
#include "src/widget/drawingtool/text.h"
#include "src/widget/drawingtool/bitmap.h"
#include "src/widget/drawingtool/measuringtool.h"
#include "src/widget/drawingtool/drawingtoolstateenum.h"

class Olygon;


class DrawingTool : public QObject
{
    public:
        DrawingTool(QGraphicsScene *scene);

        //Measuring Tool
        void createMeasuringTool(QPointF point);


        //Arbitrary Drawings
        void addVertexToOlygon(QPointF point);
        void createOlygon(QPointF point);
        void createCircle(QPointF point, float radius);
        void createLine(QPointF p1, QPointF p2);
        void createText(QPointF position, QString text);
        void createBitmap(QPointF position, QPixmap &pixmap);

        DrawingToolState getState();
        void setState(DrawingToolState state);

        bool mousePressSceneEvent(QPointF scenePos);
        bool mouseMoveSceneEvent(QPointF scenePos);
        void mouseReleaseSceneEvent();

private:
        DrawingToolState _state = DrawingToolState::OFF;
        QGraphicsScene *p_scene;
        Olygon *p_currentOlygon;
        MeasuringTool *p_measuringTool;
        void updateState();
};

#endif // DRAWINGTOOL_H
