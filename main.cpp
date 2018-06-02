#include "gamemanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameManager game;

    return a.exec();
}
