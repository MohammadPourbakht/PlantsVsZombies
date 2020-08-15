#ifndef PLAYBUTTON_H
#define PLAYBUTTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>

class PlayButton : public QGraphicsPixmapItem

{
    Q_OBJECT

private:
    QGraphicsScene *playScene;
    QMediaPlayer *playButtonMusic;

public:
    explicit PlayButton(QGraphicsScene *playScene);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);


};

#endif // PLAYBUTTON_H
