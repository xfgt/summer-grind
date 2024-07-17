//
// Created by twister on 7/17/24.
//

#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <vector>
template <typename X>
class Parser{
private:
    X m_stopLine;

public:
    Parser(std::istream&, std::string);
    bool readNext(X&);
    void setStopLine(X);
    X getStopLine() const;
};

#endif //PARSER_H
