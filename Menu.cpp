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

       //add level3Button
          l3 = new Level3Button(menuScene);

          //add level1Button
             l4 = new Level4Button(menuScene);

          //add level2Button
             l5 = new Level5Button(menuScene);

          //add level2Button
             l6 = new Level6Button(menuScene);
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
    if(l1->clickl1==true || l2->clickl2==true || l3->clickl3==true ||
       l4->clickl4==true || l5->clickl5==true || l6->clickl6==true){
        menuMusic->stop();
        this->close();
}
}
