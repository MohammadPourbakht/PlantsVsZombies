#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QTimer>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include "Level1Button.h"
#include "Level2Button.h"
#include "Level3Button.h"
#include "Level4Button.h"
#include "Level5Button.h"
#include "Level6Button.h"

class Menu : public QGraphicsView
{
    Q_OBJECT

private:
    QGraphicsScene *menuScene;
    QMediaPlayer * menuMusic;
    QTimer *menuTimer;
    Level1Button *l1;
    Level2Button *l2;
    Level3Button *l3;
    Level4Button *l4;
    Level5Button *l5;
    Level6Button *l6;

public:
    explicit Menu();
    ~Menu();

signals:

public slots:
    void menuSchedule();
};

#endif // MENU_H
