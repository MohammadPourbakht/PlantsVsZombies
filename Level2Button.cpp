#include "Level2Button.h"
#include "View.h"

Level2Button::Level2Button(QGraphicsScene *Scene) : level2Scene{Scene}
{
    clickl2 = false;

    //set picture
    setPixmap(QPixmap(":/images/level2.png"));

    //add to scene
    Scene->addItem(this);

    //setPos
    setPos(450,537);

    //create level2 button music
       level2ButtonMusic = new QMediaPlayer();
       level2ButtonMusic->setMedia(QUrl("qrc:/music/click.mp3"));

}

void Level2Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    clickl2 = true;
    level2ButtonMusic->play();

    auto myV = new View(2,2);
    myV->show();
}

Level2Button::~Level2Button()
{
    delete level2Scene;
    delete level2ButtonMusic;
}
