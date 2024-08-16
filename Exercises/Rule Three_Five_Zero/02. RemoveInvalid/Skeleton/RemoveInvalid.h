//
// Created by twister on 8/16/24.
//

#ifndef REMOVEINVALID_H
#define REMOVEINVALID_H


inline void removeInvalid(std::list<Company*>& xv){
    for(auto& it : xv){
        if(it->getId() < 0){
            delete it;
            // move all pointers one-by-one by position
            auto& pos = it;



        }
    }
}


#endif //REMOVEINVALID_H
