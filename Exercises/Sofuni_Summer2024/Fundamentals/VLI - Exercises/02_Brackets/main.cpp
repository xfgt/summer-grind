//
// Created by twister on 9/7/24.
//

#include <iostream>
#include <sstream>




bool sol(const std::string& input){

    int squares{}, curly{}, normals{}, type{}, lastType{};

    for(int i = 0; i < input.size(); i++){

        switch (input[i]){
        case '{':
        case '}':
            type = 1;
            break;

        case '[':
        case ']':
            type = 2;
            break;

        case '(':
        case ')':
            type = 3;
            break;
        default:
            break;
        } // get type

        switch (type){
        case 1: // {} expects 1, 2, 3
            curly++;
            break;

        case 2: //[] 2, 3
            squares++;
            break;

        case 3: //() only 3
            normals++;
            break;

        default:
            break;
        }


        if(lastType <= type){

        }





        lastType = type;
    }

}

int main(){



    // Hierarchy
    // {} 1
    // [] 2
    // () 3

    std::string input{};
    std::getline(std::cin, input);

    if(sol(input)){
        std::cout << "valid";
    } else{
        std::cout << "invalid";
    }

    return 0;
}