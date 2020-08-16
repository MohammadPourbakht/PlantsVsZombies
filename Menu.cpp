#include "Menu.h"

Menu::Menu()
{
    //create scene
      menuScene = new QGraphicsScene();
      menuScene->setSceneRect(0,0,1200,700);
      setScene(menuScene);

      //set background
      setBackgroundBrush(QBrush(QImage(":/images/Menu background.png")));

      //set fixed size
      setFixedSize(1200,700);
      setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
      setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

      //set Menu music music
          menuMusic = new QMediaPlayer();
          menuMusic->setMedia(QUrl("qrc:/music/MainMenu.mp3"));
          menuMusic->play();

       //start Timer
          menuTimer = new QTimer();
          menuTimer->start(1000);
          connect(menuTimer , SIGNAL(timeout()) , this , SLOT(menuSchedule()));

       //add level1Button
          l1 = new Level1Button(menuScene);

       //add level2Button
          l2 = new Level2Button(menuScene);

       //add level2Button
          l3 = new Level3Button(menuScene);
}

Menu::~Menu()
{
    delete menuMusic;
    delete menuScene;
    delete menuTimer;
}

void Menu::menuSchedule()
{
    if(menuMusic->state() == QMediaPlayer::StoppedState ){
                menuMusic->play();
            }

}
