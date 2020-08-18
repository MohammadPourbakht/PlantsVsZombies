#include "Level3Button.h"
#include "View.h"

Level3Button::Level3Button(QGraphicsScene *Scene)  : level3Scene{Scene}
{
    clickl3 = false;

    //set picture
    setPixmap(QPixmap(":/images/level3.png"));

    //add to scene
    Scene->addItem(this);

    //setPos
    setPos(539,476);

    //create level2 button music
       level3ButtonMusic = new QMediaPlayer();
       level3ButtonMusic->setMedia(QUrl("qrc:/music/shooter.mp3"));

}

void Level3Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    clickl3 = true;
    level3ButtonMusic->play();

    auto myV = new View(2,3);
    myV->show();
}

Level3Button::~Level3Button()
{
    delete level3Scene;
    delete level3ButtonMusic;
}
