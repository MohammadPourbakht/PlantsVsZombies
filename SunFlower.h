#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#include <QObject>
#include "Plant.h"
#include <QTimer>
#include "Score.h"
#include <QGraphicsScene>


class SunFlower : public QObject , public Plant
{
    Q_OBJECT
private:

    QTimer *sunTimer;
    int timeIntervals;
    Score *sunScore;
    QGraphicsScene *sunScene;



public:
    explicit SunFlower(Score *sunScore ,
    QGraphicsScene *sunScene ,QTimer *sunTimer , QGraphicsItem *parent = nullptr);


signals:

public slots:
     void makeSun();


};

#endif // SUNFLOWER_H
