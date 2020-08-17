#include "GroundRect.h"
#include <QGraphicsScene>

GroundRect::GroundRect(QGraphicsItem *parent)
    : QObject () , QGraphicsRectItem (parent)
{

}

void GroundRect:: mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    myP = new Plant();
    scene()->addItem(myP);
    myP->setPos(40,40);


}

