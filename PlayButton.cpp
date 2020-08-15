#include "PlayButton.h"


PlayButton::PlayButton(QGraphicsScene *playScene) :  playScene{playScene}
{
    //set picture
    setPixmap(QPixmap(":/images/play.png"));

    //add to scene
    playScene->addItem(this);
    setPos(600 , 350);


    //create play button music
       playButtonMusic = new QMediaPlayer();
       playButtonMusic->setMedia(QUrl("qrc:/music/shooter.mp3"));

}

void PlayButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //play button music
       playButtonMusic->play();

}


