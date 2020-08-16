#include "Level1Button.h"

Level1Button::Level1Button(QGraphicsScene *Scene) : Level1Scene{Scene}
{  
    clickl1 =false;

    //set picture
    setPixmap(QPixmap(":/images/level1.png"));

    //add to scene
    Scene->addItem(this);
    setPos(510,340);


    //create level1 button music
       Level1ButtonMusic = new QMediaPlayer();
       Level1ButtonMusic->setMedia(QUrl("qrc:/music/shooter.mp3"));
}

void Level1Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    clickl1=true;
    Level1ButtonMusic->play();
    // go level1
}

Level1Button::~Level1Button()
{
    delete Level1Scene;
    delete Level1ButtonMusic;
}
