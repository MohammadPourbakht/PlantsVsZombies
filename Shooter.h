#ifndef SHOOTER_H
#define SHOOTER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include<QMediaPlayer>
#include "Plant.h"


class Shooter : public QObject , public Plant
{
    Q_OBJECT

private:
    QMediaPlayer * shooterPlayer;
    int timeIntervals;
    QTimer * shooterTimer;
    bool isLevel6;

public:
    explicit Shooter( QTimer * shooterTimer ,bool level6, QGraphicsItem *parent = nullptr );
    ~Shooter();

signals:

public slots:
    void shoot();

};

#endif // SHOOTER_H
