//
// Created by twister on 8/5/24.
//

#ifndef SEQUENCE_H
#define SEQUENCE_H


#include <vector>


template <typename T, typename Generator>
struct Sequence{
    Generator m_gen;
    std::vector<int> m_xv;

    std::vector<int>::iterator m_begin;
    std::vector<int>::iterator m_end;

    Sequence(){
        m_xv.reserve(3); // !
        m_begin = m_xv.begin();
        m_end = m_xv.end();
    }


    auto begin() { return m_begin; }
    auto end() { return m_end; }

    void reset(){
        if(m_xv.empty()){
            m_begin = m_xv.begin();
            m_end = m_xv.end();

        } else {
            m_begin = m_xv.begin();
            --m_end;
        }

    } // problem with begin

    void generateNext(int& n){

        for(int i = 0; i < n; i++){
            m_xv.push_back(m_gen());
        }
        reset();
    }

};







#endif //SEQUENCE_H
