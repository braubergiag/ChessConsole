//
// Created by marshall on 18.10.2020.
//

#ifndef CHESSNG_CHESSCORE_H
#define CHESSNG_CHESSCORE_H
#include <string>
#include <fstream>
#include <iostream>
#include <string.h>
#include "PieceOnSquare.h"
#include "PieceMovement.h"
#include "MovementRules.h"
#include "Piece.h"
#include "Square.h"
#include "Board.h"
#include "ConsoleColors.h"

const unsigned int MAX_FNAME_SIZE = 100;
class ChessCore {
private:
    Board board;
    MovementRules moves;
    ChessCore(Board& board):board(board), fen(board.getFen()),moves(board){}
    bool moveIsCorrect = true;
    std:: string fen;
public:

    ChessCore(std::string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR/ w KQkq - 0 1 ")
        :fen(fen),board(fen),moves(board){}
    
    ChessCore  move(std::string move);
    char getPieceAt(int x, int y) const;
    void findAllMoves();
    std::string generateChessBoardView() const;
    std::string generateChessInputView() const;
    void printChessView() const;
    int writeToFile();

    ~ChessCore(){}

};


#endif //CHESSNG_CHESSENGINE_H
