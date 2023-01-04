#include <string.h>
#include <iostream>

using namespace std;

#include "Contacto.h"
#include "funciones.h"


bool Contacto::cargar(){

    char correo[31];
    long num;
    cout<<"Ingrese el número de telefono: ";
    cin>>num;
    if(!setTelefono(num)){return false;}
    cout<<"Ingrese el correo electrónico: ";
    cargarCadena(correo, 30);
    if(!arroba(correo)){
        return false;
    }
    setMail(correo);
    return true;
}

void Contacto::mostrar(){

    cout<<"  Telefono: "<<getTelefono()<<endl;
    cout<<"  Correo Electrónico: "<<getMail()<<endl;

}

