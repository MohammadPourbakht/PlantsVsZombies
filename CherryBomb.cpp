#include "CherryBomb.h"
#include <QGraphicsScene>
#include "Zombie.h"
#include <QList>


CherryBomb::CherryBomb(QTimer *cherrytTimer, QGraphicsItem *parent)
    : QObject () , Plant() , cherryTimer(cherrytTimer) , timeIntervals{0}
{
    setPixmap(QPixmap(":/images/cherry.png"));

    connect(cherryTimer , SIGNAL(timeout()) , this , SLOT(move()));
}

void CherryBomb::move()
{
    if(timeIntervals == 50){
        //collect all colliding objects in a list
        QList < QGraphicsItem * > collidingList = collidingItems();

        //decrement zombies lives
        for(size_t i{0} ; i<collidingList.size();++i){
            if(typeid(*(collidingList)[i])==typeid (Zombie)){
               ( dynamic_cast<Zombie*>(collidingList[i]))->decrementLives();
              // Zombie* zom = dynamic_cast<Zombie*>(collidingList[i]);
              // zom->decrementLives();
            }
        }
            scene()->removeItem(this);
            delete this;
    }

    setPos(x(), y());


    ++timeIntervals;
}
