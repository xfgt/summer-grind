//
// Created by twister on 7/17/24.
//

#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <typeinfo>

extern class Song testSongObj;


template <typename X>
class Parser{

    X m_stopLine; // int, string, obj

public:
    Parser(std::istream& IN, std::string stopLine){
        IN >> stopLine;



        std::string msg("");
        const std::type_info& xType = typeid(m_stopLine);

        if(xType.name() == typeid(int).name()){
            msg = "int!";
        } else if(xType.name() == typeid(std::string).name()){
            msg = "std::string!";
        } else if(xType.name() == typeid(testSongObj).name()){
            msg = "USER-DEFINED OBJECT, IT WORKS, BRO!";
        } else{
            return;
        }

        std::cout << msg << std::endl;


    }


    bool readNext(X& tmp){

        // i -> ?
        // w -> ?

        // obj -> ?!



        return false;
    }

    void setStopLine(X tmp){
        // i -> ?
        // w -> ?

        // obj -> ?!

    }



    X getStopLine() const{
        return m_stopLine;
    }
};






#endif //PARSER_H
