#include "View.h"
#include "Zombie.h"

View::View() : QGraphicsView()
{
    //create viewController
    viewController = new Controller();

    //create scene
    setScene(viewController->scene);

    //set background
    setBackgroundBrush(QBrush(QImage(":/images/Fsl-3.png")));

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

void View::schedule()
{
    ++seconds;

    if(seconds == 5 || seconds == 7 || seconds == 9 || seconds == 10){

        viewController->addZombie(6);

    }

    if(seconds % 2 == 0){
        viewController->addSun();

    }


    if(viewController->boolGameOver()==true){
     viewTimer->stop();
     viewController->ctimer->stop();

     gameOverMusic->play();

    QGraphicsPixmapItem * gameover = new QGraphicsPixmapItem();
     gameover->setPixmap(QPixmap(":/images/gameOver.png"));
     viewController->scene->addItem(gameover);
     gameover->setPos(0,0);

  }

}

