#include "View.h"
#include "Zombie.h"
#include "Menu.h"


View::View(int season, int level) : QGraphicsView()
{
    this->season=season;
    this->level=level;

    //create viewController
    viewController = new Controller(season);

    //set background
    setBackground();

    //create scene
    setScene(viewController->scene);

    //set fixed size
    setFixedSize(1200,700);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //set background music
        backgroundMusic = new QMediaPlayer();
        backgroundMusic->setMedia(QUrl("qrc:/music/GrasswalkPvZ1.mp3"));
        backgroundMusic->play();

    //set game over music
        gameOverMusic = new QMediaPlayer();
        gameOverMusic->setMedia(QUrl("qrc:/music/Game Over.mp3"));

     //set win music
        winMusic = new QMediaPlayer();
        winMusic->setMedia(QUrl("qrc:/music/win.mp3"));

     //set zombie Comming Music
        zCommingMusic = new QMediaPlayer();
        zCommingMusic->setMedia(QUrl("qrc:/music/zCommingMusic.mp3"));


    //initialize seconds to zero
    miliseconds = 0;

    //add ground
    viewController->addGround(season);


    //stat Timer
    viewTimer = new QTimer();
    viewTimer->start(500);
    connect(viewTimer , SIGNAL(timeout()) , this , SLOT(schedule()));
}
View::~View()
 {
   delete viewController;
    delete viewTimer;
}

void View::stopGame()
{
    viewTimer->stop();
    viewController->ctimer->stop();
}

void View::setBackground()
{

    if(season==1){
    //set background
    setBackgroundBrush(QBrush(QImage(":/images/Fsl-1.png")));}

    if(season==2){
    //set background
    setBackgroundBrush(QBrush(QImage(":/images/Fsl-2.png")));}

    if(season==3){
    //set background
    setBackgroundBrush(QBrush(QImage(":/images/Fsl-3.png")));}

}

