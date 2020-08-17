#ifndef SHOOTERICON_H
#define SHOOTERICON_H

#include "Icons.h"

class ShooterIcon: public QGraphicsPixmapItem , public Icons
{
    friend class Controller;
private:
    QGraphicsScene * shooterIconScene;
    bool isSelected;
    bool isSelectable;

public:
    ShooterIcon(QGraphicsScene *shooterIconScene);
    ~ShooterIcon();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setShooterIcon();
};

#endif // SHOOTERICON_H
