#include <string.h>
#include <iostream>

using namespace std;

#include "Cliente.h"
#include "funciones.h"
#include "rlutil.h"
#include "Graficos.h"

bool Cliente::cargar(){

    setId(mostrarID(1));
    char nombre[40], cuil[11];
    Direccion auxDir;
    Contacto auxCon;
    cout<<"Ingrese el nombre del cliente: ";
    cargarCadena(nombre, 39);
    setNombre(nombre);
    cout<<"Ingrese el apellido del cliente: ";
    cargarCadena(nombre, 39);
    setApellido(nombre);
    cout<<"Ingrese el Cuil o Cuit del cliente (sin guiones): ";
    cin>>cuil;
    setCuil_Cuit(cuil);
    system("cls");
    cout<<"Ingrese el domicilio del cliente: "<<endl;
    auxDir.cargar();
    setDireccion(auxDir);
    system("cls");
    cout<<"Ingrese información de contacto del cliente: "<<endl;
    if(!auxCon.cargar()){
        cout<<"Error en la carga del contacto."<<endl;
        return false;
    }
    setContacto(auxCon);
    system("cls");
    aumentarID(1);

    cout<<"ID del cliente: "<<getId()<<endl;

    cout<<endl;
    cout<<"Registro guardado."<<endl;
    cout<<endl;
    system("pause");
    system("cls");
    return true;

}

void Cliente::mostrarCUIT(const char *cuit){
        int c=0;
        for(int i=0;i<13;i++){
            if(i==2 || i==11){
                cout<<"-";
                c--;
            }else{
                cout<<cuit[c];
            }
            c++;
        }
}

void Cliente::mostrar(int x, int y){

    cuadroClientes(x, y);
    gotoxy(x+1, y+1);
    cout<<getId();
    setlocale(LC_ALL, "C");
    gotoxy(x+6, y+1);
    cout<<getNombre()<<",";
    gotoxy(x+6, y+2);
    cout<<getApellido();
    gotoxy(x+26, y+1);
    mostrarCUIT(getCuil_Cuit());
    gotoxy(x+40, y+1);
    cout<<getDireccion().getCalle()<<", "<<getDireccion().getLocalidad()<<", CP: "<<getDireccion().getCodigoPostal();
    gotoxy(x+40, y+2);
    cout<<getDireccion().getProvincia();
    gotoxy(x+81, y+1);
    cout<<getContacto().getMail();
    gotoxy(x+81, y+2);
    cout<<getContacto().getTelefono();
    gotoxy(x+95, y+1);
    setlocale(LC_ALL, "spanish");

}

void Cliente::listar(){
    int pos=0, x=6, y=3, yi=3;
    cout<<endl<<"      ID  NOMBRE Y APELLIDO    CUIT/CUIL     DOMICILIO                                CONTACTO";
    while(leer(pos)==1){
        pos++;
        mostrar(x, y);
        y+=3;
    }
    cierreCuadroClientes(x, y, yi);
    subirVentana();
}

bool Cliente::modificar(int pos){

    FILE *arc=fopen("Clientes.dat", "rb+");
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

bool Cliente::modificarCliente(){
    char r;
    Direccion auxDir;
    Contacto auxCon;
    int ID, x=5, y=3;
    char nombre[40], cuit[11];
    cout<<"Ingrese el ID del cliente: ";
    cin>>ID;
    if(buscarIDCliente(ID)==-1){
        cout<<endl;
        cout<<"Id inexistente"<<endl;
        return false;
    }
    cout<<endl<<"      ID  NOMBRE Y APELLIDO    CUIT/CUIL     DOMICILIO                                CONTACTO";
    leer(buscarIDCliente(ID));
    mostrar(x, y);
    cierreCuadroClientes(x, y+3, y);
    cout<<endl<<endl<<endl;
    cout<<"¿Desea modificar el nombre? (S/N): ";
    cin>>r;
    if(r=='S' || r=='s'){
        cout<<"Ingrese el nombre nuevamente:"<<endl;
        cargarCadena(nombre, 39);
        setNombre(nombre);
    }
    cout<<endl;
    cout<<"¿Desea modificar el apellido? (S/N): ";
    cin>>r;
    if(r=='S' || r=='s'){
        cout<<"Ingrese el apellido nuevamente:"<<endl;
        cargarCadena(apellido, 39);
        setApellido(apellido);
    }
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
    cout<<"¿Desea modificar el CUIT/CUIL? (S/N): ";
    cin>>r;
    if(r=='S' || r=='s'){
        cout<<"Ingrese el CUIT/CUIL (sin guiones) nuevamente:"<<endl;
        cin>>cuit;
        setCuil_Cuit(cuit);
    }
    cout<<endl;
    if(!modificar(buscarIDCliente(ID))){
        cout<<"Error en la modificación."<<endl;
        return false;
    }
    return true;
}

bool Cliente::grabar(){
    FILE *arc=fopen("Clientes.dat", "ab");
    if(arc==NULL){
        cout<<"Falló en la carga de archivos."<<endl;
        return false;
    }
    fwrite(this, sizeof(*this), 1, arc);
    fclose(arc);
    return true;
}

int Cliente::leer(int pos){
    FILE *arc=fopen("Clientes.dat", "rb");
    if(arc==NULL){
        cout<<"Falló en la carga de archivos."<<endl;
        return -1;
    }
    fseek(arc, sizeof *this*pos,0);
    int leyo=fread(this, sizeof *this,1, arc);
    fclose(arc);
    return leyo;
}

void Cliente::buscarPorID(){
    int  ID, x=6, y=5;
    cout<<"Ingrese el ID del cliente que desea buscar: ";
    cin>>ID;
    cout<<endl;
    if((buscarIDCliente(ID))==-1){
    cout<<"ID Inexistente."<<endl;
    }
    else{
        cout<<endl;
        cout<<"      ID  NOMBRE Y APELLIDO    CUIT/CUIL     DOMICILIO                                CONTACTO";
        int yi=y;
        gotoxy(x, y);
        leer(buscarIDCliente(ID));
        mostrar(x, y);
        y+=3;
        cierreCuadroClientes(x, y, yi);
        cout<<endl;
    }

}

void Cliente::mostrarDireccion(int ID){

    Direccion auxD;

    leer(buscarIDCliente(ID));
    auxD=getDireccion();
    auxD.mostrar();

}
