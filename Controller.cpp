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
    scoreBoard->setPos(0,0);

    //add score
    controllerScore = new Score();
    scene->addItem(controllerScore);
    controllerScore->setPos(43,101);

    //add a test shooter
    auto myShooter = new Shooter(ctimer , holder);
    scene->addItem(myShooter);
    myShooter->setPos(14,330);

    //add a test nut
        auto myNut = new Nut(12,ctimer,holder);
        scene->addItem(myNut);
        myNut->setPos(14,330);

    //add rectItem
    Ground *rect1 = new Ground();
    Ground *rect2 = new Ground();
    Ground *rect3 = new Ground();
    Ground *rect4 = new Ground();
    Ground *rect5 = new Ground();
    Ground *rect6 = new Ground();
    Ground *rect7 = new Ground();

    rect1->setRect(0,330,150,150);
    rect2->setRect(150,330,150,150);
    rect3->setRect(300,330,150,150);
    rect4->setRect(450,330,150,150);
    rect5->setRect(600,330,150,150);
    rect6->setRect(750,330,150,150);
    rect7->setRect(900,330,150,150);
    scene->addItem(rect1);
    scene->addItem(rect2);
    scene->addItem(rect3);
    scene->addItem(rect4);
    scene->addItem(rect5);
    scene->addItem(rect6);
    scene->addItem(rect7);



}

Controller::~Controller()
{
    delete holder;
    delete scene;
    delete ctimer;
}

void Controller::addZombie(const int& velocity , const int& lives)
{
    zombieList.push_back(new Zombie{velocity,ctimer,lives,holder,true});
    //add to the scene
    scene->addItem(zombieList.last());
    if(zombieList.last()->isLord==false){
    zombieList.last()->setPos(1200,365);}
    if(zombieList.last()->isLord==true){
    zombieList.last()->setPos(1200,340);}
}

void Controller::addSun()
{
    sunList.push_back(new Sun{scene,controllerScore,holder,ctimer});
}

void Controller::checkLives()
{
    for( const auto& crs : zombieList ){
                if(crs->getLives()==0){
                    zombieList.removeOne(crs);
                     delete crs;
                      }}
}


bool Controller::boolGameOver()
{
    for( const auto& crs : zombieList ){
          if(crs->gameOv==true){
             return true;
           }
}
return false;
}
