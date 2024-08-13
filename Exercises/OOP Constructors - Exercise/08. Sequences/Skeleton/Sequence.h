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
    std::vector<T> m_xv;
    typename std::vector<T>::iterator m_begin;
    bool cleared = false;

    auto begin() { return --m_begin; }
    auto end()  { return --m_xv.end(); } // x-1!

    void generateNext(const int& n){

        // if(m_begin == m_xv.end())
        //     m_begin = m_xv.begin();


        if(!(m_xv.empty())){
            for(auto it = ++m_xv.begin(); it != m_xv.end(); ++it) // +2
                std::cout << *it << ' ';
            m_xv.clear();
            m_xv.shrink_to_fit();
            cleared = true;
        }

        //                = !!
        for(int i = 0; i <= n; i++)
            m_xv.push_back(m_gen());

        m_xv.shrink_to_fit();

        {

            if(!cleared){
                if(m_begin != m_xv.end())
                    m_begin = m_xv.begin();
            } else {
                m_begin = m_xv.begin() - 1; // fix autoincrement for-range
            }
            cleared = false;
            return;

            if(m_begin != m_xv.end()){ // first time
                m_begin = m_xv.begin();
            } else {
                m_begin = m_xv.begin()-1;
            }
            return;

            if(m_begin == m_xv.end() && *m_begin != 0)
                m_begin = m_xv.begin()-1;


        }




    }

};









#endif //SEQUENCE_H
