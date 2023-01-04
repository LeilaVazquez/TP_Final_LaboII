#include <string.h>
#include <iostream>

using namespace std;

#include "Repuesto.h"
#include "funciones.h"
#include "rlutil.h"
#include "rlutil.h"
#include "Graficos.h"

bool Repuesto::alta(){

    int cat;
    setIdRepuesto(mostrarID(3));
    cout<<"ID: "<<getIdRepuesto()<<endl;
    cout<<"Ingrese el nombre: ";
    cargarCadena(nombre, 29);
    cout<<endl;
    cout<<"Ingrese la marca: ";
    cargarCadena(marca, 29);
    cout<<endl;
    cout<<"Ingrese el precio: $";
    cin>>precio;
    if(!setPrecio(precio)){
        cout<<"Precio invalido."<<endl;
        return false;
    }
    cout<<"Categorías:"<<endl;
    cout<<"  1-Plomería"<<endl<<
          "  2-Gas"<<endl<<
          "  3-Electricidad"<<endl<<
          "  4-Refrigeración"<<endl;
    cout<<"Elija la categoría: ";
    cin>>cat;
    if(!setCategoriaRepuesto(cat)){
        cout<<"Número de categoría inválido."<<endl;
        return false;
    }
    aumentarID(3);
    return true;
}

void Repuesto::mostrar(int x, int y){
    cuadroRepuestos(x, y);
    gotoxy(x+1, y+1);
    cout<<getIdRepuesto();
    setlocale(LC_ALL, "C");
    gotoxy(x+5, y+1);
    cout<<getNombre()<<" "<<getMarca();
    setlocale(LC_ALL, "spanish");
    gotoxy(x+46, y+1);
    cout<<"$"<<getPrecio();
}

bool Repuesto::modificar(int pos){

    FILE *arc=fopen("Repuestos.dat", "rb+");
    if(arc==NULL){
        cout<<"Falló en la carga de archivos."<<endl;
        return false;
    }
    fseek(arc, sizeof(*this)*pos,0);
    fwrite(this, sizeof(*this), 1, arc);
    fclose(arc);
    return true;
}

bool Repuesto::baja(){
    int ID, x=4, y=5;
    char r;
    cout<<"Ingrese el ID del repuesto: ";
    cin>>ID;
    if(buscarIDRepuesto(ID)==-1){
        cout<<"Repuesto inexistente."<<endl;
        return false;
    }
    leer(buscarIDRepuesto(ID));
    system("cls");
    mostrar(x, y);
    cierreCuadroRepuestos(x, y+2, y);
    mostrarCategoriaRepuesto(x, y-2, getCategoriaRepuesto());
    cout<<endl;
    cout<<"¿Desea dar de baja el repuesto? (S/N): ";
    cin>>r;
    if(r=='s' || r=='S'){
        setIdRepuesto(0);
        cout<<"Repuesto dado de baja exitosamente"<<endl;
    }
    modificar(buscarIDRepuesto(ID));
    return true;
}

int Repuesto::mostrarRepuestos(int cat, int x, int y){
    int pos=0,
    y_=1;
    gotoxy(x+4, y+y_);
    cout<<"ID   Detalles                           Un. "<<endl;
    while(leer(pos)==1){
        if(cat==getCategoriaRepuesto()&&getIdRepuesto()!=0){
        y++;
        gotoxy(x+4, y+y_);
        cout<<getIdRepuesto();
        gotoxy(x+8, y+y_);
        setlocale(LC_ALL, "C");
        cout<<getNombre()<<" "<<getMarca()<<" $"<<getPrecio()<<endl;
        setlocale(LC_ALL, "spanish");
        }
        pos++;
    }
    return y-1;
}

void Repuesto::mostrarPorCategoria(int cat){
    int pos=0;
    cout<<"  ID   Detalles"<<endl;
    while(leer(pos)==1){
        if(cat==getCategoriaRepuesto()&&getIdRepuesto()!=0){
        cout<<"  "<<getIdRepuesto();
        setlocale(LC_ALL, "C");
        cout<<"      "<<getNombre()<<" "<<getMarca()<<" $"<<getPrecio()<<endl;
        setlocale(LC_ALL, "spanish");
        }
        pos++;
    }
}

