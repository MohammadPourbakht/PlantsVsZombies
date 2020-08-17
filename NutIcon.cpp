#include "NutIcon.h"
#include "Icons.h"

NutIcon::NutIcon(QGraphicsScene *nutIconScene) : nutIconScene{nutIconScene}
{
    isSelected=false;
    isSelectable=false;

    //set picture
    setPixmap(QPixmap(":/images/dark nut icon.png"));

    //add to scene
    nutIconScene->addItem(this);

    //setPos
    setPos(315 , 11);

}


NutIcon::~NutIcon()
{
    delete nutIconScene;
}
