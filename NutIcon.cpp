#include "NutIcon.h"


NutIcon::NutIcon(QGraphicsScene *nutIconScene) : nutIconScene{nutIconScene}
{
    isSelected=false;
    isSelectable=false;

    //set picture
    setPixmap(QPixmap(":/images/dark wall-nut icon.png"));

    //add to scene
    nutIconScene->addItem(this);

    //setPos
    setPos(265 , 11);

}

NutIcon::~NutIcon()
{
    delete nutIconScene;
}

void NutIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(isSelectable==true){
        isSelected=true;
        //set picture
        setPixmap(QPixmap(":/images/light wall-nut icon.png"));
        //add to scene
       // shooterIconScene->addItem(this);
        //setPos
        setPos(265 , 11);
    }

    //add sound if isSelectable == false
}

void NutIcon::setNutIcon()
{
    if(isSelectable==true && isSelected==false){

        //set picture
        setPixmap(QPixmap(":/images/wall-nut icon.png"));
        //add to scene
        //shooterIconScene->addItem(this);
        //setPos
        setPos(265 ,11);

    }

    if(isSelectable==false && isSelected==false ){

        //set picture
        setPixmap(QPixmap(":/images/dark wall-nut icon.png"));
        //add to scene
        //shooterIconScene->addItem(this);
        //setPos
        setPos(265 , 11);

    }
}
