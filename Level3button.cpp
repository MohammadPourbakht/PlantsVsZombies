#include "Level3button.h"


Level3Button::Level3Button(QGraphicsScene *Scene)  : level3Scene{Scene}
{
    clickl3 = false;

    //set picture
    setPixmap(QPixmap(":/images/level3.png"));

    //add to scene
    Scene->addItem(this);

    //setPos
    setPos(500,450);

    //create level2 button music
       level3ButtonMusic = new QMediaPlayer();
       level3ButtonMusic->setMedia(QUrl("qrc:/music/shooter.mp3"));

}
