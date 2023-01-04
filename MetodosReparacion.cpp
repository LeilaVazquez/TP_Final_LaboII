#include <string.h>
#include <iostream>

using namespace std;

#include "funciones.h"
#include "Reparacion.h"
#include "Repuesto.h"
#include "Tecnico.h"
#include "Cliente.h"
#include "PresupuestoRepuesto.h"
#include "rlutil.h"
#include "Graficos.h"

bool Reparacion::grabar(){
    FILE *arc=fopen("Reparaciones.dat", "ab");
    if(arc==NULL){
        cout<<"Falló en la carga de archivos."<<endl;
        return false;
    }
    fwrite(this, sizeof(*this), 1, arc);
    fclose(arc);
    return true;
}

int Reparacion::leer(int pos){
    FILE *arc=fopen("Reparaciones.dat", "rb");
    if(arc==NULL){
        cout<<"Falló en la carga de archivos."<<endl;
        return -1;
    }
    fseek(arc, sizeof *this*pos,0);
    int leyo=fread(this, sizeof *this,1, arc);
    fclose(arc);
    return leyo;
}

bool Reparacion::modificar(int pos){

    FILE *arc=fopen("Reparaciones.dat", "rb+");
    if(arc==NULL){
        cout<<"Falló en la carga de archivos."<<endl;
        return false;
    }
    fseek(arc, sizeof(*this)*pos,0);
    fwrite(this, sizeof(*this), 1, arc);
    cout<<endl;
    cout<<"Registro modificado."<<endl;
    cout<<endl;
    fclose(arc);
    return true;
}


const char* Reparacion::mostrarEstado(int n){

    const char* Abierta="Abierta";
    const char* Cerrada="Cerrada";
    const char* En_Curso="En Curso";
    const char* Susp="Suspendida";
    const char* Canc="Cancelada";

    const char* vec[5];
    vec[0]=Abierta;
    vec[1]=Cerrada;
    vec[2]=En_Curso;
    vec[3]=Susp;
    vec[4]=Canc;

    const char* retorno=vec[n-1];
    return retorno;

}

bool Reparacion::cargar(){

    int idC;
    setIdReparacion(mostrarID(2));
    Fecha aux;
    cout<<"ID: "<<getIdReparacion()<<endl;
    cout<<"Ingrese la fecha de alta de la reparación: "<<endl;
    aux.cargar();
    setFecha(aux);
    cout<<"Ingrese el ID del cliente: ";
    cin>>idC;
    setIdCliente(idC);
    if(buscarIDCliente(idC)==-1){
        cout<<"Id inexistente"<<endl;
        return false;
    }
    setEstado(1);
    setIdTecnico(0);
    setPresupuesto(0);
    setTiempoReparacion(0.f);
    setObservaciones("  ");
    cout<<"Categorías:"<<endl;
    cout<<"  1-Plomería"<<endl<<
          "  2-Gas"<<endl<<
          "  3-Electricidad"<<endl<<
          "  4-Refrigeración"<<endl;
    cout<<"Elija la categoría: ";
    cin>>idC;
    if(!setCategoriaReparacion(idC)){
        cout<<"Número de categoría inválido."<<endl;
        return false;
    }
    aumentarID(2);
    return true;

}


bool Reparacion::actualizarEstado(){
    int idR;
    int pos;
    cout<<"Ingrese el ID de la reparación: ";
    cin>>idR;
    if(buscarIDReparacion(idR)==-1){
        cout<<"Id inexistente"<<endl;
        return false;
    }
    cout<<endl;
    pos=buscarIDReparacion(idR);
    leer(pos);
    cout<<"Estado actual:"<<mostrarEstado(getEstado());
    cout<<endl;
    int est;
    cout<<"Estados:"<<endl;
    cout<<"  1-Abierta"<<endl;
    cout<<"  2-Cerrada"<<endl;
    cout<<"  3-En Curso"<<endl;
    cout<<"  4-Supendida"<<endl;
    cout<<"  5-Cancelada"<<endl;
    cout<<"Ingrese el nuevo estado de la reparación: ";
    cin>>est;
    if(!setEstado(est)){
        cout<<"Número de Estado inválido."<<endl;
        return false;
    }
    system("cls");
    cout<<"Estado actualizado: "<<mostrarEstado(getEstado())<<endl;
    modificar(pos);
    return true;
}

