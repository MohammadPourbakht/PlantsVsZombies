#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>
#include "Zombie.h"
#include "Score.h"
#include "Sun.h"
#include "GroundRect.h"
#include "Nut.h"
#include "ShooterIcon.h"
#include "NutIcon.h"

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
    QList<GroundRect *> groundList;
    QGraphicsPixmapItem *scoreBoard;
    Score *controllerScore;
    ShooterIcon * shooterIcon;
    NutIcon * nutIcon;

public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();
    void addZombie(const int& velocity, const int & lives , bool isLord);
    void addSun();
    void addNuts(int velocity);
    bool boolGameOver();
    void checkLives();
    void addGround(const int & season);
    void checkShooterIcon();
    void planting();
    void checkNutIcon();

signals:

};

#endif // CONTROLLER_H
