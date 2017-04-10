#ifndef TEST_H
#define TEST_H

#include "src/widget/geoplotwidget.h"

class Test
{
    public:
        Test(GeoplotWidget* widget);

        void run();

    private:
        GeoplotWidget *_widget;
};

#endif // TEST_H
