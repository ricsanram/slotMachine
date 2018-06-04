#include "worker.h"
#include <QMutex>
#include <QDebug>

void Worker::doWorkRandom()
{
    QMutex mutex;
    mutex.lock();

    int randNum = randomNumber();
    emit readyRandNum(randNum);
    mutex.unlock();
}

int Worker::randomNumber()
{
    int temp = (QRandomGenerator::global()->generate())%7;
    return temp;
}
