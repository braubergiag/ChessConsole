//
// Created by marshall on 15.10.2020.
//

#ifndef CHESSNG_SQUARE_H
#define CHESSNG_SQUARE_H
#include <string>

class Square {
private:
    int x;
    int y;
public:
    Square(int x = 0, int y= 0): x(x),y(y){}
    Square (std:: string move);
    bool onBoard() const;
    friend bool operator==(const Square& a,const Square& b);
    friend bool operator!=(const Square& a,const Square& b);
    int getX() const;
    int getY() const;

};


#endif //CHESSNG_SQUARE_H
