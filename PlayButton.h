#ifndef PLAYBUTTON_H
#define PLAYBUTTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>

class PlayButton : public QGraphicsPixmapItem
{
    friend class Loading;


private:
    QGraphicsScene *playScene;
    QMediaPlayer *playButtonMusic;
    int click;

public:
    PlayButton(QGraphicsScene *playScene);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    ~PlayButton();
    void setButton();



};

#endif // PLAYBUTTON_H
