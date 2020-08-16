#ifndef LEVEL6BUTTON_H
#define LEVEL6BUTTON_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>

class Level6Button  : public QGraphicsPixmapItem
{
    friend class Menu;
private:
    QGraphicsScene * level6Scene;
    QMediaPlayer * level6ButtonMusic;
    bool clickl6;

public:
    Level6Button(QGraphicsScene *Scene);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    ~Level6Button();
};

#endif // LEVEL6BUTTON_H
