//
// Created by marshall on 22.10.2020.
//

#include "ChessCore.h"

ChessCore ChessCore::move(std::string move){
    PieceMovement  pm = PieceMovement(move);
    if (!moves.canMove(pm)){
        moveIsCorrect = false;
        return *this;
    }

    Board  nextBoard = board.move(pm);
    ChessCore  newChessEngine = ChessCore(nextBoard);
    return newChessEngine;
}
char ChessCore::getPieceAt(int x, int y) const{
    Square square = Square(x,y);
    Piece piece = board.getPieceAt(square);
    return piece == Piece::none ? '.' : (char ) piece;

}
int ChessCore::writeToFile() {
    unsigned int moveNumber = this->board.getMoveNumber();
    std::string color = (board.getMoveColor() == 0) ? " White " : " Black ";
    std::ofstream wFile(std::to_string(moveNumber) + color + " Board.txt");
    if (!wFile){
        std::cout << "Can't open the file/\n";
        return 1;
    }

    wFile << "Move: #" << std::to_string(moveNumber) << color << "FEN: " << this->board.getFen() << "\n";
    wFile << this->generateChessBoardView();
    wFile.close();
    return 0;


}
std::string ChessCore::generateChessBoardView() const {


    std::string boardView = "  +--------------------------+\n";
    for (int y = 7; y >= 0; --y)
    {
        boardView += std::to_string(y + 1);
        boardView += " |  ";


        for (int x = 0; x < 8; ++x) {
            boardView += static_cast<char>(this->getPieceAt(x, y));
            boardView += "  ";
        }


        boardView += "|\n";
    }

    boardView += "  +--------------------------+\n";
    boardView += "     a  b  c  d  e  f  g  h\n\n";
   

    return boardView;
}
void ChessCore::printChessView() const {
    std::string boardView = this->generateChessBoardView();
    std::string inputView = this->generateChessInputView();
    for (int i = 0; i < boardView.size(); ++i) {
        if (boardView[i] >= 'a' && boardView[i] <= 'z') {
            setColor(ConsoleColors::LightRed);
            std::cout << boardView[i];
        }
        else if (boardView[i] >= 'A' && boardView[i] <= 'Z') {
            setColor(ConsoleColors::Cyan);
            std::cout << boardView[i];
        }
        else {
            setColor(ConsoleColors::White);
            std::cout << boardView[i];
        }
     }
    setColor(ConsoleColors::White);
    std::cout << inputView;
}
std::string ChessCore::generateChessInputView() const {
    std::string inputView;
        if (board.getMoveNumber() == 1 && board.getMoveColor() == Color::WHITE) {
            inputView += "Welcome! Type 'w' if want to write board positions  to the file.";
            inputView += "Type 'q' to quit.\n";
        }

        inputView += Board::getMoveColor() == Color::WHITE ? "# " + std::to_string(board.getMoveNumber()) + "." +
            " Player 1 (White) turns:" : "Player 2 (Black) turns:";

        if (!(moveIsCorrect)) inputView += "You typed move incorrectly: Example Pa2a4. Try Again. ";

        return inputView;
};