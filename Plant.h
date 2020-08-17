#ifndef PLANT_H
#define PLANT_H

#include <QGraphicsPixmapItem>

class Plant : public QGraphicsPixmapItem
{


public:
    bool isDead;
    Plant();
    ~Plant();
};

#endif // PLANT_H
