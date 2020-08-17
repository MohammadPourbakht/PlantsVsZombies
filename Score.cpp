#include "Score.h"
#include <QFont>


Score::Score(QGraphicsItem *parent)
    : QGraphicsTextItem (parent) , playerScore{0}
{
    setPlainText(QString::number(playerScore));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",20));

    //create score player
       scorePlayer = new QMediaPlayer();
       scorePlayer->setMedia(QUrl("qrc:/music/sun.mp3"));

}


void Score::addToScore(int s)
{
    playerScore +=s;
    setPlainText(QString::number(playerScore));
}

Score::~Score()
{
    delete scorePlayer;
}

int Score::getScore()
{
    return playerScore;
}