bool Reparacion::gestionar(){

    int ID, idR;
    Repuesto aux;
    Tecnico auxTec;
    float importe=0, horas;
    char r;
    cout<<"Ingrese el ID reparación: "<<endl;
    cin>>idR;
    if(buscarIDReparacion(idR)==-1){
        cout<<endl;
        cout<<"Id inexistente"<<endl;
        return false;
    }
    leer(buscarIDReparacion(idR));
    if(getEstado()== 2 || getEstado()==4 || getEstado()==5){
        cout<<" Reparación no disponible para modificaciones"<<endl;
        return false;
    }
    mostrar(3, 3);
    cout<<endl<<endl<<endl;
    cout<<"¿Desea modificar el técnico asignado? (S/N): ";
    cin>>r;
    if(r=='S' || r=='s'){
        cout<<"Ingrese el ID del Técnico: "<<endl;
    cin>>ID;
    if(buscarIDTecnico(ID)==-1){
        cout<<"Id inexistente"<<endl;
        return false;
    }
    auxTec.leer(buscarIDTecnico(ID));
    if(!auxTec.getContratado()){
        cout<<"Técnico inactivo."<<endl;
        return false;
    }

    if(auxTec.getCategoria().getTipo()!=char(getCategoriaReparacion()+64)){
            cout<<"El técnico seleccionado no pertenece a la categoria de reparación"<<endl;
            return false;
    }
    setIdTecnico(ID);
    }
    cout<<"¿Desea modificar la cantidad de horas de reparación? (S/N): ";
    cin>>r;
    if(r=='S' || r=='s'){
        cout<<"Ingrese el tiempo de reparación en horas: ";
    cin>>horas;
    if(!setTiempoReparacion(horas)){
        cout<<"Tiempo de reparación inválido."<<endl;
        return false;
    }
    }
    system("cls");
    cout<<"¿Desea agregar repuestos? (S/N): ";
    cin>>r;
    if(r=='S' || r=='s'){
        seleccionarRepuesto(aux.mostrarRepuestos(getCategoriaReparacion(), 0, 1), getCategoriaReparacion(), 0, 1, idR);
    }
    importe+=calcularPresupuestoRepuesto(idR);
    cout<<endl<<endl;
    importe+=calcularPresupuestoTecnico(getIdTecnico(), getTiempoReparacion());
    cout<<"Presupuesto: $";
    setPresupuesto(importe);
    cout<<getPresupuesto();
    cout<<endl;
    cout<<"¿Desea agregar alguna observación? (S/N): ";
    cin>>r;
    if(r=='S' || r=='s'){
        cout<<"Observación: ";
        cargarCadena(observaciones, 99);
    }
    cout<<"Estado actual:"<<mostrarEstado(getEstado());
    cout<<endl;
    modificar(buscarIDReparacion(idR));
    return true;
}

void Reparacion::mostrar(int x, int y){

    Tecnico aux1;
    Cliente auxC;

    cuadroReparaciones(x, y+1);
    gotoxy(x, y);
    setlocale(LC_ALL,"spanish");
    cout<<" ID  Técnico              Cliente              Domicilio                                Categoría     Estado";
    gotoxy(x+1, y+5);
    cout<<"Observaciones:";
    gotoxy(x+77, y+5);
    cout<<"Presupuesto: ";
    gotoxy(x+93, y+5);
    cout<<"Fecha: ";
    gotoxy(x+93, y+6);
    cout<<"Tpo Rep: ";
    gotoxy(x+1, y+2);
    cout<<getIdReparacion();
    gotoxy(x+5, y+2);
    if(getIdTecnico()==0){
        cout<<"Aún no asignado.";
    }
    else{
        setlocale(LC_ALL,"C");
        aux1.leer(buscarIDTecnico(getIdTecnico()));
        cout<<aux1.getNombre()<<",";
        gotoxy(x+5, y+3);
        cout<<aux1.getApellido()<<" ID: "<<aux1.getId();
    }
    setlocale(LC_ALL, "C");
    auxC.leer(buscarIDCliente(getIdCliente()));
    gotoxy(x+26, y+2);
    cout<<auxC.getNombre()<<",";
    gotoxy(x+26, y+3);
    cout<<auxC.getApellido()<<" ID: "<<auxC.getId();
    gotoxy(x+47, y+2);
    cout<<auxC.getDireccion().getCalle()<<", "<<auxC.getDireccion().getLocalidad()<<", CP: "<<auxC.getDireccion().getCodigoPostal();
    gotoxy(x+47, y+3);
    cout<<auxC.getDireccion().getProvincia();
    gotoxy(x+88, y+2);
    setlocale(LC_ALL, "spanish");
    mostrarCategoria(getCategoriaReparacion());
    gotoxy(x+102, y+2);
    cout<<mostrarEstado(getEstado());
    setlocale(LC_ALL,"C");
    escribirEnRenglones(getObservacion(), 60, 100, x+16, y+5);
    gotoxy(x+77, y+6);
    cout<<"$"<<getPresupuesto();
    gotoxy(x+100, y+5);
    getFecha().mostrar();
    gotoxy(x+102, y+6);
    cout<<getTiempoReparacion()<<" Horas";
    setlocale(LC_ALL, "spanish");
}

void Reparacion::listar(){
    int pos=0, y=2;
    while(leer(pos)==1){
    mostrar(3, y);
    y+=10;
    pos++;
    }
    subirVentana();
}

void Reparacion::buscarPorID(){
    int  id;
    cout<<"Ingrese el ID de la reparación que desea buscar: "<<endl;
    cin>>id;
    cout<<endl;
    if((buscarIDReparacion(id))==-1){
    cout<<"ID Inexistente."<<endl;
    }
    else{
        leer(buscarIDReparacion(id));
        mostrar(3, 3);
        subirVentana();
    }

}
