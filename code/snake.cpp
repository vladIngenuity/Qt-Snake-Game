#include"snake.h"

Snake::Snake(){

    body.push_back(QPoint(5,5));
    body.push_back(QPoint(4, 5));
    body.push_back(QPoint(3, 5));
    currentDir=Direction::Right;
}

void Snake::setDirection(Direction newDir){

    if (currentDir == Direction::Up && newDir == Direction::Down) return;
    if (currentDir == Direction::Down && newDir == Direction::Up) return;
    if (currentDir == Direction::Left && newDir == Direction::Right) return;
    if (currentDir == Direction::Right && newDir == Direction::Left) return;
    currentDir = newDir;
    return;
}

void Snake::move(bool grow){
    QPoint newHead=body.front();
    if (currentDir == Direction::Up)    newHead.ry() -= 1;
    if (currentDir == Direction::Down)  newHead.ry() += 1;
    if (currentDir == Direction::Left)  newHead.rx() -= 1;
    if (currentDir == Direction::Right) newHead.rx() += 1;

    body.push_front(newHead);

    if(!grow)
        body.pop_back();

    return;
}

bool Snake::checkSelfCollision() const{
    if (body.size() < 4)
        return false;

    auto it=body.begin()+4;

    while(it != body.end())
    {
        if(*it == body.front())
            return true;

        ++it;
    }
    return false;
}

const Direction Snake::getDirection() const{
    return currentDir;
}
