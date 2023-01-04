#ifndef TECNICO_H
#define TECNICO_H

#include <Persona.h>
#include "CategoriaTecnico.h"

class Tecnico : public Persona
{
    private:
        int id;
        CategoriaTecnico categoria;
        bool contratado;

    public:
        void setId(int i){id=i;}
        void setCategoria(CategoriaTecnico c){categoria=c;}
        void setContratado(bool c){contratado=c;}

        bool getContratado(){return contratado;}
        int getId(){return id;}
        CategoriaTecnico getCategoria(){return categoria;}

        bool cargar();
        void mostrar(int x, int y);
        bool grabar();
        int leer(int pos);
        void listar();
        bool modificar(int pos);
        bool actualizarEstado();
        bool modificarTecnico();
        void buscarPorID();


};

#endif // TECNICO_H
