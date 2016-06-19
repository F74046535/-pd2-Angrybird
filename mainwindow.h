#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>
#include<QPushButton>
#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include<yellow.h>
#include<white.h>
#include <wood.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void closeEvent(QCloseEvent *);

    Bird *birdie;
    Bird *piggy;
    //Wood *shooter;
    Bird *birdies;
    Bird *birdiee;
    Bird *birdiees;
    Bird *bomb;
    Bird *egg;
    Yellow *yellowbird;
    Yellow *yellowbirds;
    White *whitebird;
    White *whitebirds;
    QPushButton *m_button;
    //QPushButton *m_buttont;
    int press;
    int count;
    int x0;
    int y0;
    int k;
    int j;
    bool a=false;
    bool b=false;
    bool c=false;
    bool d=false;
signals:
    // Signal for closing the game
     void quitGame();
private slots:
    void tick();
    // For debug slot
    void QUITSLOT();
    void handleButton();
    void GetLinearVelocity();
    void exit();
    //void restart();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QTimer timer;
};

#endif // MAINWINDOW_H
