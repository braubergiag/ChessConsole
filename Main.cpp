
#include <iostream>
#include <string>
#include "ChessCore.h"
#include "ConsoleColors.h"
using namespace std;


int main()
{

    ChessCore  chess;
    std::string move = "";

    
    while (move != "q") {
        if (move != "w")  chess.printChessView();
        cin >> move;
        if (move == "w") {
            if (chess.writeToFile() == 0) std::cout << "Succesful.\n";
            continue;
        }
        if (move != "q")
            chess = chess.move(move);
    }

    return 0;
}



