#include <iostream>
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
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#include "Graficos.h"
#include "Reparacion.h"
#include "Cliente.h"
#include "Repuesto.h"
#include "Tecnico.h"
#include "frame.h"
#include "funciones.h"
#include "PresupuestoRepuesto.h"

void logo(){
    int matriz[8][74]= {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,6,6,6,6,6,6,6,6,1,6,6,6,6,6,6,6,1,0,6,6,6,6,6,6,1,6,6,6,1,0,0,0,6,6,1,6,6,1,6,6,6,6,6,6,6,1,0,6,6,6,6,6,6,1,0,6,6,6,6,6,6,6,1,6,6,6,6,6,6,6,6,1,0},
                        {0,3,4,4,6,6,5,4,4,2,6,6,5,4,4,4,4,2,6,6,5,4,4,4,4,2,6,6,6,6,1,0,0,6,6,7,6,6,7,6,6,5,4,4,4,4,2,6,6,5,4,4,4,6,6,1,6,6,5,4,4,4,4,2,3,4,4,6,6,5,4,4,2,0},
                        {0,0,0,0,6,6,7,0,0,0,6,6,6,6,6,1,0,0,6,6,7,0,0,0,0,0,6,6,5,6,6,1,0,6,6,7,6,6,7,6,6,6,6,6,6,6,1,6,6,7,0,0,0,6,6,7,6,6,6,6,6,1,0,0,0,0,0,6,6,7,0,0,0,0},
                        {0,0,0,0,6,6,7,0,0,0,6,6,5,4,4,2,0,0,6,6,7,0,0,0,0,0,6,6,7,3,6,6,1,6,6,7,6,6,7,3,4,4,4,4,6,6,7,6,6,7,0,0,0,6,6,7,6,6,5,4,4,2,0,0,0,0,0,6,6,7,0,0,0,0},
                        {0,0,0,0,6,6,7,0,0,0,6,6,6,6,6,6,6,1,3,6,6,6,6,6,6,1,6,6,7,0,3,6,6,6,6,7,6,6,7,6,6,6,6,6,6,6,7,3,6,6,6,6,6,6,5,2,6,6,7,0,0,0,0,0,0,0,0,6,6,7,0,0,0,0},
                        {0,0,0,0,3,4,2,0,0,0,3,4,4,4,4,4,4,2,0,3,4,4,4,4,4,2,3,4,2,0,0,3,4,4,4,2,3,4,2,3,4,4,4,4,4,4,2,0,3,4,4,4,4,4,2,0,3,4,2,0,0,0,0,0,0,0,0,3,4,2,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    for(int i=0;i<8;i++){
        gotoxy(24, i+10);
        for(int j=0;j<74;j++){
            if(matriz[i][j]==6)cout<<char(219);
            else if(matriz[i][j]==3)cout<<char(200);
            else if(matriz[i][j]==4)cout<<char(205);
            else if(matriz[i][j]==2)cout<<char(188);
            else if(matriz[i][j]==7)cout<<char(186);
            else if(matriz[i][j]==5)cout<<char(201);
            else if(matriz[i][j]==1)cout<<char(187);
            else if(matriz[i][j]==0)cout<<" ";
        }
        cout<<endl;
    }
    gotoxy(44, 18);
    cout<<"Presiona una tecla para empezar";
}

void rectangle2(int x, int y, int width, int height){
    setlocale(LC_ALL, "C");
    for(int i=0; i<= width; i++){
        gotoxy1(x+i, y);
        printf("%c", 205);

        gotoxy1(x+i, y + height);
        printf("%c", 205);
    }
    for(int i=0; i<=height; i++){
        gotoxy1(x, y+i);
        printf("%c", 186);

        gotoxy1(x+ width, y + i);
        printf("%c", 186);
    }
    gotoxy1(x,y);
    printf("%c", 201);

    gotoxy1(x + width, y);
    printf("%c", 187);

    gotoxy1(x, y+ height);
    printf("%c", 200);

    gotoxy1(x+ width, y + height);
    printf("%c", 188);

    setlocale(LC_ALL, "spanish");

    rlutil::locate(58,4);
    cout<<"1.Seleccione el repuesto deseado desplazando"<<endl;
    rlutil::locate(58,5);
    cout<<"la flecha hacia arriba o hacia abajo."<<endl;
    rlutil::locate(58,6);
    cout<<"2.Presione Enter."<<endl;
    rlutil::locate(58,7);
    cout<<"3.Ingrese la cantidad de unidades deseadas"<<endl;
    rlutil::locate(58,8);
    cout<<"y presione Enter nuevamente."<<endl;
    rlutil::locate(58,9);
    cout<<"4.Desplace la flecha hacia 'Finalizar' "<<endl;
    rlutil::locate(58,10);
    cout<<"y presione Enter."<<endl;


}

void rectangle(int x, int y, int width, int height){
    setlocale(LC_ALL, "C");
    txtcolor(AZUL);
    for(int i=0; i<= width; i++){
        gotoxy1(x+i, y);
        printf("%c", 205);

        gotoxy1(x+i, y + height);
        printf("%c", 205);
    }
    for(int i=0; i<=height; i++){
        gotoxy1(x, y+i);
        printf("%c", 186);

        gotoxy1(x+ width, y + i);
        printf("%c", 186);
    }
    gotoxy1(x,y);
    printf("%c", 201);

    gotoxy1(x + width, y);
    printf("%c", 187);

    gotoxy1(x, y+ height);
    printf("%c", 200);

    gotoxy1(x+ width, y + height);
    printf("%c", 188);

    setlocale(LC_ALL, "spanish");
}

void square(int x, int y, int lado){
    rectangle(x, y, lado, lado);

}

void gotoxy1(int x, int y){
    printf("\x1B[%d;%df", y,x);
}

void txtcolor(int color){
    printf("\x1B[%dm",color);
}

void txtbgcolor(int color){
    printf("\x1B[%dm",color+10);

}

void gotocenter(int x, int y, string cad){
    int tam= cad.length();
    gotoxy(x - (tam / 2), y);
    printf("%s", cad.c_str());
}

void marco(int x, int y, int width, int height, string title){
    txtcolor(AZUL);
    rectangle(x,y,width, height);
    txtcolor(WHITE);
    gotocenter(x + (width/2), y, " " + title + " ");
}

void showTime(const char*text,int posx,int posy,bool selected){

    if(selected){
        rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
    }
    else{
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    }
    rlutil::locate(posx,posy);
    std::cout<<text<<std::endl;
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
}

void cuadroTecnicos(int x, int y){
    setlocale(LC_ALL, "C");
    ///ID
    gotoxy(x, y);
    cout<<char(204);
    for(int i=1;i<=3;i++){
        cout<<char(205);
    }
    cout<<char(206);
    gotoxy(x, y+3);
    cout<<char(204);
    for(int i=1;i<=3;i++){
        cout<<char(205);
    }
    cout<<char(206);
    for(int i=1;i<=2;i++){
        gotoxy(x, y+i);
        cout<<char(186);
        gotoxy(x+4, y+i);
        cout<<char(186);
        gotoxy(x+25, y+i);
        cout<<char(186);
        gotoxy(x+27, y+i);
        cout<<char(186);
        gotoxy(x+68, y+i);
        cout<<char(186);
        gotoxy(x+94, y+i);
        cout<<char(186);
        gotoxy(x+104, y+i);
        cout<<char(186);
    }
    ///Nombre y Apellido
    gotoxy(x+5, y);
    for(int i=1;i<=20;i++){
        cout<<char(205);
    }
    cout<<char(206);
    gotoxy(x+5, y+3);
    for(int i=1;i<=20;i++){
        cout<<char(205);
    }
    cout<<char(206);
    setlocale(LC_ALL, "C");
    ///Categoria
    gotoxy(x+26, y);
    cout<<char(205)<<char(206);
    gotoxy(x+26, y+3);
    cout<<char(205)<<char(206);
    ///Domicilio
    gotoxy(x+28, y);
    for(int i=1;i<=40;i++){
        cout<<char(205);
    }
    cout<<char(206);
    gotoxy(x+28, y+3);
    for(int i=1;i<=40;i++){
        cout<<char(205);
    }
    cout<<char(206);
    ///Contacto
    gotoxy(x+69, y);
    for(int i=1;i<=25;i++){
        cout<<char(205);
    }
    cout<<char(206);
    gotoxy(x+69, y+3);
    for(int i=1;i<=25;i++){
        cout<<char(205);
    }
    cout<<char(206);
    ///Estado
    gotoxy(x+95, y);
    for(int i=1;i<=9;i++){
        cout<<char(205);
    }
    cout<<char(185);
    gotoxy(x+95, y+3);
    for(int i=1;i<=9;i++){
        cout<<char(205);
    }
    cout<<char(185);
}

void cierreCuadroTecnicos(int x, int y, int yi){
    setlocale(LC_ALL, "C");
    gotoxy(x, y);
    cout<<char(200);
    gotoxy(x+4, y);
    cout<<char(202);
    gotoxy(x+25, y);
    cout<<char(202);
    gotoxy(x+27, y);
    cout<<char(202);
    gotoxy(x+68, y);
    cout<<char(202);
    gotoxy(x+94, y);
    cout<<char(202);
    gotoxy(x+104, y);
    cout<<char(188);

    gotoxy(x, yi);
    cout<<char(201);
    gotoxy(x+4, yi);
    cout<<char(203);
    gotoxy(x+25, yi);
    cout<<char(203);
    gotoxy(x+27, yi);
    cout<<char(203);
    gotoxy(x+68, yi);
    cout<<char(203);
    gotoxy(x+94, yi);
    cout<<char(203);
    gotoxy(x+104, yi);
    cout<<char(187);
    cout<<endl<<endl<<endl;
    setlocale(LC_ALL, "spanish");
}

void cuadroClientes(int x, int y){
    setlocale(LC_ALL, "C");
    ///ID
    gotoxy(x, y);
    cout<<char(204);
    for(int i=1;i<=3;i++){
        cout<<char(205);
    }
    cout<<char(206);
    gotoxy(x, y+3);
    cout<<char(204);
    for(int i=1;i<=3;i++){
        cout<<char(205);
    }
    cout<<char(206);
    for(int i=1;i<=2;i++){
        gotoxy(x, y+i);
        cout<<char(186);
        gotoxy(x+4, y+i);
        cout<<char(186);
        gotoxy(x+25, y+i);
        cout<<char(186);
        gotoxy(x+39, y+i);
        cout<<char(186);
        gotoxy(x+80, y+i);
        cout<<char(186);
        gotoxy(x+106, y+i);
        cout<<char(186);
    }
    ///Nombre y Apellido
    gotoxy(x+5, y);
    for(int i=1;i<=20;i++){
        cout<<char(205);
    }
    cout<<char(206);
    gotoxy(x+5, y+3);
    for(int i=1;i<=20;i++){
        cout<<char(205);
    }
    cout<<char(206);
    ///CUIL
    gotoxy(x+26, y);
    for(int i=1;i<=13;i++){
        cout<<char(205);
    }
    cout<<char(206);
    gotoxy(x+26, y+3);
    for(int i=1;i<=13;i++){
        cout<<char(205);
    }
    cout<<char(206);
    ///Domicilio
    gotoxy(x+40, y);
    for(int i=1;i<=40;i++){
        cout<<char(205);
    }
    cout<<char(206);
    gotoxy(x+40, y+3);
    for(int i=1;i<=40;i++){
        cout<<char(205);
    }
    cout<<char(206);
    ///Contacto
    gotoxy(x+81, y);
    for(int i=1;i<=25;i++){
        cout<<char(205);
    }
    cout<<char(185);
    gotoxy(x+81, y+3);
    for(int i=1;i<=25;i++){
        cout<<char(205);
    }
    cout<<char(185);
    setlocale(LC_ALL, "spanish");
}

void cierreCuadroClientes(int x, int y, int yi){
    setlocale(LC_ALL, "C");
    gotoxy(x, y);
    cout<<char(200);
    gotoxy(x+4, y);
    cout<<char(202);
    gotoxy(x+25, y);
    cout<<char(202);
    gotoxy(x+39, y);
    cout<<char(202);
    gotoxy(x+80, y);
    cout<<char(202);
    gotoxy(x+106, y);
    cout<<char(188);

    gotoxy(x, yi);
    cout<<char(201);
    gotoxy(x+4, yi);
    cout<<char(203);
    gotoxy(x+25, yi);
    cout<<char(203);
    gotoxy(x+39, yi);
    cout<<char(203);
    gotoxy(x+80, yi);
    cout<<char(203);
    gotoxy(x+106, yi);
    cout<<char(187);
    cout<<endl<<endl<<endl;
    setlocale(LC_ALL, "spanish");
}

void cuadroRepuestos(int x, int y){
    setlocale(LC_ALL, "C");
    ///ID
    gotoxy(x, y);
    cout<<char(204);
    for(int i=1;i<=3;i++){
        cout<<char(205);
    }
    cout<<char(206);
    gotoxy(x, y+2);
    cout<<char(204);
    for(int i=1;i<=3;i++){
        cout<<char(205);
    }
    cout<<char(206);

        gotoxy(x, y+1);
        cout<<char(186);
        gotoxy(x+4, y+1);
        cout<<char(186);
        gotoxy(x+45, y+1);
        cout<<char(186);
        gotoxy(x+54, y+1);
        cout<<char(186);

    ///Detalles
    gotoxy(x+5, y);
    for(int i=1;i<=40;i++){
        cout<<char(205);
    }
    cout<<char(206);
    gotoxy(x+5, y+2);
    for(int i=1;i<=40;i++){
        cout<<char(205);
    }
    cout<<char(206);
    ///Precio
    gotoxy(x+46, y);
    for(int i=1;i<=8;i++){
        cout<<char(205);
    }
    cout<<char(185);
    gotoxy(x+46, y+2);
    for(int i=1;i<=8;i++){
        cout<<char(205);
    }
    cout<<char(185);
    setlocale(LC_ALL, "spanish");
}

void cierreCuadroRepuestos(int x, int y, int yi){
    setlocale(LC_ALL, "C");
    gotoxy(x, y);
    cout<<char(200);
    gotoxy(x+4, y);
    cout<<char(202);
    gotoxy(x+45, y);
    cout<<char(202);
    gotoxy(x+54, y);
    cout<<char(188);

    gotoxy(x+4, yi);
    cout<<char(203);
    gotoxy(x+45, yi);
    cout<<char(203);
    cout<<endl<<endl<<endl;
    setlocale(LC_ALL, "spanish");
}

void mostrarCategoriaRepuesto(int x, int y, int cat){
    setlocale(LC_ALL, "C");
    gotoxy(x, y);
    cout<<char(201);
    for(int i=1;i<=53;i++)cout<<char(205);
    cout<<char(187);
    gotoxy(x, y+1);
    cout<<char(186);
    gotoxy(x+54, y+1);
    cout<<char(186);
    setlocale(LC_ALL, "spanish");
    gotoxy(x+1, y+1);
    cout<<"CATEGORÍA: ";
    if(cat==1)cout<<"Plomería";
    if(cat==2)cout<<"Gas";
    if(cat==3)cout<<"Electricidad";
    if(cat==4)cout<<"Refrigeración";
    if(cat==5)cout<<"Repuestos";
    cout<<endl<<endl<<endl<<endl<<endl;
    setlocale(LC_ALL,"spanish");
}

void cuadroReparaciones(int x, int y){
    setlocale(LC_ALL, "C");
    ///ID
    gotoxy(x, y);
    cout<<char(201);
    for(int i=1;i<=3;i++){
        cout<<char(205);
    }
    cout<<char(203);
    gotoxy(x, y+3);
    cout<<char(204);
    for(int i=1;i<=3;i++){
        cout<<char(205);
    }
    cout<<char(202);
    for(int i=1;i<=2;i++){
        gotoxy(x, y+i);
        cout<<char(186);
        gotoxy(x+4, y+i);
        cout<<char(186);
        gotoxy(x+25, y+i);
        cout<<char(186);
        gotoxy(x+46, y+i);
        cout<<char(186);
        gotoxy(x+87, y+i);
        cout<<char(186);
        gotoxy(x+101, y+i);
        cout<<char(186);
        gotoxy(x+111, y+i);
        cout<<char(186);
    }
    ///Técnico
    gotoxy(x+5, y);
    for(int i=1;i<=20;i++){
        cout<<char(205);
    }
    cout<<char(203);
    gotoxy(x+5, y+3);
    for(int i=1;i<=20;i++){
        cout<<char(205);
    }
    cout<<char(202);
    ///Cliente
        gotoxy(x+26, y);
    for(int i=1;i<=20;i++){
        cout<<char(205);
    }
    cout<<char(203);
    gotoxy(x+26, y+3);
    for(int i=1;i<=20;i++){
        cout<<char(205);
    }
    cout<<char(202);
    ///Domicilio
    gotoxy(x+47, y);
    for(int i=1;i<=40;i++){
        cout<<char(205);
    }
    cout<<char(203);
    gotoxy(x+47, y+3);
    for(int i=1;i<=40;i++){
        cout<<char(205);
    }
    cout<<char(202);
    ///Categoria
    gotoxy(x+88, y);
    for(int i=1;i<=13;i++){
        cout<<char(205);
    }
    cout<<char(203);
    gotoxy(x+88, y+3);
    for(int i=1;i<=13;i++){
        cout<<char(205);
    }
    cout<<char(202);
    ///Estado
    gotoxy(x+102, y);
    for(int i=1;i<=9;i++){
        cout<<char(205);
    }
    cout<<char(187);
    gotoxy(x+102, y+3);
    for(int i=1;i<=9;i++){
        cout<<char(205);
    }
    cout<<char(185);
    ///Observaciones
    gotoxy(x, y+6);
    cout<<char(200);
    for(int i=1;i<=14;i++)cout<<char(205);
    cout<<char(202);
    gotoxy(x+15, y+3);
    cout<<char(203);
    ///Observacion
    gotoxy(x+16, y+6);
    for(int i=1;i<=60;i++)cout<<char(205);
    cout<<char(202);
    gotoxy(x+76, y+3);
    cout<<char(203);
    ///Presupuesto
    gotoxy(x+77, y+6);
    for(int i=1;i<=15;i++)cout<<char(205);
    cout<<char(202);
    gotoxy(x+92, y+3);
    cout<<char(203);
    ///Fecha y tiempo
    gotoxy(x+93, y+6);
    for(int i=1;i<=18;i++)cout<<char(205);
    cout<<char(188);
    for(int i=1;i<=2;i++){
        gotoxy(x, y+3+i);
        cout<<char(186);
        gotoxy(x+15, y+3+i);
        cout<<char(186);
        gotoxy(x+76, y+3+i);
        cout<<char(186);
        gotoxy(x+92, y+3+i);
        cout<<char(186);
        gotoxy(x+111, y+3+i);
        cout<<char(186);
    }
}

int menuReparaciones(){

    Reparacion obj;
    int y=0;
    system("title MENÚ REPARACIONES");
    system("cls");
    do{
        rlutil::hidecursor();
        marco(39,11,43,9,"MENÚ REPARACIONES");
        showTime("   CARGAR REPARACIÓN    ",49,13,y==0);
        showTime("  LISTAR REPARACIÓNES   ",49,14,y==1);
        showTime("BUSCAR REPARACIÓN POR ID",49,15,y==2);
        showTime(" ACTUALIZAR REPARACIÓN  ",49,16,y==3);
        showTime("   ACTUALIZAR ESTADO    ",49,17,y==4);
        showTime("VOLVER AL MENÚ PRINCIPAL",49,18,y==5);

        switch(rlutil::getkey()){
            case 14:
                    rlutil::locate(49,13+y);
                    y--;
                    if(y<0){y=0;}
            break;
            case 15:
                    rlutil::locate(49,13+y);
                    y++;
                    if(y>5){y=5;}
            break;
            case 1:
                   system("cls");
                   switch(y){
                        case 0:
                            if(obj.cargar()){
                                system("cls");
                                obj.grabar();
                            }
                            system("pause");
                            system("cls");
                        break;
                        case 1:
                            obj.listar();
                            getch();
                            system("cls");
                        break;
                        case 2:
                            obj.buscarPorID();
                            getch();
                            system("cls");
                        break;
                        case 3:
                            obj.gestionar();
                            system("pause");
                            system("cls");
                        break;
                        case 4:
                            obj.actualizarEstado();
                            system("pause");
                            system("cls");
                            break;
                        case 5:
                                return 0;
                        break;
                        }
            break;
        }
    Sleep(70);
    }while(true);

    return 0;
}

int menuClientes(){

    Cliente obj;
    int y=0;
    system("title MENÚ CLIENTES");
    system("cls");
    do{
        rlutil::hidecursor();
        marco(39,11,43,8,"MENÚ CLIENTES");
        showTime("    LISTAR CLIENTES     ",49,13,y==0);
        showTime(" BUSCAR CLIENTES POR ID ",49,14,y==1);
        showTime("    CARGAR CLIENTE      ",49,15,y==2);
        showTime("   MODIFICAR CLIENTE    ",49,16,y==3);
        showTime("VOLVER AL MENÚ PRINCIPAL",49,17,y==4);

        switch(rlutil::getkey()){
            case 14:
                    rlutil::locate(49,13+y);
                    y--;
                    if(y<0){y=0;}
            break;
            case 15:
                    rlutil::locate(49,13+y);
                    y++;
                    if(y>4){y=4;}
            break;
            case 1:
                    system("cls");
                   switch(y){
                        case 0:
                            obj.listar();
                            getch();
                            system("cls");
                        break;
                        case 1:
                            obj.buscarPorID();
                            system("pause");
                            system("cls");
                            break;
                        case 2:
                            if(obj.cargar()){
                                obj.grabar();
                            }
                            system("pause");
                            system("cls");
                        break;
                        case 3:
                            obj.modificarCliente();
                            system("pause");
                            system("cls");
                        break;
                        case 4:
                                return 0;
                        break;
                        }
            break;
        }
    Sleep(70);
    }while(true);

    return 0;
}

int menuTecnicos(){

    Tecnico obj;
    int y=0;
    system("title MENÚ TÉCNICOS");
    system("cls");
    do{
        rlutil::hidecursor();
        marco(39,11,43,9,"MENÚ TECNICOS");
        showTime("    LISTAR TÉCNICOS     ",49,13,y==0);
        showTime("    CARGAR TÉCNICO      ",49,14,y==1);
        showTime("  BUCAR TÉCNICO POR ID  ",49,15,y==2);
        showTime("   MODIFICAR TÉCNICO    ",49,16,y==3);
        showTime("   ACTUALIZAR ESTADO    ",49,17,y==4);
        showTime("VOLVER AL MENÚ PRINCIPAL",49,18,y==5);

        switch(rlutil::getkey()){
            case 14:
                    rlutil::locate(49,13+y);
                    y--;
                    if(y<0){y=0;}
            break;
            case 15:
                    rlutil::locate(49,13+y);
                    y++;
                    if(y>5){y=5;}
            break;
            case 1:
                    system("cls");
                   switch(y){
                        case 0:
                            obj.listar();
                            getch();
                            system("cls");
                        break;
                        case 1:
                            if(obj.cargar()){
                                system("cls");
                                obj.grabar();
                            }
                            system("pause");
                            system("cls");
                        break;
                        case 2:
                            obj.buscarPorID();
                            getch();
                            system("cls");
                        break;
                        case 3:
                            obj.modificarTecnico();
                            system("pause");
                            system("cls");
                        break;
                        case 4:
                            obj.actualizarEstado();
                            system("pause");
                            system("cls");
                            break;
                        case 5:
                                return 0;
                        break;
                        }
            break;
        }
    Sleep(70);
    }while(true);

    return 0;
}

int menuRepuestos(){

    int y=0;
    Repuesto obj;
    system("title MENÚ REPUESTOS");
    system("cls");
    do{
        rlutil::hidecursor();
        marco(39,11,43,9,"MENÚ REPUESTOS");
        showTime("    LISTAR REPUESTOS    ",49,13,y==0);
        showTime("     BUSCAR POR ID      ",49,14,y==1);
        showTime("         ALTA           ",49,15,y==2);
        showTime("         BAJA           ",49,16,y==3);
        showTime("     MODIFICACIONES     ",49,17,y==4);
        showTime("VOLVER AL MENÚ PRINCIPAL",49,18,y==5);
        switch(rlutil::getkey()){
            case 14:
                    rlutil::locate(49,13+y);
                    y--;
                    if(y<0){y=0;}
            break;
            case 15:
                    rlutil::locate(49,13+y);
                    y++;
                    if(y>5){y=5;}
            break;
            case 1:
                    system("cls");
                   switch(y){
                        case 0:
                            obj.listarRepuestos();
                            getch();
                            system("cls");
                        break;
                        case 1:
                            obj.buscarPorID();
                            system("pause");
                            system("cls");
                        break;
                        case 2:
                            if(obj.alta()){
                                system("cls");
                                obj.grabar();
                                }
                            system("pause");
                            system("cls");
                        break;
                        case 3:
                            obj.baja();
                            system("pause");
                            system("cls");
                        break;
                        case 4:
                            obj.modificarRepuesto();
                            system("pause");
                            system("cls");
                            break;
                        case 5:
                            return 0;
                        break;
                        }
            break;
        }
    Sleep(70);
    }while(true);

    return 0;
}

int menuFiltros(){
    int y=0;
    system("title MENÚ FILTROS");
    system("cls");
    do{
        rlutil::hidecursor();
        marco(39,11,43,8,"MENÚ FILTROS");
        showTime("    FILTRAR TECNICOS    ",49,13,y==0);
        showTime("  FILTRAR REPARACIONES  ",49,14,y==1);
        showTime("    FILTRAR REPUESTOS   ",49,15,y==2);
        showTime("    FILTRAR CLIENTES    ",49,16,y==3);
        showTime("VOLVER AL MENÚ PRINCIPAL",49,17,y==4);
        switch(rlutil::getkey()){
            case 14:
                    rlutil::locate(49,13+y);
                    y--;
                    if(y<0){y=0;}
            break;
            case 15:
                    rlutil::locate(49,13+y);
                    y++;
                    if(y>4){y=4;}
            break;
            case 1:
                system("cls");
                   switch(y){
                        case 0:
                            menuFiltroTecnicos();
                            system("cls");
                        break;
                        case 1:
                            menuFiltroReparaciones();
                            system("cls");
                        break;
                        case 2:
                            menuFiltrosRepuestos();
                            system("cls");
                        break;
                        case 3:
                            menuFiltrosClientes();
                            system("cls");
                        break;
                        case 4:
                            return 0;
                        break;
                        }
            break;
        }
    Sleep(70);
    }while(true);

    return 0;
}

int menuInformes(){
    int y=0;
    system("title MENÚ INFORMES");
    system("cls");
    do{
        rlutil::hidecursor();
        marco(39,11,43,9,"MENÚ INFORMES");
        showTime("    HORAS ACUMULADAS POR TÉCNICO   ",43,13,y==0);
        showTime(" TÉCNICO CON MAS CLIENTES ASIGNADOS",43,14,y==1);
        showTime("   CLIENTE CON MAYOR PRESUPUESTO   ",43,15,y==2);
        showTime("   LOCALIDAD CON MAS REPARACIONES  ",43,16,y==3);
        showTime("       EL REPUESTO MAS USADO       ",43,17,y==4);
        showTime("     VOLVER AL MENÚ PRINCIPAL      ",43,18,y==5);

        switch(rlutil::getkey()){
            case 14:
                    rlutil::locate(43,13+y);
                    y--;
                    if(y<0){y=0;}
            break;
            case 15:
                    rlutil::locate(43,13+y);
                    y++;
                    if(y>5){y=5;}
            break;
            case 1:
                system("cls");
                   switch(y){
                        case 0:
                            horasPorTecnico();
                            system("pause");
                            system("cls");
                        break;
                        case 1:
                            if(tecnicoConMasClientes()>0){
                               cout<<"El técnico con más clientes es: ";
                               nombreYApellidoTecnico(tecnicoConMasClientes());
                               cout<<" ID: "<<buscarIDTecnico(tecnicoConMasClientes())+1;
                               cout<<endl;
                            }else{cout<<"Error"<<endl;}
                            system("pause");
                            system("cls");
                        break;
                        case 2:
                            if(clienteConMayorPresupuesto()>0){
                                cout<<"El cliente con mayor presupuesto es: ";
                                nombreYApellido(clienteConMayorPresupuesto());
                                cout<<" ID: "<<buscarIDCliente(clienteConMayorPresupuesto())+1;
                                cout<<endl;
                            }
                            else{cout<<"ERROR."<<endl;}
                            system("pause");
                            system("cls");
                        break;
                        case 3:
                            localidadMasRepa();
                            system("pause");
                            system("cls");
                        break;
                        case 4:
                            if(repuestoMasUsado()>0){
                                cout<<"El ID del repuesto más usado es: "<<repuestoMasUsado()<<endl;
                            }else{cout<<"Error";}
                            system("pause");
                            system("cls");
                        break;
                        case 5:
                                return 0;
                        break;
                        }
            break;
        }
    Sleep(70);
    }while(true);

    return 0;
}

int menuConfiguracion(){
int y=0;
    system("title MENÚ CONFIGURACIÓN");
    system("cls");
    do{
        rlutil::hidecursor();
        marco(32,9,57,15,"MENÚ CONFIGURACIÓN");
        showTime("  HACER COPIA DE SEGURIDAD DEL ARCHIVO CLIENTES  ",37,11,y==0);
        showTime("  HACER COPIA DE SEGURIDAD DEL ARCHIVO TÉCNICOS  ",37,12,y==1);
        showTime("HACER COPIA DE SEGURIDAD DEL ARCHIVO REPARACIONES",37,13,y==2);
        showTime("  HACER COPIA DE SEGURIDAD DEL ARCHIVO REPUESTOS ",37,14,y==3);
        showTime("HACER COPIA DE SEGURIDAD DEL ARCHIVO PRESUPUESTOS",37,15,y==4);
        showTime("         RESTAURAR EL ARCHIVO CLIENTES           ",37,16,y==5);
        showTime("         RESTAURAR EL ARCHIVO TÉCNICOS           ",37,17,y==6);
        showTime("       RESTAURAR EL ARCHIVO REPARACIONES         ",37,18,y==7);
        showTime("        RESTAURAR EL ARCHIVO REPUESTOS           ",37,19,y==8);
        showTime("       RESTAURAR EL ARCHIVO PRESUPUESTOS         ",37,20,y==9);
        showTime("          ESTABLECER DATOS DE INICIO             ",37,21,y==10);
        showTime("           VOLVER AL MENÚ PRINCIPAL              ",37,22,y==11);

        switch(rlutil::getkey()){
            case 14:
                    rlutil::locate(49,13+y);
                    y--;
                    if(y<0){y=0;}
            break;
            case 15:
                    rlutil::locate(49,13+y);
                    y++;
                    if(y>11){y=11;}
            break;
            case 1:
                system("cls");
                   switch(y){
                        case 0:
                            copiaSeguridadClientes();
                            system("pause");
                            system("cls");
                        break;
                        case 1:
                            copiaSeguridadTecnicos();
                            system("pause");
                            system("cls");
                        break;
                        case 2:
                            copiaSeguridadReparaciones();
                            system("pause");
                            system("cls");
                        break;
                        case 3:
                            copiaSeguridadRepuestos();
                            system("pause");
                            system("cls");
                        break;
                        case 4:copiaSeguridadPresupuestos();
                            system("pause");
                            system("cls");
                        break;
                        case 5:
                            restaurarArchivoClientes();
                            system("pause");
                            system("cls");
                        break;
                        case 6: restaurarArchivoTecnicos();
                                system("pause");
                                system("cls");
                        break;
                        case 7:restaurarArchivoReparaciones();
                                system("pause");
                                system("cls");
                        break;
                        case 8:restaurarArchivoRepuestos();
                                system("pause");
                                system("cls");
                        break;
                        case 9: restaurarArchivoPresupuestos();
                                system("pause");
                                system("cls");
                        break;
                        case 10:
                                restaurarDatosInicio();
                                system("pause");
                                system("cls");
                            break;
                        case 11:
                            return 0;
                        break;
                        }
            break;
        }
    Sleep(70);
    }while(true);

    return 0;

}

int menuFiltroTecnicos(){

 int y=0;
    system("title MENÚ FILTROS TÉCNICOS");
    system("cls");
    do{
        rlutil::hidecursor();
        marco(39,11,43,8,"MENÚ FILTRO TÉCNICOS");
        showTime(" FILTRAR POR CATEGORÍA ",49,13,y==0);
        showTime("   FILTRAR POR ESTADO  ",49,14,y==1);
        showTime("   FILTRAR POR NOMBRE  ",49,15,y==2);
        showTime(" FILTRAR POR LOCALIDAD ",49,16,y==3);
        showTime("VOLVER AL MENÚ ANTERIOR",49,17,y==4);

        switch(rlutil::getkey()){
            case 14:
                    rlutil::locate(49,13+y);
                    y--;
                    if(y<0){y=0;}
            break;
            case 15:
                    rlutil::locate(49,13+y);
                    y++;
                    if(y>4){y=4;}
            break;
            case 1:
                system("cls");
                   switch(y){
                        case 0:
                            filtrarTecnicoCat();
                            getch();
                            system("cls");
                        break;
                        case 1:
                            filtrarTecnicoEstado();
                            getch();
                            system("cls");
                        break;
                        case 2:
                            filtrarTecnicoNombre();
                            getch();
                            system("cls");
                        break;
                        case 3:
                            filtrarTecnicoLocalidad();
                            getch();
                            system("cls");
                        break;
                        case 4:
                                return 0;
                        break;
                        }
            break;
        }
    Sleep(70);
    }while(true);
    return 0;

}

int menuFiltroReparaciones(){
    int y=0;
    system("title MENÚ FILTROS REPARACIONES");
    system("cls");
    do{
        rlutil::hidecursor();
        marco(39,11,43,10,"MENÚ FILTRO REPARACIONES");
        showTime("    FILTRAR POR PRESUPUESTO     ",45,13,y==0);
        showTime("FILTRAR POR TIEMPO DE REPARACIÓN",45,14,y==1);
        showTime("      FILTRAR POR ESTADO        ",45,15,y==2);
        showTime("   FILTRAR POR ID DE CLIENTE    ",45,16,y==3);
        showTime("   FILTRAR POR ID DE TÉCNICO    ",45,17,y==4);
        showTime("     FILTRAR POR CATEGORÍA      ",45,18,y==5);
        showTime("    VOLVER AL MENÚ ANTERIOR     ",45,19,y==6);
        switch(rlutil::getkey()){
            case 14:
                    rlutil::locate(44,13+y);
                    y--;
                    if(y<0){y=0;}
            break;
            case 15:
                    rlutil::locate(44,13+y);
                    y++;
                    if(y>6){y=6;}
            break;
            case 1:
                system("cls");
                   switch(y){
                        case 0:
                            filtrarRepaPresup();
                            getch();
                            system("cls");
                        break;
                        case 1:
                            filtrarRepaTiempo();
                            getch();
                            system("cls");
                        break;
                        case 2:
                            filtrarRepaEstado();
                            getch();
                            system("cls");
                            break;
                        case 3:
                            filtrarRepaCliente();
                            getch();
                            system("cls");
                            break;
                        case 4:
                            filtrarRepaTecnico();
                            getch();
                            system("cls");
                            break;
                        case 5:
                            filtrarRepaCat();
                            getch();
                            system("cls");
                        case 6:
                            return 0;
                        break;
                        }
            break;
        }
    Sleep(70);
    }while(true);

    return 0;
}

int menuFiltrosRepuestos(){
    int y=0;
    system("title MENÚ FILTROS REPUESTOS");
    system("cls");
    do{
        rlutil::hidecursor();
        marco(39,11,43,8,"MENÚ FILTROS REPUESTOS");
        showTime("   FILTRAR POR MARCA   ",49,13,y==0);
        showTime("  FILTRAR POR NOMBRE   ",49,14,y==1);
        showTime("   FILTRAR POR PRECIO  ",49,15,y==2);
        showTime(" FILTRAR POR CATEGORÍA ",49,16,y==3);
        showTime("VOLVER AL MENÚ ANTERIOR",49,17,y==4);

        switch(rlutil::getkey()){
            case 14:
                    rlutil::locate(49,13+y);
                    y--;
                    if(y<0){y=0;}
            break;
            case 15:
                    rlutil::locate(49,13+y);
                    y++;
                    if(y>4){y=4;}
            break;
            case 1:
                system("cls");
                   switch(y){
                        case 0:
                            filtrarRepuPorMarca();
                            getch();
                            system("cls");
                        break;
                        case 1:
                            filtrarRepuPorNombre();
                            getch();
                            system("cls");
                        break;
                        case 2:
                            filtrarRepuPorPrecio();
                            getch();
                            system("cls");
                        break;
                        case 3:
                            filtrarRepuPorCat();
                            getch();
                            system("cls");
                        break;
                        case 4:
                            return 0;
                        break;
                        }
            break;
        }
    Sleep(70);
    }while(true);

    return 0;
}

int menuFiltrosClientes(){

    int y=0;
    system("title MENÚ FILTROS CLIENTES");
    system("cls");
    do{
        rlutil::hidecursor();
        marco(39,11,43,8,"MENÚ FILTROS CLIENTES");
        showTime("  FILTRAR POR NOMBRE   ",49,13,y==0);
        showTime(" FILTRAR POR LOCALIDAD ",49,14,y==1);
        showTime("    FILTRAR POR CUIT   ",49,15,y==2);
        showTime("VOLVER AL MENÚ ANTERIOR",49,17,y==3);
        switch(rlutil::getkey()){
            case 14:
                    rlutil::locate(49,13+y);
                    y--;
                    if(y<0){y=0;}
            break;
            case 15:
                    rlutil::locate(49,13+y);
                    y++;
                    if(y>3){y=3;}
            break;
            case 1:
                system("cls");
                   switch(y){
                        case 0:
                            filtrarClienteNombre();
                            getch();
                            system("cls");
                        break;
                        case 1:
                            filtrarClienteLocalidad();
                            getch();
                            system("cls");
                        break;
                        case 2:
                            filtrarClienteCUIT();
                            getch();
                            system("cls");
                        break;
                        case 3:
                            return 0;
                        break;
                        }
            break;
        }
    Sleep(70);
    }while(true);

    return 0;
}


