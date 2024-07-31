//
// Created by twister on 7/31/24.
//
#include "Register.h"

Register::Register(size_t numCompanies){
    numAdded = numCompanies;
    companiesArray = new Company[numAdded];
}


Register::~Register(){
    delete[] companiesArray;
    companiesArray = nullptr;
}


Company Register::get(int companyId) const{
    for(size_t i = 0; i < numAdded; i++){
        if(companiesArray[i].getId() == companyId){
            return companiesArray[i];
        }
    }
}

void Register::add(const Company& c){

    for(size_t i = 0; i < numAdded; i++){
        if(companiesArray[i].getName().empty() &&
            companiesArray[i].getId() == NULL){
            companiesArray[i] = c;
            return;
        }

    }

}
