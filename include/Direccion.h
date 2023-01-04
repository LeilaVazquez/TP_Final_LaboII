#ifndef DIRECCION_H
#define DIRECCION_H
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class Direccion
{
    private:
        char calle[20];
        char localidad[20];
        char provincia[20];
        char codigoPostal[10];

    public:
        ///sets
        void setCalle(const char*c){strcpy(calle, c);}
        void setLocalidad(const char*c){strcpy(localidad, c);}
        void setProvincia(const char*c){strcpy(provincia, c);}
        void setCodigoPostal(const char*c){strcpy(codigoPostal, c);}
        ///gets
        const char* getCalle(){return calle;}
        const char* getLocalidad(){return localidad;}
        const char* getProvincia(){return provincia;}
        const char* getCodigoPostal(){return codigoPostal;}

        void cargar();
        void mostrar();

};

#endif // DIRECCION_H
