//
// Created by twister on 7/28/24.
//

#ifndef ORDEREDINSERTER_H
#define ORDEREDINSERTER_H


#include "Company.h"

#include <vector>

struct OrderedInserter{

    std::vector<const Company*> m_companies;

    explicit OrderedInserter(std::vector<const Company*>& xv) : m_companies(xv) {}

    operator Company*()(Company* x) const {
        //?
    }

    void insert(Company* sample){

    }
};


#endif //ORDEREDINSERTER_H
