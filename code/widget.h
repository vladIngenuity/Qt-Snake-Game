#pragma once
#include<QWIdget>
#include"snake.h"
#include"food.h"
#include<QTimer>
#include<QKeyEvent>
#include<QPainter>
#include<QMessageBox>
class Widget : public QWidget{
    Q_OBJECT

public:
    Widget(QWidget *parent =nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void gameLoop();

private:
    Snake snake;
    Food food;
    QTimer *timer;
    const int TILE_SIZE = 20;
    bool hasNextDir = false;
    Direction nextDirBuffer;

    void resetGame();
    void showGameOverMessage();

};
