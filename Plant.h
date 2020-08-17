#ifndef PLANT_H
#define PLANT_H

#include <QGraphicsPixmapItem>

class Plant : public QGraphicsPixmapItem
{
private:
    bool isDead;
public:
    Plant();
    ~Plant();
};

#endif // PLANT_H
