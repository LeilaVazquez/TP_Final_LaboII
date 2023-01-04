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
#include <bits/stdc++.h>
#include <fstream>

using namespace std;
using namespace rlutil;

#include "funciones.h"
#include "Fecha.h"
#include "Tecnico.h"
#include "Cliente.h"
#include "Reparacion.h"
#include "Repuesto.h"
#include "Graficos.h"
#include "frame.h"

int main()
{
    HANDLE m_hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bottemRight={(signed)120, (signed)9001};
    system("mode con: cols=120 lines=30");
    SetConsoleScreenBufferSize(m_hConsole, bottemRight);
    logo();
    getch();
    if(!setteoContador()){
        cout<<"Error en la carga de archivos."<<endl;
        return false;
    }
    setlocale(LC_ALL, "spanish");
    int y=0;
    system("title SISTEMA DE GESTIÓN DE REPARACIONES");
    system("cls");
    do{
        rlutil::hidecursor();
        marco(39,11,43,11,"MENÚ PRINCIPAL");
        txtcolor(WHITE);
        showTime(" REPARACIONES ",53,13,y==0);
        showTime("   CLIENTES   ",53,14,y==1);
        showTime("   TÉCNICOS   ",53,15,y==2);
        showTime("  REPUESTOS   ",53,16,y==3);
        showTime("   FILTROS    ",53,17,y==4);
        showTime("   INFORMES   ",53,18,y==5);
        showTime("CONFIGURACIÓN ",53,19,y==6);
        showTime("    SALIR     ",53,20,y==7);

        switch(rlutil::getkey()){
            case 14:
                    rlutil::locate(54,13+y);
                    y--;
                    if(y<0){y=0;}
            break;
            case 15:
                    rlutil::locate(54,13+y);
                    y++;
                    if(y>7){y=7;}
            break;
            case 1:
                   switch(y){
                        case 0:
                            menuReparaciones();
                        break;
                        case 1:
                            menuClientes();
                        break;
                        case 2:
                            menuTecnicos();
                        break;
                        case 3:
                            menuRepuestos();
                        break;
                        case 4:
                            menuFiltros();
                        break;
                        case 5:
                            menuInformes();
                            break;
                        case 6:
                            menuConfiguracion();
                            break;
                        case 7:
                                system("cls");
                                rectangle(50,13,19,4);
                                rlutil::locate(52,15);
                                txtcolor(WHITE);
                                cout<<"HASTA LA PRÓXIMA";
                                getch();
                                return 0;
                        break;
                        }
            break;
        }
    Sleep(70);
    }while(true);
    return 0;
}
