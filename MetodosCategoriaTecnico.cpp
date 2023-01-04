#include <iostream>

using namespace std;

#include "CategoriaTecnico.h"


bool CategoriaTecnico::cargar(){
    char cat;
    cout<<"A - Plomero"<<endl;
    cout<<"B - Gasista"<<endl;
    cout<<"C - Electricista"<<endl;
    cout<<"D - Frigorista"<<endl<<endl;
    cout<<"Ingrese la categoría: ";
    cin>>cat;
    switch(cat){
    case 'A':
        setTipo('A');
        setPrecio(600);
        setEspecialidad("Plomero");
        break;
    case 'a':
        setTipo('A');
        setPrecio(600);
        setEspecialidad("Plomero");
        break;
    case 'B':
        setTipo('B');
        setPrecio(500);
        setEspecialidad("Gasista");
        break;
    case 'b':
        setTipo('B');
        setPrecio(500);
        setEspecialidad("Gasista");
        break;
    case 'C':
        setTipo('C');
        setPrecio(400);
        setEspecialidad("Electricista");
        break;
    case 'c':
        setTipo('C');
        setPrecio(400);
        setEspecialidad("Electricista");
        break;
    case 'D':
        setTipo('D');
        setPrecio(300);
        setEspecialidad("Frigorista");
        break;
    case 'd':
        setTipo('D');
        setPrecio(300);
        setEspecialidad("Frigorista");
        break;
    default:
        setTipo('0');
        return false;
        break;
    }
    return true;
}

