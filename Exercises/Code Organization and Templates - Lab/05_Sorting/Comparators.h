//
// Created by twister on 7/21/24.
//

#ifndef COMPARATORS_H
#define COMPARATORS_H

#include <iostream>
#include <cstring>
#include <string>
#include <sstream>



// TODO: Прочети ме (компаратори)
// възползвай се от >> И  << операторите,
// както и от std::stringstream,
// и предефинирането на bool operator< за std::strcmp(str1.c_str(), str2.c_str()) < 0



/*
    bool operator()(const Point& lhs, const Point& rhs) const {
        return (comparison);
    }
*/




template<typename T>
struct LessThan {
    bool operator()(const T& a, const T& b){

        std::stringstream ss;
        std::string x, y{};

        ss << a;
        x = ss.str();

        ss.str("");
        ss.clear();

        ss << b;
        y = ss.str();

        return (std::strcmp(x.c_str(), y.c_str()) < 0);

    }
};




template <typename T, class LT = LessThan<T>>
struct Reverse{

    // !(expression form LT)


};











#endif //COMPARATORS_H