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
    T cinObj;

public:
    Parser(std::istream&, std::string );
    bool readNext(T);
    friend bool operator !=(const Parser<T>&, const Parser<T>&);

};



template<typename T>
bool operator!= (const Parser<T>& left, const Parser<T>& right){
    return left.cinObj != right.cinObj;
}


template <class T>
Parser<T>::Parser(std::istream& IN, std::string stopWord) : m_IN(IN), m_stopLine(std::move(stopWord)){ m_IN >> cinObj; }


template <class X>
bool Parser<X>::readNext(X n){
    m_IN >> n;

    // compare object to cinObj and m_stopLine

    return false;

}



#endif //PARSER_H
