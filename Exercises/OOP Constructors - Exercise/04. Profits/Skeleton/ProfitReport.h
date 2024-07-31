//
// Created by twister on 7/30/24.
//

#ifndef PROFITREPORT_H
#define PROFITREPORT_H


#include "Company.h"
#include "ProfitCalculator.h"
#include <map>

struct getProfitReport{
    typedef const std::map<int, ProfitCalculator> theMap;

    const Company* m_start;
    const Company* m_finish;

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

        auto skip = sizeof(m_start);
        const Company* end = m_finish+1;
        for(auto& x = m_start; x != end; ++x){
            std::cout << *x << std::endl;
        }

    }



    friend std::ostream& operator << (std::ostream&, const getProfitReport&);


};

std::ostream& operator << (std::ostream& OUT, const getProfitReport& obj ){

    // TODO
}







#endif //PROFITREPORT_H
