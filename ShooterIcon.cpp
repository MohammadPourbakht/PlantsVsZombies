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
    setPos(174 , 34);

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
        shooterIconScene->addItem(this);

        //setPos
        setPos(174 , 34);
    }
}
