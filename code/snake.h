#pragma once

#include<deque>
#include<QPoint>
enum class Direction{Up,Down,Left,Right};
class Snake{
public:
    Snake();

    void move(bool grow=false);

    void setDirection(Direction newDir);
    const Direction getDirection() const;

    bool checkSelfCollision() const;

const std::deque<QPoint>& getBody() const{ return body; }

private:
    std::deque<QPoint> body;
    Direction currentDir=Direction::Right;

};
