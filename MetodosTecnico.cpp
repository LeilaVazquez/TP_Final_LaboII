#include <string.h>
#include <iostream>

using namespace std;

#include "Tecnico.h"
#include "funciones.h"
#include "rlutil.h"
#include "Graficos.h"

bool Tecnico::cargar(){

    char nombre[40];
    Direccion auxDir;
    Contacto auxCon;
    CategoriaTecnico cat;
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
    setContacto(auxCon);
    system("cls");
    cout<<"INFORMACIÓN TÉCNICA"<<endl;
    setId(mostrarID(0));
    cout<<"ID del técnico: "<<getId()<<endl;
    cat.cargar();
    setCategoria(cat);
    if(cat.getTipo()=='0'){
        cout<<"Error en la carga de categoría."<<endl;
        return false;
    }
    setContratado(true);
    aumentarID(0);
    return true;

}

void Tecnico::mostrar(int x, int y){

    cuadroTecnicos(x, y);
    gotoxy(x+1, y+1);
    cout<<getId();
    setlocale(LC_ALL, "C");
    gotoxy(x+6, y+1);
    cout<<getNombre()<<",";
    gotoxy(x+6, y+2);
    cout<<getApellido();
    setlocale(LC_ALL, "spanish");
    gotoxy(x+26, y+1);
    cout<<getCategoria().getTipo();
    gotoxy(x+28, y+1);
    setlocale(LC_ALL, "C");
    cout<<getDireccion().getCalle()<<", "<<getDireccion().getLocalidad()<<", CP: "<<getDireccion().getCodigoPostal();
    gotoxy(x+28, y+2);
    cout<<getDireccion().getProvincia();
    setlocale(LC_ALL,"spanish");
    gotoxy(x+70, y+1);
    cout<<getContacto().getMail();
    gotoxy(x+70, y+2);
    cout<<getContacto().getTelefono();
    gotoxy(x+95, y+1);
    if(getContratado())cout<<"Activo";
    else cout<<"Inactivo";
}

void Tecnico::listar(){
    int pos=0, x=7, y=1, yi;
    gotoxy(x, y);
    cout<<" ID  NOMBRE Y APELLIDO   CAT DOMICILIO                               CONTACTO                  ESTADO";
    y++;
    yi=y;
    while(leer(pos)==1){
        pos++;
        mostrar(x, y);
        y+=3;
    }
    cierreCuadroTecnicos(x, y, yi);
    subirVentana();
}

bool Tecnico::modificar(int pos){

    FILE *arc=fopen("Tecnicos.dat", "rb+");
    if(arc==NULL){
        cout<<"Falló en la carga de archivos."<<endl;
        return false;
    }
    fseek(arc, sizeof(*this)*pos,0);
    fwrite(this, sizeof(*this), 1, arc);
    cout<<"Registro modificado."<<endl;
    fclose(arc);
    return true;
}

bool Tecnico::modificarTecnico(){
    Direccion auxDir;
    Contacto auxCon;
    CategoriaTecnico auxCat;
    char r;
    int ID, x=7, y=1;
    cout<<"Ingrese el ID del Técnico: ";
    cin>>ID;
    if(buscarIDTecnico(ID)==-1){
        cout<<endl;
        cout<<"Id inexistente"<<endl;
        return false;
    }
    leer(buscarIDTecnico(ID));
    if(!getContratado()){
        cout<<"Técnico inactivo."<<endl;
        return false;
    }
    system("cls");
    gotoxy(x, y);
    cout<<" ID  NOMBRE Y APELLIDO   CAT DOMICILIO                               CONTACTO                  ESTADO";
    y++;
    int yi=y;
    mostrar(x, y);
    y+=3;
    cierreCuadroTecnicos(x, y, yi);
    cout<<endl;
    cout<<"¿Desea modificar el domicilio? (S/N): ";
    cin>>r;
    if(r=='S' || r=='s'){
        auxDir.cargar();
        setDireccion(auxDir);
        cout<<"Se modificó el domicilio"<<endl;
    }
    cout<<endl;
    cout<<"¿Desea modificar el contacto? (S/N): ";
    cin>>r;
    if(r=='S' || r=='s'){
        if(!auxCon.cargar()){
            cout<<"Error en la carga del contacto."<<endl;
            return false;
        }
        setContacto(auxCon);
        cout<<"Se modificó el contacto"<<endl;
    }
    cout<<endl;
    cout<<"¿Desea modificar la categoría? (S/N): ";
    cin>>r;
    if(r=='S' || r=='s'){
        if(!auxCat.cargar()){
            cout<<"Error en la carga de la categoría.";
            return false;
        }
        setCategoria(auxCat);
        cout<<"Se modificó la categoría."<<endl;
    }
    cout<<endl;
    if(!modificar(buscarIDTecnico(ID))){
        cout<<"Error en la modificación."<<endl;
        return false;
    }
    return true;
}

bool Tecnico::actualizarEstado(){
    int ID, x=7, y=1;
    char r;
    cout<<"Ingrese el ID del Técnico: ";
    cin>>ID;
    if(buscarIDTecnico(ID)==-1){
        cout<<endl;
        cout<<"Id inexistente"<<endl;
        return false;
    }
    leer(buscarIDTecnico(ID));
    system("cls");
    gotoxy(x, y);
    cout<<" ID  NOMBRE Y APELLIDO   CAT DOMICILIO                               CONTACTO                  ESTADO";
    y++;
    int yi=y;
    mostrar(x, y);
    y+=3;
    cierreCuadroTecnicos(x, y, yi);
    cout<<endl;
    cout<<"¿Desea cambiar el estado del técnico? (S/N)";
    cin>>r;
    if(r=='S' || r=='s'){
        setContratado(!getContratado());
    }
    cout<<endl;
    if(!modificar(buscarIDTecnico(ID))){
        cout<<"Error en la modificación."<<endl;
        return false;
    }
    return true;
}

bool Tecnico::grabar(){
    FILE *arc=fopen("Tecnicos.dat", "ab");
    if(arc==NULL){
        cout<<"Falló en la carga de archivos."<<endl;
        return false;
    }
    fwrite(this, sizeof(*this), 1, arc);
    fclose(arc);
    return true;
}

int Tecnico::leer(int pos){
    FILE *arc=fopen("Tecnicos.dat", "rb");
    if(arc==NULL){
        cout<<"Falló en la carga de archivos."<<endl;
        return -1;
    }
    fseek(arc, sizeof *this*pos,0);
    int leyo=fread(this, sizeof *this,1, arc);
    fclose(arc);
    return leyo;
}

void Tecnico::buscarPorID(){
    int  ID, x=7, y=4;
    cout<<"Ingrese el ID del cliente que desea buscar: ";
    cin>>ID;
    cout<<endl;
    if((buscarIDTecnico(ID))==-1){
    cout<<"ID Inexistente."<<endl;
    }
    else{
        gotoxy(x, y);
        cout<<" ID  NOMBRE Y APELLIDO   CAT DOMICILIO                               CONTACTO                  ESTADO";
        y++;
        int yi=y;
        leer(buscarIDTecnico(ID));
        mostrar(x, y);
        y+=3;
        cierreCuadroTecnicos(x, y, yi);
        cout<<endl;
    }
}
