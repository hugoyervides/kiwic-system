/*
Class Stop words to store the stop words XD
*/
#include <iostream>
#include <vector>
#include <iostream>

class Stopwords{
    private:
        std::vector<std::string> words_;

    public:
        //Constructor
        Stopwords();
        //Metodos
        void capture_words();
        void capture_from_file();
        std::vector<std::string> get_words();     
        void display_words();   
};
//Constructor
Stopwords::Stopwords(){
    std::cout << "Constructor default" << std::endl;
}
//Metodos
void Stopwords::capture_words(){
    //Variable declaration
    std::string word;
    std::cout<<"Introduce stop words, al terminar introduce $" << std::endl;
    do{
        std::cin>>word;
        this->words_.push_back(word);
    }while(word != "$");
    this->words_.pop_back();
}
void Stopwords::capture_from_file(){
    std::ifstream input_file;
    std::string file_name;
    std::cout<<"Introduce el nombre del archivo de las stopwords" << std::endl;
    std::cin>>file_name;
    input_file.open(file_name);
    if(!input_file.is_open()){
        std::cout<<"Archivo invalido" << std::endl;
        return;
    }
    while(!input_file.eof()){
        std::string word;
        input_file >> word;
        this->words_.push_back(word); 
    }
}
std::vector<std::string> Stopwords::get_words(){
    return this->words_;
}
void Stopwords::display_words(){
    for(std::vector<std::string>::iterator i = this->words_.begin(); i != this->words_.end(); i ++){
        std::cout << *i << std::endl;
    }
}