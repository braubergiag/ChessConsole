//
// Created by marshall on 22.10.2020.
//

#include "MovementRules.h"
bool MovementRules::canMove(PieceMovement pm) {
    this->pm = pm;
    return canMoveFrom() && canMoveTo() && canFigureMove();
}
bool MovementRules::canMoveFrom()  {
    Square check = Square(pm.from.getX(),pm.from.getY());
    Piece piece = board.getPieceAt(check);
    bool isCorrect = (piece == pm.piece) && pm.from.onBoard();
    return isCorrect && board.getColor(pm.piece) == board.getMoveColor();
}
bool MovementRules::canMoveTo()const {
    return pm.to.onBoard() && pm.to != pm.from &&
           board.getColor(board.getPieceAt(pm.to)) != board.getMoveColor();
}
bool MovementRules::canFigureMove()const {
    switch(pm.piece){
        case Piece::blackKing:
        case Piece::whiteKing:
            return canKingMove();
        case Piece::blackKnight:
        case Piece::whiteKnight:
            return canKnightMove();
        case Piece::blackBishop:
        case Piece::whiteBishop:
            return canBishopMove();
        case Piece::blackQueen:
        case Piece::whiteQueen:
            return canMoveStraight();
        case Piece::blackRook:
        case Piece::whiteRook:
            return canRookMove();
        case Piece::blackPawn:
        case Piece::whitePawn:
            return canPawnMove();
        default:
            return false;
    }
}
bool MovementRules::canKingMove() const {
    if (pm.absDx() <= 1 && pm.absDy() <= 1)
        return true;
    return false;
}
bool MovementRules::canKnightMove() const {
    if ((pm.absDx() == 1 && pm.absDy() == 2) || (pm.absDx() == 2 && pm.absDy() == 1))
        return true;
    return false;
}
bool MovementRules::canMoveStraight() const {
    Square at = pm.from;
    do {
        at = Square(at.getX() + pm.signX(),at.getY() + pm.signY());
        if (at == pm.to) return true;
    } while (at.onBoard() && board.getPieceAt(at) == Piece::none);
    return false;
}



bool MovementRules::canBishopMove()const {
    if (pm.signX() != 0 && pm.signY() != 0)
        return canMoveStraight();
    return false;
}
bool MovementRules::canRookMove() const {
    if (pm.signX() == 0 || pm.signY() == 0)
        return canMoveStraight();
    return false;

}
bool MovementRules::canPawnMove()const {
    if (pm.from.getY() < 1 || pm.from.getY() > 6)
        return false;
    int stepY = board.getColor(pm.piece) == Color::WHITE ? 1 : -1;

    return canPawnGo(stepY) || canPawnJump(stepY) || canPawnEat(stepY);
}

bool MovementRules::canPawnGo(int stepY) const {
    if ((board.getPieceAt(pm.to) == Piece::none) &&
        pm.dx() == 0 &&
        (pm.dy() == stepY))
        return true;
    return false;
}


bool MovementRules::canPawnJump(int stepY) const {
    if (board.getPieceAt(pm.to) == Piece::none && (pm.dx() == 0) && (pm.dy() == 2 * stepY) &&
        (pm.from.getY() == 1 || pm.from.getY() == 6) &&
        (board.getPieceAt(Square(pm.from.getX(),pm.from.getY() + stepY)) == Piece::none))
        return true;
    return false;
}

bool MovementRules::canPawnEat(int stepY) const {
    if (board.getPieceAt(pm.to) != Piece::none &&
        pm.absDx() == 1 && pm.dy() == stepY)
        return true;
    return false;

}
