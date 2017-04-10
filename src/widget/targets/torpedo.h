#ifndef TORPEDO_H
#define TORPEDO_H

#include "src/widget/targets/target.h"

class Torpedo : public Target
{
    public:
        Torpedo();

        void drawBackground(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) const;
        void drawForeground(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) const;
};

#endif // TORPEDO_H
