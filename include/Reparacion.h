#ifndef INCIDENCIA_H
#define INCIDENCIA_H

#include "Repuesto.h"
#include "Fecha.h"


class Reparacion{

private:
    int idReparacion;
    float presupuesto;
    float tiempoReparacion;
    char observaciones[100];
    int estado;
    Repuesto repuestosReparacion;
    int categoriaReparacion;
    Fecha fechaAltaReparacion;
    int idCliente;
    int idTecnico;


public:
    ///sets
    void setIdReparacion(int id){idReparacion=id;}
    void setPresupuesto(float p){presupuesto=p;}
    bool setTiempoReparacion(float tr){
        if(tr>=0){
            tiempoReparacion=tr;
            return true;
        }
        return false;
    }
    void setObservaciones(const char *o){strcpy(observaciones,o);}
    bool setEstado(int e){
        if(e>0&&e<6){
            estado=e;
            return true;
        }
        return false;
    }
    void setRepuestosReparacion(Repuesto ri){repuestosReparacion=ri;}
    bool setCategoriaReparacion(int ci){
        if(ci>0&&ci<5){
            categoriaReparacion=ci;
            return true;
        }
        return false;
    }
    void setFecha(Fecha f){fechaAltaReparacion=f;}
    void setIdCliente(int ic){idCliente=ic;}
    void setIdTecnico(int it){idTecnico=it;}

    ///gets
    int getIdReparacion(){return idReparacion;}
    float getPresupuesto(){return presupuesto;}
    float getTiempoReparacion(){return tiempoReparacion;}
    char *getObservacion(){return observaciones;}
    int getEstado(){return estado;}
    Repuesto getRepuestosReparacion(){return repuestosReparacion;}
    int getCategoriaReparacion(){return categoriaReparacion;}
    int getIdCliente(){return idCliente;}
    int getIdTecnico(){return idTecnico;}
    Fecha getFecha(){return fechaAltaReparacion;}

    const char* mostrarEstado(int n);
    bool cargar();
    void mostrar(int x, int y);
    void listar();
    bool modificar(int pos);
    bool actualizarEstado();
    bool gestionar();
    bool grabar();
    int leer(int pos);
    void buscarPorID();


};
#endif // INCIDENCIA_H
