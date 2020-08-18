#include "Exit.h"
#include "View.h"

Exit::Exit( QGraphicsScene *Scene  ) : exitButtonScene{Scene}
{
    clickExitButton = false;

    //set picture
    setPixmap(QPixmap(":/images/exit.png"));

    //add to scene
    Scene->addItem(this);

    //setPos
    setPos(350,500);

    //create level1 button music
       exitButtonMusic = new QMediaPlayer();
       exitButtonMusic->setMedia(QUrl("qrc:/music/shooter.mp3"));

}

Exit::~Exit()
{
    delete exitButtonScene;
    delete exitButtonMusic;
}

void Exit::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    clickExitButton=true;
    exitButtonMusic->play();
    exit(1);
}
