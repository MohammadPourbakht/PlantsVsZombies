#ifndef REPLYBUTTON_H
#define REPLYBUTTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>



class ReplyButton :public QGraphicsPixmapItem
{
    friend class View;
private:
    QGraphicsScene * replayButtonScene;
    QMediaPlayer * replayButtonMusic;
    bool clickReplayButton;
    int season;
    int level;

public:
     ReplyButton(QGraphicsScene *Scene , int season , int level);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    ~ReplyButton();
};

#endif // REPLYBUTTON_H
