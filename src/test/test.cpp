#include "test.h"
#include "src/widget/targets/torpedo.h"
#include "src/widget/targets/combatantlinecarrier.h"
#include "src/widget/targets/targetenums.h"
#include "src/widget/units/units.h"
#include <stdlib.h>

void qSleep(int ms)
{
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
}

Test::Test(GeoplotWidget *widget)
{
    _widget = widget;
}

void Test::run()
{
    _widget->setBackground(":/images/resources/testmap.png");
    _widget->setDistanceScale(NauticalMileLength(20));

    CombatantLineCarrier *t1 = new CombatantLineCarrier();
    t1->setPos(QPointF(100, 100));
    t1->setAnnotationString("Friendly");
    t1->setCategory(TargetCategory::SURFACE);
    t1->setThreat(TargetThreat::FRIENDLY);
    t1->setPos(150, 80);
    t1->setPos(200, 50);
    t1->setPos(250, 10);
    t1->setPos(275, 80);
    t1->setPos(300, 90);

    CombatantLineCarrier *t2 = new CombatantLineCarrier();
    t2->setPos(QPointF(700, 200));
    t2->setAnnotationString("Hostile");
    t2->setCategory(TargetCategory::SURFACE);
    t2->setThreat(TargetThreat::HOSTILE);

    Torpedo *t3 = new Torpedo();
    t3->setPos(QPointF(100, 100));
    t3->setAnnotationString("Hostile");
    t3->setCategory(TargetCategory::SUBSURFACE);
    t3->setThreat(TargetThreat::HOSTILE);

    CombatantLineCarrier *t4 = new CombatantLineCarrier();
    t4->setPos(t3->pos(), NauticalMileLength(10), DegreeAngle(-45));
    t4->setAnnotationString("Unknown");
    t4->setCategory(TargetCategory::SURFACE);
    t4->setThreat(TargetThreat::UNKNOWN);

    _widget->addTarget(t1);
    _widget->addTarget(t2);
    _widget->addTarget(t3);
    _widget->addTarget(t4);

    _widget->setPositionDotTimerInterval(1500);
    _widget->activatePositionDotTracking(true);
}
