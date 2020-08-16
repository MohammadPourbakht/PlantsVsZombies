#include "Level6Button.h"

Level6Button::Level6Button(QGraphicsScene *Scene)  : level6Scene{Scene}
{
    clickl6 = false;

    //set picture
    setPixmap(QPixmap(":/images/level6.png"));

    //add to scene
    Scene->addItem(this);

    //setPos
    setPos(810,575);

    //create level5 button music
       level6ButtonMusic = new QMediaPlayer();
       level6ButtonMusic->setMedia(QUrl("qrc:/music/shooter.mp3"));

}


void Level6Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    clickl6 = true;
    level6ButtonMusic->play();
    // go level3...
}

Level6Button::~Level6Button()
{
    delete level6Scene;
    delete level6ButtonMusic;
}