void View::schedule()
{
    if(season==1){
        viewController->scene->removeItem(viewController->nutIcon);
        viewController->scene->removeItem(viewController->cherryIcon);
    }
    if(season==2){
        viewController->scene->removeItem(viewController->cherryIcon);
    }

    if(miliseconds % 2000 == 0){
        viewController->addSun();
    }

    miliseconds=miliseconds+500;


  //season 1 level1

    if(season==1 && level==1){
        if(miliseconds==45000){
            zCommingMusic->play();
        }
        if(miliseconds == 50000 || miliseconds == 54000|| miliseconds == 57000
                || miliseconds == 59000 || miliseconds == 60000 ){

            viewController->addZombie( 6 , 4 , false,1);

        }}

  //season2 level2
    if(season==2 && level==2){
        if(miliseconds==45000){
            zCommingMusic->play();
        }
        int row1=rand()%2;
        int row2;
        if(miliseconds == 63000 || miliseconds == 62000 || miliseconds == 58000 || miliseconds == 50000  ){

            viewController->addZombie( 6 , 4 , false,row1);

        }
        if(row1==0){row2=1;}
        if(row1==1){row2=0;}

        if(miliseconds == 55000 || miliseconds == 60000 || miliseconds == 63000 || miliseconds == 64000  ){

            viewController->addZombie( 6 , 4 , false,row2);

        }}

    //season2 level3
        if(season==2 && level==3){
            if(miliseconds==40000){
                zCommingMusic->play();
            }
            int row1=rand()%2;
            int row2;
            if(miliseconds == 45000 || miliseconds == 48000 || miliseconds == 50000
                    || miliseconds == 52000 ||miliseconds==51000  ){

                viewController->addZombie( 6 , 4 , false,row1);

            }
            if(row1==0){row2=1;}
            if(row1==1){row2=0;}

            if(miliseconds == 48000 || miliseconds == 49000 || miliseconds == 50000 ||
                    miliseconds == 51000 ||miliseconds==52000  ){

                viewController->addZombie( 6 , 4 , false,row2);

            }}

     //season3 level4
        if(season==3 && level==4){
            if(miliseconds==35000){
                zCommingMusic->play();
            }
            int row1=rand()%3;
            int row2;
            int row3;
            if(miliseconds == 40000 || miliseconds == 47000 || miliseconds == 48000 || miliseconds == 50000   ){

                viewController->addZombie( 6 , 4 , false,row1);

            }
            if(miliseconds==53000){viewController->addZombie( 6 , 10 , true,row1);}

            if(row1==0){
                row2=rand()%2+1;
            if(row2==1){row3=2;}
            if(row2==2){row3=1;}}

            if(row1==1){row2=(rand()%2)*2;
           if(row2==0){row3=2;}
            if(row2==2){row3=0;}}

            if(row1==2){
            row2=rand()%2;
            if(row2==0){row3=1;}
            if(row2==1){row3=0;} }

            if(miliseconds == 44000 || miliseconds == 47000 || miliseconds == 50000 || miliseconds == 51000  ){

                viewController->addZombie( 6 , 4 , false,row2);
            }
         if(miliseconds==53000){viewController->addZombie( 6 , 10 , true,row2);}

            if(miliseconds == 46000 || miliseconds == 48000 || miliseconds == 50000 || miliseconds == 51000  ){

                viewController->addZombie( 6 , 4 , false,row3);

            }if(miliseconds==53000){viewController->addZombie( 6 , 10 , true,row3);}}

   //season3 level5
        if(season==3 && level==5){
            if(miliseconds==35000){
                zCommingMusic->play();
            }
            int row1=rand()%3;
            int row2;
            int row3;
            if(miliseconds == 40000 || miliseconds == 47000 || miliseconds == 48000 || miliseconds == 50000   ){

                viewController->addZombie( 6 , 4 , false,row1);

            }
            if(miliseconds==53000){viewController->addZombie( 6 , 12 , true,row1);}

            if(row1==0){
                row2=rand()%2+1;
            if(row2==1){row3=2;}
            if(row2==2){row3=1;}}

            if(row1==1){row2=(rand()%2)*2;
           if(row2==0){row3=2;}
            if(row2==2){row3=0;}}

            if(row1==2){
            row2=rand()%2;
            if(row2==0){row3=1;}
            if(row2==1){row3=0;} }

            if(miliseconds == 44000 || miliseconds == 47000 || miliseconds == 50000 || miliseconds == 51000  ){

                viewController->addZombie( 6 , 4 , false,row2);
            }
         if(miliseconds==53000){viewController->addZombie( 6 , 12 , true,row2);}

            if(miliseconds == 46000 || miliseconds == 48000 || miliseconds == 50000 || miliseconds == 51000  ){

                viewController->addZombie( 6 , 4 , false,row3);

            }if(miliseconds==53000){viewController->addZombie( 6 , 12 , true,row3);}}

     //season3 level6
        if(season==3 && level==6){
            if(miliseconds==35000){
                zCommingMusic->play();
            }
            int row1=rand()%3;
            int row2;
            int row3;
            if(miliseconds == 40000 || miliseconds == 47000 || miliseconds == 48000
                    || miliseconds == 50000 ||miliseconds==53000  ){

                viewController->addZombie(12 , 15 , true,row1);

            }


            if(row1==0){
                row2=rand()%2+1;
            if(row2==1){row3=2;}
            if(row2==2){row3=1;}}

            if(row1==1){row2=(rand()%2)*2;
           if(row2==0){row3=2;}
            if(row2==2){row3=0;}}

            if(row1==2){
            row2=rand()%2;
            if(row2==0){row3=1;}
            if(row2==1){row3=0;} }

            if(miliseconds == 44000 || miliseconds == 47000 || miliseconds == 50000
                    || miliseconds == 51000 ||miliseconds==53000 ){

                viewController->addZombie( 12 , 15 , true,row2);
            }


            if(miliseconds == 46000 || miliseconds == 48000 || miliseconds == 50000
                    || miliseconds == 51000 ||miliseconds==53000 ){

                viewController->addZombie( 12 , 15 , true,row3);

            }}

    if(backgroundMusic->state() == QMediaPlayer::StoppedState){
                backgroundMusic->play();
            }

        viewController->checkLives();

        if(viewController->boolGameOver()==true){
         stopGame();
         backgroundMusic->stop();
         gameOverMusic->play();

        QGraphicsPixmapItem * gameover = new QGraphicsPixmapItem();
         gameover->setPixmap(QPixmap(":/images/Un2.png"));
         viewController->scene->addItem(gameover);
         gameover->setPos(0,0);

         menuB = new MenuButton(viewController->scene);
         replayB = new ReplyButton(viewController->scene , season , level);
         exitB = new Exit(viewController->scene);
       }

        //win page
        if(viewController->boolGameOver()==false && miliseconds==70){
              stopGame();
              backgroundMusic->stop();
              winMusic->play();

             QGraphicsPixmapItem * win = new QGraphicsPixmapItem();
              win->setPixmap(QPixmap(":/images/win.png"));
              viewController->scene->addItem(win);
              win->setPos(0,0);
               menuB = new MenuButton(viewController->scene);
               if(level!=6){
               nextB = new NextButton(viewController->scene , level);
               exitB = new Exit(viewController->scene);
               }
              }

         viewController->planting(season);


}

