//
// Created by User on 002-2.7.2024 г..
//


/*
 * place;                                                                               string
 * coordinates (latitude <horizontal lines> [_x], longitude <vertical lines> [_y]);     float
 *
 *
 *  No two locations have the same name!            (_x1, _y1 -> name1; _x2, _y2 -> name2; name1 != name2)
 *  Some locations may have the same coordinates!   (nameN -> _x1 || _x2 && _y1 || _y2)
 *
 *
 *  INPUT: [name,latitude,longitude]
 *  the output has to be the same format in the same order
 *
 */


#include <iostream>
#include <utility>
#include <sstream>

class Location{

private:
    std::string m_place{};
    float _m_latitude;
    float _m_longitude;

public:
    // explicit for constructor call with one argument
    explicit Location(std::string p ="", float x =0.0f, float y =0.0f) : m_place(std::move(p)), _m_latitude(x), _m_longitude(y) {}

};


int main(){

    std::string place{};
    float x{};
    float y{};
    char symbol{};
    Location* loc = nullptr;

    while(symbol != '.'){
        // read input
        // maybe use stringstream

        // class init
        loc = new Location(place, x, y);

        // delete obj
        delete[] loc;

        // read char
        std::cin >> symbol;
        std::cin.clear();
    }






    return 0;
}