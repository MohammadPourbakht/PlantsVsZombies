#include "PlayButton.h"
#include "View.h"

PlayButton::PlayButton(QGraphicsScene *playScene) :  playScene{playScene}
{
    click=1;

    //create play button music
       playButtonMusic = new QMediaPlayer();
       playButtonMusic->setMedia(QUrl("qrc:/music/shooter.mp3"));

}

void PlayButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    click=0;
    //play button music
       playButtonMusic->play();

       auto myV = new View();
            myV->show();

}

PlayButton::~PlayButton()
{
    delete playButtonMusic;
    delete  playScene;
}


void PlayButton::setButton()
{

    //set picture
    setPixmap(QPixmap(":/images/play.png"));

    //add to scene
    playScene->addItem(this);
    setPos(510,340);
}

