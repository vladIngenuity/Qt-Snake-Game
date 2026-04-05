#pragma once
#include <QPoint>

class Food{
public:
    Food();

    void generate(int fieldWidth, int fieldHeight);

    QPoint getPosition() const {return position;}

private:
    QPoint position;

};
