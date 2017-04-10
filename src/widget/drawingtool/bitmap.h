#ifndef BITMAP_H
#define BITMAP_H

#include <QGraphicsPixmapItem>

class Bitmap : public QGraphicsPixmapItem
{
    public:
        Bitmap(QPointF position, QPixmap &pixmap);
};

#endif // BITMAP_H
