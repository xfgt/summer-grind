//
// Created by twister on 7/19/24.
//

#ifndef SPLIT_H
#define SPLIT_H
//returns a vector

#include <iostream>
#include <vector>
#include <sstream>

std::vector<int> split(std::string line, char seperator){
    std::vector<int> v;

    int x{};
    std::string sample;
    std::stringstream ss(line);

    while(std::getline(ss, sample, seperator)){
        x = std::stoi(sample);
        v.push_back(x);
    }

    return v;
}

std::vector<std::string> split(std::string line, char seperator){
    std::vector<std::string> v;

    std::string sample;
    std::stringstream ss(line);

    while(std::getline(ss, sample, seperator)){
        v.push_back(sample);
    }

    return v;
}


class Song;
std::vector<Song> split(std::string line, char seperator){
    std::vector<Song> v;

    Song s;

    std::string sample;
    std::stringstream ss(line);

    while(std::getline(ss, sample, seperator)){
        s >> sample;
        v.push_back(s);
    }

    return v;
}

#endif //SPLIT_H