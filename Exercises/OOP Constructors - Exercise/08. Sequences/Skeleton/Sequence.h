//
// Created by twister on 8/5/24.
//

#ifndef SEQUENCE_H
#define SEQUENCE_H


#include <vector>


template <typename T, typename Generator>
struct Sequence{

    std::vector<T> m_xv;
    typedef typename std::vector<T>::iterator m_it;

    int m_last;
    Generator m_gen;

    Sequence() : m_last(0) { }

    m_it begin() { return m_xv.begin(); }
    m_it end() { return m_xv.end(); }


    void generateNext(int& n){
        for(int i = 0; i < n; i++){
            m_last = m_gen();
            m_xv.push_back(m_last);
        }

        //reset iterators to continue for range loop

    }

};







#endif //SEQUENCE_H
