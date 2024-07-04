//
// Created by User on Чт-4.7.2024 г..
//
#include <iostream>
#include <vector>
#include <algorithm> // pair
#include <sstream>
#include <iomanip>
#include <cmath>

struct Sale{

    std::string m_town;
    std::string m_product;
    double m_price;
    double m_quantity;
    double m_weight;

    Sale(std::string inp =""){
        std::string tempPrice{};
        std::string tempQ{};

        std::stringstream ss(inp);

        ss >> m_town;
        ss >> m_product;
        ss >> tempPrice;
        ss >> tempQ;

        m_price = std::stod(tempPrice);
        m_quantity = std::stod(tempQ);
        m_weight = m_price * m_quantity;

    }





};



void printResult(const std::vector<Sale*>& x){

    for(const auto& m : x){
        if(m != nullptr){
            std::cout << std::fixed << std::setprecision(2) <<  m->m_town << " -> " << m->m_weight << std::endl;

        }
    }
}

int main(){
    std::vector<Sale*> sales;


     // std::fixed
    int N{};
    std::cin >> N;
    std::cin.ignore();
    std::cin.clear();
    sales.reserve(N);


    std::string input{};
    Sale* sp = nullptr;

//  fill vector of sales
    for(int i = 0; i < N; i++){
        std::getline(std::cin, input);
        sp = new Sale(input);
        sales.push_back(sp);
        std::cin.clear();
    }


//  find duplicate towns and sum their weights

    for(const auto& it : sales){
        if(it == nullptr) continue;
        std::string searchingString = it->m_town;

        for(auto& x :sales){
            if(x == nullptr) continue;
            std::string current = x->m_town;

            if(current == searchingString){
                if(it->m_weight == x->m_weight) continue;
                it->m_weight += x->m_weight;

                // delete x block
                delete x;
                x = nullptr;
            }
        }


    }

//  sort alphabetically


//  print result
    printResult(sales);





//  Memory management

// vector
    for(auto& it : sales){
        delete it;
        it = nullptr;
    }
    sp = nullptr;
    sales.clear();

// pair


    return 0;
}