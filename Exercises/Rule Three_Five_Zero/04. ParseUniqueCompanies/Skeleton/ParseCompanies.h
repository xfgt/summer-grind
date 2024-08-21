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

//  get size
    while(ss >> id >> name){
        N++;
    }

    ss.clear(); //!!!
    ss.seekg(0);

    std::string search{};
    std::string current{};
    Company* cpms = new Company[N];

//  search & filter
   for(int i = 0; i < N; i++){
       current = search;

       ss >> id >> name;

       auto* x = new Company(id, name);
       search = filterFunction(*x);

       if(search != current && x->getId() > 0){
           cpms[i] = *x;
       } else{
           --N;
           i--;
           delete x;
       }


   }




    return cpms;
}


#endif //PARSECOMPANIES_H
