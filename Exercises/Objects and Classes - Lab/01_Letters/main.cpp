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

private:
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

    bool checkWord(char* word, int sz, char& x){
        bool good = false;
        if(x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z'){
            for(int i = 0; i <= sz; i++){
                if(word[i] >= 'a' && word[i] <= 'z' || word[i] >= 'A' && word[i] <= 'Z'){ // nothing other than a letter
                    if(word[i] == x || word[i] == x - 32 || word[i] == x + 32){ // case sensitivity doesn't matter
                        good = true;
                        break;
                    }
                }
            }
        } else {
            return false;
        }
        return good;

    }

    bool isDuplicate(char* word, char arrOfWords[][45], int m){
        for(int i = 0; i < m; i++){
            if(std::strcmp(arrOfWords[i], word) == 0) // works!
                return true;
        }
        return false;
    }

    void assignWords(char* sample, char words[][45], int& sizex, char& x){
        int i{};
        int j{};
        int m {};
        while(sample[i] != '\0'){
            int r (-1);
            char temp[45]{};
            int g(-1);
            bool isGood = false;

            while(sample[j] != ' ' && sample[j] != '\0' && sample[j] != '.' && sample[j] != ',' && r < 45){
                temp[++g] = sample[j];
                j++;
            }

            if(checkWord(temp, g, x)){
                if(!isDuplicate(temp, words, m)){
                    isGood = true;
                    int f{};
                    while(r < 45 && temp[f] != '\0')
                        words[m][++r] = temp[f++];
                }

            }
            if(m <= sizex && isGood) m++;

            i = ++j;
            g=0;
            isGood = false;
        }
        if(m != 0)
            sortLexicographic(words, m);
        else{
            for(int i = 0; i < 3; i++)
                words[0][i] = '-';
        }

    }


    void sortLexicographic(char words[][45], int& m){
        // perform bubble sort algorithm
        char* temp = new char[45];
        memset(temp, '\0', 45);
        bool flag = 0;
        for(int i = 1; i < m-1; i++){
            flag = 0;

            for(int j = 0 ; j < m-i; j++){

                // default swap procedure
                if(std::strcmp(words[j], words[j+1]) > 0){
                    flag = 1;
                    std::strcpy(temp, words[j]);
                    std::strcpy(words[j], words[j+1]);
                    std::strcpy(words[j+1], temp);
                }
            }
            if(flag == 0)
                break;
        }
        delete[] temp;


    }

    void printWords(char words[][45], int& x) const{
        for(int i = 0; i < x; i++){
            if(words[i][0] == '\0')
                break;

            for(int j = 0; j < 45; j++){
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
        char words[x][45];
        memset(words, '\0', x*45);
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
