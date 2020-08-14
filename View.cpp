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
    setFixedSize(1200,700);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

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
}

