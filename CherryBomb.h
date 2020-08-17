#ifndef CHERRYBOMB_H
#define CHERRYBOMB_H

#include <QObject>
#include "Plant.h"
#include <QTimer>

class CherryBomb : public QObject , public Plant
{
    Q_OBJECT
private:
    int timeIntervals;
    QTimer * cherryTimer;
public:
    explicit CherryBomb(QTimer *cherrytTimer,QGraphicsItem *parent = nullptr);

signals:

public slots:
    void move();
};

#endif // CHERRYBOMB_H
