//
// Created by marshall on 22.10.2020.
//

#include "PieceMovement.h"
PieceMovement::PieceMovement(std::string move){
    piece =  static_cast<Piece>(move[0]);
    from = Square(move.substr(1,2));
    to = Square(move.substr(3,2));
    promotion = (move.length() == 6) ? static_cast<Piece>(move[5]) : Piece::none;

}