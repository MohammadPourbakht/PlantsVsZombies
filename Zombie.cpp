#include "Zombie.h"

Zombie::Zombie(const int& pixPer40MiliSec , QTimer *timer
               , QGraphicsItem *parent)
    : QObject () , QGraphicsPixmapItem (parent) ,
      pixPer40MiliSec{pixPer40MiliSec}
{
  //set picture
   setPixmap(QPixmap(":/images/"));

   //connect timer to moveToLeft
   connect(timer , SIGNAL(timeout()) , this , SLOT(moveToLeft()));

}


