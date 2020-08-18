#include "GroundRect.h"
#include <QGraphicsScene>
#include <QPen>

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
}
void GroundRect::setGroundRect(int x, int y)
{
    setRect(x,y,150,150);
    QPen *pen = new QPen("transparent");
    this->setPen(*pen);
 }
GroundRect::~GroundRect()
{
    delete plantMusic;
}


