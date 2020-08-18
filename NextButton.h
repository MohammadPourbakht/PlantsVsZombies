#ifndef NEXTBUTTON_H
#define NEXTBUTTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>



class NextButton :public QGraphicsPixmapItem
{
    friend class View;
private:
    QGraphicsScene * nextButtonScene;
    QMediaPlayer * nextButtonMusic;
    bool clickNextButton;
    int level;

public:
     NextButton(QGraphicsScene *Scene  , int level);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    ~NextButton();
};

#endif // NEXTBUTTON_H
