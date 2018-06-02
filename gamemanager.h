#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QWidget>
#include "mainwindow.h"

class GameManager : public QWidget
{
    Q_OBJECT
public:
    explicit GameManager(QWidget *parent = nullptr);


private:
    MainWindow slotGame;
    int coin, bet, multiplier, won;
signals:

public slots:
};

#endif // GAMEMANAGER_H
