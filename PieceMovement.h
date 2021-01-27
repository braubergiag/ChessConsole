//
// Created by marshall on 18.10.2020.
//

#ifndef CHESSNG_PIECEMOVEMENT_H
#define CHESSNG_PIECEMOVEMENT_H

#include "PieceOnSquare.h"
#include "Piece.h"
#include "Square.h"
#include <string>
#include <cmath>


class PieceMovement {
public:
    Piece piece;
    Square from;
    Square to;
    Piece  promotion;

    PieceMovement(PieceOnSquare& fs,Square& to, Piece promotion = Piece::none) :
        piece(fs.piece),from(fs.square),to(to),promotion(promotion){};
    PieceMovement(std::string move);
    PieceMovement(){};
    int dx () const { return to.getX() - from.getX();}
    int dy() const { return to.getY() - from.getY();}
    int absDx() const {return abs(dx());}
    int absDy() const {return abs(dy());}
    int signX() const {return (dx() > 0) -  (dx() < 0);}
    int signY() const {return (dy() > 0) -  (dy() < 0);}



};


#endif //CHESSNG_FIGUREMOVING_H
