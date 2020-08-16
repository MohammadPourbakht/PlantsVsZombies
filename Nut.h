#ifndef NUT_H
#define NUT_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Nut : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:

    int pixPer40MiliSec;
public:
    Nut(const int& pixPer40MiliSec , QTimer *timer
           , QGraphicsItem *parent);

signals:

public slots:
     void moveToRight();
};

#endif // NUT_H
