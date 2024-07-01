//
// Created by User on 030-30.6.2024 г..
//


// 10x10 matrix

// . healty
// # rust-resistant
// ! began to rust

// there may be 0, 1 or more parts that have begun to rust

// time



/*
 * algorithm
 *
 * find '!'in the matrix
 * form there read the number of unit time (n)
 * make a rhomboid which is (n * 2 - 1) where each level up and down is (n * 2 - 1) - x, where x % 2 == 0;
 * for each new row created by (n * 2 - 1) - x, scan from start to x and determin whether it is a '.' or '#';
 * if it is a '#' skip, otherwise put '!'
 * print the new matrix
 */


#include <iostream>
#define ROWS 10
#define COLS 10


class RustMaker{

private:
    char** m_matrix;
    int m_rows,
        m_cols;
    int m_unitTime;

public:
    RustMaker(char** mtrx =nullptr, int r =0, int c =0, int x =0){
        m_matrix = mtrx;
        m_rows = r;
        m_cols = c;
        m_unitTime = x;
    }

    void printResult() const{
        for (int i = 0; i < m_rows; ++i) {
            for (int j = 0; j < m_cols; ++j) {
                std::cout << m_matrix[i][j] << ' ';
            }
            std::cout << std::endl;
        }
        std::cout << m_unitTime << std::endl;
    }



};

int main(){


    char** matrix = new char*[ROWS];
        for(int r = 0; r < ROWS; r++){
            matrix[r] = new char[COLS];
            for(int c = 0; c < COLS; c++){
                std::cin >> matrix[r][c];
            }
        }
        std::cin.clear();

        int unitTime{};
        std::cin >> unitTime;
        std::cin.clear();


        RustMaker r(matrix, ROWS, COLS, unitTime);
        //r.getSchema();
        r.printResult();







// Memory management
    for(int i = 0; i < ROWS; i++){
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}