#ifndef SHOVELICON_H
#define SHOVELICON_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>

class ShovelIcon : public QGraphicsPixmapItem
{
    friend class Controller;
private:
    QGraphicsScene * shovelIconScene;
    bool isSelected;

public:
    ShovelIcon(QGraphicsScene *shovelIconScene);
    ~ShovelIcon();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setShovelIcon();
};

#endif // SHOVELICON_H



