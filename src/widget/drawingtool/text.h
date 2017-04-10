#ifndef TEXT_H
#define TEXT_H

#include <QGraphicsTextItem>

class Text : public QGraphicsTextItem
{
    public:
        Text(QPointF position, QString text);
};

#endif // TEXT_H
