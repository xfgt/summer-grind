//
// Created by twister on 8/5/24.
//

#ifndef SEQUENCE_H
#define SEQUENCE_H


#include <vector>


template <typename T, typename Generator>
struct Sequence{
    Generator m_gen;
    std::vector<T> m_xv;
    typename std::vector<T>::iterator m_begin;
    typename std::vector<T>::iterator m_end;


    auto begin() { return m_begin; }  // for-range auto increment
    auto end()  { return m_end; }     // actual value


    void generateNext(const int& n){

        auto h = m_begin;
        auto r = m_xv.end();

        if(!m_xv.empty()){
            for(auto it = ++h; it != r; ++it){
                std::cout << *it << ' ';
            }
            m_xv.clear();
            m_xv.shrink_to_fit();
            m_xv.assign(1, 0);
        }

        for(int i = 0; i <= n; i++)
            m_xv.push_back(m_gen());


        m_begin = m_xv.begin();
        m_end = m_xv.end()-1;




    }

};









#endif //SEQUENCE_H
