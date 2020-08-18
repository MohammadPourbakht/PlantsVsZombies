#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>


class MenuButton :public QGraphicsPixmapItem
{
    friend class View;
private:
    QGraphicsScene * menuButtonScene;
    QMediaPlayer * menuButtonMusic;
    bool clickMenuButton;

public:
     MenuButton(QGraphicsScene *Scene);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    ~ MenuButton();
};

#endif // MENUBUTTON_H
