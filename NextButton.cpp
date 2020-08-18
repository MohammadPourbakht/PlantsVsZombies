#include "NextButton.h"
#include "View.h"

NextButton::NextButton( QGraphicsScene *Scene  , int level) : nextButtonScene{Scene}
{
    clickNextButton = false;

    //set picture
    setPixmap(QPixmap(":/images/next.png"));

    //add to scene
    Scene->addItem(this);

    //setPos
    setPos(350,500);

    //create level1 button music
       nextButtonMusic = new QMediaPlayer();
       nextButtonMusic->setMedia(QUrl("qrc:/music/shooter.mp3"));

       this->level = level;

}

NextButton::~NextButton()
{
    delete nextButtonScene;
    delete nextButtonMusic;
}

void NextButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    clickNextButton=true;
    nextButtonMusic->play();

    if( level ==1 ){
        auto myV = new View(2,level + 1);
        myV->show();
    }

    if( level ==2 ){
        auto myV = new View(2,level + 1);
        myV->show();
    }
    if( level ==3 ){
        auto myV = new View(3,level + 1);
        myV->show();
    }

    if( level == 4 || level == 5 ){
        auto myV = new View(3,level+1);
        myV->show();
    }

}

