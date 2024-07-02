//
// Created by User on 030-30.6.2024 г..
//


// 10x10 matrix

// . healty
// # rust-resistant
// ! began to rust

// there may be 0, 1 or more parts that have begun to rust

// time


#include <iostream>
#define ROWS 10
#define COLS 10


class RustMaker{

private:
    char** m_matrix;
    int m_rows,
        m_cols;
    int m_unitTime;


    int getRustPointsCount() const{
        int count{};

        for (int i = 0; i < m_rows; ++i) {
            for (int j = 0; j < m_cols; ++j) {
                if(m_matrix[i][j] ==  '!'){
                    count++;
                }
            }
        }
        return count;
    }

    void toLeft(int limit, int x, int start){
        if(start <= 0) return;
        for(int i = start-1; i >= 0 && limit > 0; i--, limit--){
            if(m_matrix[x][i] != '#')
                m_matrix[x][i] = 'L';
        }
    }

    void toRight(int x, int start, int limit){
        if(start >= m_cols) return;
        for(int i = start+1; i < m_cols && limit > 0; i++, limit--){
            if(m_matrix[x][i] != '#')
                m_matrix[x][i] = 'R';
        }
    }

    void toBottom(int y, int start, int limit){
        if(start >= m_rows) return;
        for(int i = start+1; i < m_rows && limit > 0; i++, limit--){
            if(m_matrix[i][y] != '#')
                m_matrix[i][y] = 'B';
        }
    }

    void toTop(int y, int start, int limit){
       if(start <= 0) return;
       for(int i = start-1; i >= 0 && limit > 0; i--, limit--){
           if(m_matrix[i][y] != '#')
               m_matrix[i][y] = 'T';
       }
    }

    void createRustOfPointByScale(int x, int y, int n){
        int lim = n-1;

        m_matrix[x][y] = '@';






        toLeft(n, x, y);
        toRight(x, y, n);
        toBottom(y, x, n);
        toTop(y,x,n);









        // 00            90
        //     4-5, 4-5
        // 09            99






    }

    void workPoints(){
        for (int i = 0; i < m_rows; i++)
            for (int j = 0; j < m_cols; j++)
                if(m_matrix[i][j] ==  '!')
                    createRustOfPointByScale(i, j, m_unitTime); // assign with 'x'
    }




public:
    RustMaker(char** mtrx =nullptr, int r =0, int c =0, int x =0){
        m_matrix = mtrx;
        m_rows = r;
        m_cols = c;
        m_unitTime = x;
    }

    void getSchema(){
        workPoints();

    }

    void printResult(){
        for (int i = 0; i < m_rows; ++i) {
            for (int j = 0; j < m_cols; ++j) {
// TODO: swap 'x' with '!'
//                if(m_matrix[i][j] == 'x')
//                    m_matrix[i][j] = '!';

                std::cout << m_matrix[i][j];
            }
            std::cout << std::endl;
        }

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
        r.getSchema();
        r.printResult();







// Memory management
    for(int i = 0; i < ROWS; i++){
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}