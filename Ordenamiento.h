/*
Class ordenamiento to sort words from a vector of strings
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Ordenamiento{
    private:
        std::vector<std::string> list_;
    public:
        //Constructor
        Ordenamiento(std::vector<std::string>);
        std::vector<std::string> sort_words();
};

Ordenamiento::Ordenamiento(std::vector<std::string> list_){
    this-> list_ = list_;
}

std::vector<std::string> Ordenamiento::sort_words(){
    //std::vector<std::string> result;
    std::sort(list_.begin(), list_.end());
    return list_;
}