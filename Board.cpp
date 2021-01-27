//
// Created by marshall on 18.10.2020.
//

#include "Board.h"




Color Board::moveColor = Color::NONE;
Color Board::changeColor(Color color) {
    if (color == Color::WHITE) return Color::BLACK;
    if (color == Color::BLACK) return Color::WHITE;
    return Color::NONE;
}
Color Board::getColor(Piece piece) {
    if (piece == Piece::none)
        return Color::NONE;
    return (piece == Piece::whiteBishop ||
            piece == Piece::whiteKing ||
            piece == Piece::whiteKnight ||
            piece == Piece::whitePawn ||
            piece == Piece::whiteRook ||
            piece == Piece::whiteQueen)
            ? Color::WHITE
            : Color::BLACK;
}
Board::Board(std::string fen){
    this->fen = fen;
    for (size_t x = 0; x < COLS; ++x)
        for (size_t y = 0; y < ROWS; ++y)
            pieces[x][y] = Piece::none;
    InitBoard();
}
Board  Board::move(PieceMovement &pm){

    Board next = Board(fen);
    next.setPieceAt(pm.from, Piece::none);
    next.setPieceAt(pm.to,pm.piece);
    if (moveColor == Color::BLACK)
        next.moveNumber++;
    moveColor = changeColor(moveColor);
    next.updateFen();
    return next;

}
Board::~Board(){
}
void Board::setPieceAt(Square& square,Piece piece){
    if (square.onBoard())
        pieces[square.getX()][square.getY()] = piece;
}
Piece Board::getPieceAt(Square square) const{
    if (square.onBoard())
        return pieces[square.getX()][square.getY()];
    return Piece::none;
}
void Board::InitBoard(){
    std::string parts = fen;
    std::string partsParsed[FEN_PARTS_SIZE];
    size_t countParts = splitStr(parts,FEN_PARTS_DELIM,partsParsed,FEN_PARTS_SIZE);

    if (countParts != FEN_PARTS_SIZE) return;
    InitPieces(partsParsed[0]);
    moveColor = (partsParsed[1] == "b") ? Color::BLACK : Color::WHITE;
    moveNumber = stoi(partsParsed[5]);


}
void Board::InitPieces(std::string& data){
    for (int j = 8; j >= 2; --j)
        data = replaceSubstr(data,std::to_string(j),std::to_string(j-1) + "1");
    data = replaceSubstr(data,"1",".");
    std::string board_rows[ROWS];
    splitStr(data, FEN_ROWS_DELIM, board_rows, ROWS);
    char none = '.';
    for (int y = 7; y >= 0; --y)
        for (int x = 0; x < 8; x++)
            pieces[x][y] = board_rows[7 - y][x] == '.' ? Piece::none : (Piece) board_rows[7 - y][x];

}
void Board::updateFen(){
    fen = generatePiecesFen() + " " +
          ((moveColor == Color::WHITE) ? "w" : "b") +
          " - - 0 " + std::to_string(moveNumber) + " ";
}
std::string Board::generatePiecesFen() const{
    std::string fen_pieces;
    char none ='1';
    for (int y = 7; y >= 0; --y)
    {
        for (int x = 0; x < 8; ++x)
           fen_pieces.push_back(pieces[x][y] == Piece::none ? none :(char) pieces[x][y]);
        if (y >= 0)
            fen_pieces.push_back('/');
    }
    return fen_pieces;

}
int Board::getMoveNumber() const {
    return moveNumber;
}
const std::string &Board::getFen() const {
    return fen;
}
void Board::setFen(const std::string &fen) {
    Board::fen = fen;
}
Color Board::getMoveColor() {
    return moveColor;
}
void Board::setMoveColor(Color moveColor) {
    Board::moveColor = moveColor;
}


