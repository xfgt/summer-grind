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


    auto begin() { return m_begin; }
    auto end() { return m_xv.end()-1; } // x-1!

    void generateNext(int& n){

        std::stringstream m_ss;
        if(n == 0){
            m_begin = m_xv.end()-1;
            return;
        }


        if(!(m_xv.empty()))
            m_xv.clear();

        for(int i = 0; i <= n; i++){ // = (!!!)
            int x = m_gen();
            m_ss << x << " ";
            m_xv.push_back(x);
        }


        m_begin = m_xv.begin(); // !!!

        std::cout << m_ss.str();

    }

};







#endif //SEQUENCE_H
