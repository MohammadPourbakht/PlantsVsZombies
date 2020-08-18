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

    //initialize seconds to zero
    seconds = 0;

    //add ground
    viewController->addGround(season);


    //stat Timer
    viewTimer = new QTimer();
    viewTimer->start(1000);
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

    if(seconds % 10 == 0){
        viewController->addSun();
    }

    ++seconds;


  //season 1 level1

    if(season==1 && level==1){
        if(seconds == 50 || seconds == 54|| seconds == 57 || seconds == 59 || seconds == 60 ){

            viewController->addZombie( 6 , 4 , false,1);

        }}

  //season2 level2
    if(season==2 && level==2){
        int row1=rand()%2;
        int row2;
        if(seconds == 63 || seconds == 62 || seconds == 58 || seconds == 50  ){

            viewController->addZombie( 6 , 4 , false,row1);

        }
        if(row1==0){row2=1;}
        if(row1==1){row2=0;}

        if(seconds == 55 || seconds == 60 || seconds == 63 || seconds == 64  ){

            viewController->addZombie( 6 , 4 , false,row2);

        }}

    //season2 level3
        if(season==2 && level==3){
            int row1=rand()%2;
            int row2;
            if(seconds == 45 || seconds == 48 || seconds == 50 || seconds == 52 ||seconds==51  ){

                viewController->addZombie( 6 , 4 , false,row1);

            }
            if(row1==0){row2=1;}
            if(row1==1){row2=0;}

            if(seconds == 48 || seconds == 49 || seconds == 50 || seconds == 51 ||seconds==52  ){

                viewController->addZombie( 6 , 4 , false,row2);

            }}

        //season3 level4
        if(season==3 && level==4){
            int row1=rand()%3;
            int row2;
            int row3;
            if(seconds == 40 || seconds == 47 || seconds == 48 || seconds == 50   ){

                viewController->addZombie( 6 , 4 , false,row1);

            }
            if(seconds==53){viewController->addZombie( 6 , 10 , true,row1);}

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

            if(seconds == 44 || seconds == 47 || seconds == 50 || seconds == 51  ){

                viewController->addZombie( 6 , 4 , false,row2);
            }
         if(seconds==53){viewController->addZombie( 6 , 10 , true,row2);}

            if(seconds == 46 || seconds == 48 || seconds == 50 || seconds == 51  ){

                viewController->addZombie( 6 , 4 , false,row3);

            }if(seconds==53){viewController->addZombie( 6 , 10 , true,row3);}}

        //season3 level5
        if(season==3 && level==5){
            int row1=rand()%3;
            int row2;
            int row3;
            if(seconds == 40 || seconds == 47 || seconds == 48 || seconds == 50   ){

                viewController->addZombie( 6 , 4 , false,row1);

            }
            if(seconds==53){viewController->addZombie( 6 , 12 , true,row1);}

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

            if(seconds == 44 || seconds == 47 || seconds == 50 || seconds == 51  ){

                viewController->addZombie( 6 , 4 , false,row2);
            }
         if(seconds==53){viewController->addZombie( 6 , 12 , true,row2);}

            if(seconds == 46 || seconds == 48 || seconds == 50 || seconds == 51  ){

                viewController->addZombie( 6 , 4 , false,row3);

            }if(seconds==53){viewController->addZombie( 6 , 12 , true,row3);}}

        //season3 level6
        if(season==3 && level==6){
            int row1=rand()%3;
            int row2;
            int row3;
            if(seconds == 40 || seconds == 47 || seconds == 48 || seconds == 50 ||seconds==53  ){

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

            if(seconds == 44 || seconds == 47 || seconds == 50 || seconds == 51 ||seconds==53 ){

                viewController->addZombie( 12 , 15 , true,row2);
            }


            if(seconds == 46 || seconds == 48 || seconds == 50 || seconds == 51 ||seconds==53 ){

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
       }
        //add backtomenu and replay


       viewController->planting(season);



}

