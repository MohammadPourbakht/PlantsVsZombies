#include "Bullet.h"
#include<QGraphicsScene>


Bullet::Bullet(QTimer * bulletTimer, const int & velocity, QGraphicsItem *parent)
    : QObject() , QGraphicsPixmapItem(parent) , velocity{velocity}
{
    //set picture
    setPixmap(QPixmap(":/images/bullet.png"));

    //connect to moveToRight
    connect(bulletTimer , SIGNAL(timeout()) , this , SLOT(moveToRight));

}

void Bullet::moveToRight()
{
    //jone zombie kam konim inja


    // move to right
    setPos(x()+velocity , y());

    //delete if the bullet is off the screen
    if(x()>1200){
        scene()->removeItem(this);
        delete this;
    }

}
