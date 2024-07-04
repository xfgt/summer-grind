//
// Created by User on Чт-4.7.2024 г..
//


#include <iostream>
#include <vector>
#include <cstring>



void swap(char*& c1, char*& c2){
    char temp[30];

    std::strcpy(temp, c1);
    std::strcpy(c1, c2);
    std::strcpy(c2, temp);


}

void shiftWords(std::vector<char*>& w, int& x){
    for(int j = 0 ; j <= x; j++) // !!
        for(int i = 0; i < w.size()-x; i++)
            swap(w[i], w[i+2]);


}
int main(){

    std::vector<char*> words;
    char text[100];
    int shift{};

    std::cin.get(text, 99);
    std::cin.clear();
    std::cin >> shift;
    std::cin.clear();


    char* word = nullptr;
    int i{};
    while(text[i] >= 'a' && text[i] <= 'z' && i < 100 || text[i] >= 'A' && text[i] <= 'Z' && i < 100){
        int g(-1);
        word = new char[30];
        while(text[i] != ' ' && text[i] != '\0' && text[i] != '\n' && g < 30){ //// big problem
            word[++g] = text[i++];
        }
        word[g+1] = '\0';
        i++;

        if(g >= 0)
            words.push_back(word);


    }

    shiftWords(words, shift);

//  print
    for(const auto& x : words)
        std::cout << x << std::endl;




//  memory management

    for(auto& it : words){
        delete it;
        it = nullptr;
    }
    words.clear();
    word = nullptr;

    return 0;
}