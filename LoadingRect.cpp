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
