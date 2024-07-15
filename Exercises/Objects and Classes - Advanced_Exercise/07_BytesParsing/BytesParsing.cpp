//
// Created by twister on 7/14/24.
//
#include "BytesParsing.h"

#include <pstl/execution_defs.h>


void printVector(const std::vector<long long>& vec){
    for(const auto& it : vec)
        std::cout << it << " ";
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
        long long number{};
        for(j = k; j < rawDataBytesCount; j++){
            for(int f = 0; f < iterations; f++, k++){
                if(k > rawDataBytesCount) return PARSE_FAILURE;
                number += rawDataBytes[k];
            }
            break;
        }
        outParsedNumbers.push_back(number);

        //from front to back ss, 2002 -> 200 (16) -> 512, 2(16) -> 2 [push front]
        //outParsedNumbers.insert(outParsedNumbers.begin(), number); // "push front"
    }

    return PARSE_SUCCESS;
}

extern void printResult (const ErrorCode errorCode, const std::vector<long long>& parsedNumbers) {
    switch(errorCode){
    case PARSE_EMPTY: // don't print vector at all
            std::cout << "No input provided" << std::endl;
            break;
        case PARSE_SUCCESS:
            printVector(parsedNumbers);
        std::cout << std::endl;
            break;
    case PARSE_FAILURE:
        printVector(parsedNumbers);
        std::cout << "Warning, buffer underflow detected" << std::endl;
            break;
        default:
            break;
    }


}
