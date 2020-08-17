#ifndef NUTICON_H
#define NUTICON_H

#include "Icons.h"

class NutIcon : public QGraphicsPixmapItem , public Icons
{
    friend class Controller;
private:
    QGraphicsScene * nutIconScene;
    bool isSelected;
    bool isSelectable;

public:
    NutIcon(QGraphicsScene *shooterIconScene);
    ~NutIcon();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setShooterIcon();

};

#endif // NUTICON_H
