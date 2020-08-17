#ifndef GROUNDRECT_H
#define GROUNDRECT_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include "Plant.h"
#include <QGraphicsScene>


class GroundRect : public QObject , public QGraphicsRectItem
{
    Q_OBJECT
    friend class Controller;
private:
    Plant *myP = nullptr;
    QMediaPlayer * plantMusic;
    bool clickBlock;
    int row;
    int column;

public:
    explicit GroundRect(QGraphicsItem *parent );
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    ~GroundRect();
    void setGroundRect(int x , int y);

signals:

public slots:

};

#endif // GROUNDRECT_H
