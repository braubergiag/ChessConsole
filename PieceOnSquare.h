//
// Created by marshall on 18.10.2020.
//
#include "Piece.h"
#include "Square.h"
#ifndef CHESSNG_PIECEONSQUARE_H
#define CHESSNG_PIECEONSQUARE_H
class PieceOnSquare {

public:
    Piece piece;
    Square square;
    PieceOnSquare(Square& square_,  Piece & piece): piece(piece),square(square){}
};

#endif 
