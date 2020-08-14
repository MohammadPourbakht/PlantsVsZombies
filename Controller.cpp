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
    ctimer->start(40);    // 50 | 40  ???

    //add scoreBoard
    scoreBoard = new QGraphicsPixmapItem();
    scoreBoard->setPixmap(QPixmap(":/images/score.png"));
    scene->addItem(scoreBoard);
    scoreBoard->setPos(10,10);

    //add score
    controllerScore = new Score();
    scene->addItem(controllerScore);
    controllerScore->setPos(35,112);

    //add a test shooter
    auto myShooter = new Shooter(ctimer , holder);
    scene->addItem(myShooter);
    myShooter->setPos(20,400);


}

Controller::~Controller()
{
    delete holder;
    delete scene;
    delete ctimer;
}

void Controller::addZombie(const int& velocity , const int& lives)
{
    zombieList.push_back(new Zombie{velocity,ctimer,lives,holder});
    //add to the scene
    scene->addItem(zombieList.last());
    zombieList.last()->setPos(1200,365);
}

void Controller::addSun()
{
    sunList.push_back(new Sun{scene,controllerScore,holder,ctimer});
}


bool Controller::boolGameOver()
{
    for( const auto& crs : zombieList ){
          if(crs->gameOv==0){
             return true;
           }
}
return false;
}
