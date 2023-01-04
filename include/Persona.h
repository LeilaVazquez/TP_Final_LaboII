#ifndef PERSONA_H
#define PERSONA_H

#include <string.h>
#include "Direccion.h"
#include "Contacto.h"

class Persona
{
    protected:
        char nombre[40];
        char apellido[40];
        Direccion direc;
        Contacto contac;
    public:
        ///sets
        void setNombre(const char* n){strcpy(nombre, n);}
        void setApellido(const char*n){strcpy(apellido, n);}
        void setDireccion(Direccion d){direc=d;}
        void setContacto(Contacto c){contac=c;}
        ///gets
        const char* getNombre(){return nombre;}
        const char* getApellido(){return apellido;}
        Direccion getDireccion(){return direc;}
        Contacto getContacto(){return contac;}


};

#endif // PERSONA_H
