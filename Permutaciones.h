/*
Class permutaciones to do circle shitfts
*/
#include <iostream>
#include <vector>
#include <sstream>


using namespace std;

class Permutaciones{
    private:
        vector<string> lines_;

    public:
        //Constructor
        Permutaciones(vector<string>);
        string permutations(string);
        vector<string> circle_shifts();

};

Permutaciones::Permutaciones(vector<string> lines_){
    this->lines_ = lines_;
}

string Permutaciones::permutations(string aux) {
	string word;
    stringstream s_stream(aux);
	vector<string> perm_cache;
    //Capture the words
	while (s_stream >> word){
		perm_cache.push_back(word);
	}
	word = perm_cache.back();
	perm_cache.pop_back();
	perm_cache.insert(perm_cache.begin(), word);
	word = "";
	for (vector<string>::iterator i = perm_cache.begin(); i != perm_cache.end(); i++) {
		word = word + " " + *i;
	}
	return word;
}

//Method to do circle shifts
vector<string> Permutaciones::circle_shifts(){
    vector<string> result;
    string dump, cache;
	for(vector<string>::iterator i = lines_.begin(); i != lines_.end(); i++){
		int iterator = 0;
		stringstream s_stream(*i);
		while (getline(s_stream, dump, ' ')) {
			iterator++;
		}
		cache = *i;
		for (int temp = 0; temp < iterator; temp++) {
			cache = permutations(cache);
			result.push_back(cache);
		}
	}
	this->lines_ = result;
    return this->lines_;
}