//
// Created by twister on 7/21/24.
//

#ifndef PRINTUTILS_H
#define PRINTUTILS_H

#include <iostream>
#include <iterator>

//T<X, [L<T,R<T>>] >
template <typename C, typename X>
void printContainer(const X& beg, const X& end){
    for(typename C::const_iterator it = beg; it != end; ++it){
        std::cout << *it << std::endl;
    }
}
//    for(typename C::const_iterator it=data.begin();it!= data.end();++it){
















#endif //PRINTUTILS_H
