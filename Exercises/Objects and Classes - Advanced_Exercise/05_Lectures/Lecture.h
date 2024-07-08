//
// Created by User on Нд-7.7.2024 г..
//

#ifndef LECTURE_H
#define LECTURE_H

#include <iostream>
#include <set>
#include <vector>
#include "ResourceType.h"


namespace SoftUni{


    class Lecture {
        std::set<Resource>::iterator itB;
        std::set<Resource>::iterator itE;
    public:
        std::set<Resource> myLectures;

        Lecture(){
            itB = myLectures.begin();
            itE = myLectures.end();
        }

        std::set<Resource>::iterator begin() { return itB; }
        std::set<Resource>::iterator end() { return itE; }

        void reset(){
            itB = myLectures.begin();
            itE = myLectures.end();
        }

//      41
        int operator[](ResourceType index){
            for(auto& i : myLectures){

                if(index == i.getType()){
                    return i.getType();
                }
            }
            return Lecture::begin()->getType();
        }

    };

//  insert object to set comparison
    bool operator<(const Resource& left, const Resource& right){
        return left.getId() < right.getId();
    }

//  27
    Lecture& operator<<(Lecture& lobj, const Resource& robj){
    lobj.myLectures.insert(robj);
    lobj.reset();

    return lobj;
}

//  38
std::vector<ResourceType>& operator<<(std::vector<ResourceType>&v, const Lecture& lobj){
    v.push_back(lobj.myLectures.end()->getType()); // begin?
    return v;
}





}









#endif //SOLUTION_SOFTUNICPP_OOP_LECTURE_H



