#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>
#include "Zombie.h"
#include "Score.h"
#include "Sun.h"
#include "Ground.h"
#include "Nut.h"

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
    void addZombie(const int& velocity, const int & lives , bool isLord);
    void addSun();
    void addNuts(int velocity);
    bool boolGameOver();
    void checkLives();

signals:

};

#endif // CONTROLLER_H
