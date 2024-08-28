//
// Created by twister on 8/27/24.
//


#include <cmath>
#include <iostream>

std::string getDigitName(char x ='0'){
    switch (x){
    case '0': return "zero ";
    case '1': return "one ";
    case '2': return "two ";
    case '3': return "three ";
    case '4': return "four ";
    case '5': return "five ";
    case '6': return "six ";
    case '7': return "seven ";
    case '8': return "eight ";
    case '9': return "nine ";
        default:
            return "";
    }
}


std::string processNumber(std::string x, size_t sz){
    if(sz > 4)
        return "";

    bool hasDec = false;
    std::string output{};
    int type{};

    for (int i = 0; i < sz; i++){

        type = std::pow(10,sz-i-1);
        switch (type){
        case 1000:
            output += getDigitName(x[i]) + "thousand ";
            break;
        case 100:
            if(x[i] != '0')
                output += getDigitName(x[i]) + "hundred ";
            break;



        case 10:
            hasDec = true;
            switch (x[i]){
            case '1':
                switch (x[i+1]){ // teen
                case '0':
                    output += "ten";
                        break;
                case '1':
                    output += "eleven";
                        break;
                case '2':
                    output += "twelve";
                        break;
                case '3':
                    output += "thirteen";
                        break;
                case '5':
                    output += "fifteen";
                        break;
                case '8':
                    output += "eighteen";
                    break;

                case '4':
                case '6':
                case '7':
                case '9':
                    output += getDigitName(x[i+1]) + "teen";
                        break;
                default:
                    break;

                }
                break;
        case '2':
            output += "twenty";
                break;
        case '3':
            output += "thirty";
                break;
        case '5':
            output += "fifty";
                break;

        case '4':
        case '6':
        case '7':
        case '8':
        case '9':
            output += getDigitName(x[i]) + "ty";
                break;
        default:
            break;
            }

            break;





        case 1:
            if(hasDec && x[i-1] != 0){
                output += getDigitName(x[i]);
                hasDec = false; //todo
            } else if(!hasDec){
                output += getDigitName(x[i]);
            }


            break;

        default:
            break;
        }

    }

    return output;
}

int main(){

    std::string number{};
    while(true){
        std::getline(std::cin, number);
        std::cout << processNumber(number, number.size()) << std::endl;
    }


    return 0;
}