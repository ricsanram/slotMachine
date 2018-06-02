#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include <QPixmap>
#include <QRandomGenerator>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setCoins(int);
    void setBet(int);
    void setMultiplier(int);
    void setWon(int);
    void setRandomNumbers(int,int,int);
    ~MainWindow();



private:
    Ui::MainWindow *ui;
    QPixmap A;
    QPixmap B;
    QPixmap C;
    QPixmap D;
    QPixmap E;
    QPixmap F;
    QPixmap G;
    QVector<QPixmap> letters;
    QMovie *animation;
    int randNum1;
    int randNum2;
    int randNum3;
    int coins,bet,multiplier,won;

public slots:
    void displayPull();
    void displayBet();
    void displayWon();
    void displayMultiplier();
    void displayCoins();

};

#endif // MAINWINDOW_H
