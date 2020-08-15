#include "Ground.h"
#include <QGraphicsScene>

Ground::Ground(Plant *plant,QGraphicsItem *parent) : QObject() , QGraphicsRectItem(parent) ,
    plant(plant)

{
    QGraphicsRectItem *rect1 = new QGraphicsRectItem();
    QGraphicsRectItem *rect2 = new QGraphicsRectItem();
    QGraphicsRectItem *rect3 = new QGraphicsRectItem();
    QGraphicsRectItem *rect4 = new QGraphicsRectItem();
    QGraphicsRectItem *rect5 = new QGraphicsRectItem();
    QGraphicsRectItem *rect6 = new QGraphicsRectItem();
    QGraphicsRectItem *rect7 = new QGraphicsRectItem();

    rect1->setRect(0,370,150,150);
    rect2->setRect(150,370,150,150);
    rect3->setRect(300,370,150,150);
    rect4->setRect(450,370,150,150);
    rect5->setRect(600,370,150,150);
    rect6->setRect(750,370,150,150);
    rect7->setRect(900,370,150,150);
    scene()->addItem(rect1);
    scene()->addItem(rect2);
    scene()->addItem(rect3);
    scene()->addItem(rect4);
    scene()->addItem(rect5);
    scene()->addItem(rect6);
    scene()->addItem(rect7);
}

void Ground::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    plant = new Plant();


}
