#include "SunFlowerIcon.h"

SunFlowerIcon::SunFlowerIcon(QGraphicsScene *sunFlowerIconScene) : sunFlowerIconScene{sunFlowerIconScene}
{
    isSelected=false;
    isSelectable=false;

    //set picture
    setPixmap(QPixmap(":/images/sunflower icon.png"));

    //add to scene
    sunFlowerIconScene->addItem(this);

    //setPos
    setPos(440 , 11);

}

SunFlowerIcon::~SunFlowerIcon()
{
    delete sunFlowerIconScene;
}


