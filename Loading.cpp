#include "Loading.h"
#include "LoadingRect.h"

Loading::Loading() : QGraphicsView()
{
    //create scene
    loadingScene = new QGraphicsScene();
    loadingScene->setSceneRect(0,0,1200,700);
    setScene(loadingScene);

    //set background
    setBackgroundBrush(QBrush(QImage(":/images/loading.png")));

    //set fixed size
    setFixedSize(1200,700);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //set loading music
        loadingMusic = new QMediaPlayer();
        loadingMusic->setMedia(QUrl("qrc:/music/loading.mp3"));
        loadingMusic->play();

    //initialize seconds to zero
        seconds = 0;

    //stat Timer
        loadingTimer = new QTimer();
        loadingTimer->start(1000);
        connect(loadingTimer , SIGNAL(timeout()) , this , SLOT(loadingSchedule()));

}

Loading::~Loading()
{

}

void Loading::loadingSchedule()
{
    seconds = seconds+30;

    auto rect = new LoadingRect(loadingTimer , 40);
    scene()->addItem(rect);
    rect->setPos(x()+seconds + 222 , y()+610);  // change ??

  if(rect->x()>800){
      delete rect;
  }



}
