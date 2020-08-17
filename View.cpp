#include "View.h"
#include "Zombie.h"
#include "Menu.h"

View::View(int level) : QGraphicsView()
{

    this->level=level;
    //create viewController
    viewController = new Controller();

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

    if(level==1){
    //set background
    setBackgroundBrush(QBrush(QImage(":/images/Fsl-1.png")));}

    if(level==2){
    //set background
    setBackgroundBrush(QBrush(QImage(":/images/Fsl-2.png")));}

    if(level==3){
    //set background
    setBackgroundBrush(QBrush(QImage(":/images/Fsl-3.png")));}

}

void View::schedule()
{
    ++seconds;

    if(seconds == 3 || seconds == 9 || seconds == 13 || seconds == 15){

        viewController->addZombie(6 , 10);

    }

    if(seconds % 2 == 0){
        viewController->addSun();

    }

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


}

