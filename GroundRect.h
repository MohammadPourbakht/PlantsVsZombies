#ifndef GROUNDRECT_H
#define GROUNDRECT_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include "Plant.h"



class GroundRect : public QObject , public QGraphicsRectItem
{
    Q_OBJECT
private:
    Plant *myP = nullptr;
    QMediaPlayer * plantMusic;
public:
    explicit GroundRect(QGraphicsItem *parent = nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    ~GroundRect();
    void setGroundRect(int x , int y);

signals:

public slots:

};

#endif // GROUNDRECT_H
