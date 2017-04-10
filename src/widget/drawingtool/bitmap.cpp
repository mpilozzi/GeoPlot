#include "bitmap.h"

Bitmap::Bitmap(QPointF position, QPixmap &pixmap) : QGraphicsPixmapItem(pixmap)
{
    setFlag(ItemIsMovable);
    setPos(position);
}
