#include "Controller.h"
#include "Shooter.h"

Controller::Controller(QObject *parent) : QObject(parent)
{
  //create scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1200,700);

    //create holder
    holder = new QGraphicsRectItem();
    holder->setRect(0,0,1200,700);

    //create and start ctimer
    ctimer = new QTimer();
    ctimer->start(40);

    //add scoreBoard
    scoreBoard = new QGraphicsPixmapItem();
    scoreBoard->setPixmap(QPixmap(":/images/score.png"));
    scene->addItem(scoreBoard);
    scoreBoard->setPos(0,0);

    //add score
    controllerScore = new Score();
    scene->addItem(controllerScore);
    controllerScore->setPos(39,95);

    //add a test shooter
//    auto myShooter = new Shooter(ctimer , holder);
//    scene->addItem(myShooter);
//    myShooter->setPos(14,330);


    //......................
    shooterIcon = new ShooterIcon(scene);


    //add a test nut
//        auto myNut = new Nut(12,ctimer,holder);
//        scene->addItem(myNut);
//        myNut->setPos(14,330);

}

Controller::~Controller()
{
    delete holder;
    delete scene;
    delete ctimer;
}

void Controller::addZombie(const int& velocity , const int& lives ,  bool isLord)
{
    zombieList.push_back(new Zombie{velocity,ctimer,lives,holder,isLord});
    //add to the scene
    scene->addItem(zombieList.last());

    if(zombieList.last()->getisLord()==false){  //ghadeshoon
    zombieList.last()->setPos(1200,365);}

    if(zombieList.last()->getisLord()==true){
    zombieList.last()->setPos(1200,340);}
}

void Controller::addSun()
{
    sunList.push_back(new Sun{scene,controllerScore,holder,ctimer});
}

void Controller::checkLives() //delete zombies that dead from List
{
    for( const auto& zom : zombieList ){
                if(zom->getLives()==0){
                    zombieList.removeOne(zom);
                     delete zom;
                }}
}

void Controller::addGround(const int & season)
{
    if(season == 1 ){
        for(int i = 0 ; i < 7 ; i++){
            groundList.push_back(new GroundRect{holder});
            groundList.last()->setGroundRect( (i * 150) , 486);
            scene->addItem(groundList.last());
        }
    }

    if(season == 2 ){
        for(int j = 0 ; j < 2 ; j++){
         for(int i = 0 ; i < 7 ; i++){
            groundList.push_back(new GroundRect{holder});
            groundList.last()->setGroundRect( (i * 150) , 486 - (j*150));
            scene->addItem(groundList.last());
        }
        }
    }


    if(season == 3 ){
        for(int j = 0 ; j < 3 ; j++){
           for(int i = 0 ; i < 7 ; i++){
             groundList.push_back(new GroundRect{holder});
             groundList.last()->setGroundRect( (i * 150) , 486 - (j*150));
             scene->addItem(groundList.last());
        }
        }
    }

}

void Controller::checkShooterIcon()
{
    if(controllerScore->getScore()>=100){
        shooterIcon->isSelectable = true;
    }
    if(controllerScore->getScore()<100){
        shooterIcon->isSelectable=false;
    }
    shooterIcon->setShooterIcon();
}

void Controller::planting()
{
    if(shooterIcon->isSelected==true){
        for( const auto& ground : groundList ){
              if(ground->clickBlock==true){
                 ground->myP = new Shooter(ctimer , holder);
                 scene->addItem(ground->myP);
                ground->myP->setPos(14,330);
                  controllerScore=controllerScore-100;
                  shooterIcon->isSelected=false;
                  ground->clickBlock=false;
                  return;
               }
    }
    }
}

bool Controller::boolGameOver()
{
    for( const auto& zom : zombieList ){
          if(zom->gameOv==true){
             return true;
           }
}
return false;
}
