#include "Level5Button.h"
#include "View.h"

Level5Button::Level5Button(QGraphicsScene *Scene)  : level5Scene{Scene}
{
    clickl5= false;

    //set picture
    setPixmap(QPixmap(":/images/level5.png"));

    //add to scene
    Scene->addItem(this);

    //setPos
    setPos(736,497);

    //create level5 button music
       level5ButtonMusic = new QMediaPlayer();
       level5ButtonMusic->setMedia(QUrl("qrc:/music/click.mp3"));

}


void Level5Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    clickl5 = true;
    level5ButtonMusic->play();

    auto myV = new View(3,5);
    myV->show();
}


Level5Button::~Level5Button()
{
    delete level5Scene;
    delete level5ButtonMusic;
}

