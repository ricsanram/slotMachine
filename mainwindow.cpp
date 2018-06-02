#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTest>
#include <QVector>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    A.load(":/images/A.png");
    B.load(":/images/B.png");
    C.load(":/images/C.png");
    D.load(":/images/D.png");
    E.load(":/images/E.png");
    F.load(":/images/F.png");
    G.load(":/images/G.png");
    letters.append(A);
    letters.append(B);
    letters.append(C);
    letters.append(D);
    letters.append(E);
    letters.append(F);
    letters.append(G);
    animation = new QMovie(":/images/animationShadow.gif");

    bet=0;
    coins=50;
    multiplier=0;
    won=0;
    resetBet = false;
    displayBet();
    displayMultiplier();
    displayPull();
    displayWon();
    displayCoins();

    ui->buttonPull->connect(ui->buttonPull,SIGNAL(clicked(bool)),this,SLOT(actionPull()));
    ui->buttonBet->connect(ui->buttonBet,SIGNAL(clicked(bool)),this, SLOT(actionBet()));
}

void MainWindow::setCoins(int inputCoin)
{
    coins = inputCoin;
    displayCoins();
}

void MainWindow::setBet(int inputBet)
{
    bet = inputBet;
    displayBet();
}

void MainWindow::setMultiplier(int inputMultiplier)
{
    multiplier = inputMultiplier;
    displayMultiplier();
}

void MainWindow::setWon(int inputWon)
{
    won = inputWon;
    displayWon();
}

void MainWindow::setRandomNumbers(int inputRand1, int inputRand2, int inputRand3)
{
    randNum1 = inputRand1;
    randNum2 = inputRand2;
    randNum3 = inputRand3;
}

void MainWindow::addCoins(int wonCoins)
{
    coins+=wonCoins;
    displayCoins();
}

void MainWindow::subtractCoins(int lostCoins)
{
    coins-=lostCoins;
    displayCoins();
}

void MainWindow::addBet()
{
    bet++;
    displayBet();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::displayPull()
{
    randNum1 = QRandomGenerator::global()->generate()%7;
    randNum2 = QRandomGenerator::global()->generate()%7;
    randNum3 = QRandomGenerator::global()->generate()%7;
    ui->slot1->setMovie(animation);
    ui->slot2->setMovie(animation);
    ui->slot3->setMovie(animation);
    animation->start();
    QTest::qWait(750);
    ui->slot1->setPixmap(letters[randNum1]);
    QTest::qWait(500);
    ui->slot2->setPixmap(letters[randNum2]);
    QTest::qWait(500);
    ui->slot3->setPixmap(letters[randNum3]);
}

void MainWindow::displayBet()
{
    ui->labelBet->setText("BET " + QString::number(bet));
}

void MainWindow::displayWon()
{
    ui->labelWon->setText("YOU WON " + QString::number(won) + " COINS!");
}

void MainWindow::displayMultiplier()
{
    if (multiplier == 0)
        ui->labelMultiplier->setText("");
    else
        ui->labelMultiplier->setText("x"+QString::number(multiplier));
}

void MainWindow::displayCoins()
{
    ui->labelCoins->setText(QString::number(coins) + " COINS");
}

void MainWindow::actionBet()
{
    if (bet<3)
    {
        addBet();
    }
    if (resetBet == true)
    {
        setBet(1);
        resetBet = false;
    }

}

void MainWindow::actionPull()
{
    if (bet!=0)
    {
        ui->labelWon->setText("YOU WON " + QString::number(won) + " COINS!");
        subtractCoins(bet);
        displayPull();
        if (randNum1==randNum2 && randNum2==randNum3)
        {
            setWon(100);
        }

        setBet(bet);
        addCoins(won);
        resetBet = true;
    } else
        ui->labelWon->setText("ADD YOUR BET!");

}
