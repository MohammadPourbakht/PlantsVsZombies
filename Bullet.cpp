#include "Bullet.h"

Bullet::Bullet(QTimer * bulletTimer, const int & velocity, QGraphicsItem *parent)
    : QObject() , QGraphicsPixmapItem(parent) , velocity{velocity}
{
    //set picture
    setPixmap(QPixmap(":/images/bullet.png"));

    //connect to moveToRight

}
