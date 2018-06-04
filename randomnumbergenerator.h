#ifndef RANDOMNUMBERGENERATOR_H
#define RANDOMNUMBERGENERATOR_H

#include <QWidget>
#include "controller.h"
#include "worker.h"
#include <QThread>
#include <QVector>

class RandomNumberGenerator : public QWidget
{
    Q_OBJECT
public:
    int getRandy1();
    int getRandy2();
    int getRandy3();
    explicit RandomNumberGenerator(QWidget *parent = nullptr);

private:
signals:

public slots:

};

#endif // RANDOMNUMBERGENERATOR_H
