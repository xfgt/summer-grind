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
    auto end()  { return --m_xv.end(); } // x-1!

    void generateNext(int& n){

        if(!(m_xv.empty())){
            for(auto it = m_begin+2; it != m_xv.end(); ++it)
                std::cout << *it << ' ';
            m_xv.clear();
        }

        //                = !!
        for(int i = 0; i <= n; i++){
            m_xv.push_back(m_gen());
        }


        if(m_begin != m_xv.end())
            m_begin = m_xv.begin() + 1;

        if(*m_begin != 0)
            m_begin = m_xv.begin()-1;
        else
            m_begin = m_xv.begin();

    }

};







#endif //SEQUENCE_H
