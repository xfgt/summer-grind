//
// Created by twister on 8/16/24.
//

#ifndef REMOVEINVALID_H
#define REMOVEINVALID_H


inline void removeInvalid(std::list<Company*>& xl){
    auto next = xl.begin();

    for(auto& it : xl){
        ++next;
        if(it == nullptr){
            xl.remove(it);
            break;
        }

        if(it->getId() < 0){
            auto x = std::next(next, 0);
            *it = **x;

            delete *x;
            *x = nullptr;

            while(++next != xl.end()){
                if((*next)->getId() >= 0){

                        *x++ = new Company(**next);


                    delete *next;
                    *next = nullptr;

                } else {
                    delete *next;
                    *next = nullptr;
                }
            }


        }

    }




}

#endif //REMOVEINVALID_H
