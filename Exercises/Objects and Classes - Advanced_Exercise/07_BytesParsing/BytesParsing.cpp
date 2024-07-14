//
// Created by twister on 7/14/24.
//
#include "BytesParsing.h"


extern ErrorCode parseData (const std::string& commands,
                            const char* rawDataBytes,
                            const size_t rawDataBytesCount,
                            std::vector<long long>& outParsedNumbers)

{

// rawData -> char - 30;

/* cheta bukvata ot stringa
 * s neq postavqm granica:
 * s -> short = 2
 * i -> int = 4
 * l -> longlong 8
 *
 */
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
                break;
        }

        if(iterations == 0) continue;


        //from front to back ss, 2002 -> 200 (16) -> 512, 2(16) -> 2 [push front]
        long long number{};
        for(j = k; j < rawDataBytesCount; j++){
            for(int f = 0; f < iterations; f++, k++){
                number += rawDataBytes[k];
            }
            break;
        }
        outParsedNumbers.push_back(number);
        outParsedNumbers.insert(outParsedNumbers.begin(), number); // "push front"




    }



}

extern void printResult (const ErrorCode errorCode, const std::vector<long long>& parsedNumbers) {




}
