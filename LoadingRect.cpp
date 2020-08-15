#include<QGraphicsScene>
#include "LoadingRect.h"

LoadingRect::LoadingRect(QTimer *bulletTimer, const int &velocity)
        : QObject() , velocity{velocity}
{
    //set picture
    setPixmap(QPixmap(":/images/loadingRect2.png"));

    //connect to moveToRight
    connect(bulletTimer , SIGNAL(timeout()) , this , SLOT(moveToRight()));

}


void LoadingRect::moveToRight()
{
    // move to right
    setPos(x() , y());

    //delete if the bullet is off the screen
    if(x()>800){                            //800 ? must be change
        scene()->removeItem(this);
        delete this;
    }
}


