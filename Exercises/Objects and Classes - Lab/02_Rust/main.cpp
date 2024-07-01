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
 * for each new row created by (n * 2 - 1) - x, scan from start to x and determine whether it is a '.' or '#';
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



    void workPoints(){

        for (int i = 0; i < m_rows; i++) {
            for (int j = 0; j < m_cols; j++) {
                if(m_matrix[i][j] ==  '!'){
                    makeRhomboid(j, i); // j = x, i = y
                    return;
                }
            }
        }

    }

    void makeRhomboid (int x, int y){
        // work with m_unitTime

        int leftX{};
        int rightX{};
        // y const

        int topY{};
        int bottomY{};
        // x const

        // borders
        for(int l =x, change =0; l >= 0 && change <= m_unitTime; l--, change++)
            leftX = l;

        for(int r =x, change =0; r < 10 && change <= m_unitTime; r++, change++)
            rightX = r;

        for(int t =y, change =0; t >= 0 && change <= m_unitTime; t--, change++)
            topY = t;

        for(int b =y, change =0; b < 10 && change <= m_unitTime; b++, change++)
            bottomY = b;






        // save the values
        int lx = leftX;
        int rx = rightX;
        int ty = topY;
        int by = bottomY;



        // top
        for(int i = y; i >= ty; i--){
            //check row
            for(int j = lx; j <= rx; j++){
                if(m_matrix[i][j] != '#'){
                    m_matrix[i][j] = '!';
                }
            }
            lx++;
            rx--;

        }

        lx = leftX+1;
        rx = rightX-1;
        y++;

        // bottom
        for(int i = y; i <= by; i++){
            //check row
            for(int j = lx; j <= rx; j++){
                if(m_matrix[i][j] != '#'){
                    m_matrix[i][j] = '!';
                }
            }
            lx++;
            rx--;
        }

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

    void printResult() const{
        for (int i = 0; i < m_rows; ++i) {
            for (int j = 0; j < m_cols; ++j) {
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