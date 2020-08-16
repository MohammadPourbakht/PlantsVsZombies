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


