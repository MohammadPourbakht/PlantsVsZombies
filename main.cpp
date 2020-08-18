#include <QApplication>
#include "View.h"
#include <cstdlib>
#include <ctime>
#include "Loading.h"
#include "Menu.h"

int main(int argc, char *argv[])
{
QApplication a(argc , argv);

srand(time(0));

auto loading = new Loading();
loading->show();
return a.exec();

//auto myM = new Menu();
//     myM->show();
//     return a.exec();

//auto myV = new View(3);
//myV->show();
//return a.exec();

}
