#include "Ground.h"
#include <QGraphicsScene>

Ground::Ground(QGraphicsItem *parent)
    : QObject () , QGraphicsRectItem (parent)
{

}

void Ground:: mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    myP = new Plant();
    scene()->addItem(myP);
    myP->setPos(40,40);


}

