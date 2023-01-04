#include <string.h>
#include <iostream>

using namespace std;

#include "funciones.h"
#include "PresupuestoRepuesto.h"


bool PresupuestoRepuesto::grabar(){
    FILE *arc=fopen("Presupuestos.dat", "ab");
    if(arc==NULL){
        cout<<"Falló en la carga de archivos."<<endl;
        return false;
    }
    fwrite(this, sizeof(*this), 1, arc);
    fclose(arc);
    return true;
}

int PresupuestoRepuesto::leer(int pos){
    FILE *arc=fopen("Presupuestos.dat", "rb");
    if(arc==NULL){
        cout<<"Falló en la carga de archivos. Archivo aún no generado."<<endl;
        return -1;
    }
    fseek(arc, sizeof *this*pos,0);
    int leyo=fread(this, sizeof *this,1, arc);
    fclose(arc);
    return leyo;
}

void PresupuestoRepuesto::mostrar(){
    cout<<"ID reparación: "<<getIdReparacion()<<endl;
    cout<<"ID repuesto: "<<getIdRe()<<endl;
    cout<<"Categoría: "<<getCatRepuesto()<<endl;
    cout<<"Unidades: "<<getUnidades()<<endl;
    cout<<"Precio Unitario: "<<getPrecio()<<endl;
    cout<<endl;
}
