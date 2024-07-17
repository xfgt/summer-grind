//
// Created by twister on 7/17/24.
//

#ifndef PRINTUTILS_H
#define PRINTUTILS_H
#include <iostream>
#include <vector>

template <typename R>
void printVector(const std::vector<R>& v);

template <typename R>
void printVector(const std::vector<R>& v){
    for(const auto& it : v){
        std::cout << it << ' ';
    }
}

#endif //PRINTUTILS_H
