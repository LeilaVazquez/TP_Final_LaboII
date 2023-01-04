#ifndef GRAFICOS_H_INCLUDED
#define GRAFICOS_H_INCLUDED

#define RED     31
#define GREEN   32
#define YELLOW  33
#define AZUL    34
#define MAGENTA 35
#define CIAN    36
#define WHITE   37

#include "rlutil.h"


void logo();

void gotoxy1(int x, int y);

void txtcolor(int color);

void txtbgcolor(int color);

void rectangle2(int x, int y, int width, int height);

void rectangle(int x, int y, int width, int height);

void square(int x, int y, int lado);

void gotocenter(int x, int y, string cadena);

void marco(int x, int y, int width, int height, string title);

void showTime(const char*text,int posx,int posy,bool selected);

void cuadroTecnicos(int x, int y);

void cierreCuadroTecnicos(int x, int y, int yi);

void cuadroClientes(int x, int y);

void cierreCuadroClientes(int x, int y, int yi);

void cuadroRepuestos(int x, int y);

void cierreCuadroRepuestos(int x, int y, int yi);

void mostrarCategoriaRepuesto(int x, int y, int cat);

void cuadroReparaciones(int x, int y);

void rectangulo();

int menuReparaciones();

int menuClientes();

int menuTecnicos();

int menuRepuestos();

int menuInformes();

int menuFiltros();

int menuConfiguracion();

int menuFiltroTecnicos();

int menuFiltroReparaciones();

int menuFiltrosRepuestos();

int menuFiltrosClientes();

#endif // GRAFICOS_H_INCLUDED
