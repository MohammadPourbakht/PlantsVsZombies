#ifndef SUN_H
#define SUN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "Score.h"
#include <QTimer>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>

class Sun : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QGraphicsScene *sunScene;
    Score *sunScore;
    int timeIntervals;

public:
    Sun(QGraphicsScene *sunScene , Score *sunScore , QGraphicsItem *parent ,
        QTimer *timer);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
public slots:
    void move();

};

#endif // SUN_H
