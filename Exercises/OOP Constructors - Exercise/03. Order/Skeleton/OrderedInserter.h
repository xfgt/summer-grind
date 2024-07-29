//
// Created by twister on 7/28/24.
//

#ifndef ORDEREDINSERTER_H
#define ORDEREDINSERTER_H


#include <algorithm>

#include "Company.h"
#include <vector>


struct OrderedInserter{

    const Company* current;
    std::vector<const Company*>& m_inputVector;
    std::vector<const Company*>::iterator it;


    explicit OrderedInserter(std::vector<const Company*>& xv) :
    m_inputVector(xv),
    current(nullptr),
    it(nullptr){}

    void insert(const Company* x){

        if(current == nullptr){
            m_inputVector.push_back(x);
            it = m_inputVector.begin();
            current = x;
            return;
        }

        if(x->getId() < current->getId()){
            m_inputVector.insert(m_inputVector.begin(), x);
        } else{
            if(it-1 < m_inputVector.begin()){
                m_inputVector.push_back(x);
            } else { // mid insert

                m_inputVector.insert(current position iterator + 1, x);



            }

        }
        it = m_inputVector.end()-1; /// !
        current = x;
    }



};




#endif //ORDEREDINSERTER_H
