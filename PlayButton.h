#ifndef PLAYBUTTON_H
#define PLAYBUTTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>

class PlayButton : public QGraphicsPixmapItem

{


private:
    QGraphicsScene *playScene;
    QMediaPlayer *playButtonMusic;

public:
    PlayButton(QGraphicsScene *playScene);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);




};

#endif // PLAYBUTTON_H
