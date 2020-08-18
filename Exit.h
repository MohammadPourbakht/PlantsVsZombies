#ifndef EXIT_H
#define EXIT_H


#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>

class Exit :public QGraphicsPixmapItem
{
    friend class View;
private:
    QGraphicsScene * exitButtonScene;
    QMediaPlayer * exitButtonMusic;
    bool clickExitButton;


public:
     Exit(QGraphicsScene *Scene  );
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    ~Exit();
};


#endif // EXIT_H
