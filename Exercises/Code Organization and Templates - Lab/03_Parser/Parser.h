//
// Created by twister on 7/18/24.
//

#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <utility>

template<typename T>
class Parser{

private:
    std::istream& m_IN;
    std::string m_stopLine;

public:
    Parser(std::istream&, std::string );
    bool readNext(T);
    template <class Y, class E>
    friend bool operator!=(const Parser<Y>&, const E&);
};


template <class T>
Parser<T>::Parser(std::istream& IN, std::string stopWord) : m_IN(IN), m_stopLine(std::move(stopWord)) {}

template <class X>
bool Parser<X>::readNext(X sample){
    m_IN >> sample;
    return sample != m_stopLine;
}

template <class R, class F>
bool operator != (const Parser<R>& left, const F& right){
    return left.m_stopLine != right.str();
}




#endif //PARSER_H
