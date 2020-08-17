#include "Nut.h"
#include "Zombie.h"
#include <QGraphicsScene>

Nut::Nut(const int& pixPer40MiliSec , QTimer *timer
              , QGraphicsItem *parent)
    : QObject ()  , Plant() , pixPer40MiliSec{pixPer40MiliSec}
{
     Layer=0;

    //set picture
     setPixmap(QPixmap(":/images/nut1.png"));

     connect(timer , SIGNAL(timeout()) , this , SLOT(moveToRight()));

}

void Nut::moveToRight()
{

    //collect all colliding objects in a list
    QList < QGraphicsItem * > collidingList = collidingItems();

    //decrement zombies lives
    for(size_t i{0} ; i<collidingList.size();++i){
        if(typeid(*(collidingList)[i])==typeid (Zombie)){
           Zombie* zom = dynamic_cast<Zombie*>(collidingList[i]); 
           zom->setLives(0);

           return;
        }
    }

    if(x()>1200){
        scene()->removeItem(this);
        delete this;
    }

    setPos( x() + pixPer40MiliSec , y() );

    if(Layer%8==0){
    setPos( x() + pixPer40MiliSec , y() );
    setPixmap(QPixmap(":/images/Wall-nut 1.png"));}

    if(Layer%8==1){
    setPos( x() + pixPer40MiliSec , y() );
    setPixmap(QPixmap(":/images/Wall-nut 2.png"));}

    if(Layer%8==2){
    setPos( x() + pixPer40MiliSec , y() );
    setPixmap(QPixmap(":/images/Wall-nut 3.png")); }

    if(Layer%6==3){
    setPos( x() + pixPer40MiliSec , y() );
    setPixmap(QPixmap(":/images/Wall-nut 4.png"));}

    if(Layer%8==4){
    setPos( x() + pixPer40MiliSec , y() );
    setPixmap(QPixmap(":/images/Wall-nut 5.png"));}

    if(Layer%8==5){
    setPos( x() + pixPer40MiliSec , y() );
    setPixmap(QPixmap(":/images/Wall-nut 6.png"));}

    if(Layer%8==6){
    setPos( x() + pixPer40MiliSec , y() );
    setPixmap(QPixmap(":/images/Wall-nut 7.png"));}

    if(Layer%8==7){
    setPos( x() + pixPer40MiliSec , y() );
    setPixmap(QPixmap(":/images/Wall-nut 8.png"));}

    Layer=Layer+1;

}
