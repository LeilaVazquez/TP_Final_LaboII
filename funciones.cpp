#include "funciones.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctime>
#include <string>
#include <windows.h>
#include <ctype.h>
#include "rlutil.h"
#include <MMSystem.h>
#include <cstdlib>
#include <clocale>
#include <cstring>

using namespace std;

#include "Reparacion.h"
#include "Cliente.h"
#include "Repuesto.h"
#include "Tecnico.h"
#include "PresupuestoRepuesto.h"
#include "Graficos.h"


bool arroba(char correo[]){ ///validacion de email de contacto con @
    int c=0;
    while(correo[c]!='\0'){
        if(correo[c]=='@'){
            return true;
        }
        c++;
    }
    return false;
}

void ponerVectorVacio(char v[], int tam){
    for(int i=0;i<tam;i++){
        v[i]=' ';
    }
}

void ponerMatrizCero(float v[][3], int tam, int tam2, int cat){
    Repuesto aux;
    int pos=0, i=0;
    while(aux.leer(pos)==1){
        if(aux.getIdRepuesto()!=0 && aux.getCategoriaRepuesto()==cat){
            v[i][0]=float(aux.getIdRepuesto());
            v[i][1]=0.f;
            v[i][2]=aux.getPrecio();
            i++;
        }
        pos++;
    }
}

