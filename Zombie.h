#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QMovie>
#include <QLabel>
#include <QMediaPlayer>

class Zombie : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int lives;
    int pixPer40MiliSec;
    int Layer;
     QMediaPlayer *zombieMusic;

public:
    int  gameOv;
    Zombie(const int& pixPer40MiliSec , QTimer *timer
           ,const int lives, QGraphicsItem *parent);
    ~Zombie();

    void decrementLives();

public slots:
    void moveToLeft();

};

#endif // ZOMBIE_H
