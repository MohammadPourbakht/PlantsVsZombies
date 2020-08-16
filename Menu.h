#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QTimer>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMediaPlayer>

class Menu : public QGraphicsView
{
    Q_OBJECT

private:
    QGraphicsScene *MenuScene;
    QMediaPlayer * MenuMusic;
    QTimer *menuTimer;


public:
    explicit Menu();
    ~Menu();

signals:

public slots:
    void menuSchedule();
};

#endif // MENU_H
