#ifndef CLIENTE_H
#define CLIENTE_H
#include <string.h>
#include <Persona.h>

class Cliente : public Persona
{
    private:
        int id;
        char cuil_cuit[11];

    public:
        void setId(int n){id=n;}
        void setCuil_Cuit(const char *c){strcpy(cuil_cuit,c);}

        int getId(){return id;}
        const char* getCuil_Cuit(){return cuil_cuit;}

        bool cargar();
        void mostrarCUIT(const char *cuit);
        void mostrar(int x, int y);
        bool grabar();
        void listar();
        bool modificar(int pos);
        bool modificarCliente();
        int leer(int pos);
        void buscarPorID();
        void mostrarDireccion(int ID);

};

#endif // CLIENTE_H
