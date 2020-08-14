#include "Zombie.h"

Zombie::Zombie(const int& pixPer40MiliSec , QTimer *timer
               , QGraphicsItem *parent)
    : QObject () , QGraphicsPixmapItem (parent) ,
      pixPer40MiliSec{pixPer40MiliSec}
{


    Layer=0;
  //set picture
   setPixmap(QPixmap(":/images/Layer 1.png"));

   //connect timer to moveToLeft
   connect(timer , SIGNAL(timeout()) , this , SLOT(moveToLeft()));

}


void Zombie::moveToLeft()
{
    setPos( x() - pixPer40MiliSec , y() );

        if(Layer%6==0){
        setPos( x() - pixPer40MiliSec , y() );
        setPixmap(QPixmap(":/images/Layer 1.png"));}

        if(Layer%6==1){
        setPos( x() - pixPer40MiliSec , y() );
        setPixmap(QPixmap(":/images/Layer 2.png"));}

        if(Layer%6==2){
        setPos( x() - pixPer40MiliSec , y() );
        setPixmap(QPixmap(":/images/Layer 3.png")); }

        if(Layer%6==3){
        setPos( x() - pixPer40MiliSec , y() );
        setPixmap(QPixmap(":/images/Layer 4.png"));}

        if(Layer%6==4){
        setPos( x() - pixPer40MiliSec , y() );
        setPixmap(QPixmap(":/images/Layer 5.png"));}

        if(Layer%6==5){
        setPos( x() - pixPer40MiliSec , y() );
        setPixmap(QPixmap(":/images/Layer 6.png"));}

        if( x() == 0){

         exit(1);
    }

    Layer=Layer+1;
}


