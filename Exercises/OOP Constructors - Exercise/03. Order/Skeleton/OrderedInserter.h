//
// Created by twister on 7/28/24.
//

#ifndef ORDEREDINSERTER_H
#define ORDEREDINSERTER_H


#include "Company.h"
#include <vector>


struct OrderedInserter{

    const Company* current;
    std::vector<const Company*>::iterator it;
    std::vector<const Company*>& m_inputVector;

    explicit OrderedInserter(std::vector<const Company*>& xv) :
    m_inputVector(xv),
    current(nullptr) {}

    void insert(const Company* x){
        if(current == nullptr){
            m_inputVector.push_back(x);
            it = m_inputVector.begin();
        }
        else m_inputVector.insert(it++, x);


        current = x;

    }

    bool operator<(const Company* sample) const {
        return sample->getId() < current->getId();
    }


};




#endif //ORDEREDINSERTER_H
