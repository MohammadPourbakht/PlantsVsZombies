#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsSimpleTextItem>

class Score : public QGraphicsTextItem
{
private:
    int playerScore;
public:
    Score(QGraphicsItem *parent = 0);
    void addToScore(int s);
};

#endif // SCORE_H
