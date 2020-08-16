#include "Level4Button.h"

Level4Button::Level4Button(QGraphicsScene *Scene)  : level4Scene{Scene}
{
    clickl3 = false;

    //set picture
    setPixmap(QPixmap(":/images/level4.png"));

    //add to scene
    Scene->addItem(this);

    //setPos
    setPos(540,477);

    //create level2 button music
       level4ButtonMusic = new QMediaPlayer();
       level4ButtonMusic->setMedia(QUrl("qrc:/music/shooter.mp3"));

}
