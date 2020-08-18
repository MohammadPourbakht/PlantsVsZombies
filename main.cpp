#include <QApplication>
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


}
