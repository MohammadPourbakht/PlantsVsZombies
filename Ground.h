#ifndef GROUND_H
#define GROUND_H

#include <QObject>

class Ground : public QObject
{
    Q_OBJECT
public:
    explicit Ground(QObject *parent = nullptr);

signals:

public slots:
};

#endif // GROUND_H