void mostrarMatriz(float v[][3], int tam, int tam2){ ///muestra matriz de presupuesto
    for(int i=0;i<tam;i++){
        for(int j=0;j<tam2;j++){
            cout<<v[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0;i<tam;i++){
        pal[i]=std::cin.get();
        if(pal[i]=='\n') break;
        }
    pal[i]='\0';
    fflush(stdin);
}

bool setteoContador(){ ///inicializa los contadores autonumericos
    int cont=1;
    FILE *arc=fopen("Contador.dat", "rb");      ///si esta creado lo lee
    if(arc==NULL){
        arc=fopen("Contador.dat", "ab");        ///sino lo crea
        if(arc==NULL){
            cout<<"No funciono"<<endl;
            return false;
        }
        fwrite(&cont, sizeof(cont),1,arc);
        fseek(arc, (sizeof(cont)*1), 0);       ///se desplaza un registro
        fwrite(&cont, sizeof(cont), 1, arc);
        fseek(arc, (sizeof(cont)*2), 0);       ///se desplaza 2
        fwrite(&cont, sizeof(cont), 1, arc);
        fseek(arc, (sizeof(cont)*3), 0);
        fwrite(&cont, sizeof(cont), 1, arc);
    }
    fclose(arc);
    return true;
}

void subirVentana(){
    gotoxy(119, 1);
    rlutil::setColor(0);
    cout<<".";
    rlutil::setColor(1);
}

void mostrarCategoria(int numero){
    if(numero==1)cout<<"Plomería";
    if(numero==2)cout<<"Gas";
    if(numero==3)cout<<"Electricidad";
    if(numero==4)cout<<"Refrigeración";
}

int sacarUltimaPalabra(const char*cadena, int tam){
    while(cadena[tam]!=' ' && tam!=-1)tam--;
    return tam+1;
}

void escribirEnRenglones(const char*cadena, int ancho, int tam, int x, int y){
    int conT=0, conP=0;
    gotoxy(x, y);
    for(int i=0;i<tam;i++){
        if(cadena[i]=='\n')break;
        if(cadena[i]!=' ')conP++;
        else if(cadena[i]==' '){
            conT+=conP+1;
            if(conT<=ancho){
                for(int j=i-conP;j<conP+i-1;j++){
                    if(cadena[j]==' ')break;
                    cout<<cadena[j];
                }
                cout<<" ";
            }
            else{
                y++;
                gotoxy(x, y);
                for(int j=i-conP;j<conP+i-1;j++){
                    if(cadena[j]==' ')break;
                    cout<<cadena[j];
                }
                cout<<" ";
                conT=conP;
            }
            conP=0;
        }
    }
    int pos=sacarUltimaPalabra(cadena, tam);
    for(int j=pos;j<tam;j++){
        if(cadena[j]=='\0')break;
        cout<<cadena[j];
    }
}

void aumentarID(int pos){ ///recibe la posicion para usarla como desplazamiento
  FILE *arc;
  int con;
  arc=fopen("Contador.dat", "rb+");
  fseek(arc, sizeof(con)*pos, 0);
  fread(&con, sizeof(con), 1, arc);
  con++;
  fseek(arc, ftell(arc)-sizeof(con), 0);
  fwrite(&con, sizeof(con), 1, arc);
  fclose(arc);
}

int mostrarID(int pos){
  FILE *arc;
  int con;
  arc=fopen("Contador.dat", "rb");
  fseek(arc, sizeof(con)*pos, 0);
  fread(&con, sizeof(con), 1, arc);
  fclose(arc);
  return con;
}

int buscarIDTecnico(int ID){
    int cont=0;
        Tecnico aux;
        while(aux.leer(cont)==1){
        if(ID==aux.getId()){
            return cont;
        }
        cont++;
    }
    return -1;
}

int buscarIDCliente(int ID){
    int cont=0;
        Cliente aux;
        while(aux.leer(cont)==1){
        if(ID==aux.getId()){
            return cont;
        }
        cont++;
    }
    return -1;

}

int buscarIDReparacion(int ID){
    int cont=0;
    Reparacion aux2;
        while(aux2.leer(cont)==1){
            if(ID==aux2.getIdReparacion()){
                    return cont;
            }
            cont++;
        }
        return -1;
}

int buscarIDRepuesto(int ID){
    int cont=0;
    Repuesto aux3;
        while(aux3.leer(cont)==1){
        if(ID==aux3.getIdRepuesto()){
            return cont;
        }
        cont++;
    }
    return -1;
}

void mostrarTabla(int x, int y, int s, int c, char selector[], float cantidad[][3], int cat){
    Repuesto aux;
    for(int i=0;i<c;i++){
        gotoxy(x+2, y+s+2);
        cout<<selector[s]<<endl;
    }
    for(int i=0;i<c;i++){     ///for para la columna de unidades
        gotoxy(x+45, y+i+2);
        cout<<cantidad[i][1]<<endl;
    }
    aux.mostrarRepuestos(cat, x, y);
    gotoxy(x+6, y+2+c);
    cout<<"Finalizar";
}

void setearCantidad(int c, int cat, int idReparacion, float cantidad[][3]){
    PresupuestoRepuesto auxPre;
    auxPre.setIdReparacion(idReparacion);
    auxPre.setCatRepuesto(cat);
    for(int i=0;i<c;i++){
    if(cantidad[i][1]!=0){
        auxPre.setIdRep(cantidad[i][0]);
        auxPre.setUnidades(cantidad[i][1]);
        auxPre.setPrecio(cantidad[i][2]);
        auxPre.grabar();
        }
    }
}

int seleccionarRepuesto(int c, int cat, int x, int y, int idReparacion){
        int s=0;
        char *selector;             ///vector dinámico para la flecha
        selector=new char[c];
        if(selector==NULL){
            cout<<"Error."<<endl;
            return -1;
        }
        float (*cantidad)[3];       ///matriz dinámica para los repuestos ( muestra cantidad y precio)
        cantidad=new float [c][3];
        if(cantidad==NULL){
            cout<<"Error."<<endl;
            delete selector;
            return -1;
        }
        ponerVectorVacio(selector, c);
        ponerMatrizCero(cantidad, c, 3, cat);
        while(true){
            system("cls");
            rectangle2(55,3,50,9);           ///movimiento flecha
            selector[s]=char(16);
            mostrarTabla(x, y, s, c, selector, cantidad, cat);
            selector[s]=' ';
            int k=rlutil::getkey();
            if(k==rlutil::KEY_UP)s--;
            else if(k==rlutil::KEY_DOWN)s++;
            if(s==-1) s=c;
            if(s==c+1) s=0;
            if(k==rlutil::KEY_ENTER){
                if(s==c){
                  /// finaliza y setea la seleccion
                    setearCantidad(c, cat, idReparacion, cantidad);
                    break;
                }
                else{
                    cantidad[s][1]=0;
                    system("cls");
                    rectangle2(55,3,50,9);
                    mostrarTabla(x, y, s, c, selector, cantidad, cat);
                    gotoxy(x+45, y+s+2);
                    cin>>cantidad[s][1];
                }
            }
        }
        delete cantidad;
        delete selector;
        return 1;
}

float calcularPresupuestoRepuesto(int idR){ ///calcula que el presupuesto segun los repuestos
    int pos=0;
    float presupuesto=0;
    PresupuestoRepuesto auxPre;
    while(auxPre.leer(pos)==1){
        if(auxPre.getIdReparacion()==idR){
            presupuesto+=auxPre.getUnidades()*auxPre.getPrecio();
        }
        pos++;
    }
    return presupuesto;
}

float calcularPresupuestoTecnico(int ID, float horas){ ///calcula el presupuesto segun el tecnico
    int pos=0;
    Tecnico aux;
    while(aux.leer(pos)==1){
        if(aux.getId()==ID){
            return horas*aux.getCategoria().getPrecio();
        }
        pos++;
    }
    return 0;
}

char pasarAmayusc(char &cat){

    if(cat>96 && cat<123)cat-=32;
    return cat;

}

void filtrarTecnicoCat(){ ///filtra solo los activos
    Tecnico auxT;
    char cat;
    int pos=0, y=10;
    bool bandera;
    cout<<" CATEGORÍAS"<<endl;
    cout<<"  A - Plomero"<<endl;
    cout<<"  B - Gasista"<<endl;
    cout<<"  C - Electricista"<<endl;
    cout<<"  D - Frigorista"<<endl<<endl;
    cout<<"Ingrese la categoria que desea filtrar: ";
    cin>>cat;
    pasarAmayusc(cat);
    while(auxT.leer(pos)==1){
        if(cat==auxT.getCategoria().getTipo()){
        auxT.mostrar(7, y);
        bandera=true;
        y+=3;
        }
    pos++;
    }
    if(!bandera)cout<<"No hay técnicos con la categoría "<<cat<<endl;
    else cierreCuadroTecnicos(7, y, 10);
    subirVentana();
}

void filtrarTecnicoEstado(){
    Tecnico auxT;
    bool estado, bandera=false;
    int pos=0, y=8;
    cout<<" ESTADOS"<<endl;
    cout<<"1. Activo"<<endl;
    cout<<"0. Inactivo"<<endl;
    cout<<"Ingrese el estado que desea filtrar: ";
    cin>>estado;
    cout<<endl;
    if(estado){
        cout<<"Técnicos con el estado Activo "<<endl;
    }else{
    cout<<"Tecnicos con el estado Inactivo "<<endl;

    }
    while(auxT.leer(pos)==1){
        pos++;
        if(estado==auxT.getContratado()){
            auxT.mostrar(7, y);
            y+=3;
            bandera=true;
        }
    }
    if(!bandera)cout<<"No hat técnicos en el estado elegido.";
    else cierreCuadroTecnicos(7, y, 8);
    subirVentana();
}

bool buscarMenor(float monto){
    Reparacion auxR;
    int pos=0, y=10;
    bool bandera=false;
    while(auxR.leer(pos)==1){
        pos++;
        if(auxR.getPresupuesto()<=monto){
            bandera=true;
            auxR.mostrar(3, y);
            y+=10;
            }
        }
        return bandera;
}

bool buscarMayor(float monto){
    Reparacion auxR;
    int pos=0, y=10;
    bool bandera=false;
    while(auxR.leer(pos)==1){
        pos++;
        if(auxR.getPresupuesto()>=monto){
            bandera=true;
            auxR.mostrar(3, y);
            y+=10;
            }
        }
        return bandera;
}

bool buscarEntre(float monto, float monto2){

    Reparacion auxR;
    int pos=0, y=12;
    bool bandera=false;
    while(auxR.leer(pos)==1){
        pos++;
        if(auxR.getPresupuesto()>=monto && auxR.getPresupuesto()<=monto2){
            bandera=true;
            auxR.mostrar(3, y);
            y+=10;
            }
        }
        return bandera;
}

void filtrarRepaPresup(){
    float monto=0, monto2=0;
    int opc;
    cout<<"Ingrese la opcion de búsqueda: "<<endl;
    cout<<"  1.Menor o igual que "<<endl;
    cout<<"  2.Mayor o igual que "<<endl;
    cout<<"  3.Entre que y que "<<endl;
    cin>>opc;
    switch(opc){
    case 1:
        cout<<"MENOR O IGUAL QUE  "<<endl;
        cout<<"Ingrese el monto: "<<endl;
        cout<<" $ ";
        cin>>monto;
        if(!buscarMenor(monto)) cout<<"No hay reparaciones con ese criterio de búsqueda"<<endl;
        break;
    case 2:
        cout<<"MAYOR O IGUAL QUE  "<<endl;
        cout<<"Ingrese el monto: "<<endl;
        cout<<" $ ";
        cin>>monto;
        if(!buscarMayor(monto)) cout<<"No hay reparaciones con ese criterio de búsqueda"<<endl;
        break;
    case 3:
        cout<<"ENTRE  "<<endl;
        cout<<"Ingrese el monto menor: "<<endl;
        cout<<" $ ";
        cin>>monto;
        cout<<"Ingrese el monto mayor: "<<endl;
        cout<<" $ ";
        cin>>monto2;
        if(!buscarEntre(monto,monto2)) cout<<"No hay reparaciones con ese criterio de búsqueda"<<endl;
        break;
    default :
        cout<<"Opción incorrecta"<<endl;
        break;
    }
    subirVentana();
}

bool buscarMenorTiempo(float tiempo){
    bool bandera=false;
    Reparacion auxR;
    int pos=0, y=10;
    while(auxR.leer(pos)==1){
        pos++;
        if(auxR.getTiempoReparacion()<=tiempo){
            auxR.mostrar(3, y);
            bandera=true;
            y+=10;
        }
    }
    return bandera;
}

bool buscarMayorTiempo(float tiempo){
    bool bandera=false;
    Reparacion auxR;
    int pos=0, y=10;
    while(auxR.leer(pos)==1){
        pos++;
        if(auxR.getTiempoReparacion()>=tiempo){
            auxR.mostrar(3, y);
            bandera=true;
            y+=10;
        }
    }
    return bandera;
}

bool buscarEntreTiempo(float tiempo, float tiempo2){
    bool bandera=false;
    Reparacion auxR;
    int pos=0, y=12;
    while(auxR.leer(pos)==1){
        pos++;
        if(auxR.getTiempoReparacion()>=tiempo && auxR.getTiempoReparacion()<=tiempo2){
            auxR.mostrar(3, y);
            bandera=true;
            y+=10;
        }
    }
    return bandera;
}

void filtrarRepaTiempo(){
    int opc;
    float tiempo, tiempo2;
    cout<<"Ingrese la opcion de búsqueda: "<<endl;
    cout<<"  1.Menor o igual que "<<endl;
    cout<<"  2.Mayor o igual que "<<endl;
    cout<<"  3.Entre que y que "<<endl;
    cin>>opc;
    switch(opc){
    case 1:
        cout<<"MENOR O IGUAL QUE  "<<endl;
        cout<<"Ingrese el tiempo de reparación en horas: "<<endl;
        cin>>tiempo;
        if(!buscarMenorTiempo(tiempo)) cout<<"No hay reparaciones con ese criterio de búsqueda "<<endl;
        break;
    case 2:
        cout<<"MAYOR O IGUAL QUE  "<<endl;
        cout<<"Ingrese el tiempo de reparación: "<<endl;
        cin>>tiempo;
        if(!buscarMayorTiempo(tiempo)) cout<<"No hay reparaciones con ese criterio de búsqueda "<<endl;
        break;
    case 3:
        cout<<"ENTRE  "<<endl;
        cout<<"Ingrese el tiempo de reparación menor: "<<endl;
        cin>>tiempo;
        cout<<"Ingrese el tiempo de reparación mayor: "<<endl;
        cin>>tiempo2;
        if(!buscarEntreTiempo(tiempo, tiempo2)) cout<<" No hay reparaciones con ese criterio de búsqueda "<<endl;
        break;
    default :
        cout<<"Opción incorrecta"<<endl;
        break;
    }
    subirVentana();
}

void filtrarRepaEstado(){
    Reparacion auxR;
    int estado;
    int pos=0, y=11;
    cout<<" ESTADOS"<<endl;
    cout<<"  1-Abierta"<<endl<<
          "  2-Cerrada"<<endl<<
          "  3-En Curso"<<endl<<
          "  4-Supendida"<<endl<<
          "  5-Cancelada"<<endl<<endl;
    cout<<"Ingrese el estado que desea filtrar: ";
    cin>>estado;
    cout<<endl;
    while(auxR.leer(pos)==1){
        pos++;
        if(auxR.getEstado()==estado){
        auxR.mostrar(3, y);
        y+=10;
        }
    }
    subirVentana();
}

void filtrarRepaCat(){
    Reparacion auxR;
    int pos=0, cat, y=9;
    bool bandera=false;
    cout<<" CATEGORÍAS:"<<endl;
    cout<<"  1-Plomería"<<endl<<
          "  2-Gas"<<endl<<
          "  3-Electricidad"<<endl<<
          "  4-Refrigeración"<<endl;
    cout<<"Ingrese la categoria que desea filtrar: ";
    cin>>cat;
    while(auxR.leer(pos)==1){
        if(cat==auxR.getCategoriaReparacion()){
        bandera=true;
        auxR.mostrar(3 ,y);
        y+=10;
        }
    pos++;
    }
    if(!bandera)cout<<"No hay reparaciones con la categoría ingresada."<<endl;
    subirVentana();
}

void filtrarRepaCliente(){ ///filtra cliente por ID
    Reparacion auxR;
    int pos=0, y=4;
    int idCliente;
    bool bandera=false;
    cout<<"Ingrese el ID del Cliente: ";
    cin>>idCliente;
    while(auxR.leer(pos)==1){
        if(idCliente==auxR.getIdCliente()){
            bandera=true;
            auxR.mostrar(3, y);
            y+=10;
        }
    pos++;
    }
    if(!bandera)cout<<"No hay reparaciones de ese cliente o el ID del cliente no existe."<<endl;
    subirVentana();
}

void filtrarRepaTecnico(){ ///busca Tecnico por ID en el archivo de Reparaciones
    Reparacion auxR;
    int pos=0, y=4;
    int idTecnico;
    bool bandera=false;
    cout<<"Ingrese el ID del Técnico asignado a la reparación: ";
    cin>>idTecnico;
    while(auxR.leer(pos)==1){
        if(idTecnico==auxR.getIdTecnico()){
            bandera=true;
            auxR.mostrar(3, y);
            y+=10;
        }
    pos++;
    }
    if(!bandera)cout<<"No hay reparaciones asignadas a ese técnico o el ID del técnico no existe."<<endl;
    subirVentana();
}

void filtrarRepuPorMarca(){ ///filtra respetando mayusc y minusc
    Repuesto auxR;
    int pos=0, y=7;
    char marca[30]={0};
    bool bandera=false;
    cout<<"Ingrese la marca del repuesto que desea filtrar (respetando mayúsculas y minúsculas): "<<endl;
    cargarCadena(marca,29);
    while(auxR.leer(pos)==1){
        if(strcmp(marca, auxR.getMarca())==0){
            bandera=true;
            auxR.mostrar(30, y);
            y+=2;
        }
        pos++;
    }
    if(!bandera)cout<<"No hay repuestos con la marca ingresada"<<endl;
    else{
      cierreCuadroRepuestos(30, y, 7);
      mostrarCategoriaRepuesto(30, 5, 5);
    }
    subirVentana();
}

void filtrarRepuPorCat(){ ///filtra repuestos por categoria
    int cat;
    Repuesto aux;
    int pos=0, y=10;
    bool bandera=false;
    cout<<"Categorías:"<<endl;
    cout<<"  1-Plomería"<<endl<<"  2-Gas"<<endl<<"  3-Electricidad"<<endl<<"  4-Refrigeración"<<endl;
    cout<<"Ingrese la categoría del Repuesto: ";
    cin>>cat;
    cout<<endl;
    while(aux.leer(pos)==1){
        if(aux.getCategoriaRepuesto()==cat && aux.getIdRepuesto()!=0){
            bandera=true;
            aux.mostrar(20, y);
            y+=2;
        }
        pos++;
    }
    if(!bandera)cout<<"No hay registros con categoría "<<cat<<endl;
    else {
        cierreCuadroRepuestos(20, y, 10);
        mostrarCategoriaRepuesto(20, 8, cat);
    }
    subirVentana();
}

void filtrarRepuPorNombre(){///Filtra por nombre respetando mayúsculas y minúsculas
    char auxNom[30];
    Repuesto auxRep;
    int pos=0, y=7;
    bool bandera=false;
    cout<<"Ingrese el nombre del Repuesto (respetando mayúsculas y minúsculas): ";
    cargarCadena(auxNom, 29);
    while(auxRep.leer(pos)==1){
        if(strcmp(auxNom, auxRep.getNombre())==0){
            bandera=true;
            auxRep.mostrar(30, y);
            y+=2;
        }
        pos++;
    }
    if(!bandera)cout<<"No hay repuesto con el nombre ingresado"<<endl;
    else{
        cierreCuadroRepuestos(30, y, 7);
        mostrarCategoriaRepuesto(30, 5, 5);
    }
    subirVentana();
}

bool buscarMenorPrecio(float precio){
    Repuesto auxR;
    int pos=0, y=13;
    bool bandera=false;
    while(auxR.leer(pos)==1){
            pos++;
            if(auxR.getPrecio()<=precio){
                bandera=true;
                auxR.mostrar(20, y);
                y+=2;
            }
        }
        if(bandera){
            cierreCuadroRepuestos(20, y, 13);
            mostrarCategoriaRepuesto(20, 11, 5);
        }
        return bandera;
}

bool buscarMayorPrecio(float precio){
    Repuesto auxR;
    int pos=0, y=13;
    bool bandera=false;
    while(auxR.leer(pos)==1){
            pos++;
            if(auxR.getPrecio()>=precio){
                bandera=true;
                auxR.mostrar(20, y);
                y+=2;
            }
        }
        if(bandera){
            cierreCuadroRepuestos(20, y, 13);
            mostrarCategoriaRepuesto(20, 11, 5);
        }
        return bandera;
}

bool buscarEntrePrecio(float precio, float precio2){
    Repuesto auxR;
    int pos=0, y=15;
    bool bandera=false;
    while(auxR.leer(pos)==1){
            pos++;
            if(auxR.getPrecio()>=precio && auxR.getPrecio()<=precio2){
                bandera=true;
                auxR.mostrar(20, y);
                y+=2;
            }
        }
        if(bandera){
            cierreCuadroRepuestos(20, y, 15);
            mostrarCategoriaRepuesto(20, 13, 5);
        }
        return bandera;
}

void filtrarRepuPorPrecio(){
    float precio=0, precio2=0;
    int opc;
    cout<<" OPCIONES"<<endl;
    cout<<"1.  Menor o igual que "<<endl;
    cout<<"2.  Mayor o igual que "<<endl;
    cout<<"3.  Entre que y que "<<endl;
    cout<<"Ingrese la opcion de búsqueda: ";
    cin>>opc;
    switch(opc){
    case 1:
        cout<<"MENOR O IGUAL QUE  "<<endl;
        cout<<"Ingrese el precio: "<<endl;
        cout<<" $ ";
        cin>>precio;
        if(!buscarMenorPrecio(precio))cout<<"No hay repuesto con el criterio ingresado"<<endl;
        break;
    case 2:
        cout<<"MAYOR O IGUAL QUE  "<<endl;
        cout<<"Ingrese el precio: "<<endl;
        cout<<" $ ";
        cin>>precio;
        if(!buscarMayorPrecio(precio))cout<<"No hay repuesto con el criterio ingresado"<<endl;
        break;
    case 3:
        cout<<"ENTRE  "<<endl;
        cout<<"Ingrese el precio menor: "<<endl;
        cout<<" $ ";
        cin>>precio;
        cout<<"Ingrese el precio mayor: "<<endl;
        cout<<" $ ";
        cin>>precio2;
        if(!buscarEntrePrecio(precio, precio2))cout<<"No hay repuesto con el criterio ingresado"<<endl;
        break;
    default :
        cout<<"Opción incorrecta"<<endl;
    break;
    }
    subirVentana();
}

void filtrarTecnicoNombre(){///Filtra por nombre respetando mayúsculas y minúsculas
    char auxNom[40];
    Tecnico auxTec;
    int pos=0, y=3;
    bool bandera=false;
    cout<<"Ingrese el nombre del Técnico: ";
    cargarCadena(auxNom, 39);
    while(auxTec.leer(pos)==1){
        if(strcmp(auxNom, auxTec.getNombre())==0){
            bandera=true;
            auxTec.mostrar(7, y);
            y+=3;
        }
        pos++;
    }
    if(!bandera)cout<<"No hay Técnico con el nombre ingresado."<<endl;
    else cierreCuadroTecnicos(7, y, 3);
    subirVentana();
}

void filtrarTecnicoLocalidad(){///Filtra por localidad respetando mayúsculas y minúsculas
    char auxLoc[20];
    Tecnico auxTec;
    bool bandera=false;
    int pos=0, y=3;
    cout<<"Ingrese la localdiad del Técnico: ";
    cargarCadena(auxLoc, 19);
    while(auxTec.leer(pos)==1){
        if(strcmp(auxLoc, auxTec.getDireccion().getLocalidad())==0){
            auxTec.mostrar(7, y);
            bandera=true;
            y+=3;
        }
        pos++;
    }
    if(!bandera)cout<<"No hay Técnico con la localidad ingresada"<<endl;
    else cierreCuadroTecnicos(7, y, 3);
    subirVentana();
}

void filtrarClienteNombre(){
    char auxNom[40];
    Cliente auxTec;
    bool bandera=false;
    int pos=0, y=3;
    cout<<"Ingrese el nombre del Cliente: ";
    cargarCadena(auxNom, 39);
    while(auxTec.leer(pos)==1){
        if(strcmp(auxNom, auxTec.getNombre())==0){
            auxTec.mostrar(6, y);
            bandera=true;
            y+=3;
        }
        pos++;
    }
    if(!bandera)cout<<"No hay Cliente con el nombre ingresado"<<endl;
    else cierreCuadroClientes(6, y, 3);
    subirVentana();
}

void filtrarClienteLocalidad(){
    char auxLoc[20];
    Cliente auxTec;
    int pos=0, y=3;
    bool bandera=false;
    cout<<"Ingrese la localdiad del Cliente: ";
    cargarCadena(auxLoc, 19);
    while(auxTec.leer(pos)==1){
        if(strcmp(auxLoc, auxTec.getDireccion().getLocalidad())==0){
            auxTec.mostrar(6, y);
            bandera=true;
            y+=3;
        }
        pos++;
    }
    if(!bandera)cout<<"No hay Cliente con la localidad ingresada"<<endl;
    else cierreCuadroClientes(6, y, 3);
    subirVentana();
}

void filtrarClienteCUIT(){
    char auxCUIT[12];
    Cliente auxC;
    int pos=0, y=3;
    bool bandera=false;
    cout<<"Ingrese el CUIT del Cliente (Sin guiones): ";
    cargarCadena(auxCUIT,11);
    while(auxC.leer(pos)==1){
        if(strcmp(auxCUIT,auxC.getCuil_Cuit())==0){
            auxC.mostrar(6, y);
            bandera=true;
            y+=3;
        }
        pos++;
    }
    if(!bandera)cout<<"No hay Cliente con el CUIT ingresado"<<endl;
    else cierreCuadroClientes(6, y, 3);
    subirVentana();
}

///FUNCIONES INFORMES///

float cantHoras(int id){

    Reparacion auxR;
    int pos=0;
    float cont=0;
    while(auxR.leer(pos)==1){
        if(auxR.getIdTecnico()==id){
            cont+=auxR.getTiempoReparacion();
        }
        pos++;
    }
    return cont;
}

void horasPorTecnico(){

    Tecnico auxT;
    int pos=0;
    float acumHoras=0;

    while(auxT.leer(pos)==1){
        acumHoras=cantHoras(auxT.getId());
        cout<<"El Técnico: ";
        setlocale(LC_ALL, "C");
        cout<<auxT.getNombre()<<" "<<auxT.getApellido()<<" tiene un total de "<<acumHoras<<" horas acumuladas"<<endl;
        setlocale(LC_ALL, "spanish");
    pos++;
    }


}

int contarClientes(){
    Cliente aux;
    FILE *arc=fopen("Clientes.dat", "rb");
    if(arc==NULL){
        cout<<"Falló en la carga de archivos."<<endl;
        return 0;
    }
    fseek(arc, 0, 2);
    int tam=ftell(arc)/sizeof(aux);
    fclose(arc);
    return tam;
}

float mayorPresupuesto(int id){
    Reparacion auxRep;
    int pos=0;
    float presupuesto=0;
    while(auxRep.leer(pos)==1){
        if(auxRep.getIdCliente()==id){
            if(auxRep.getPresupuesto()>presupuesto)presupuesto=auxRep.getPresupuesto();
        }
        pos++;
    }
    return presupuesto;
}

int MayorVector(float vec[], int tam){ ///para presupuesto
    int posMax=0;
    for(int i=0;i<tam;i++){
        if(vec[i]>=vec[posMax])posMax=i;
    }
    return posMax;
}

int MayorVector(int vec[], int tam){
    int posMax=0;
    for(int i=0;i<tam;i++){
        if(vec[i]>vec[posMax])posMax=i;
    }
    return posMax;
}

int clienteConMayorPresupuesto(){
    Cliente auxCli;
    int pos=0, tam=contarClientes();
    float *vec;
    vec=new float[tam];
    if(vec==NULL){
            cout<<"Error."<<endl;
            return -1;
    }
    while(auxCli.leer(pos)==1){
        vec[pos]=mayorPresupuesto(auxCli.getId());
        pos++;
    }
    int clienteMax=MayorVector(vec, tam);
    delete vec;
    return clienteMax+1;
}

void nombreYApellido(int id){
    Cliente auxCli;
    int pos=0;
    char nombre[40], apellido[40];
    while(auxCli.leer(pos)==1){
        if(auxCli.getId()==id){
            strcpy(nombre, auxCli.getNombre());
            strcpy(apellido, auxCli.getApellido());
        }
        pos++;
    }
    setlocale(LC_ALL, "C");
    cout<<nombre<<" "<<apellido;
    setlocale(LC_ALL, "spanish");
}

void nombreYApellidoTecnico(int id){
    Tecnico auxCli;
    int pos=0;
    char nombre[40], apellido[40];
    while(auxCli.leer(pos)==1){
        if(auxCli.getId()==id){
            strcpy(nombre, auxCli.getNombre());
            strcpy(apellido, auxCli.getApellido());
        }
        pos++;
    }
    setlocale(LC_ALL, "C");
    cout<<nombre<<" "<<apellido;
    setlocale(LC_ALL, "spanish");
}

void listarPre(){
    PresupuestoRepuesto aux;
    int pos=0;
    while(aux.leer(pos)==1){
        aux.mostrar();
        cout<<endl;
        pos++;
    }
}

int contarRepuestos(){
    Repuesto aux;
    FILE *arc=fopen("Repuestos.dat", "rb");
    if(arc==NULL){
        cout<<"Falló en la carga de archivos."<<endl;
        return 0;
    }
    fseek(arc, 0, 2);
    int tam=ftell(arc)/sizeof(aux);
    fclose(arc);
    return tam;
}

float vecesUsado(int id){
    PresupuestoRepuesto auxRep;
    int pos=0;
    int veces=0;
    while(auxRep.leer(pos)==1){
        if(auxRep.getIdRe()==id){
            veces+=auxRep.getUnidades();
        }
        pos++;
    }
    return veces;
}

int repuestoMasUsado(){
    Repuesto auxRep;
    int pos=0, tam=contarRepuestos();
    int *vec;
    vec=new int[tam];
    if(vec==NULL){
            cout<<"Error."<<endl;
            return -1;
    }
    FILE *arc=fopen("Presupuestos.dat", "rb");
    if(arc==NULL){
        cout<<"No hay presupuestos de repuestos cargados."<<endl;
        delete vec;
        return -1;
    }
    while(auxRep.leer(pos)==1){
        vec[pos]=vecesUsado(auxRep.getIdRepuesto());
        pos++;
    }
    int repuestoMax=MayorVector(vec, tam)+1;
    delete vec;
    return repuestoMax;
}

class Localidad{
private:
    char nombre[20];
    int cantidad;
public:
    void setNombre(const char* n){strcpy(nombre, n);}
    void setCantidad(int n){cantidad=n;}
    const char* getNombre(){return nombre;}
    int getCantidad(){return cantidad;}
    void aumentarCantidad(){cantidad++;}
};

int MayorVector(Localidad vec[], int tam){
    int posMax=0;
    for(int i=0;i<tam;i++){
        if(vec[i].getCantidad()>=vec[posMax].getCantidad())posMax=i;
    }
    return posMax;
}

void inicializarVector(Localidad vec[], int tam){
    for(int i=0;i<tam;i++){
        vec[i].setCantidad(0);
    }
}

int contarLocalidades(){ ///cuenta las localidades no repetidas para armar el vector dinamico
    Cliente auxCli, *vec;
    int pos=0, tam=contarClientes();
    vec=new Cliente[tam];
    if(vec==NULL){
            cout<<"Error."<<endl;
            return -1;
        }
    while(auxCli.leer(pos)==1){
        vec[pos]=auxCli;
        pos++;
    }
    Localidad *vecAux;
    vecAux=new Localidad[tam];
    if(vecAux==NULL){
            cout<<"Error."<<endl;
            return -1;
        }
    int cont=0;
    for(int i=0;i<tam;i++){
        bool bandera=true;
        for(int j=0;j<tam;j++){
            if(strcmp(vec[i].getDireccion().getLocalidad(), vecAux[j].getNombre())==0){
                bandera=false;
            }
        }
        if(bandera){
        vecAux[cont].setNombre(vec[i].getDireccion().getLocalidad());
        cont++;
        }
    }
    delete vec;
    delete vecAux;
    return cont;
}

const char* obtenerLocalidad(int id){ ///retorna localidad de cliente a igual ID
    Cliente auxCli;
    int pos=0;
    while(auxCli.leer(pos)==1){
        if(auxCli.getId()==id)return auxCli.getDireccion().getLocalidad();
        pos++;
    }
    return "0";
}

int localidadMasRepa(){ ///cuenta las localidades
    Reparacion auxRep;
    Localidad *vec;
    int tam=contarLocalidades(), pos=0, cont=0;
    vec=new Localidad[tam];
    if(vec==NULL){
            cout<<"Error."<<endl;
            return -1;
    }
    inicializarVector(vec,tam);
    char loc[20];
    while(auxRep.leer(pos)==1){
        strcpy(loc, obtenerLocalidad(auxRep.getIdCliente()));
        bool noHay=true;
        for(int i=0;i<tam;i++){
            if(strcmp(loc, vec[i].getNombre())==0){
                vec[i].aumentarCantidad();
                noHay=false;
            }
        }
        if(noHay){
            vec[cont].setNombre(loc);
            vec[cont].setCantidad(1);
            cont++;
        }
        pos++;
    }
    int localidadMayor=MayorVector(vec, tam);
    cout<<"La localidad con más reparaciones es "<<vec[localidadMayor].getNombre()<<" con "<<vec[localidadMayor].getCantidad()<<" reparaciones."<<endl;
    delete vec;
    return 1;
}

int contarTecnicos(){ ///cuenta registro de tecnicos
    Tecnico aux;
    FILE *arc=fopen("Tecnicos.dat", "rb");
    if(arc==NULL){
        cout<<"Falló en la carga de archivos."<<endl;
        return 0;
    }
    fseek(arc, 0, 2);
    int tam=ftell(arc)/sizeof(aux);
    fclose(arc);

    return tam;
}

int contarClientesTecnico(int id){
    Reparacion auxRep;
    int pos=0, cont=0, *vec, tam=contarClientes();
    vec=new int[tam];
    if(vec==NULL){
            cout<<"Error."<<endl;
            return -1;
        }
    while(auxRep.leer(pos)==1){
        bool bandera=true;
        if(auxRep.getIdTecnico()==id){
            for(int i=0;i<tam;i++){
                if(auxRep.getIdCliente()==vec[i])bandera=false; ///si hay mas de una reparacion del mismo cliente
            }                                                   ///set bandera false y no suma al vector dinamico
            if(bandera){
            vec[cont]=auxRep.getIdCliente();
            cont++;
            }
        }
        pos++;
    }
    delete vec;
    return cont;
}

int tecnicoConMasClientes(){
    Tecnico auxTec;
    int pos=0, *vec, tam=contarTecnicos();
    vec=new int[tam];
    if(vec==NULL){
            cout<<"Error."<<endl;
            return -1;
    }
    while(auxTec.leer(pos)==1){
        vec[pos]=contarClientesTecnico(auxTec.getId());
        pos++;
    }
    int tecMayor=MayorVector(vec, tam);
    delete vec;
    return tecMayor+1;
}

///FUNCIONES CONFIGURACIÓN///

bool copiaSeguridadClientes(){

    FILE *p=fopen("Clientes.dat", "rb");
    if(p==NULL){
        cout<<"Error en la carga del archivo 'Clientes.dat'."<<endl;
        return false;
    }
    FILE *p1=fopen("Clientes.bkp", "wb");
    if(p1==NULL){
        fclose(p);
        cout<<"Error en la carga del archivo 'Clientes.bkp'."<<endl;
        return false;
    }
    char opc;
    cout<<"¿Desea realizar la copia de seguridad del archivo de Clientes? (s/n): ";
    cin>>opc;
    if (opc=='s' || opc=='S'){
      system("copy Clientes.dat Clientes.bkp");
    }
    else {
        cout<<"No se realizó la copia."<<endl;
    }
    fclose(p);
    fclose(p1);
    return true;

}

bool restaurarArchivoClientes(){

    FILE *p=fopen("Clientes.dat", "wb");
    if(p==NULL){
        cout<<"Error en la carga del archivo 'Clientes.dat'."<<endl;
        return false;
    }
    FILE *p1=fopen("Clientes.bkp", "rb");
    if(p1==NULL){
        fclose(p);
        cout<<"Error en la carga del archivo 'Clientes.bkp'."<<endl;
        return false;
    }
    char opc;
    cout<<"¿Desea realizar la restauración del archivo Clientes? (s/n): ";
    cin>>opc;
    if (opc=='s' || opc=='S'){
      system("copy Clientes.bkp Clientes.dat");
    }
    else {
        cout<<"No se realizó la restauración."<<endl;
    }
    fclose(p);
    fclose(p1);
    return true;
}

bool copiaSeguridadTecnicos(){

    FILE *p=fopen("Tecnicos.dat", "rb");
    if(p==NULL){
        cout<<"Error en la carga del archivo 'Tecnicos.dat'."<<endl;
        return false;
    }
    FILE *p1=fopen("Tecnicos.bkp", "wb");
    if(p1==NULL){
        fclose(p);
        cout<<"Error en la carga del archivo 'Tecnicos.bkp'."<<endl;
        return false;
    }
    char opc;
    cout<<"¿Desea realizar la copia de seguridad del archivo de Tecnicos? (s/n): ";
    cin>>opc;
    if (opc=='s' || opc=='S'){
      system("copy Tecnicos.dat Tecnicos.bkp");
    }
    else {
        cout<<"No se realizó la copia."<<endl;
    }
    fclose(p);
    fclose(p1);
    return true;

}

bool restaurarArchivoTecnicos(){

    FILE *p=fopen("Tecnicos.dat", "wb");
    if(p==NULL){
        cout<<"Error en la carga del archivo 'Tecnicos.dat'."<<endl;
        return false;
    }
    FILE *p1=fopen("Tecnicos.bkp", "rb");
    if(p1==NULL){
        fclose(p);
        cout<<"Error en la carga del archivo 'Tecnicos.bkp'."<<endl;
        return false;
    }
    char opc;
    cout<<"¿Desea realizar la restauración del archivo Tecnicos? (s/n): ";
    cin>>opc;
    if (opc=='s' || opc=='S'){
      system("copy Tecnicos.bkp Tecnicos.dat");
    }
    else {
        cout<<"No se realizó la restauración."<<endl;
    }
    fclose(p);
    fclose(p1);
    return true;
}

bool copiaSeguridadReparaciones(){

    FILE *p=fopen("Reparaciones.dat", "rb");
    if(p==NULL){
        cout<<"Error en la carga del archivo 'Reparaciones.dat'."<<endl;
        return false;
    }
    FILE *p1=fopen("Reparaciones.bkp", "wb");
    if(p1==NULL){
        fclose(p);
        cout<<"Error en la carga del archivo 'Reparaciones.bkp'."<<endl;
        return false;
    }
    char opc;
    cout<<"¿Desea realizar la copia de seguridad del archivo de Reparaciones? (s/n): ";
    cin>>opc;
    if (opc=='s' || opc=='S'){
      system("copy Reparaciones.dat Reparaciones.bkp");
    }
    else {
        cout<<"No se realizó la copia."<<endl;
    }
    fclose(p);
    fclose(p1);
    return true;

}

bool restaurarArchivoReparaciones(){

    FILE *p=fopen("Reparaciones.dat", "wb");
    if(p==NULL){
        cout<<"Error en la carga del archivo 'Reparaciones.dat'."<<endl;
        return false;
    }
    FILE *p1=fopen("Reparaciones.bkp", "rb");
    if(p1==NULL){
        fclose(p);
        cout<<"Error en la carga del archivo 'Reparaciones.bkp'."<<endl;
        return false;
    }
    char opc;
    cout<<"¿Desea realizar la restauración del archivo Reparaciones? (s/n): ";
    cin>>opc;
    if (opc=='s' || opc=='S'){
      system("copy Reparaciones.bkp Reparaciones.dat");
    }
    else {
        cout<<"No se realizó la restauración."<<endl;
    }
    fclose(p);
    fclose(p1);
    return true;
}

bool copiaSeguridadRepuestos(){

    FILE *p=fopen("Repuestos.dat", "rb");
    if(p==NULL){
        cout<<"Error en la carga del archivo 'Repuestos.dat'."<<endl;
        return false;
    }
    FILE *p1=fopen("Repuestos.bkp", "wb");
    if(p1==NULL){
        fclose(p);
        cout<<"Error en la carga del archivo 'Repuestos.bkp'."<<endl;
        return false;
    }
    char opc;
    cout<<"¿Desea realizar la copia de seguridad del archivo de Repuestos? (s/n): ";
    cin>>opc;
    if (opc=='s' || opc=='S'){
      system("copy Repuestos.dat Repuestos.bkp");
    }
    else {
        cout<<"No se realizó la copia."<<endl;
    }
    fclose(p);
    fclose(p1);
    return true;

}

bool restaurarArchivoRepuestos(){

    FILE *p=fopen("Repuestos.dat", "wb");
    if(p==NULL){
        cout<<"Error en la carga del archivo 'Repuestos.dat'."<<endl;
        return false;
    }
    FILE *p1=fopen("Repuestos.bkp", "rb");
    if(p1==NULL){
        fclose(p);
        cout<<"Error en la carga del archivo 'Repuestos.bkp'."<<endl;
        return false;
    }
    char opc;
    cout<<"¿Desea realizar la restauración del archivo Repuestos? (s/n): ";
    cin>>opc;
    if (opc=='s' || opc=='S'){
      system("copy Repuestos.bkp Repuestos.dat");
    }
    else {
        cout<<"No se realizó la restauración."<<endl;
    }
    fclose(p);
    fclose(p1);
    return true;
}

bool copiaSeguridadPresupuestos(){

    FILE *p=fopen("Presupuestos.dat", "rb");
    if(p==NULL){
        cout<<"Error en la carga del archivo 'Presupuestos.dat'."<<endl;
        return false;
    }
    FILE *p1=fopen("Presupuestos.bkp", "wb");
    if(p1==NULL){
        fclose(p);
        cout<<"Error en la carga del archivo 'Presupuestos.bkp'."<<endl;
        return false;
    }
    char opc;
    cout<<"¿Desea realizar la copia de seguridad del archivo de Presupuestos? (s/n): ";
    cin>>opc;
    if (opc=='s' || opc=='S'){
      system("copy Presupuestos.dat Presupuestos.bkp");
    }
    else {
        cout<<"No se realizó la copia."<<endl;
    }
    fclose(p);
    fclose(p1);
    return true;

}

bool restaurarArchivoPresupuestos(){

    FILE *p=fopen("Presupuestos.dat", "wb");
    if(p==NULL){
        cout<<"Error en la carga del archivo 'Presupuestos.dat'."<<endl;
        return false;
    }
    FILE *p1=fopen("Presupuestos.bkp", "rb");
    if(p1==NULL){
        fclose(p);
        cout<<"Error en la carga del archivo 'Presupuestos.bkp'."<<endl;
        return false;
    }
    char opc;
    cout<<"¿Desea realizar la restauración del archivo Presupuestos? (s/n): ";
    cin>>opc;
    if (opc=='s' || opc=='S'){
      system("copy Presupuestos.bkp Presupuestos.dat");
    }
    else {
        cout<<"No se realizó la restauración."<<endl;
    }
    fclose(p);
    fclose(p1);
    return true;
}

bool restaurarDatosInicio(){

    char opc;
    cout<<"¿Desea realizar la restauración de datos de inicio? (s/n): ";
    cin>>opc;
    if(opc=='s' || opc=='S'){
        FILE *arc=fopen("Clientes.dat", "wb");
        if(arc==NULL){
            cout<<"Error en la carga del archivo 'Clientes.dat'."<<endl;
            return false;
        }
        FILE *arc1=fopen("ClientesInc.dat", "rb");
        if(arc1==NULL){
            fclose(arc);
            cout<<"Error en la carga del archivo 'ClientesInc.dat'."<<endl;
            return false;
        }
        system("copy ClientesInc.dat Clientes.dat");
        fclose(arc);
        fclose(arc1);
        ///---///
        arc=fopen("Tecnicos.dat", "wb");
        if(arc==NULL){
            cout<<"Error en la carga del archivo 'Tecnicos.dat'."<<endl;
            return false;
        }
        arc1=fopen("TecnicosInc.dat", "rb");
        if(arc1==NULL){
            fclose(arc);
            cout<<"Error en la carga del archivo 'TecnicosInc.dat'."<<endl;
            return false;
        }
        system("copy TecnicosInc.dat Tecnicos.dat");
        fclose(arc);
        fclose(arc1);
        ///---///
        arc=fopen("Reparaciones.dat", "wb");
        if(arc==NULL){
            cout<<"Error en la carga del archivo 'Reparaciones.dat'."<<endl;
            return false;
        }
        arc1=fopen("ReparacionesInc.dat", "rb");
        if(arc1==NULL){
            fclose(arc);
            cout<<"Error en la carga del archivo 'ReparacionesInc.dat'."<<endl;
            return false;
        }
        system("copy ReparacionesInc.dat Reparaciones.dat");
        fclose(arc);
        fclose(arc1);
        /// ---///
        arc=fopen("Repuestos.dat", "wb");
        if(arc==NULL){
            cout<<"Error en la carga del archivo 'Repuestos.dat'."<<endl;
            return false;
        }
        arc1=fopen("RepuestosInc.dat", "rb");
        if(arc1==NULL){
            fclose(arc);
            cout<<"Error en la carga del archivo 'RepuestosInc.dat'."<<endl;
            return false;
        }
        system("copy RepuestosInc.dat Repuestos.dat");
        fclose(arc);
        fclose(arc1);
        /// ---- ///
        arc=fopen("Presupuestos.dat", "wb");
        if(arc==NULL){
            cout<<"Error en la carga del archivo 'Presupuestos.dat'."<<endl;
            return false;
        }
        arc1=fopen("PresupuestosInc.dat", "rb");
        if(arc1==NULL){
            fclose(arc);
            cout<<"Error en la carga del archivo 'PresupuestosInc.dat'."<<endl;
            return false;
        }
        system("copy PresupuestosInc.dat Presupuestos.dat");
        fclose(arc);
        fclose(arc1);


        ///  ----- //// contador

        arc=fopen("Contador.dat", "wb");
        if(arc==NULL){
            cout<<"Error en la carga del archivo 'Contador.dat'."<<endl;
            return false;
        }
        arc1=fopen("ContadorInc.dat", "rb");
        if(arc==NULL){
            fclose(arc);
            cout<<"Error en la carga del archivo 'ContadorInc.dat'."<<endl;
            return false;
        }
        system("copy ContadorInc.dat Contador.dat");
        fclose(arc);
        fclose(arc1);
    }
    return true;
    cout<<"Se restauraron los datos de inicio."<<endl;
}


