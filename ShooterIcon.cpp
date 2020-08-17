#include "ShooterIcon.h"


ShooterIcon::ShooterIcon(QGraphicsScene *shooterIconScene)
{
    isSelected=false;
    isSelectable=false;

    //set picture
    setPixmap(QPixmap(":/images/dark shooter icon.png"));

    //add to scene
    shooterIconScene->addItem(this);

    //setPos
    setPos(338,528);

}
