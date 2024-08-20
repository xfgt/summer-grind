//
// Created by twister on 8/20/24.
//

#ifndef PARSECOMPANIES_H
#define PARSECOMPANIES_H




inline Company* parseUniqueCompanies
(const std::string& input , int& N, std::string(*chosenFunction)(const Company& obj)) {

    N = 0;
    auto** list = new Company*[10];

    int id;
    std::string name;
    std::stringstream ss(input);

    //  fill
    while(ss >> id >> name){
        list[N++] = new Company(id, name);

    }


    return list[0];
}


#endif //PARSECOMPANIES_H
