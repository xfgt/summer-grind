//
// Created by twister on 9/6/24.
//

#include <iostream>
#include <sstream>
#include <vector>


int main(){
    std::vector<int> a, b, merged;

    std::string input{};
    std::getline(std::cin, input);
    std::stringstream ss(input);
    std::string hold{};

    while(ss >> hold){
        a.push_back(std::stoi(hold));
    }

    std::getline(std::cin, input);
    std::stringstream ssl(input);
    while(ssl >> hold){
        b.push_back(std::stoi(hold));
    }



    std::vector<int>& larger = a;
    std::vector<int>& smaller = b;

    if(a.size() < b.size()){
        larger = b;
        smaller = a;
    }


    for(int i = 0; i < larger.size(); i++){
       if(i > smaller.size())
           merged.push_back(larger.at(i));

        merged.insert(larger.begin()+i, smaller.at(i));
    }


    for(const auto& it : merged)
        std::cout << it << ' ';



    return 0;
}