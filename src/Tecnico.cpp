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
    cout<<"Ingrese el nombre del t�cnico: ";
    cargarCadena(nombre, 39);
    setNombre(nombre);
    cout<<"Ingrese el apellido del t�cnico: ";
    cargarCadena(nombre, 39);
    setApellido(nombre);
    system("cls");
    cout<<"Ingrese el domicilio del t�cnico: "<<endl;
    auxDir.cargar();
    setDireccion(auxDir);
    system("cls");
    cout<<"Ingrese informaci�n de contacto del t�cnico: "<<endl;
    if(!auxCon.cargar()){
        cout<<"Error en la carga del contacto."<<endl;
        return false;
    }
    ///setContacto(auxCon);
    system("cls");
    cout<<"INFORMACI�N T�CNICA"<<endl;
    ///Autonum�rico
    ///cout<<"ID del t�cnico: "<<getId()<<endl;
    ///Listado de la especialdiades
    cout<<"Ingrese la especialidad del t�cnico: ";
    cargarCadena(nombre, 29);
    setEspecialidad(nombre);
    ///Listado de las categorias
    cout<<"Ingrese la categoria del t�cnico: ";
    cin>>aux;
    setContratado(true);
    return true;

}

void Tecnico::mostrar(){



}
