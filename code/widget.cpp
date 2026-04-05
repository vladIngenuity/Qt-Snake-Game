#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent) : QWidget(parent) {

    resize(400, 400);
    setStyleSheet("background-color: black;");

    timer=new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::gameLoop);
    timer->start(150);
}

void Widget::gameLoop(){

    QPoint head=snake.getBody().front();

    if(head.x()<0 || head.x() >= width()/TILE_SIZE ||
        head.y()<0 || head.y() >= height()/TILE_SIZE)
    {
        timer->stop();
        showGameOverMessage();
        return;
    }


    bool willGrow=(snake.getBody().front() == food.getPosition());
    if(willGrow) {
        food.generate(width()/ TILE_SIZE,height()/TILE_SIZE);
    }

    if(hasNextDir){
        snake.setDirection(nextDirBuffer);
        hasNextDir=false;
    }

        snake.move(willGrow);

    if(snake.checkSelfCollision()){
         timer->stop();
        showGameOverMessage();
     }

    update();
 }

void Widget::keyPressEvent(QKeyEvent *event) {
    Direction current = snake.getDirection();
    Direction pressed;
    bool valid = true;

    switch (event->key()) {
    case Qt::Key_W: pressed = Direction::Up;    if(current == Direction::Down)  valid = false; break;
    case Qt::Key_S: pressed = Direction::Down;  if(current == Direction::Up)    valid = false; break;
    case Qt::Key_A: pressed = Direction::Left;  if(current == Direction::Right) valid = false; break;
    case Qt::Key_D: pressed = Direction::Right; if(current == Direction::Left)  valid = false; break;
    default: valid = false;
    }

    if (valid) {
        nextDirBuffer = pressed;
        hasNextDir = true;
    }
}

void Widget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);

    painter.setBrush(Qt::red);
    painter.setPen(Qt::NoPen);

    painter.drawEllipse(food.getPosition().x()*TILE_SIZE,
                        food.getPosition().y() * TILE_SIZE,
                        TILE_SIZE, TILE_SIZE);

    const auto& body=snake.getBody();
    for(size_t i=0;i < body.size();i++){
        if(i==0){
            painter.setBrush(Qt::yellow);
        } else {
            painter.setBrush(Qt::green);
        }

       painter.drawRect(body[i].x() * TILE_SIZE, body[i].y() * TILE_SIZE,
                         TILE_SIZE, TILE_SIZE);

    }

    painter.setPen(QColor(50,50,50));
    for(int i = 0; i < width(); i += TILE_SIZE)
        painter.drawLine(i, 0, i, height());
    for(int j = 0; j < height(); j += TILE_SIZE)
        painter.drawLine(0, j, width(), j);
}

void Widget::showGameOverMessage(){
    QMessageBox msgBox(this);
    msgBox.setStyleSheet("QMessageBox { background-color: white; } "
                         "QLabel {background-color: white; }"
                         "QPushButton { background-color: lightgray;  }");

    msgBox.setWindowTitle("Game over");
    msgBox.setText("Змейка врезалась");
    msgBox.setInformativeText("Ваш счет: " + QString::number(snake.getBody().size()-3));

    msgBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Close);
    msgBox.button(QMessageBox::Retry)->setText("Попробуй снова");
    msgBox.button(QMessageBox::Close)->setText("Выход");

    if(msgBox.exec()==QMessageBox::Retry)
    {
        resetGame();
    }
    else
        qApp->quit();
}
void Widget::resetGame()
{
    snake=Snake();
    food.generate(width() / TILE_SIZE, height() / TILE_SIZE);
    timer->start(150);
    update();
}
