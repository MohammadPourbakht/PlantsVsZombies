#include "CherryBomb.h"
#include <QGraphicsScene>
#include "Zombie.h"
#include <QList>


CherryBomb::CherryBomb(QTimer *cherrytTimer, QGraphicsItem *parent)
    : QObject () , Plant() , cherryTimer(cherrytTimer) , timeIntervals{0}
{
    setPixmap(QPixmap(":/images/cherry.png"));

    //create shooter player
    cherryBombPlayer = new QMediaPlayer();
    cherryBombPlayer->setMedia(QUrl("qrc:/music/cherry.mp3")); //add cherry mp3 .........................

    connect(cherryTimer , SIGNAL(timeout()) , this , SLOT(move()));
}

void CherryBomb::move()
{
    if(timeIntervals == 50){         // bade 2 sanie betereke

        //collect all colliding objects in a list
        QList < QGraphicsItem * > collidingList = collidingItems();

        //decrement zombies lives
        for(size_t i{0} ; i<collidingList.size(); ++i){
            if(typeid(*(collidingList)[i])==typeid (Zombie)){
                Zombie* zom = dynamic_cast<Zombie*>(collidingList[i]);
                zom->setLives(0);

            }
        }
            scene()->removeItem(this);
            delete this;
             return;  // doroste? check shavad ....................................
    }

    setPos(x(), y());


    ++timeIntervals;
}
