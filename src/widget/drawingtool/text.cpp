#include "text.h"

Text::Text(QPointF position, QString text) : QGraphicsTextItem(text)
{
    setPos(position.x(), position.y());
    setFlag(ItemIsMovable);
}
