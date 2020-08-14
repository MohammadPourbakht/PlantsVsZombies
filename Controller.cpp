#include "Controller.h"

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

}

Controller::~Controller()
{
    delete holder;
    delete scene;
    delete ctimer;
}

void Controller::addZombie(int velocity)
{
    zombieList.push_back(new Zombie{velocity,ctimer,holder});
    //add to the scene
    scene->addItem(zombieList.last());
    zombieList.last()->setPos(1200,365);
}
