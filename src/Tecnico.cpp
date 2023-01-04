#include "Tecnico.h"

void Tecnico::cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0;i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
        }
    pal[i]='\0';
    fflush(stdin);
}

bool Tecnico::cargar(){

    int aux;
    char nombre[40];
    Direccion auxDir;
    Contacto auxCon;
    cout<<"Ingrese el nombre del técnico: ";
    cargarCadena(nombre, 39);
    setNombre(nombre);
    cout<<"Ingrese el apellido del técnico: ";
    cargarCadena(nombre, 39);
    setApellido(nombre);
    system("cls");
    cout<<"Ingrese el domicilio del técnico: "<<endl;
    auxDir.cargar();
    setDireccion(auxDir);
    system("cls");
    cout<<"Ingrese información de contacto del técnico: "<<endl;
    if(!auxCon.cargar()){
        cout<<"Error en la carga del contacto."<<endl;
        return false;
    }
    ///setContacto(auxCon);
    system("cls");
    cout<<"INFORMACIÓN TÉCNICA"<<endl;
    ///Autonumérico
    ///cout<<"ID del técnico: "<<getId()<<endl;
    ///Listado de la especialdiades
    cout<<"Ingrese la especialidad del técnico: ";
    cargarCadena(nombre, 29);
    setEspecialidad(nombre);
    ///Listado de las categorias
    cout<<"Ingrese la categoria del técnico: ";
    cin>>aux;
    setContratado(true);
    return true;

}

void Tecnico::mostrar(){



}
