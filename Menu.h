#ifndef MENU_H
#define MENU_H


#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMediaPlayer>



class Menu : public QGraphicsView
{


private:
    QGraphicsScene *MenuScene;
    QMediaPlayer * MenuMusic;


public:
    explicit Menu();
    ~Menu();


};

#endif // MENU_H
