#ifndef GEOPLOTWIDGET_H
#define GEOPLOTWIDGET_H

#include <QWidget>
#include "src/widget/geoview.h"
#include "src/widget/geoscene.h"
#include "src/widget/units/units.h"

class GeoplotWidget : public QWidget
{
    Q_OBJECT

    public:
        explicit GeoplotWidget(QWidget *parent = 0);
        ~GeoplotWidget();

        void addTarget(Target *target);
        void setBackground(const char *imagePath);
        void setDistanceScale(Length backgroundWidth);
        void setDistanceScale(QRectF rectangle, Length rectangleWidth);

        void setPositionDotTimerInterval(int msec);
        void activatePositionDotTracking(bool activate);

    protected:
        void keyPressEvent(QKeyEvent * event);
        void resizeEvent(QResizeEvent *event);

    private:
        GeoScene _scene;
        GeoView _view;
};

#endif // GEOPLOTWIDGET_H
