#ifndef PLAYBUTTON_H
#define PLAYBUTTON_H

#include <QObject>

class PlayButton : public QObject
{
    Q_OBJECT
public:
    explicit PlayButton(QObject *parent = nullptr);

signals:

};

#endif // PLAYBUTTON_H
