#ifndef COMBATANTLINECARRIER_H
#define COMBATANTLINECARRIER_H

#include "src/widget/targets/target.h"

class CombatantLineCarrier : public Target
{
    public:
        CombatantLineCarrier();

        void drawBackground(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) const;
        void drawForeground(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) const;
};

#endif // COMBATANTLINECARRIER_H
