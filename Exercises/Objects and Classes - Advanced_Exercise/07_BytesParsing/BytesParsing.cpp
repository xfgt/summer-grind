//
// Created by twister on 7/14/24.
//
#include "BytesParsing.h"

#include <cmath>
#include <string>


void printVector(const std::vector<long long>& vec){
    for(const auto& it : vec)
        std::cout << it << " ";
}

int hexIntShort(const std::string& str){
    int decimal{};
    int result{};
    char digit{};
    for(int i = 0, j = str.size(); i < str.size(); i++, j--){
        digit = str[i];
        if(digit == '0'){
            j--;
            continue;
        }
        decimal = std::stoi(&digit);
        result += decimal * pow(16, j);

    }
    return result;
}

int hexIntInt(const std::string& str){
    //TODO
}

extern ErrorCode parseData (const std::string& commands,
                            const char* rawDataBytes,
                            const size_t rawDataBytesCount,
                            std::vector<long long>& outParsedNumbers)

{


    if(rawDataBytesCount == 0 || commands.empty())
        return PARSE_EMPTY;

// rawData -> char - 30;

    int j{};
    int k{};
    for(int i = 0; i < commands.size(); i++){
        int iterations{};
        switch (commands[i]){
            case 's':   // short -> 16 bits (2*8)   [base 16]
                iterations = 2;
                break;
            case 'i':   // int -> 32 bits (4*8)
                iterations = 4;
                break;
            case 'l':   // long -> 64 bits (8*8)
                iterations = 8;
                break;

            default:
                break;  // TODO: Return error if bad sequence occurs;
                        // TODO: Keep in mind that the command buffer may contain commands, which you have no data for in your data buffer.
                        // TODO: When you reach such case -> simply ignore the rest of the commands from the command buffer.
        }

        if(iterations == 0) return PARSE_FAILURE;


        //convertion and "upload"
        std::string number("");
        for(j = k; j < rawDataBytesCount; j++){
            for(int f = 0; f < iterations; f++, k++){
                if(k > rawDataBytesCount) return PARSE_FAILURE;
                if(rawDataBytesCount >= '\000' && rawDataBytesCount <= '\011') // 0 - 9
                    number += rawDataBytes[k]+'0';
            }
            switch (commands[i]){
            case 's':   // short -> 16 bits (2*8)   [base 16]
                outParsedNumbers.insert(outParsedNumbers.begin(), hexIntShort(number)); // "push_front"
                break;
            case 'i':   // int -> 32 bits (4*8)
                outParsedNumbers.insert(outParsedNumbers.begin(), hexIntInt(number));
                break;
            case 'l':   // long -> 64 bits (8*8)

                break;

            default:
                break;
            }

            break; // loop break
        }



    }

    return PARSE_SUCCESS;
}

extern void printResult (const ErrorCode errorCode, const std::vector<long long>& parsedNumbers) {
    switch(errorCode){
    case PARSE_EMPTY:
            std::cout << "No input provided";
            break;
        case PARSE_SUCCESS:
            printVector(parsedNumbers);
            break;
    case PARSE_FAILURE:
        printVector(parsedNumbers);
        std::cout << "Warning, buffer underflow detected";
            break;
        default:
            break;
    }


}
