#include <QApplication>
#include "View.h"
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[])
{
QApplication a(argc , argv);

srand(time(0));

auto myV = new View();
myV->show();
return a.exec();


}
