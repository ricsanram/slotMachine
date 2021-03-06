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
    static int generate();
    explicit RandomNumberGenerator(QWidget *parent = nullptr);

private:
    int randy1;
    int randy2;
    int randy3;
signals:

public slots:

};

#endif // RANDOMNUMBERGENERATOR_H
