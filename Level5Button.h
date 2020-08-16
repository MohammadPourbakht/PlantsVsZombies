#ifndef LEVEL5BUTTON_H
#define LEVEL5BUTTON_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>


class Level5Button  : public QGraphicsPixmapItem
{
    friend class Menu;
private:
    QGraphicsScene * level5Scene;
    QMediaPlayer * level5ButtonMusic;
    bool clickl5;

public:
    Level5Button(QGraphicsScene *Scene);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    ~Level5Button();
};

#endif // LEVEL5BUTTON_H
