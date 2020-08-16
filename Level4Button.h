#ifndef LEVEL4BUTTON_H
#define LEVEL4BUTTON_H


#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>


class Level4Button  : public QGraphicsPixmapItem
{
    friend class Menu;
private:
    QGraphicsScene * level4Scene;
    QMediaPlayer * level4ButtonMusic;
    bool clickl4;

public:
    Level4Button(QGraphicsScene *Scene);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    ~Level4Button();
};

#endif // LEVEL4BUTTON_H
