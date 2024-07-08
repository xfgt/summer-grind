//
// Created by User on Нд-7.7.2024 г..
//

#ifndef LECTURE_H
#define LECTURE_H

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include "ResourceType.h"

static int f = 0;

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
            if(myLectures.empty()){
                itB = myLectures.begin();
                itE = myLectures.end();
                --itE;
            } else {
                itB = myLectures.begin();
            }

        }

//      41
        int operator[](ResourceType index){
            int x{};
            for(auto& i : myLectures){
                if(index == i.getType()){
                    x++;
                }
            }
            return x;
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
std::vector<ResourceType>& operator<<(std::vector<ResourceType>&v, Lecture& lobj){
    if(v.empty())
        v.push_back(lobj.myLectures.begin()->getType());


    bool dup = false;
    for(auto w : lobj.myLectures){
        for(auto& vit : v)
            if(w.getType() == vit)
                dup = true;
        if(!dup)
            v.push_back(w.getType());
        dup = false;

    }




        std::sort(v.begin(), v.end());

    return v;
}





}









#endif //SOLUTION_SOFTUNICPP_OOP_LECTURE_H



