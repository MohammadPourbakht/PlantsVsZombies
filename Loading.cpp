#include "Loading.h"

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





}
