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
    Parser(std::istream& IN, std::string stopLine){
        IN >> stopLine;
        //TODO: parse std::string to X?
        setStopLine(std::move(stopLine));
    }
    bool readNext(X& tmp){
        //TODO: operator!= overload for us-def objects, ints, strings
        return tmp != getStopLine();
    }


    void setStopLine(X& tmp) { m_stopLine = std::move(tmp); }
    X getStopLine() const { return m_stopLine; }
};


#endif //PARSER_H
