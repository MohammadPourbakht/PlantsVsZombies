#ifndef CHERRYBOMB_H
#define CHERRYBOMB_H

#include <QObject>
#include "Plant.h"
#include <QTimer>
#include <QGraphicsPixmapItem>
#include<QMediaPlayer>


class CherryBomb : public QObject , public Plant
{
    Q_OBJECT
private:
    int timeIntervals;
    QTimer * cherryTimer;
    QMediaPlayer * cherryBombPlayer;
public:
    explicit CherryBomb(QTimer *cherrytTimer , QGraphicsItem *parent = nullptr);
int gettimeIntervals();
signals:

public slots:
    void move();
};

#endif // CHERRYBOMB_H
