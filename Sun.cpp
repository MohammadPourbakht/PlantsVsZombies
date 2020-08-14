#include "Sun.h"
#include <cstdlib>

Sun::Sun(QGraphicsScene *sunScene, Score *sunScore, QGraphicsItem *parent,
         QTimer *timer)
    : QObject () , QGraphicsPixmapItem (parent) ,
      sunScene(sunScene) , sunScore(sunScore) , timeIntervals{0}
{
    //set picture
    setPixmap(QPixmap(":/images/sun.png"));

    //add to scene
    sunScene->addItem(this);
    setPos(rand()%1150,0);

    //connect timer to move
    connect(timer , SIGNAL(timeout()) , this , SLOT(move()));
}
