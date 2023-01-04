#ifndef CONTACTO_H
#define CONTACTO_H
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;


class Contacto
{
    private:
        long telefono;
        char mail[31];

    public:
        ///sets
        bool setTelefono(long n){
            if(n>0){
                telefono=n;
                return true;
            }
            return false;
        }
        void setMail(const char*m){strcpy(mail, m);}
        ///gets
        long getTelefono(){return telefono;}
        const char*getMail(){return mail;}

        bool cargar();
        void mostrar();

};

#endif // CONTACTO_H
