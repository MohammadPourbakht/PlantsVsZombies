#ifndef NUT_H
#define NUT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "Plant.h"

class Nut : public QObject , public Plant
{
    Q_OBJECT
private:
    int Layer;
    int pixPer40MiliSec;
public:
    Nut(const int& pixPer40MiliSec , QTimer *timer , QGraphicsItem *parent);


signals:

public slots:
     void moveToRight();
};

#endif // NUT_H
