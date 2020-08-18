#ifndef CHERRYICON_H
#define CHERRYICON_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>

class CherryIcon: public QGraphicsPixmapItem
{
    friend class Controller;
private:
    QGraphicsScene * cherryIconScene;
    bool isSelected;
    bool isSelectable;

public:
    CherryIcon(QGraphicsScene *cherryIconScene);
    ~CherryIcon();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setCherryIcon();
};

#endif // CHERRYICON_H
