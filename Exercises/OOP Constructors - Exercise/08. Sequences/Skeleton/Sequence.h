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

    auto begin() { return m_begin; }
    auto end() { return m_xv.end(); }

    void generateNext(int& n){

        for(int i = 0; i < n; i++){
            int x = m_gen();
            std::cout << x << ' ';
            m_xv.push_back(x);
        }
        m_begin = m_xv.begin(); // !

    }

};







#endif //SEQUENCE_H
