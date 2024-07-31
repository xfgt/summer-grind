//
// Created by twister on 7/30/24.
//

#ifndef PROFITREPORT_H
#define PROFITREPORT_H


#include "Company.h"
#include "ProfitCalculator.h"
#include <map>


struct getProfitReport{
    friend std::ostream& operator << (std::ostream&, const getProfitReport&);




    std::map<std::string, int> m_results;

    const Company* m_start;
    const Company* m_finish;
    typedef std::map<int, ProfitCalculator> theMap;
    theMap& m_data;

    explicit getProfitReport(const Company* start, const Company* finish, theMap& data) :
        m_start(start),
        m_finish(finish),
        m_data(data) {

        const Company* end = m_finish+1;

        for(const auto& it : m_data){
            auto x = m_start; // no ref!!
            while (x != end){
                if(it.first == x->getId()){
                    int result = it.second.calculateProfit(*x);
                    m_results[x->getName()] = result;
                    break;
                }
                ++x;
            }
        }
    }// !Constructor

};

inline std::ostream& operator << (std::ostream& OUT, const getProfitReport& obj ) {
    for(const auto& it : obj.m_results){
        OUT << it.first << " = " << it.second << std::endl;
    }
    return OUT;
}







#endif //PROFITREPORT_H
