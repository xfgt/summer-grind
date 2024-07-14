//
// Created by twister on 7/14/24.
//
#include "BytesParsing.h"

#include <cmath>

long long convert(long long n){
    long long dec = 0, i = 0, rem;

    while (n!=0) {
        rem = n % 10;
        n /= 10;
        dec += rem * std::pow(2, i);
        ++i;
    }
    return dec;
}

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
            case 's':
                iterations = 2;
                break;
            case 'i':
                iterations = 4;
                break;
            case 'l':
                iterations = 8;
                break;
            default:
                break;
        }

        if(iterations == 0) continue;



        long long number{};
        for(j = k; j < rawDataBytesCount; j++){
            for(int f = 0; f < iterations; f++, k++){
                number += rawDataBytes[k];
            }
            break;
        }
        outParsedNumbers.push_back(number);




    }



}

extern void printResult (const ErrorCode errorCode, const std::vector<long long>& parsedNumbers) {




}
