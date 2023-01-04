#include <string.h>
#include <iostream>

using namespace std;

#include "Contacto.h"
#include "funciones.h"


bool Contacto::cargar(){

    char correo[31];
    long num;
    cout<<"Ingrese el n�mero de telefono: ";
    cin>>num;
    if(!setTelefono(num)){return false;}
    cout<<"Ingrese el correo electr�nico: ";
    cargarCadena(correo, 30);
    if(!arroba(correo)){
        return false;
    }
    setMail(correo);
    return true;
}

void Contacto::mostrar(){

    cout<<"  Telefono: "<<getTelefono()<<endl;
    cout<<"  Correo Electr�nico: "<<getMail()<<endl;

}

