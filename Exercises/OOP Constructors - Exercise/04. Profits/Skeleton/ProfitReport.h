//
// Created by twister on 7/30/24.
//

#ifndef PROFITREPORT_H
#define PROFITREPORT_H


#include "Company.h"
#include "ProfitCalculator.h"
#include <map>


struct getProfitReport{

    std::map<std::string, int> m_results;



    const Company* m_start;
    const Company* m_finish;
    typedef std::map<int, ProfitCalculator> theMap;
    theMap& m_data;


    explicit getProfitReport(const Company* start, const Company* finish, theMap& data) :
        m_start(start),
        m_finish(finish),
        m_data(data) {


        // find by id
        // it.second.calc() == * profit calcs by comp tax percentage

        // get companies vector iterate by id and calc values with certain
        // company tax percentage


        // iterate by memory from start to finish (m_)

        const Company* end = m_finish+1;


        for(const auto& it : m_data){
            for(auto& x = m_start; x != end; ++x){
            //      std::cout << *x << std::endl;
                if(it.first == x->getId()){
                    int result = it.second.calculateProfit(*x);
                    m_results[x->getName()] = result;
                    break;
                }
            }

        }





    }



    friend std::ostream& operator << (std::ostream&, const getProfitReport&);


};

std::ostream& operator << (std::ostream& OUT, const getProfitReport& obj ){
    //obj.m_results
    for(const auto& it : obj.m_results){
        OUT << &it << std::endl;
    }
    return OUT;
}







#endif //PROFITREPORT_H
