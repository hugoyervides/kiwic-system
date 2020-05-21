/*
Input class to get the input from a file or from console
*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

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
        void capture_lines();
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
    for(vector<string>::iterator i = lines_.begin(); i != lines_.end(); i++){
        string line = *i;
        cout<< line << endl;
    }
}

//Method to get the data from the console
void Input::capture_lines(){
    string line;
    cout<<"Insert $ when done! <3" <<endl;
    //While loop to capture the lines
    do {
        getline(cin,line);
        transform(line.begin(), line.end(), line.begin(),
		[](unsigned char c) { return tolower(c); });
        lines_.push_back(line);
    } while (line != "$");
    //Delete the $
    lines_.pop_back();
}


