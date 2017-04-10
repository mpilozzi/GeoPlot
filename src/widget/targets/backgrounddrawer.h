#ifndef BACKGROUNDDRAWER_H
#define BACKGROUNDDRAWER_H

#include "target.h"
#include <QPainter>

class BackgroundDrawer
{
    public:
        BackgroundDrawer();
        static void drawBackgroundSymbol(const Target *tar, QPainter *painter);

        static void drawUnknownAir(QPainter *painter, QRectF rect);
        static void drawFriendlyAir(QPainter *painter, QRectF rect);
        static void drawNeutralAir(QPainter *painter, QRectF rect);
        static void drawHostileAir(QPainter *painter, QRectF rect);

        static void drawUnknownSubSurface(QPainter *painter, QRectF rect);
        static void drawFriendlySubSurface(QPainter *painter, QRectF rect);
        static void drawNeutralSubSurface(QPainter *painter, QRectF rect);
        static void drawHostileSubSurface(QPainter *painter, QRectF rect);

        static void drawUnknownSurface(QPainter *painter, QRectF rect);
        static void drawFriendlySurface(QPainter *painter, QRectF rect);
        static void drawNeutralSurface(QPainter *painter, QRectF rect);
        static void drawHostileSurface(QPainter *painter, QRectF rect);
};

#endif // BACKGROUNDDRAWER_H
