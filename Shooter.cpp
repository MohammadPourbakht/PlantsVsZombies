#include "Shooter.h"
#include<QGraphicsScene>
#include"Bullet.h"

Shooter::Shooter(QTimer * shooterTimer, QGraphicsItem *parent)
    : QObject() , Plant() , shooterTimer{shooterTimer} , timeIntervals{0}
{
    bool isDead = false;
    //set picture
    setPixmap(QPixmap(":/images/shooter.png"));                 //image shooter

    //create shooter player
    shooterPlayer = new QMediaPlayer();
    shooterPlayer->setMedia(QUrl("qrc:/music/shooter.mp3"));        //sound shooter

    //connect shoot slot
    connect(shooterTimer , SIGNAL(timeout()) , this , SLOT(shoot()));

}

Shooter::~Shooter()
{
    bool isDead = true;
    delete shooterPlayer;
}

void Shooter::shoot()
{
    //shoot every 400 millisecond
    if( timeIntervals % 10 == 0 ){

        //create bullet
        auto bullet = new Bullet(shooterTimer , 24);

        scene()->addItem(bullet);
        bullet->setPos(x()+ 90 , y() + 23);

        //play shooterPlayer
        if(shooterPlayer->state() == QMediaPlayer::PlayingState){
            shooterPlayer->setPosition(0);
        }
        else if(shooterPlayer->state() == QMediaPlayer::StoppedState){
            shooterPlayer->play();
        }

    }

    //invrement timeIntervals
    ++timeIntervals;
}
