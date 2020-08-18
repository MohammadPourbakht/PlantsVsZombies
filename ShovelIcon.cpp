#include "ShovelIcon.h"


ShovelIcon::ShovelIcon(QGraphicsScene *shovelIconScene) : shovelIconScene{shovelIconScene}
{
    isSelected=false;
    isSelectable=false;

    //set picture
    setPixmap(QPixmap(":/images/shovel icon.png"));

    //add to scene
    shovelIconScene->addItem(this);

    //setPos
    setPos(730 , 11);

}

ShovelIcon::~ShovelIcon()
{
 delete shovelIconScene;
}
