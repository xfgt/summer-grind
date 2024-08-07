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
    std::stringstream m_ss;

    auto begin() { return m_begin; }
    auto end() { return --m_xv.end(); } // x-1!

    void generateNext(int& n){


        if(!(m_xv.empty())){
            std::cout << m_ss.str();
            m_xv.clear();
        }


        for(int i = 0; i <= n; i++){ // = (!!!)
            int x = m_gen();
            m_ss << "(" << x << ") ";
            m_xv.push_back(x);
        }

        m_begin = m_xv.begin()-1; // !!!



    }

};







#endif //SEQUENCE_H
