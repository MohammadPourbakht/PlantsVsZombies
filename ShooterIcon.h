#ifndef SHOOTERICON_H
#define SHOOTERICON_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>

class ShooterIcon: public QGraphicsPixmapItem
{

private:
    QGraphicsScene * shooterIconScene;
    bool isSelected;
    bool isSelectable;

public:
    ShooterIcon(QGraphicsScene *shooterIconScene);
    ~ShooterIcon();
};

#endif // SHOOTERICON_H
