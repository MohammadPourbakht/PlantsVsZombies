#include "SunFlowerIcon.h"

SunFlowerIcon::SunFlowerIcon(QGraphicsScene *sunFlowerIconScene) : sunFlowerIconScene{sunFlowerIconScene}
{
    isSelected=false;
    isSelectable=false;

    //set picture
    setPixmap(QPixmap(":/images/dark sunflower icon.png"));

    //add to scene
    sunFlowerIconScene->addItem(this);

    //setPos
    setPos(168 , 11);

}

SunFlowerIcon::~SunFlowerIcon()
{
    delete sunFlowerIconScene;
}

void SunFlowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(isSelectable==true){
        isSelected=true;
        //set picture
        setPixmap(QPixmap(":/images/light sunflower icon.png"));
        //add to scene
       // shooterIconScene->addItem(this);
        //setPos
        setPos(168 , 11);
    }

    //add sound if isSelectable == false
}

void SunFlowerIcon::setSunFlowerIcon()
{
    if(isSelectable==true && isSelected==false){

        //set picture
        setPixmap(QPixmap(":/images/sunflower icon.png"));
        //add to scene
        //shooterIconScene->addItem(this);
        //setPos
        setPos(168 ,11);

    }

    if(isSelectable==false && isSelected==false ){

        //set picture
        setPixmap(QPixmap(":/images/dark sunflower icon.png"));
        //add to scene
        //shooterIconScene->addItem(this);
        //setPos
        setPos(168 , 11);

    }
}


