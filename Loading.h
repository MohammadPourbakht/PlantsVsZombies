#ifndef LOADING_H
#define LOADING_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QMediaPlayer>
#include <QGraphicsScene>
#include "PlayButton.h"

class Loading : public QGraphicsView
{
     Q_OBJECT

private:
    QGraphicsScene *loadingScene;
    QTimer *loadingTimer;
    int seconds;
    QMediaPlayer * loadingMusic;
    PlayButton* playButton;


public:
    explicit Loading();
    ~Loading();

signals:

public slots:
    void loadingSchedule();

};

#endif // LOADING_H
