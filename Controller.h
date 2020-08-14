#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QMainWindow>

class Controller : public QMainWindow
{
    Q_OBJECT

public:
    Controller(QWidget *parent = 0);
    ~Controller();
};

#endif // CONTROLLER_H
