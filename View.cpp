#include "View.h"
#include "Zombie.h"
#include "Menu.h"

View::View(int level) : QGraphicsView()
{
    this->season=level;
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
    ++seconds;

    //nutIcon
    viewController->checkNutIcon();

    //shooterIcon
    viewController->checkShooterIcon();

    //sunFlowerIcon
    viewController->checkSunFlowerIcon();

    //cherryIcon
    viewController->checkCherryIcon();

    viewController->planting();

    if(seconds == 1 || seconds == 39 || seconds == 43 || seconds == 45){

        viewController->addZombie(6 , 10 , false);

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

