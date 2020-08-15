#ifndef LOADINGRECT_H
#define LOADINGRECT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>


class LoadingRect : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    int velocity;


public:
    explicit LoadingRect(QTimer * bulletTimer , const int & velocity);

signals:

public slots:
    void moveToRight();

};

#endif // LOADINGRECT_H
