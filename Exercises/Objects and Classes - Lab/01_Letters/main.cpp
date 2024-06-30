//
// Created by User on 029-29.6.2024 г..
//

/* TODO order all met words starting with a char in lexicographic order
 *
     text
     character

     extract all words that have 'char' in them
     sort the found words in lexicographic order
     print result
 */

#include <iostream>
#include <cstring>


class GetWords{

    char ch{};
    char* text;


    int countWords(char* sample, char& x) const {
        int cnt{};
        while(*sample != '\0'){

            while(*sample != ' ' && *sample != '\0'){
                sample++;
            }
            cnt++;
            sample++;
        }
        return cnt;
    }
    void assignWords(char* sample, char words[][20], int& sizex, char& x){
        int i{};
        int j{};
        int m {};
        bool firstMet = false;

        while(sample[i] != '\0'){
            int r (-1);
            while(sample[j] != ' ' && sample[j] != '\0' && r < 20){

                if(sample[j] == x || sample[j] == x - 32 || sample[j] == x + 32) firstMet = true;

                if(firstMet) words[m][++r] = sample[j];

                j++;
            }

            if(m <= sizex && firstMet) m++;

            i = ++j;
            firstMet=false;
        }

    }
    void printWords(char words[][20], int& x) const{
        for(int i = 0; i < x; i++){
            if(words[i][0] == '\0')
                break;
            for(int j = 0; j < 20; j++){
                if(words[i][j] != ' ' && words[i][j] != '\0'){
                    std::cout << words[i][j];
                } else {
                    break;
                }
            }
            std::cout << ' ';
        }
        std::cout << std::endl;
    }


public:
    GetWords(char* txt =nullptr, char ltr ='\0'){
        if(std::strlen(txt) > 0){
            text = new char[std::strlen(txt)+1];
            memcpy(text, txt, std::strlen(txt)+1);
            text[std::strlen(txt)+1] = '\0';
            ch = ltr;
        }

        int x = countWords(text, ch);
        char words[x][20];
        memset(words, '\0', x*20);

        assignWords(text, words, x, ch);

        printWords(words, x);



    }







};


int main(){

    char inputText[2000]{};
    char letter{};

    std::cin.get(inputText, 1999);
    std::cin.clear();

    std::cin>>letter;
    std::cin.clear();

    GetWords* solve = nullptr;
    while(letter != '.'){
        solve = new GetWords(inputText, letter);




        delete[] solve;
        std::cin >> letter;
        std::cin.clear();
    }









    return 0;
}
