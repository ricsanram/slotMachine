#include "randomnumbergenerator.h"
#include <QDebug>
#include <QRandomGenerator>
#include <QThread>
#include <qtconcurrentrun.h>
#include <QApplication>
#include <QtConcurrent>

using namespace QtConcurrent;


int RandomNumberGenerator::getRandy1()
{
    return randy1;
}

int RandomNumberGenerator::getRandy2()
{
    return randy2;
}

int RandomNumberGenerator::getRandy3()
{
    return randy3;
}

int RandomNumberGenerator::generate()
{
    int temp = QRandomGenerator::global()->generate()%7;

    qDebug() << QString::number(temp) << " from " << QThread::currentThread();
    return temp;
}

RandomNumberGenerator::RandomNumberGenerator(QWidget *parent) : QWidget(parent)
{
    Controller controller1;
    emit controller1.createRandNum();

    Controller controller2;
    emit controller2.createRandNum();

    Controller controller3;
    emit controller3.createRandNum();

    randy1 = QRandomGenerator::global()->generate()%7;
    randy2 = QRandomGenerator::global()->generate()%7;
    randy3 = QRandomGenerator::global()->generate()%7;
}
