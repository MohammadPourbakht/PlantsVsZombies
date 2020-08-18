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

    shooterIcon = new ShooterIcon(scene);
    nutIcon = new NutIcon(scene);
    sunFlowerIcon = new SunFlowerIcon(scene);
    cherryIcon = new CherryIcon( scene);

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
    sunList.push_back(new Sun{scene,controllerScore,ctimer,holder});
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
            groundList.last()->row=i * 150;
            groundList.last()->column=486;
        }
    }
    if(season == 2 ){
        for(int j = 0 ; j < 2 ; j++){
         for(int i = 0 ; i < 7 ; i++){
            groundList.push_back(new GroundRect{holder});
            groundList.last()->setGroundRect( (i * 150) , 486 - (j*150));
            scene->addItem(groundList.last());
            groundList.last()->row=(i * 150);
            groundList.last()->column=486 - (j*150);
        }
        }
    }
    if(season == 3 ){
        for(int j = 0 ; j < 3 ; j++){
           for(int i = 0 ; i < 7 ; i++){
             groundList.push_back(new GroundRect{holder});
             groundList.last()->setGroundRect( (i * 150) , 486 - (j*150));
             scene->addItem(groundList.last());
             groundList.last()->row=(i * 150);
             groundList.last()->column=486 - (j*150);
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

    for( const auto& zom : zombieList ){
if(zom->getxx()!=-1 && zom->getyy()!= -1){
    for( const auto& ground : groundList ){
  if(ground->row == zom->getxx() && ground->column == zom->getyy()){
  ground->myP=nullptr;
  }
    }
}
    }

    //score kam bshe click konim nabayd bekare , in chand khat nabashe vaghti score ziad she hmonja mikare
    if(shooterIcon->isSelected==false && nutIcon->isSelected==false
       && sunFlowerIcon->isSelected==false && cherryIcon->isSelected==false){
             for( const auto& ground : groundList ){
           ground->clickBlock=false;
             }
       }

    //shooterIcon
    if(shooterIcon->isSelected==true){
        for( const auto& ground : groundList ){
            if(ground->myP->isDead == true){
                ground->myP==nullptr;}

              if(ground->clickBlock==true && ground->myP==nullptr){
                 ground->myP = new Shooter(ctimer , holder);
                 scene->addItem(ground->myP);
                 ground->myP->setPos(ground->row,ground->column);
                 controllerScore->setScore(controllerScore->getScore()-100);
                 shooterIcon->isSelected=false;
                 ground->clickBlock=false;
               }
    }
    }

    //nutIcon

    if(nutIcon->isSelected==true){
       for( const auto& ground : groundList ){
           if(ground->myP->isDead == true){
           ground->myP==nullptr;}

              if(ground->clickBlock==true && ground->myP==nullptr){
                 ground->myP = new Nut(12,ctimer , holder);
                 scene->addItem(ground->myP);
                 ground->myP->setPos(ground->row , (ground->column)+20);
                 controllerScore->setScore(controllerScore->getScore()-150);
                 nutIcon->isSelected=false;
                 ground->clickBlock=false;
                 ground->myP=nullptr;
               }
    }
    }

    //sunFlowerIcon

    if(sunFlowerIcon->isSelected==true){
       for( const auto& ground : groundList ){
           if(ground->myP->isDead == true){
           ground->myP == nullptr;}
              if(ground->clickBlock==true && ground->myP==nullptr){
                 ground->myP = new SunFlower( controllerScore , scene , ctimer , holder);
                 scene->addItem(ground->myP);
                 ground->myP->setPos(ground->row,ground->column);
                 controllerScore->setScore(controllerScore->getScore() - 50);
                 sunFlowerIcon->isSelected=false;
                 ground->clickBlock=false;

               }
    }
    }


    //cherryIcon
    if(cherryIcon->isSelected==true){
        for( const auto& ground : groundList ){

              if(ground->clickBlock==true && ground->myP==nullptr){

                 ground->myP = new CherryBomb(ctimer , holder);
                 scene->addItem(ground->myP);
                 ground->myP->setPos((ground->row)-150 , (ground->column)-150);
                 controllerScore->setScore(controllerScore->getScore()-150);
                 cherryIcon->isSelected=false;
                 ground->clickBlock=false;

                 }
    }
    }

}

void Controller::checkNutIcon()
{

    if(controllerScore->getScore()>=150){
        nutIcon->isSelectable = true;
    }
    if(controllerScore->getScore()<150){
        nutIcon->isSelectable=false;
    }
    nutIcon->setNutIcon();
}

void Controller::checkSunFlowerIcon()
{
    if(controllerScore->getScore()>= 50){
        sunFlowerIcon->isSelectable = true;
    }
    if(controllerScore->getScore()< 50){
        sunFlowerIcon->isSelectable=false;
    }
   sunFlowerIcon->setSunFlowerIcon();

}

void Controller::checkCherryIcon()
{
    if(controllerScore->getScore()>= 150){
        cherryIcon->isSelectable = true;
    }
    if(controllerScore->getScore()< 150){
        cherryIcon->isSelectable=false;
    }
   cherryIcon->setCherryIcon();
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
