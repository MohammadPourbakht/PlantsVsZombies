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


class View : public QGraphicsView
{
    Q_OBJECT

private:
    QTimer *viewTimer;
    int seconds;
    Controller *viewController;
    QMediaPlayer *backgroundMusic;
    QMediaPlayer *gameOverMusic;
    int season ;
    int level;
    QMediaPlayer * winMusic;
    MenuButton * menuB;
    ReplyButton * replayB;
    NextButton * nextB;

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
