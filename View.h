#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QMediaPlayer>
#include "Controller.h"
#include "MenuButton.h"
#include "ReplyButton.h"
#include "NextButton.h"
#include "Exit.h"

class View : public QGraphicsView
{
    Q_OBJECT

private:
    QTimer *viewTimer;
    int miliseconds;
    Controller *viewController;
    QMediaPlayer *backgroundMusic;
    QMediaPlayer *gameOverMusic;
    int season ;
    int level;
    QMediaPlayer * winMusic;
     QMediaPlayer * zCommingMusic;
    MenuButton * menuB;
    ReplyButton * replayB;
    NextButton * nextB;
    Exit* exitB;

public:
    explicit View(int season , int level);
    ~View();
    void stopGame();
    void setBackground();

signals:

public slots:
    void schedule();
};

#endif // VIEW_H
