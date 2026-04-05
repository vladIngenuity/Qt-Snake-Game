#include "food.h"
#include<random>

Food::Food(){
    position=QPoint(10,10);
}

void Food::generate(int fieldWidth, int fieldHeight) {

    static std::mt19937 gen(std::random_device{}());

    std::uniform_int_distribution<> disX(0, fieldWidth-1);
    std::uniform_int_distribution<> disY(0, fieldHeight-1);

    position=QPoint(disX(gen),disY(gen));
}
