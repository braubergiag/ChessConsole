#include <string.h>
#include <string>

#ifndef CHESSN_FENPARSING_H
#define CHESSN_FENPARSING_H


// ¬спомогательные методы дл€ парсинга FEN
std::string replaceSubstr(std::string temp, std::string old_substr, std::string new_substr);
size_t splitStr(std::string str, std::string delimeter, std::string* result, size_t num_of_splits);


#endif //CHESSN_FENPARSING_H
