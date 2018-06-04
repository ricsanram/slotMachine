#include "gamemanager.h"

GameManager::GameManager(QWidget *parent) : QWidget(parent)
{
    slotGame.showBegin();
    slotGame.show();
}


