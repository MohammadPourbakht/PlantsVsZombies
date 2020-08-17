#ifndef NUTICON_H
#define NUTICON_H


#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>

class NutIcon: public QGraphicsPixmapItem
{
    friend class Controller;
private:
    QGraphicsScene * nutIconScene;
    bool isSelected;
    bool isSelectable;

public:
    NutIcon(QGraphicsScene *nutIconScene);
    ~NutIcon();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setNutIcon();
};

#endif // NUTICON_H
