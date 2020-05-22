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
    Stopwords* stop_words;
    char opcion;
    int line_no;
    //Capture the data
    my_input = new Input();
    my_input->capture_from_file();
    //Preguntar si queremos eliminar lineas
    do{
        //Desplegar lineas
        my_input->display_lines();
        cout<<"Deseas eliminar una linea? (y/n)" << endl;
        cin >> opcion;
        if(opcion == 'y'){
            cout << "Introduce numero de linea" << endl;
            cin >> line_no;
            my_input->delete_line(line_no);
        }
    }while(opcion != 'n');
    //Preguntar por stop words
    cout<<"Quieres agregar stop words? (y/n)" << endl;
    cin>>opcion;
    if(opcion == 'y'){
        //Capturar stop words
        stop_words = new Stopwords();
        stop_words->capture_from_file();
        my_input->delete_stop_words(stop_words);
    }
    //Feed the data into the permutaciones class
    perm = new Permutaciones(my_input->get_lines());
    //Feed the data into the sorting algorithm
    ord = new Ordenamiento(perm->circle_shifts());
    //Preguntar si queremos cambiar el orden
    cout << "Cambiar orden de ordenamiento? (y/n)" << endl;
    cin >> opcion;
    if (opcion == 'y'){
        //cambiar el orden
        ord->change_sort_type('d');
    }
    delete my_input;
    my_input = new Input(ord->sort_words());
    //Preguntar si queremos eliminar lineas
    do{
        //Desplegar lineas
        my_input->display_lines();
        cout<<"Deseas eliminar una linea? (y/n)" << endl;
        cin >> opcion;
        if(opcion == 'y'){
            cout << "Introduce numero de linea" << endl;
            cin >> line_no;
            my_input->delete_line(line_no);
        }
    }while(opcion != 'n');
    return 0;
}
