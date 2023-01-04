#ifndef REPUESTO_H
#define REPUESTO_H
#include <string.h>
#include <iostream>
#include <conio.h>

class Repuesto{

private:
    int idRepuesto;
    int categoriaRepuestos;
    char nombre[30];
    float precio;
    char marca[30];

public:
    ///sets
    void setIdRepuesto(int id){idRepuesto=id;}
    bool setCategoriaRepuesto(int cr){
        if(cr>0&&cr<5){
           categoriaRepuestos=cr;
           return true;
        }
        return false;
    }
    void setNombre(const char *n){strcpy(nombre,n);}
    bool setPrecio(float p){
        if(p>0){
            precio=p;
            return true;
        }
        return false;
    }
    void setMarca(const char *m){strcpy(marca,m);}


    ///gets
    int getIdRepuesto(){return idRepuesto;}
    int getCategoriaRepuesto(){return categoriaRepuestos;}
    char *getNombre(){return nombre;}
    float getPrecio(){return precio;}
    char *getMarca(){return marca;}

    bool alta();
    bool baja();
    bool grabar();
    int leer(int pos);
    void mostrar(int x, int y);
    bool modificar(int pos);
    int mostrarRepuestos(int cat, int x, int y);
    void mostrarPorCategoria(int cat);
    void listarRepuestos();
    bool modificarRepuesto();
    void buscarPorID();

};

#endif // REPUESTO_H
