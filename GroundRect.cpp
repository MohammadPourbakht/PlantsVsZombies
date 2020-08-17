#include "GroundRect.h"
#include <QGraphicsScene>

GroundRect::GroundRect(QGraphicsItem *parent)
    : QObject () , QGraphicsRectItem (parent)
{

    clickBlock=false;
    row=0;
    column=0;


}

void GroundRect:: mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    clickBlock=true;
    //set plant music
        plantMusic = new QMediaPlayer();
        plantMusic->setMedia(QUrl("qrc:/music/Plant.mp3"));
        plantMusic->play();



}

GroundRect::~GroundRect()
{
    delete plantMusic;
}

void GroundRect::setGroundRect(int x, int y)
{
    setRect(x,y,150,150);
   // this->hide();

}



