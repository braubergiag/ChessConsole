#include "ConsoleColors.h"

void setColor(ConsoleColors color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((ConsoleColors::Black << 4) | color));
}