void Repuesto::listarRepuestos(){
    int y=4, yi1=y, y2=4, yi2=y2;
    int pos=0;
    while(leer(pos)==1){
        pos++;
        if(getCategoriaRepuesto()==1){
            mostrar(4, y);
            y+=2;
        }
    }
    cierreCuadroRepuestos(4, y, yi1);
    mostrarCategoriaRepuesto(4, yi1-2, 1);

    pos=0;
    while(leer(pos)==1){
        pos++;
        if(getCategoriaRepuesto()==2){
            mostrar(61, y2);
            y2+=2;
        }
    }
    cierreCuadroRepuestos(61, y2, yi2);
    mostrarCategoriaRepuesto(61, yi2-2, 2);

    if(y>=y2)y2=y;
    else y=y2;
    y+=4;
    y2+=4;
    yi1=y;
    yi2=y2;

    pos=0;
    while(leer(pos)==1){
        pos++;
        if(getCategoriaRepuesto()==3){
            mostrar(4, y);
            y+=2;
        }
    }
    cierreCuadroRepuestos(4, y, yi1);
    mostrarCategoriaRepuesto(4, yi1-2, 3);

    pos=0;
    while(leer(pos)==1){
        pos++;
        if(getCategoriaRepuesto()==4){
            mostrar(61, y2);
            y2+=2;
        }
    }
    cierreCuadroRepuestos(61, y2, yi2);
    mostrarCategoriaRepuesto(61, yi2-2, 4);
    subirVentana();
}

bool Repuesto::grabar(){
    FILE *arc=fopen("Repuestos.dat", "ab");
    if(arc==NULL){
        cout<<"Falló en la carga de archivos."<<endl;
        return false;
    }
    fwrite(this, sizeof(*this), 1, arc);
    fclose(arc);
    return true;
}

int Repuesto::leer(int pos){
    FILE *arc=fopen("Repuestos.dat", "rb");
    if(arc==NULL){
        cout<<"Falló en la carga de archivos."<<endl;
        return -1;
    }
    fseek(arc, sizeof *this*pos,0);
    int leyo=fread(this, sizeof *this,1, arc);
    fclose(arc);
    return leyo;
}

bool Repuesto::modificarRepuesto(){

    char r;
    int ID,cat, x=4, y=5;
    cout<<"Ingrese el ID del repuesto: ";
    cin>>ID;
    if(buscarIDRepuesto(ID)==-1){
        cout<<endl;
        cout<<"Id inexistente"<<endl;
        return false;
    }
    leer(buscarIDRepuesto(ID));
    mostrar(x, y);
    cierreCuadroRepuestos(x, y+2, y);
    mostrarCategoriaRepuesto(x, y-2, getCategoriaRepuesto());
    cout<<"¿Desea modificar el nombre? (S/N): ";
    cin>>r;
    if(r=='S' || r=='s'){
        cout<<"Ingrese el nombre: "<<endl;
        cargarCadena(nombre, 29);
        cout<<endl;
        cout<<"Se modificó el nombre"<<endl;
    }
    cout<<endl;
    cout<<"¿Desea modificar la marca? (S/N): ";
    cin>>r;
    if(r=='S' || r=='s'){
        cout<<"Ingrese la marca: "<<endl;
        cargarCadena(marca, 29);
        cout<<"Se modificó la marca"<<endl;
    }
    cout<<endl;
    cout<<"¿Desea modificar el precio? (S/N): ";
    cin>>r;
    if(r=='S' || r=='s'){
    cout<<"Ingrese el precio: $";
    cin>>precio;
        if(!setPrecio(precio)){
            cout<<"Precio invalido."<<endl;
            return false;
        }
    cout<<"Se modificó el precio"<<endl;
    }
    cout<<endl;
    cout<<"¿Desea modificar la categoría? (S/N): ";
    cin>>r;
    if(r=='S' || r=='s'){
    cout<<endl;
    cout<<"Categorías:"<<endl;
    cout<<"  1-Plomería"<<endl<<
          "  2-Electricidad"<<endl<<
          "  3-Gas"<<endl<<
          "  4-Refrigeración"<<endl;
    cout<<"Elija la categoría: ";
    cin>>cat;
        if(!setCategoriaRepuesto(cat)){
            cout<<"Número de categoría inválido."<<endl;
            return false;
        }
    cout<<"Se modificó la categoría"<<endl;
    }
    cout<<endl;
    if(!modificar(buscarIDRepuesto(ID))){
        cout<<"Error en la modificación."<<endl;
        return false;
    }
    return true;
}

void Repuesto::buscarPorID(){
    int  ID, x=3, y=5;
    cout<<"Ingrese el ID de la reparación que desea buscar: ";
    cin>>ID;
    cout<<endl;
    if((buscarIDRepuesto(ID))==-1){
    cout<<"ID Inexistente."<<endl;
    }
    else{
        leer(buscarIDRepuesto(ID));
        mostrar(x, y);
        cierreCuadroRepuestos(x, y+2, y);
        mostrarCategoriaRepuesto(x, y-2, getCategoriaRepuesto());
    }
}
