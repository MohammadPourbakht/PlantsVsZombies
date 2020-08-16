#include "Zombie.h"
#include <QGraphicsScene>
#include <QList>
#include "Plant.h"

Zombie::Zombie(const int& pixPer40MiliSec , QTimer *timer
              ,const int lives , QGraphicsItem *parent)
    : QObject () , QGraphicsPixmapItem (parent) ,
      pixPer40MiliSec{pixPer40MiliSec} , lives{lives}
{

    gameOv=false;
    Layer=0;
  //set picture
   setPixmap(QPixmap(":/images/Layer 1.png"));

   //connect timer to moveToLeft
   connect(timer , SIGNAL(timeout()) , this , SLOT(moveToLeft()));

   //set zombie sound
      zombieMusic = new QMediaPlayer();
      zombieMusic->setMedia(QUrl("qrc:/music/Groan4.mp3"));

      if(zombieMusic->state() == QMediaPlayer::PlayingState){
          zombieMusic->setPosition(0);
      }
      else if(zombieMusic->state() == QMediaPlayer::StoppedState){
          zombieMusic->play();
      }
}

Zombie::~Zombie()
{
    delete zombieMusic;
}

void Zombie::decrementLives()
{

    //decrement zombies lives
    --lives;
    //remove and delete if lives == 0
    if(lives==0){
        scene()->removeItem(this);
    }
}

int Zombie::getLives()
{
    return lives;
}

void Zombie::setLives(int lives)
{
    this->lives = lives;
}


void Zombie::moveToLeft()
{
    //collect colliding items in the list
    QList<QGraphicsItem *> collidingObjects = collidingItems();
    //remove and delete collidingItem if it was a plant
    for(size_t i{0} ; i<collidingObjects.size();++i){
        Plant* plant = dynamic_cast<Plant*>(collidingObjects[i]);
        if(plant){

            scene()->removeItem(collidingObjects[i]);
            delete collidingObjects[i];
          QMediaPlayer*  zombieBiteMusic = new QMediaPlayer();
            zombieBiteMusic->setMedia(QUrl("qrc:/music/ZombieBite.mp3"));

            if(zombieBiteMusic->state() == QMediaPlayer::PlayingState){
                zombieBiteMusic->setPosition(0);
            }
            else if(zombieBiteMusic->state() == QMediaPlayer::StoppedState){
                zombieBiteMusic->play();
            }
        }
    }

    setPos( x() - pixPer40MiliSec , y() );

        if(Layer%6==0){
        setPos( x() - pixPer40MiliSec , y() );
        setPixmap(QPixmap(":/images/Layer 1.png"));}

        if(Layer%6==1){
        setPos( x() - pixPer40MiliSec , y() );
        setPixmap(QPixmap(":/images/Layer 2.png"));}

        if(Layer%6==2){
        setPos( x() - pixPer40MiliSec , y() );
        setPixmap(QPixmap(":/images/Layer 3.png")); }

        if(Layer%6==3){
        setPos( x() - pixPer40MiliSec , y() );
        setPixmap(QPixmap(":/images/Layer 4.png"));}

        if(Layer%6==4){
        setPos( x() - pixPer40MiliSec , y() );
        setPixmap(QPixmap(":/images/Layer 5.png"));}

        if(Layer%6==5){
        setPos( x() - pixPer40MiliSec , y() );
        setPixmap(QPixmap(":/images/Layer 6.png"));}

        if( x() == 0 && lives!= 0){
        gameOv=true;

    }

    Layer=Layer+1;
}


