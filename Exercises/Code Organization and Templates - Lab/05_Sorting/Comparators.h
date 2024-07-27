//
// Created by twister on 7/21/24.
//

#ifndef COMPARATORS_H
#define COMPARATORS_H

#include <iostream>
#include <cstring>
#include <string>
#include <sstream>



template<typename T> // functor (old lambda)
struct LessThan {
    bool operator()(const T& a, const T& b) const {

        // std::stringstream ss;
        // std::string x, y{};
        //
        // ss << a;
        // x = ss.str();
        //
        // ss.str("");
        // ss.clear();
        //
        // ss << b;
        // y = ss.str();
        //
        // return (std::strcmp(x.c_str(), y.c_str()) < 0);
        return a < b;

    }
};


template <typename T, class LT>
struct Reverse{
    bool operator()(const T& left, const T& right) const {
        LT lt;
        return !lt(left, right);
    }
};











#endif //COMPARATORS_H
