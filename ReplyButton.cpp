#include "ReplyButton.h"
#include "View.h"



ReplyButton::ReplyButton( QGraphicsScene *Scene , int season , int level) : replayButtonScene{Scene}
{
    clickReplayButton = false;

    //set picture
    setPixmap(QPixmap(":/images/replay.png"));

    //add to scene
    Scene->addItem(this);

    //setPos
    setPos(350,500);

    //create level1 button music
       replayButtonMusic = new QMediaPlayer();
       replayButtonMusic->setMedia(QUrl("qrc:/music/shooter.mp3"));

       this->season = season;
       this->level = level;

}

ReplyButton::~ReplyButton()
{
    delete replayButtonScene;
    delete replayButtonMusic;
}

void ReplyButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    clickReplayButton=true;
    replayButtonMusic->play();

    auto myV = new View(season,level);
    myV->show();
}

