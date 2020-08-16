#include "Level4Button.h"

Level4Button::Level4Button(QGraphicsScene *Scene)  : level4Scene{Scene}
{
    clickl4= false;

    //set picture
    setPixmap(QPixmap(":/images/level4.png"));

    //add to scene
    Scene->addItem(this);

    //setPos
    setPos(639,510);

    //create level2 button music
       level4ButtonMusic = new QMediaPlayer();
       level4ButtonMusic->setMedia(QUrl("qrc:/music/shooter.mp3"));

}


void Level4Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    clickl4 = true;
    level4ButtonMusic->play();
    // go level3...
}


Level4Button::~Level4Button()
{
    delete level4Scene;
    delete level4ButtonMusic;
}
