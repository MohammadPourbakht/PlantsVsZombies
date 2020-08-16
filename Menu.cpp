#include "Menu.h"

Menu::Menu()
{
    //create scene
      MenuScene = new QGraphicsScene();
      MenuScene->setSceneRect(0,0,1200,700);
      setScene(MenuScene);

      //set background
      setBackgroundBrush(QBrush(QImage(":/images/Menu background.png")));

      //set fixed size
      setFixedSize(1200,700);
      setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
      setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

      //set MenuMusic music
          MenuMusic = new QMediaPlayer();
          MenuMusic->setMedia(QUrl("qrc:/music/MainMenu.mp3"));
          MenuMusic->play();
}

Menu::~Menu()
{
    delete MenuMusic;
    delete MenuScene;

}
