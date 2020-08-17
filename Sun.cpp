#include "Sun.h"
#include <cstdlib>

Sun::Sun(QGraphicsScene *sunScene , Score *sunScore , QTimer *timer
         , QGraphicsItem *parent)
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

void Sun::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    sunScore->addToScore(25);

    //play sun media player
        sunScore->scorePlayer->play();

    sunScene->removeItem(this);
    delete this;
}

void Sun::move()
{
   ++timeIntervals;
    setPos(x() , y()+6);

    if(timeIntervals == 50 || y() > 700)
    {
        sunScene->removeItem(this);
        delete this;
    }
}
