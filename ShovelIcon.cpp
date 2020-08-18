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
    setPos(730 , 0);

}

ShovelIcon::~ShovelIcon()
{
    delete shovelIconScene;
}

void ShovelIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(isSelectable==true){
        isSelected=true;
        //set picture
        setPixmap(QPixmap(":/images/light shovel icon.png"));
        //add to scene
       // shooterIconScene->addItem(this);
        //setPos
        setPos(730 , 0);
    }

    //add sound if isSelectable == false

}

