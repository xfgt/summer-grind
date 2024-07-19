//
// Created by twister on 7/18/24.
//

#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <sstream>


template<typename T>
class Parser{

private:
    std::istream& m_IN;
    std::string m_stopLine;



public:
    Parser(std::istream&, std::string );
    bool readNext(T&);

};

template <class T>
Parser<T>::Parser(std::istream& IN, std::string stopWord) : m_IN(IN), m_stopLine(std::move(stopWord)){}


template <class T>
bool Parser<T>::readNext(T& n) {



    std::string wholeString{};
    std::string currentSong{};
    std::ostringstream oss;
    oss << n;

    wholeString = oss.str();

    std::istringstream sSong(wholeString);
    sSong >> currentSong;

    if( currentSong != m_stopLine ){

        m_IN >> n;
        return true;
    } else {

        return false;
    }











}

#endif //PARSER_H
