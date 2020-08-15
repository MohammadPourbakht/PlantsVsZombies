#include<QGraphicsScene>
#include "LoadingRect.h"

LoadingRect::LoadingRect(QTimer *bulletTimer, const int &velocity)
        : QObject() , velocity{velocity}
{
    //set picture
    setPixmap(QPixmap(":/images/loadingRect.png"));

    //connect to moveToRight
    connect(bulletTimer , SIGNAL(timeout()) , this , SLOT(moveToRight()));

}

void LoadingRect::moveToRight()
{
    // move to right
    setPos(x()+velocity , y());

    //delete if the bullet is off the screen
    if(x()>1000){                            //800 ? must be change
        scene()->removeItem(this);
        delete this;
    }
}


