//
// Created by twister on 7/19/24.
//

#ifndef JOIN_H
#define JOIN_H
// returns a std::string
#include <iostream>
#include <sstream>
#include <vector>
template<typename T>
std::string join(const std::vector<T>& v, const std::string& theNewSep){
    std::string result{};
    std::string sample{};
    std::ostringstream os(sample);

    for(auto it = v.begin(); it != v.end(); ++it){
        T type = *it;
        os << type;

        std::istringstream s(os.str()); // result += os.str();
        s  >> result;
        os << theNewSep;

    }









    return result;
}

#endif //JOIN_H
