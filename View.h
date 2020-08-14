#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QMediaPlayer>
#include "Controller.h"


class View : public QGraphicsView
{
    Q_OBJECT

private:
    QTimer *viewTimer;
    int seconds;
    Controller *viewController;
    QMediaPlayer *backgroundMusic;
    QMediaPlayer *gameOverMusic;

public:
    explicit View();
    ~View();

signals:

public slots:
    void schedule();
};

#endif // VIEW_H
