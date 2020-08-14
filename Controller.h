#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>
#include "Zombie.h"
#include "Score.h"
#include "Sun.h"


class Controller : public QObject
{
    Q_OBJECT
    friend class View;
    friend class Zombie;
private:
    QGraphicsScene *scene;
    QTimer *ctimer;
    QGraphicsRectItem *holder;
    QList<Zombie *> zombieList;
    QList<Sun *> sunList;

    QGraphicsPixmapItem *scoreBoard;
    Score *controllerScore;


public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();
    void addZombie(int velocity);
    void addSun();
    void addNuts(int velocity);

signals:

};

#endif // CONTROLLER_H
