#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsSimpleTextItem>
#include <QMediaPlayer>

class Score : public QGraphicsTextItem
{
    friend class Sun;

private:
    int playerScore;
    QMediaPlayer * scorePlayer;
public:
    Score(QGraphicsItem *parent = 0);
    void addToScore(int s);
    ~Score();
    int getScore();
};

#endif // SCORE_H
