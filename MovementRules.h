//
// Created by marshall on 22.10.2020.
//

#ifndef CHESSN_MOVEMENTRULES_H
#define CHESSN_MOVEMENTRULES_H
#include "PieceMovement.h"
#include "Board.h"


class MovementRules {

    PieceMovement pm;
    Board board;

    bool canMoveFrom();
    bool canMoveTo()const;
    bool canFigureMove() const;
    bool canKingMove() const;
    bool canKnightMove() const;
    bool canBishopMove() const;
    bool canRookMove() const;
    bool canMoveStraight() const;
    bool canPawnMove()const;
    bool canPawnGo(int stepY)const;
    bool canPawnJump(int stepY)const;
    bool canPawnEat(int stepY)const;
public:
    MovementRules(Board board) :board(board) {}
    bool canMove(PieceMovement pm);

};


#endif //CHESSN_MOVES_H
