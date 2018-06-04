#include "controller.h"
#include <QDebug>

Controller::Controller()
{
    Worker *worker = new Worker;
    worker->moveToThread(&workerThread);

    connect(&workerThread, &QThread::finished,worker, &QObject::deleteLater);

    connect(this, &Controller::createRandNum,worker,&Worker::doWorkRandom);
    connect(worker, &Worker::readyRandNum, this, &Controller::handleRandNum);

    workerThread.start();
}

void Controller::handleRandNum(int randnum)
{
   randomNumber = randnum;
   qDebug() << randnum;
}

Controller::~Controller()
{
    workerThread.quit();
    workerThread.wait();
}

int Controller::getRandomNumber()
{
    return randomNumber;
}
