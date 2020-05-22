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
        char sort_type_;
    public:
        //Constructor
        Ordenamiento(std::vector<std::string>);
        std::vector<std::string> sort_words();
        void change_sort_type(char);
};

Ordenamiento::Ordenamiento(std::vector<std::string> list_){
    this-> list_ = list_;
    this-> sort_type_ = 'a';
}

void Ordenamiento::change_sort_type(char sort_type_){
    this->sort_type_=sort_type_;
}

std::vector<std::string> Ordenamiento::sort_words(){
    if(this->sort_type_ == 'a'){
        std::sort(list_.begin(), list_.end());
        return list_;
    }
    else if(this->sort_type_ == 'd'){
        std::sort(list_.begin(), list_.end(), greater<std::string>());
        return list_;
    }
}