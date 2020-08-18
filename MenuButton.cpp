#include "MenuButton.h"
#include "Menu.h"

MenuButton::MenuButton( QGraphicsScene *Scene) : menuButtonScene{Scene}
{
    clickMenuButton = false;

    //set picture
    setPixmap(QPixmap(":/images/menu.png"));

    //add to scene
    Scene->addItem(this);

    //setPos
    setPos(550,500);

    //create level1 button music
       menuButtonMusic = new QMediaPlayer();
       menuButtonMusic->setMedia(QUrl("qrc:/music/click.mp3"));

}

MenuButton::~MenuButton()
{
    delete menuButtonScene;
    delete menuButtonMusic;
}

void MenuButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    clickMenuButton=true;
    menuButtonMusic->play();

    auto myM = new Menu();
    myM->show();
}
