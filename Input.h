/*
Input class to get the input from a file or from console
*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "stopwords.h"

using namespace std;

class Input{
    //Declaracion de los atributos
    private:
        vector<string> lines_;

    public:
        Input();
        Input(vector<string>);
        vector<string> get_lines();
        void display_lines();
        string transform_line(string);
        void capture_lines();
        void capture_from_file();
        void delete_stop_words(Stopwords*);
        void delete_line(int);
};

//Default constructor
Input::Input(){
    cout<<"Default constructor" << endl;
}

//Constructor con parametros
Input::Input(vector<string> lines_){
    this->lines_ = lines_;
}

//Method to get the vector
vector<string> Input::get_lines(){
    return this->lines_;
}

//Method to display the lines
void Input::display_lines(){
    int line_no = 1;
    for(vector<string>::iterator i = lines_.begin(); i != lines_.end(); i++){
        string line = *i;
        cout << "Line " + to_string(line_no) + " : "
            << line << endl;
        line_no++;
    }
}

//Metodo para eliminar lineas
void Input::delete_line(int line_no){
    int counter = 1;
    for(vector<string>::iterator i = this->lines_.begin(); i != this->lines_.end(); i++){
        if(counter == line_no){
            this->lines_.erase(i);
            break;
        }
        counter ++;
    }
}

string Input::transform_line(string line){
    transform(line.begin(), line.end(), line.begin(),
	[](unsigned char c) { return tolower(c); });
    return line;
}

//Method to get the data from the console
void Input::capture_lines(){
    string line;
    cout<<"Insert $ when done! <3" <<endl;
    //While loop to capture the lines
    do {
        getline(cin,line);
        line = this->transform_line(line);
        lines_.push_back(line);
    } while (line != "$");
    //Delete the $
    lines_.pop_back();
}

//Method to capture data from a file
void Input::capture_from_file(){
    ifstream input_file;
    string line;
    string file_name;
    cout<< "Introduce el nombre del archivo a usar: " <<endl;
    cin >> file_name;
    input_file.open(file_name);
    if(!input_file.is_open()){
        cout<<"Invalid file!" << endl;
        return;
    }
    while(getline(input_file, line)){
        //Metemos la linea dentro del stack
        line = this->transform_line(line);
        this->lines_.push_back(line);
    }
}

//Method to delete stop words
void Input::delete_stop_words(Stopwords* stop_words){
    vector<string> words;
    words = stop_words->get_words();
    for(vector<string>::iterator i = words.begin(); i != words.end(); i++){
        string word = " " + *i;
        for(vector<string>::iterator k = this->lines_.begin(); k != this->lines_.end(); k++){ 
            string::size_type size = (*k).find(word);
            if(size != string::npos){
                (*k).erase(size, (word).length());
            }
        }
    }
}