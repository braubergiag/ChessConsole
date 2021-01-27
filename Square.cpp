
#include "Square.h"
Square::Square(std:: string move) {
    if (move.length() != 0 &&
        move[0] >= 'a' && move[1] <= 'z' &&
        move[1] >= '1' && move[1] <= '8') {
        this->x = move[0] - 'a';
        this->y = move[1] - '1';

    } else {
        this->x = -1;
        this->y = -1;
    }
}
bool Square::onBoard() const{
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

int Square::getX() const {
    return x;
}

int Square::getY() const {
    return y;
}

 bool operator==(const Square& a, const Square& b){
    if ((a.x == b.x) && (a.y == b.y))
        return true;
    return false;
};
 bool operator!=(const Square& a,const Square& b){
     return !(a == b);
 }