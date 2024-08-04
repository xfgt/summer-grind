//
// Created by twister on 8/3/24.
//


#include <iostream>
#include "BigInt.h"



int main(){


    std::string a;
    std::string b;
    std::cin >> a >> b;

    BigInt bOne(a);
    BigInt bTwo(b);

    int start, end{};

    try {

        std::stoi(bOne.getDigits()); // check
        std::stoi(bTwo.getDigits()); // check

        start = std::stoi(bOne.getDigits());
        end = std::stoi(bTwo.getDigits());

        if(start > 101 || end > 101)
            throw std::out_of_range("");

        if(end < start){
            throw std::runtime_error("");
        }

        for(int i = start; i < end; i++){
            if(i % 45 == 0){
                std::cout << i << std::endl;
            }
        }

    } catch (std::out_of_range&) {
        start = std::stoi(a.substr(a.size()-2));
        end = std::stoi(b.substr(b.size()-2));

        if(end < start){
            if(end == 0)
                end = 100;
            else
                throw std::runtime_error("");
        }

        for(int i = start; i < end; i++){
            if(i % 45 == 0){
                std::cout << bOne.getDigits().replace(bOne.getDigits().size()-2, 3, std::to_string(i)) << std::endl;
            }
        }

    }



    return 0;

}