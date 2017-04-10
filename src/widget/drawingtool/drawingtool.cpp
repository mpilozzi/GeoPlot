#include "drawingtool.h"
#include "olygon.h"
#include <QDebug>

DrawingTool::DrawingTool(QGraphicsScene *scene)
{
    p_scene = scene;
}

void DrawingTool::createMeasuringTool(QPointF point)
{
    if(_state != DrawingToolState::MEASURING_TOOL)
    {
        qDebug("ERROR: Attempting to use measuring tool from wrong state.");
        return;
    }

    //Create measuring tool
    p_measuringTool = new MeasuringTool(point);
    p_scene->addItem(p_measuringTool);

    //Transition to next state
    setState(DrawingToolState::MEASURING_TOOL_MOVE);
}

void DrawingTool::createOlygon(QPointF point)
{
    if(_state != DrawingToolState::CREATE_POLYGON)
    {
        qDebug("ERROR: Attempting to create polygon from wrong state.");
        return;
    }

    // Create the polygon
    Olygon* poly = new Olygon(point);
    p_scene->addItem(poly);
    p_currentOlygon = poly;

    // Transition to the next state
    setState(DrawingToolState::ADD_TO_POLYGON);
}

void DrawingTool::addVertexToOlygon(QPointF vertex)
{
    p_currentOlygon->addVertex(vertex);
}

void DrawingTool::createCircle(QPointF point, float radius){
    Circle* circle = new Circle(point, radius);
    p_scene->addItem(circle);
}

void DrawingTool::createLine(QPointF p1, QPointF p2)
{
    Olygon* line = new Olygon(p1);
    line->addVertex(p2);
    line->completeOlygon();
    p_scene->addItem(line);
}

void DrawingTool::createText(QPointF position, QString text){
    Text *textItem = new Text(position, text);
    p_scene->addItem(textItem);
}

void DrawingTool::createBitmap(QPointF position, QPixmap &pixmap)
{
    Bitmap *bitmap = new Bitmap(position, pixmap);
    p_scene->addItem(bitmap);
}

DrawingToolState DrawingTool::getState()
{
    updateState();
    return _state;
}

void DrawingTool::setState(DrawingToolState state)
{
    _state = state;
}

void DrawingTool::updateState()
{
    if(_state == DrawingToolState::ADD_TO_POLYGON)
    {
        if(!(p_currentOlygon->beingCreated))
        {
            p_currentOlygon = nullptr;
            setState(DrawingToolState::CREATE_POLYGON);
        }
    }
//    else if(_state == DrawingToolState::MEASURING_TOOL_MOVE)
//    {
//        p_measuringTool = nullptr;
//        setState(DrawingToolState::MEASURING_TOOL);
    //    }
}
bool DrawingTool::mousePressSceneEvent(QPointF scenePos)
{
    DrawingToolState state = getState();
    QGraphicsItem *clickItem = p_scene->itemAt(scenePos,QTransform());

    if (state == DrawingToolState::MEASURING_TOOL){
        createMeasuringTool(scenePos);
        setState(DrawingToolState::MEASURING_TOOL_MOVE);
        return true;
    }

    else if (clickItem == 0 || clickItem->flags() != QGraphicsItem::GraphicsItemFlag::ItemIsMovable)
    {
        if(state != DrawingToolState::OFF)
        {
            if (state == DrawingToolState::ADD_TO_POLYGON){
                    addVertexToOlygon(scenePos);
                    return true;
            }

            else if (state == DrawingToolState::CREATE_POLYGON){
                createOlygon(scenePos);
                return true;
            }
        }

        else
            return false;
    }

    return false;
}

bool DrawingTool::mouseMoveSceneEvent(QPointF scenePos)
{
    DrawingToolState state = getState();

    if (state == DrawingToolState::MEASURING_TOOL_MOVE){
        p_measuringTool->updateMeasureLine(scenePos);
        return true;
    }
    else return false;
}

void DrawingTool::mouseReleaseSceneEvent()
{
    DrawingToolState state = getState();

    if (state == DrawingToolState::MEASURING_TOOL_MOVE){
        delete p_measuringTool;
        setState(DrawingToolState::MEASURING_TOOL);
    }
}
