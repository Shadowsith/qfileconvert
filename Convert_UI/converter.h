#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>


class Converter {

public:
    static int convertImg(std::string input, std::string output);
    static int convertVid(std::string input, std::string output);

};

#endif // CONVERTER_H
