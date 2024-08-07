//
// Created by twister on 8/5/24.
//

#ifndef SEQUENCE_H
#define SEQUENCE_H


#include <vector>
#include <sstream>


template <typename T, typename Generator>
struct Sequence{
    Generator m_gen;
    std::vector<int> m_xv;
    std::vector<int>::iterator m_begin;
    std::ostringstream m_oss;

    auto begin() { return m_begin; }
    auto end() { return m_xv.end(); }

    void generateNext(int& n){
        if(n == 0)
            return;

        if(!(m_xv.empty()))
            m_xv.clear();

        for(int i = 0; i < n; i++){
            int x = m_gen();
            m_xv.push_back(x);
            m_oss << x << " ";
        }


        m_begin = m_xv.begin(); // !!!

        std::cout << m_oss.str();
    }

};







#endif //SEQUENCE_H
