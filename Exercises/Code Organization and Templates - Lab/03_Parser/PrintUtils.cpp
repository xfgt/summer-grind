//
// Created by twister on 7/17/24.
//


#include "PrintUtils.h"

template <typename R>
void printVector(const std::vector<R>& v){
    for(const auto& it : v){
        std::cout << *it << ' ';
    }
}