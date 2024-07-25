//
// Created by twister on 7/21/24.
//

#ifndef COMPARATORS_H
#define COMPARATORS_H

#include <iostream>
#include <cstring>
#include <string>
#include <sstream>







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

// < 0
// x > y


template <typename T, class LT = LessThan<T>>
struct Reverse{
    bool operator()(const T& left, const LT& right) const {
        return left > right;
    }
    // !(expression form LT)


};











#endif //COMPARATORS_H
