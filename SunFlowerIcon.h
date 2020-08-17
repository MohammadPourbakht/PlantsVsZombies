#ifndef SUNFLOWERICON_H
#define SUNFLOWERICON_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>

class SunFlowerIcon : public QGraphicsPixmapItem
{
    friend class Controller;
private:
    QGraphicsScene * sunFlowerIconScene;
    bool isSelected;
    bool isSelectable;

public:
    SunFlowerIcon(QGraphicsScene *sunFlowerIconScene);
    SunFlowerIcon();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setSunFlowerIcon();
};

#endif // SUNFLOWERICON_H
