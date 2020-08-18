#include "Controller.h"
#include "Shooter.h"

Controller::Controller( int season,QObject *parent) : QObject(parent)
{

    this->season=season;

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

    //add icons
        shooterIcon = new ShooterIcon(scene);
        sunFlowerIcon = new SunFlowerIcon(scene);
        shovelIcon = new ShovelIcon(scene);

    if(season==2){

     nutIcon = new NutIcon(scene);}

    if(season ==3){

     cherryIcon = new CherryIcon(scene);
}

}

Controller::~Controller()
{
    delete holder;
    delete scene;
    delete ctimer;
}

void Controller::addZombie(const int& velocity , const int& lives ,  bool isLord,int row)
{
    zombieList.push_back(new Zombie{velocity,ctimer,lives,holder,isLord});
    //add to the scene
    scene->addItem(zombieList.last());
if(season==1){
     //ghadeshoon
    zombieList.last()->setPos(1200,515);
}
if(season==2){
 //ghadeshoon
    zombieList.last()->setPos(1200,515+row*150);
}


if(season==3){
    if(zombieList.last()->getisLord()==false){  //ghadeshoon
    zombieList.last()->setPos(1200,515+(row*150));}
    if(zombieList.last()->getisLord()==true){  //ghadeshoon
    zombieList.last()->setPos(1200,515+(row*150));}

}
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

void Controller::planting(int s)
{
    season=s;

    if(season==3){


            //nutIcon
            checkNutIcon();

            //shooterIcon
           checkShooterIcon();

            //sunFlowerIcon
            checkSunFlowerIcon();

            //cherryIcon
            checkCherryIcon();

            //shovelIcon
            checkShovelIcon();


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
    && sunFlowerIcon->isSelected==false && cherryIcon->isSelected==false && shovelIcon->isSelected==false){
             for( const auto& ground : groundList ){
           ground->clickBlock=false;
             }
       }

    //shooterIcon
    if(shooterIcon->isSelected==true){
        nutIcon->isSelected=false;
        cherryIcon->isSelected=false;
        sunFlowerIcon->isSelected=false;
        shovelIcon->isSelected=false;

        for( const auto& ground : groundList ){

              if(ground->clickBlock==true && ground->myP==nullptr){
                 ground->myP = new Shooter(ctimer , holder);
                 scene->addItem(ground->myP);
                 ground->myP->setPos(ground->row , ground->column);
                 ground->plantMusic->play();
                 controllerScore->setScore(controllerScore->getScore()-100);
                 shooterIcon->isSelected=false;
                 ground->clickBlock=false;
               }
    }
    }

    //nutIcon

    if(nutIcon->isSelected==true){
        shooterIcon->isSelected=false;
        cherryIcon->isSelected=false;
        sunFlowerIcon->isSelected=false;
        shovelIcon->isSelected=false;
       for( const auto& ground : groundList ){

              if(ground->clickBlock==true && ground->myP==nullptr){
                 ground->myP = new Nut(12,ctimer , holder);
                 scene->addItem(ground->myP);
                 ground->myP->setPos(ground->row , (ground->column)+20);
                 ground->plantMusic->play();
                 controllerScore->setScore(controllerScore->getScore()-150);
                 nutIcon->isSelected=false;
                 ground->clickBlock=false;
                 ground->myP=nullptr;
               }
    }
    }

    //sunFlowerIcon

    if(sunFlowerIcon->isSelected==true){
        nutIcon->isSelected=false;
        cherryIcon->isSelected=false;
        shooterIcon->isSelected=false;
        shovelIcon->isSelected=false;
       for( const auto& ground : groundList ){

              if(ground->clickBlock==true && ground->myP==nullptr){
                 ground->myP = new SunFlower( controllerScore , scene , ctimer , holder);
                 scene->addItem(ground->myP);
                 ground->myP->setPos(ground->row,ground->column);
                 ground->plantMusic->play();
                 controllerScore->setScore(controllerScore->getScore() - 50);
                 sunFlowerIcon->isSelected=false;
                 ground->clickBlock=false;

               }
    }
    }


    //cherryIcon
    if(cherryIcon->isSelected==true){
        nutIcon->isSelected=false;
        shooterIcon->isSelected=false;
        sunFlowerIcon->isSelected=false;
        shovelIcon->isSelected=false;
        for( const auto& ground : groundList ){

              if(ground->clickBlock==true && ground->myP==nullptr){

                 ground->myP = new CherryBomb(ctimer , holder);
                 scene->addItem(ground->myP);
                 ground->myP->setPos((ground->row)-150 , (ground->column)-150);
                 ground->plantMusic->play();
                 controllerScore->setScore(controllerScore->getScore()-150);
                 cherryIcon->isSelected=false;
                 ground->clickBlock=false;

                 }
    }
    }

    //shovelIcon
    if(shovelIcon->isSelected==true){
        nutIcon->isSelected=false;
        cherryIcon->isSelected=false;
        sunFlowerIcon->isSelected=false;
        shooterIcon->isSelected=false;
        for( const auto& ground : groundList ){

              if(ground->clickBlock==true){
                 scene->removeItem(ground->myP);
                 delete  ground->myP;
                 ground->myP = nullptr;
                 shovelIcon->isSelected=false;
                 ground->clickBlock=false;

                 }
    }
    }}

    if(season ==2){

            //nutIcon
            checkNutIcon();

            //shooterIcon
           checkShooterIcon();

            //sunFlowerIcon
            checkSunFlowerIcon();

            //shovelIcon
            checkShovelIcon();

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
            && sunFlowerIcon->isSelected==false &&  shovelIcon->isSelected==false){
                     for( const auto& ground : groundList ){
                   ground->clickBlock=false;
                     }
               }

            //shooterIcon
            if(shooterIcon->isSelected==true){
                nutIcon->isSelected=false;
                sunFlowerIcon->isSelected=false;
                shovelIcon->isSelected=false;

                for( const auto& ground : groundList ){

                      if(ground->clickBlock==true && ground->myP==nullptr){
                         ground->myP = new Shooter(ctimer , holder);
                         scene->addItem(ground->myP);
                         ground->myP->setPos(ground->row , ground->column);
                         ground->plantMusic->play();
                         controllerScore->setScore(controllerScore->getScore()-100);
                         shooterIcon->isSelected=false;
                         ground->clickBlock=false;
                       }
            }
            }

            //nutIcon

            if(nutIcon->isSelected==true){
                shooterIcon->isSelected=false;
                sunFlowerIcon->isSelected=false;
                shovelIcon->isSelected=false;
               for( const auto& ground : groundList ){

                      if(ground->clickBlock==true && ground->myP==nullptr){
                         ground->myP = new Nut(12,ctimer , holder);
                         scene->addItem(ground->myP);
                         ground->myP->setPos(ground->row , (ground->column)+20);
                         ground->plantMusic->play();
                         controllerScore->setScore(controllerScore->getScore()-150);
                         nutIcon->isSelected=false;
                         ground->clickBlock=false;
                         ground->myP=nullptr;
                       }
            }
            }

            //sunFlowerIcon

            if(sunFlowerIcon->isSelected==true){
                nutIcon->isSelected=false;
                shooterIcon->isSelected=false;
                shovelIcon->isSelected=false;
               for( const auto& ground : groundList ){

                      if(ground->clickBlock==true && ground->myP==nullptr){
                         ground->myP = new SunFlower( controllerScore , scene , ctimer , holder);
                         scene->addItem(ground->myP);
                         ground->myP->setPos(ground->row,ground->column);
                         ground->plantMusic->play();
                         controllerScore->setScore(controllerScore->getScore() - 50);
                         sunFlowerIcon->isSelected=false;
                         ground->clickBlock=false;

                       }
            }
            }

            //shovelIcon
            if(shovelIcon->isSelected==true){
                nutIcon->isSelected=false;
                sunFlowerIcon->isSelected=false;
                shooterIcon->isSelected=false;
                for( const auto& ground : groundList ){

                      if(ground->clickBlock==true){
                         scene->removeItem(ground->myP);
                         delete  ground->myP;
                         ground->myP = nullptr;
                         shovelIcon->isSelected=false;
                         ground->clickBlock=false;

                         }
            }
            }

    }

    if(season==1){

            //shooterIcon
           checkShooterIcon();

            //sunFlowerIcon
            checkSunFlowerIcon();

            //shovelIcon
            checkShovelIcon();

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
            if(shooterIcon->isSelected==false && sunFlowerIcon->isSelected==false &&  shovelIcon->isSelected==false){
                     for( const auto& ground : groundList ){
                   ground->clickBlock=false;
                     }
               }

            //shooterIcon
            if(shooterIcon->isSelected==true){
                sunFlowerIcon->isSelected=false;
                shovelIcon->isSelected=false;

                for( const auto& ground : groundList ){

                      if(ground->clickBlock==true && ground->myP==nullptr){
                         ground->myP = new Shooter(ctimer , holder);
                         scene->addItem(ground->myP);
                         ground->myP->setPos(ground->row , ground->column);
                         ground->plantMusic->play();
                         controllerScore->setScore(controllerScore->getScore()-100);
                         shooterIcon->isSelected=false;
                         ground->clickBlock=false;
                       }
            }
            }

            //sunFlowerIcon

            if(sunFlowerIcon->isSelected==true){
                shooterIcon->isSelected=false;
                shovelIcon->isSelected=false;
               for( const auto& ground : groundList ){

                      if(ground->clickBlock==true && ground->myP==nullptr){
                         ground->myP = new SunFlower( controllerScore , scene , ctimer , holder);
                         scene->addItem(ground->myP);
                         ground->myP->setPos(ground->row,ground->column);
                         ground->plantMusic->play();
                         controllerScore->setScore(controllerScore->getScore() - 50);
                         sunFlowerIcon->isSelected=false;
                         ground->clickBlock=false;

                       }
            }
            }

            //shovelIcon
            if(shovelIcon->isSelected==true){
                sunFlowerIcon->isSelected=false;
                shooterIcon->isSelected=false;
                for( const auto& ground : groundList ){

                      if(ground->clickBlock==true){
                         scene->removeItem(ground->myP);
                         delete  ground->myP;
                         ground->myP = nullptr;
                         shovelIcon->isSelected=false;
                         ground->clickBlock=false;

                         }
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

void Controller::checkShovelIcon()
{
    shovelIcon->setShovelIcon();
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
