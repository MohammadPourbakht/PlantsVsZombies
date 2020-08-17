#ifndef SHOOTERICON_H
#define SHOOTERICON_H


#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>

class ShooterIcon: public QGraphicsPixmapItem
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
