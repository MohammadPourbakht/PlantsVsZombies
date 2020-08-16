#ifndef LEVEL3BUTTON_H
#define LEVEL3BUTTON_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>


class Level3Button  : public QGraphicsPixmapItem
{
    friend class Menu;
private:
    QGraphicsScene * level3Scene;
    QMediaPlayer * level3ButtonMusic;
    bool clickl3;

public:
    Level3Button(QGraphicsScene *Scene);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    ~Level3Button();
};

#endif // LEVEL3BUTTON_H
