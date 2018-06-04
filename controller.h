#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QThread>
#include "worker.h"

class Controller : public QObject
{
    Q_OBJECT
    QThread workerThread;
public:
    Controller();
    ~Controller();
    int getRandomNumber();

private:
    int randomNumber;
signals:
    void createRandNum();
public slots:
    void handleRandNum(int randnum);
};

#endif // CONTROLLER_H
