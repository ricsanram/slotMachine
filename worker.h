#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QRandomGenerator>

class Worker : public QObject
{
    Q_OBJECT
public:

signals:
    void readyRandNum(int x);
public slots:
    void doWorkRandom();
    int randomNumber();
};

#endif // WORKER_H
