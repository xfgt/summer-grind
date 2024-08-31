//
// Created by twister on 8/31/24.
//


#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>


bool check(const std::string& x, const size_t& sz) {
    if(sz < 3 || sz > 16)
        return false;

    size_t i = 0;
    while(i != sz){


        if (!(x[i] >= 'a' && x[i] <= 'z' || x[i] >= 'A' && x[i] <= 'Z')){
            return false;
        } else if (!(x[i] >= '0' && x[i] <= '9')){
            return false;
        } else if(!(x[i] == '-' || x[i] == '_')){
            return false;
        } else{
            return true;
        }

        i++;
    }
    return true;
}

int main(){

    std::string input{}, hold{};
    std::getline(std::cin, input);
    std::stringstream ss(input);


    while(std::getline(ss, hold, ',')){
        if(check(hold, hold.size())){
            hold.erase(std::remove_if(hold.begin(), hold.end(), ::isspace), hold.end());
            std::cout << hold << std::endl;
        }
    }

    return 0;
}