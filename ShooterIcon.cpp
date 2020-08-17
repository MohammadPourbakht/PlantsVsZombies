#include "ShooterIcon.h"


ShooterIcon::ShooterIcon(QGraphicsScene *shooterIconScene) : shooterIconScene{shooterIconScene}
{
    isSelected=false;
    isSelectable=false;

    //set picture
    setPixmap(QPixmap(":/images/dark shooter icon.png"));

    //add to scene
    shooterIconScene->addItem(this);

    //setPos
    setPos(165 , 11);

}

ShooterIcon::~ShooterIcon()
{
    delete shooterIconScene;
}

void ShooterIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(isSelectable==true){
        isSelected=true;
        //set picture
        setPixmap(QPixmap(":/images/light shooter icon.png"));

        //add to scene
       // shooterIconScene->addItem(this);

        //setPos
        setPos(165 , 11);
    }

    //add sound if isSelectable == false
}

void ShooterIcon::setShooterIcon()
{
    if(isSelectable==true && isSelected==false){

        //set picture
        setPixmap(QPixmap(":/images/shooter icon.png"));
        //add to scene
        //shooterIconScene->addItem(this);
        //setPos
        setPos(165 ,11);

    }

    if(isSelectable==false){

        //set picture
        setPixmap(QPixmap(":/images/dark shooter icon.png"));
        //add to scene
        //shooterIconScene->addItem(this);
        //setPos
        setPos(165 , 11);

    }
}
