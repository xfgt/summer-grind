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

    try{

        std::stoi(bOne.getDigits()); // check
        std::stoi(bTwo.getDigits()); // check

        // {
        //     bOne = bOne.getDigits().replace(0, 1, "0");
        //     bTwo = bTwo.getDigits().replace(0, 1, "0");
        // }

        start = std::stoi(bOne.getDigits());
        end = std::stoi(bTwo.getDigits());


        for(int i = start; i < end;  i++){
            if(i % 45 == 0){
                std::cout << i << std::endl;
            }
        }
    }
    catch (...){
        start = std::stoi(a.substr(a.size()-2));
        end = std::stoi(b.substr(b.size()-3));

        for(int i = start; i < end; i++){
            if(i % 45 == 0){
                std::cout << bOne.getDigits().replace(bOne.getDigits().size()-2, 3, std::to_string(i)) << std::endl;
            }
        }
    }





    return 0;
}