//
// Created by User on 029-29.6.2024 г..
//
// IDENTICAL RESULTS: https://tools.knowledgewalls.com/online-lexicographic-ascending-or-descending-sort

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

class GetWords{

private:
    char m_letter;
    char* m_text;
    std::vector<char*> m_matches;

//  NEW FUNCTIONS

//  remove ',' and '.'
    void cleanText(){
        for(int i = 0; i < std::strlen(m_text); i++)
            if(m_text[i] == '.' || m_text[i] == ',')
                m_text[i] = ' ';


    }

//  check duplicate words
    bool isDuplicate(char*& word){
        for(const auto& current : m_matches){
            if(strcmp(current, word) == 0)
                return true;
        }
        return false;
    }
    
//  fill vector with matching words
    void fillVector(){
        for(int i = 0; i < std::strlen(m_text); i++){
            char* word = new char[45];
            memset(word, '\0', 45);

            bool fits = false;
            int g(-1);

            while(m_text[i] != ' '){
                word[++g] = m_text[i++];
//                if(word[0] >= 'A' && word[0] <= 'Z')
//                    fits = false;
                if(word[g] == m_letter || word[g] == m_letter - 32 || word[g] == m_letter+32) {
                    fits = true;
                }
            }
            if(fits){
                if(!(isDuplicate(word))){
                    m_matches.push_back(word);
                } else{
                    delete[] word;
                }
            } else {
                delete[] word;
            }

        }

    }


    void lexSort(){
        char temp[45]{};

        for(int i = 0; i < m_matches.size()-1; i++){
            for(int j = 0; j < m_matches.size() - i - 1; j++){
                if(std::strcmp(m_matches[j], m_matches[j+1]) > 0){
                    std::strcpy(temp, m_matches[j]);
                    std::strcpy(m_matches[j], m_matches[j+1]);
                    std::strcpy(m_matches[j+1], temp);
                }
            }


        }

    }

public:
    GetWords(char* txt =nullptr, char ltr ='\0'){
        if(std::strlen(txt) <= 0 || !(ltr >= 'a' && ltr <= 'z' || ltr >= 'A' && ltr <= 'Z')){
            m_text = nullptr;
            m_letter = '\0';
            return;
        }
        m_text = new char[std::strlen(txt)+1];
        memcpy(m_text, txt, std::strlen(txt)+1);
        m_letter = ltr;

        cleanText(); // remove ', and '.'
        fillVector(); // pushback into vector words that match
        lexSort();

    }

    ~GetWords(){
        if(m_text != nullptr){
            delete[] m_text;
            m_text = nullptr;
        }
        if(!(m_matches.empty())){
            for(const auto& x : m_matches){
                delete x;
            }
            m_matches.clear();
        }
    }

//  print matched words
    void showResult() const{
        if(m_matches.empty()){
            std::cout << "---" << std::endl;
            return;
        }
        for(const auto& x : m_matches)
            std::cout << x << ' ';
        std::cout << std::endl;
    }

};


int main(){

    char inputText[500]{};

    char letter{};

    std::cin.get(inputText, 499);
    std::cin.clear();

    std::cin>>letter;
    std::cin.clear();

    GetWords* solve = nullptr;
    while(letter != '.'){
        solve = new GetWords(inputText, letter);
        solve->showResult();
        delete solve;

        std::cin >> letter;
        std::cin.clear();
    }




    return 0;
}
