//
// Created by twister on 8/20/24.
//

#ifndef PARSECOMPANIES_H
#define PARSECOMPANIES_H


inline Company* parseUniqueCompanies
(const std::string& input , int& N, std::string(*filterFunction)(const Company& obj)) {

    N = 0;
    int id;
    std::string name;
    std::istringstream ss(input);
    std::vector<Company*> v;

//  get size
    while(ss >> id >> name){
        N++;
    }


    Company** cpms = new Company*[N];


    ss.clear(); //!!!
    ss.seekg(0);

    std::string search{};
    std::string current{};


//  search & filter
   for(size_t i = 0; i < N; i++){
       current = search;

       ss >> id >> name;

       auto* x = new Company(id, name);
       search = filterFunction(*x);

       if(search != current){
           cpms[i] = x;
       } else{
           --N;
           i--;
           delete x;
       }


   }




    return cpms[0];
}


#endif //PARSECOMPANIES_H
