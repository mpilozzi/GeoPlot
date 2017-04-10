#include "src/widget/geoplotwidget.h"
#include <QGraphicsScene>
#include "src/widget/geoview.h"
#include <QGridLayout>
#include <QDebug>
#include "src/widget/drawingtool/drawingtoolstateenum.h"
#include "src/widget/targets/target.h"

GeoplotWidget::GeoplotWidget(QWidget *parent) : QWidget(parent)
{
    // Initialize members
    _view.setScene(&_scene);
    Target::setScenePointer(&_scene); // Give targets the pointer for plot so they can use the scale

    _scene.setDistanceScale(1); // Scale initially set to 1 km width

    QGridLayout layout;
    this->setLayout(&layout);
    layout.addWidget(&_view);

    // Enable antialiasing
    _view.setRenderHints(QPainter::HighQualityAntialiasing);
}

GeoplotWidget::~GeoplotWidget()
{
}

void GeoplotWidget::keyPressEvent(QKeyEvent * event)
{
    DrawingToolState state = _scene.getDrawingToolState();

    if (event->key() == Qt::Key_P)
    {
        if (state == DrawingToolState::OFF)
            _scene.setDrawingToolState(DrawingToolState::CREATE_POLYGON);

        else if(state == DrawingToolState::CREATE_POLYGON || state == DrawingToolState::ADD_TO_POLYGON)
                _scene.setDrawingToolState(DrawingToolState::OFF);
    }

    else if (event->key() == Qt::Key_M){
        if (state == DrawingToolState::OFF)
            _scene.setDrawingToolState(DrawingToolState::MEASURING_TOOL);

        else if(state == DrawingToolState::MEASURING_TOOL || state == DrawingToolState::MEASURING_TOOL_MOVE)
                _scene.setDrawingToolState(DrawingToolState::OFF);
    }
}

void GeoplotWidget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);

    // Resize the QGraphicsView to match the size of the widget
    _view.resize(this->width(), this->height());
}

void GeoplotWidget::addTarget(Target *target)
{
    _scene.addTarget(target);
    _scene.addItem(target);
}

void GeoplotWidget::setBackground(const char *imagePath)
{
    _scene.setBackground(imagePath);
}

void GeoplotWidget::setDistanceScale(Length backgroundWidth)
{
    _scene.setDistanceScale((double)_scene.getBackgroundWidth() / (backgroundWidth.toMeters()));
}

void GeoplotWidget::setDistanceScale(QRectF rectangle, Length rectangleWidth)
{
    _scene.setDistanceScale((double)rectangle.width() / (rectangleWidth.toMeters()));
}

void GeoplotWidget::setPositionDotTimerInterval(int msec)
{
    _scene.setPositionDotTimerInterval(msec);
}

void GeoplotWidget::activatePositionDotTracking(bool activate)
{
    _scene.activatePositionDotTracking(activate);
}
