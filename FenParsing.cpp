//
// Created by marshall on 26.10.2020.
//

#include "FenParsing.h"
std::string replaceSubstr(std::string str,std::string old_substr,std::string new_substr){
    std::string temp = str;
    size_t index = 0;
    while (true){
        index = temp.find(old_substr,index);
        if (index == std::string::npos) return temp;

        temp.replace(index,1,new_substr);

        index += new_substr.length();

    }
}
size_t splitStr(std::string str,std::string delimeter,std::string * result,size_t num_of_splits){

    std::string *  partsParsed = new std::string[num_of_splits];
    std::string fen_part;
    size_t pos= 0, countParts = 0;

    for (size_t i = 0;(pos = str.find(delimeter)) != std::string::npos; ++i){
        fen_part = str.substr(0,pos);
        partsParsed[i] = fen_part;
        str.erase(0,pos + delimeter.length());
        result[i] = partsParsed[i];
        countParts++;
    }
    delete[] partsParsed;
    return countParts;

}