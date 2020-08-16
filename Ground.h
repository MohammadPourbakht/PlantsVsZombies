#ifndef GROUND_H
#define GROUND_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include "Plant.h"



class Ground : public QObject , public QGraphicsRectItem
{
    Q_OBJECT
private:
    Plant *myP = nullptr;
public:
    explicit Ground(QGraphicsItem *parent = nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:

public slots:

};

#endif // GROUND_H
