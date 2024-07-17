//
// Created by twister on 7/17/24.
//
#include "Parser.h"

template <typename X>
Parser<X>::Parser(std::istream& IN, std::string stopLine){
    IN >> stopLine;
    //TODO: parse std::string to X?
    setStopLine(std::move(stopLine));
}

template <typename X>
bool Parser<X>::readNext(X& tmp){
    //TODO: operator!= overload for us-def objects, ints, strings
    return tmp != getStopLine();
}

template <typename X>
void Parser<X>::setStopLine(X tmp) { m_stopLine = std::move(tmp); }

template <typename X>
X Parser<X>::getStopLine() const{ return m_stopLine; }

