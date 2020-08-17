#include "GroundRect.h"
#include <QGraphicsScene>

GroundRect::GroundRect(QGraphicsItem *parent)
    : QObject () , QGraphicsRectItem (parent)
{


}

void GroundRect:: mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //set plant music
        plantMusic = new QMediaPlayer();
        plantMusic->setMedia(QUrl("qrc:/music/plant.mp3"));
        plantMusic->play();

}

GroundRect::~GroundRect()
{
    delete plantMusic;
}

void GroundRect::setGroundRect(int x, int y)
{
    setRect(x,y,150,150);

}



