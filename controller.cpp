#include "controller.h"

Controller::Controller()
{
    Worker *worker = new Worker;
    worker->moveToThread(&workerThread);

    connect(&workerThread, &QThread::finished,worker, &QObject::deleteLater);

    connect(this, &Controller::createRandNum,worker,&Worker::doWorkRandom);
    connect(worker, &Worker::readyRandNum, this, &Controller::handleRandNum);

    workerThread.start();
}

void Controller::handleRandNum(const int &randnum)
{
   randomNumber = randnum;
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
