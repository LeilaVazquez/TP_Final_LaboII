#include <string.h>
#include <iostream>

using namespace std;

#include "Direccion.h"
#include "funciones.h"

void Direccion::cargar(){

    char aux[20], aux2[10];
    cout<<"Ingrese el nombre y número de la calle: ";
    cargarCadena(aux, 19);
    setCalle(aux);
    cout<<"Ingrese el nombre de la localidad: ";
    cargarCadena(aux, 19);
    setLocalidad(aux);
    cout<<"Ingrese el nombre de la provincia: ";
    cargarCadena(aux, 19);
    setProvincia(aux);
    cout<<"Ingrese el codigo postal: ";
    cargarCadena(aux2, 9);
    setCodigoPostal(aux2);
}

void Direccion::mostrar(){

    setlocale(LC_ALL, "C");
    cout<<"  Calle: "<<getCalle()<<endl;
    cout<<"  Localidad: "<<getLocalidad()<<endl;
    cout<<"  Provincia: "<<getProvincia()<<endl;
    cout<<"  Codigo Postal: "<<getCodigoPostal()<<endl;
    setlocale(LC_ALL, "spanish");

}
