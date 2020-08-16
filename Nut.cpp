#include "Nut.h"
#include "Zombie.h"
#include <QGraphicsScene>

Nut::Nut(const int& pixPer40MiliSec , QTimer *timer
              , QGraphicsItem *parent)
    : QObject () , QGraphicsPixmapItem (parent) ,
      pixPer40MiliSec{pixPer40MiliSec}
{

    //set picture
     setPixmap(QPixmap(":/images/nut1.jpg"));

     connect(timer , SIGNAL(timeout()) , this , SLOT(moveToRight()));

}

void Nut::moveToRight()
{
    setPos( x() + pixPer40MiliSec , y() );

    //collect all colliding objects in a list
    QList < QGraphicsItem * > collidingList = collidingItems();

    //decrement zombies lives
    for(size_t i{0} ; i<collidingList.size();++i){
        if(typeid(*(collidingList)[i])==typeid (Zombie)){
           Zombie* zom = dynamic_cast<Zombie*>(collidingList[i]);
           zom->decrementLives();

           //remove and delete
           scene()->removeItem(this);
           delete this;
           return;
        }
    }

    if(x()>1200){
        scene()->removeItem(this);
        delete this;
    }

}
