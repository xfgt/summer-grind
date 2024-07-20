//
// Created by twister on 7/19/24.
//

#ifndef JOIN_H
#define JOIN_H
// returns a std::string
#include <iostream>
#include <sstream>
#include <variant>
#include <vector>
#include <pstl/execution_defs.h>

template<typename T>
std::string join(const std::vector<T>& v, const std::string& theNewSep){
    std::string result{};
    std::string sample{};
    std::ostringstream os(sample);

    for(auto it = v.begin(); it != v.end(); ++it){
        T type = *it;

        os << type;
        if(it < v.end()-1)
            os << theNewSep;

    }

    return os.str();
}

#endif //JOIN_H
