#ifndef LEVEL1BUTTON_H
#define LEVEL1BUTTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>
#include "Menu.h"

class Level1Button :public QGraphicsPixmapItem
{
    friend class Menu;
private:
    QGraphicsScene *Level1Scene;
    QMediaPlayer *Level1ButtonMusic;
    bool clickl1;

public:
    Level1Button(QGraphicsScene *Scene);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    ~Level1Button();

};

#endif // LEVEL1BUTTON_H
