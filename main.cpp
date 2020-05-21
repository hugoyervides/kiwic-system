/*
KWIC System implementation using Pipes and Filters
Developed By
Victor Hugo Oyervides - A01382836

*/
#include <iostream>
#include "input.h"
#include "ordenamiento.h"
#include "permutaciones.h"
#include <string>

int main(){
    //Variable declaration
    Input* my_input;
    Permutaciones* perm;
    Ordenamiento* ord;

    //Capture the data
    my_input = new Input();
    my_input->capture_lines();

    //Feed the data into the permutaciones class
    perm = new Permutaciones(my_input->get_lines());
    //Feed the data into the sorting algorithm
    ord = new Ordenamiento(perm->circle_shifts());
    delete my_input;
    my_input = new Input(ord->sort_words());
    my_input->display_lines();
    return 0;
}
