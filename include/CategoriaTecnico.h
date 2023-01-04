#ifndef CATEGORIATECNICO_H
#define CATEGORIATECNICO_H
#include <string.h>

class CategoriaTecnico
{
    private:
        float precio;
        char tipo;
        char especialidad[30];

    public:
        ///sets
        void setTipo(char t){tipo=t;}
        void setPrecio(float p){precio=p;}
        void setEspecialidad(const char* e){strcpy(especialidad, e);}

        ///gets
        float getPrecio(){return precio;}
        char getTipo(){return tipo;}
        const char* getEspecialidad(){return especialidad;}

        bool cargar();
};

#endif // CATEGORIATECNICO_H
