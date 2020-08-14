#include "Bullet.h"
#include<QGraphicsScene>
#include<QList>



Bullet::Bullet(QTimer * bulletTimer, const int & velocity, QGraphicsItem *parent)
    : QObject() , QGraphicsPixmapItem(parent) , velocity{velocity}
{
    //set picture
    setPixmap(QPixmap(":/images/bullet.png"));

    //connect to moveToRight
    connect(bulletTimer , SIGNAL(timeout()) , this , SLOT(moveToRight()));

}

void Bullet::moveToRight()
{
    //
    QList < QGraphicsItem* > collidingList = collidigItems();


    // move to right
    setPos(x()+velocity , y());

    //delete if the bullet is off the screen
    if(x()>1200){
        scene()->removeItem(this);
        delete this;
    }

}
