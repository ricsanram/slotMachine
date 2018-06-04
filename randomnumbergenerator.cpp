#include "randomnumbergenerator.h"
#include <QDebug>
#include <QRandomGenerator>


int RandomNumberGenerator::getRandy1()
{
    Controller controller1;
    emit controller1.createRandNum();
    return controller1.getRandomNumber();
}

int RandomNumberGenerator::getRandy2()
{
    Controller controller2;
    emit controller2.createRandNum();
    return controller2.getRandomNumber();
}

int RandomNumberGenerator::getRandy3()
{
    Controller controller3;
    emit controller3.createRandNum();
    return controller3.getRandomNumber();
}

RandomNumberGenerator::RandomNumberGenerator(QWidget *parent) : QWidget(parent)
{

}
