#include "Direccion.h"


void Direccion::cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0;i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
        }
    pal[i]='\0';
    fflush(stdin);
}

void Direccion::cargar(){

    char aux[20], aux2[10];
    cout<<"Ingrese el nombre de la calle: ";
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

    cout<<"Calle: "<<getCalle()<<endl;
    cout<<"Localidad: "<<getLocalidad()<<endl;
    cout<<"Provincia: "<<getProvincia()<<endl;
    cout<<"Codigo Postal: "<<getCodigoPostal()<<endl;

}
