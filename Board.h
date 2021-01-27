//
// Created by marshall on 18.10.2020.
//

#ifndef CHESSNG_BOARD_H
#define CHESSNG_BOARD_H
#include <string>
#include <stdlib.h>
#include <string.h>

#include "PieceMovement.h"
#include "Piece.h"
#include "Square.h"
#include "fenParsing.h"
#include "PieceOnSquare.h"
#include "Square.h"

const size_t ROWS = 8;
const size_t COLS = 8;
const size_t FEN_PARTS_SIZE = 6;
const std::string FEN_PARTS_DELIM = " ";
const std::string FEN_ROWS_DELIM = "/";
enum Color { WHITE,BLACK,NONE};

class Board {
    Piece pieces[ROWS][COLS];
    std:: string fen;
    unsigned int moveNumber;
    static Color moveColor;
public:
    Board(std::string fen);
    Board();
    ~Board();
    Board  move(PieceMovement& pm);
    void setPieceAt(Square& square,Piece piece);
    Piece getPieceAt(Square square) const;
    int getMoveNumber() const;
    void InitBoard();
    void InitPieces(std::string& data);
    void updateFen();
    const std::string &getFen() const;
    void setFen(const std::string &fen);
    std::string generatePiecesFen() const;
    static Color changeColor(Color color);
    static Color getColor(Piece piece);
    static Color getMoveColor();
    static void setMoveColor(Color moveColor);
};


#endif //CHESSNG_BOARD_H
