#ifndef GRAFICO_H
#define GRAFICO_H

#include "rlutil.h"

/*void showTime(const char*text,int posx,int posy,bool selected){

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

void rectangulo(){
       for(int x=31; x<80; x++){
            gotoxy(x,12); printf("&c",205);
            gotoxy(x,20); printf("%c",205); ///21
        }
        for(int y=13; y<20; y++){
            gotoxy(30,y); printf("%c",186);
            gotoxy(80,y); printf("%c",186);
        }
        gotoxy(30,12); printf("%c",201);
        gotoxy(30,20); printf("%c",200); ///21
        gotoxy(80,12); printf("%c",187);
        gotoxy(80,20); printf("%c",188); ///21
}

int menuIncidencias(){

    Incidencia obj;
    int y=0;
    system("title MENU INCIDENCIAS");
    do{
        system("cls");
        rlutil::hidecursor();
        //rectangulo();
        showTime("     CARGAR INCIDENCIA     ",50,14,y==0);
        showTime("     LISTAR INCIDENCIAS    ",50,15,y==1);
        showTime("   ACTUALIZAR INCIDENCIA   ",50,16,y==2);
        showTime("  VOLVER AL MENU PRINCIPAL ",50,17,y==3);

        switch(rlutil::getkey()){
            case 14:
                    rlutil::locate(50,14+y);
                    y--;
                    if(y<0){y=0;}
            break;
            case 15:
                    rlutil::locate(50,14+y);
                    y++;
                    if(y>3){y=3;}
            break;
            case 1:
                   system("cls");
                   switch(y){
                        case 0:
                            if(obj.cargar()){
                                system("cls");
                                obj.mostrar();
                            }
                            system("pause");
                        break;
                        case 1:

                        break;
                        case 2:

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

int menuClientes(){

    Cliente obj;
    int y=0;
    system("title MENU CLIENTES");
    do{
        system("cls");
        rlutil::hidecursor();
        //rectangulo();
        showTime("     LISTAR CLIENTES      ",50,14,y==0);
        showTime("     CARGAR CLIENTE       ",50,15,y==1);
        showTime("    MODIFICAR CLIENTE     ",50,16,y==2);
        showTime(" VOLVER AL MENU PRINCIPAL ",50,17,y==3);

        switch(rlutil::getkey()){
            case 14:
                    rlutil::locate(50,14+y);
                    y--;
                    if(y<0){y=0;}
            break;
            case 15:
                    rlutil::locate(50,14+y);
                    y++;
                    if(y>3){y=3;}
            break;
            case 1:
                    system("cls");
                   switch(y){
                        case 0:

                        break;
                        case 1:
                            if(obj.cargar()){
                                system("cls");
                                obj.mostrar();
                            }
                            system("pause");
                        break;
                        case 2:

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

int menuTecnicos(){

    Tecnico obj;
    int y=0;
    system("title MENU TÉCNICOS");
    do{
        system("cls");
        rlutil::hidecursor();
        //rectangulo();
        showTime("     LISTAR TÉCNICOS      ",50,14,y==0);
        showTime("     CARGAR TÉCNICO      ",50,15,y==1);
        showTime("    MODIFICAR TÉCNICO     ",50,16,y==2);
        showTime(" VOLVER AL MENU PRINCIPAL ",50,17,y==3);

        switch(rlutil::getkey()){
            case 14:
                    rlutil::locate(50,14+y);
                    y--;
                    if(y<0){y=0;}
            break;
            case 15:
                    rlutil::locate(50,14+y);
                    y++;
                    if(y>3){y=3;}
            break;
            case 1:
                    system("cls");
                   switch(y){
                        case 0:

                        break;
                        case 1:
                            //obj.cargar()
                            cout<<endl;
                            //obj.mostrar();
                            system("pause");
                        break;
                        case 2:

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

int menuRepuestos(){

    int y=0;
    system("title MENU REPUESTOS");
    do{
        system("cls");
        rlutil::hidecursor();
        //rectangulo();
        showTime("     LISTAR REPUESTOS     ",50,14,y==0);
        showTime("          ALTA            ",50,15,y==1);
        showTime("          BAJA            ",50,16,y==2);
        showTime("      MODIFICACIONES      ",50,17,y==3);
        showTime(" VOLVER AL MENU PRINCIPAL ",50,18,y==4);

        switch(rlutil::getkey()){
            case 14:
                    rlutil::locate(50,14+y);
                    y--;
                    if(y<0){y=0;}
            break;
            case 15:
                    rlutil::locate(50,14+y);
                    y++;
                    if(y>4){y=4;}
            break;
            case 1:
                   switch(y){
                        case 0:

                        break;
                        case 1:

                        break;
                        case 2:

                        break;
                        case 3:

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

int menuReportes()
{
    int y=0;
    system("title MENU REPORTES");
    do{
        system("cls");
        rlutil::hidecursor();
        //rectangulo();
        showTime("  INCIDENCIAS POR CATEGORIA    ",50,14,y==0);
        showTime("   INCIDENCIAS POR CLIENTE     ",50,15,y==1);
        showTime(" CATEGORIA CON MAS INCIDENCIAS ",50,16,y==2);
        showTime("          OTROS 2              ",50,17,y==3);
        showTime(" VOLVER AL MENU PRINCIPAL      ",50,18,y==4);

        switch(rlutil::getkey()){
            case 14:
                    rlutil::locate(50,14+y);
                    y--;
                    if(y<0){y=0;}
            break;
            case 15:
                    rlutil::locate(50,14+y);
                    y++;
                    if(y>4){y=4;}
            break;
            case 1:
                   switch(y){
                        case 0:

                        break;
                        case 1:

                        break;
                        case 2:

                        break;
                        case 3:

                        case 4:
                                  return 0;
                        break;
                        }
            break;
        }
    Sleep(70);
    }while(true);

    return 0;
}*/
#endif // GRAFICO_H
